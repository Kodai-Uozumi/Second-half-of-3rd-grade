/* N入力1出力のニューラルネットワーク */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_INPUT 2
#define NUM_HIDDEN 10				/* 中間層のユニット数 */
#define RAND (double)rand()/(double)RAND_MAX	/* 区間[0,1]の疑似一様乱数 */
#define ETA 0.01					/* η(イータ)：学習係数(小さい正の値) */
#define TRAINING_TIMES 1000			/* 学習回数 */
#define f(z) 1.0/(1.0+exp(-z))		/* シグモイド関数 */
#define MAX_DATA 150				/* 教師データの最大数（これより多く設定したい場合変更する */

/* プロトタイプ宣言 入力から出力を求める計算を関数化する場合 */
double NN(double x[], double v[][NUM_INPUT + 1], double w[], double z[]);
double rand_normal(double x_test[], double mu, double sigma);

int main(void)
{
	int i, j, k;
	int t;

	double x[NUM_INPUT + 1];			/* 入力値 +1は閾値ユニット分*/
	x[NUM_INPUT] = 1.0;					/* 閾値ユニットへの入力は常に１ */

	double v[NUM_HIDDEN][NUM_INPUT + 1];	/* 入力から中間層ユニットへの結合荷重（入力と閾値の2つに対する重み）*/
	double u_h[NUM_HIDDEN];		/* 中間層ユニットの内部状態 */
	double z[NUM_HIDDEN + 1];	/* 中間層ユニットの出力 */
	z[NUM_HIDDEN] = 1.0;		/* 閾値ユニットへの入力は常に１ */

	double w[NUM_HIDDEN + 1];	/* 中間層から出力ユニットへの結合荷重（閾値ユニット含むため+1） */
	double u_y;					/* 出力ユニットの内部状態 */
	double y;					/* 出力ユニットの出力 */
	double yd;					/* 目標出力（教師信号） */

	double delta_y;				/* 誤差逆伝搬に用いる変数 */
	double delta_h[NUM_HIDDEN];	/* 誤差逆伝搬に用いる変数 */

	double error;
	double sum_error;

	double data[MAX_DATA][NUM_INPUT +1];	/*  入力データ（行：データ番号，列：入力xと出力yのペアつまり教師データ）INPUT_+1は入力数と出力数の和の意味 */

	srand(9999);				/* 乱数シード */

	double temp;
	int num_data = 0;

	double x_test[NUM_INPUT];	/* テスト入力 */
	int bunkatu = 50;			/* テスト時の入力範囲分割数 */


	FILE* f1 = fopen("training_data_2021_a.txt", "r");
	FILE* f2 = fopen("training_curve.txt", "w");
	FILE* f3 = fopen("y_test.txt", "w");


	/*  訓練データの読込み */
	printf("Reading training data\n");

	while (fscanf(f1, "%lf", &temp) != EOF) {
		printf("#%d\t", num_data+1);
		data[num_data][0] = temp;			
		printf("x[0]:%f\t", temp);				
		
		fscanf(f1, "%lf", &temp);
		data[num_data][1] = temp;
		printf("x[1]:%f\t", temp);

		fscanf(f1, "%lf", &temp);
		data[num_data][2] = temp;	
		printf("yd:%f\n", temp);

		num_data++;							/*  訓練データ数をのカウント（training_data_2021_a.txtの行数カウント） */
	}
	fclose(f1);
	printf("Press Enter to continue...");
	getchar();

	/*  【学習ここから】 */

	/*  【初期化】結合重みの初期化（0±1.0の範囲でランダムに重みを初期化している） */
	for (j = 0; j < NUM_HIDDEN; j++) {
		for (i = 0; i < NUM_INPUT + 1; i++) {
			v[j][i] = 2.0 * RAND - 1.0;							/*  入力xに対する重み */
		}
	}
	for (j = 0; j < NUM_HIDDEN + 1; j++) {
		w[j] = 2.0 * RAND - 1.0;								/*  中間層の出力に対する重み */
	}

	/*  【出力計算と学習のループ（TRAINING_TIMES回繰り返す）】 */
	for (t = 0; t < TRAINING_TIMES; t++) {

		sum_error = 0.0;
		for (int data_count = 0; data_count < num_data; data_count++) {

			/* 【課題１】入力から出力を計算する */
			for (i = 0; i < NUM_INPUT; i++) {
				x[i] = data[data_count][i];						/*  data_count番目のxの値を代入する */
			}

			y = NN(x, v, w, z);
			yd = data[data_count][NUM_INPUT];					/*  目標出力（教師信号） */
			
			error = 0.5 * (y - yd) * (y - yd);					/* 誤差計算 */
			sum_error += error;									/* 誤差和の保存 */

			/* 【誤差逆伝搬法による学習】 */
			/*  出力層のデルタdelta_yの計算（実習） */
			delta_y = y - yd;
			/*  中間層から出力層の重み更新（実習） */
			for(j = 0; j < NUM_HIDDEN + 1; j++){
				w[j] -= ETA * delta_y * z[j];
			}
			/*  中間層のデルタdelta_h[j]の計算（実習） */
			for(j = 0; j < NUM_HIDDEN; j++){
				delta_h[j] = delta_y * z[j] * (1 - z[j]) * w[j];
			}
			/*  入力層から中間層の重み更新（実習） */
			for(j = 0; j < NUM_HIDDEN; j++){
				for(i = 0; i < NUM_INPUT + 1; i++){
					v[j][i] -= ETA * delta_h[j] * x[i]; 
				}
			}
			/*  【誤差逆伝搬法ここまで】 */
		}
		
		/* 【課題２】訓練回数と誤差和をprintfで表示する．同時にfprintfでファイルにも保存する（実習） */
        printf("training: %d\n",t); /* 表示テスト用のダミー */
		printf("%f\n", sum_error);
		fprintf(f2, "%d\t%f\t", t, sum_error);
		
		sum_error = 0.0;
		for (i = 0; i < bunkatu + 1; i++) {
			
			x_test[0] = (2.0 / bunkatu) * i - 1.0;
			
			for (j = 0; j < bunkatu + 1; j++) {
				x_test[1] = (2.0 / bunkatu) * j - 1.0;
				
				y = NN(x_test, v, w, z);
				/* テスト誤差の評価 */
				yd = rand_normal(x_test, 0.0, 0.3); /* 二次元正規分布にx_testを代入して真の値ydを求める */
				sum_error += 0.5 * (y - yd) * (y - yd);
			}
		}
		fprintf(f2, "%f\n", sum_error);

	}
	fclose(f2);



	/* 【課題３】テスト誤差の検証 */
	sum_error = 0.0;
	/* 列ラベル書き込み */
	fprintf(f3, "\t");
	for (j = 0; j < bunkatu + 1; j++) {
		x_test[1] = (2.0 / bunkatu) * j - 1.0;
		if (j != bunkatu) {
			//printf("x_test[1] = %f\t", x_test[1]);		/* 行の最後でなければタブ（空白）を入れて継続 */
			fprintf(f3, "%f\t", x_test[1]);
		}
		else {
			//printf("x_test[1] = %f\n", x_test[1]);		/* 行の最後で改行しているだけ */
			fprintf(f3, "%f\n", x_test[1]);
		}
		
	}

	for (i = 0; i < bunkatu + 1; i++) {

		x_test[0] = (2.0 / bunkatu) * i - 1.0;
		/* 行ラベル書き込み */
		//printf("x_test[0] = %f\t", x_test[0]);
		fprintf(f3, "%f\t", x_test[0]);

		for (j = 0; j < bunkatu + 1; j++) {
			x_test[1] = (2.0 / bunkatu) * j - 1.0;

			/* NNの出力計算と結果表示・保存 */
			
			/* ニューラルネットワークの順伝播計算（入力x_testから出力yを計算する）（実習）/*
			/* 課題1で作成した順伝播計算（入力から出力を求めるプログラムを貼り付ければよい */
			/* ただし，入力はx_[0],x[1]ではなく，x_test[0],x_test[1]なので注意 */
			y = NN(x_test, v, w, z);
			/* テスト誤差の評価 */
			yd = rand_normal(x_test, 0.0, 0.3); /* 二次元正規分布にx_testを代入して真の値ydを求める */
			sum_error += 0.5 * (y - yd) * (y - yd);
			
			if (j != bunkatu) {
				//printf("y=%f\t", y);
				fprintf(f3, "%f\t", y);
			}
			else {
				//printf("y=%f\n", y);
				fprintf(f3, "%f\n",y);
			}
		}
	}
	printf("test_error = %f\n", sum_error);
	return 0;
}


/*【発展課題１】ニューラルネットワークの順伝播計算の関数化 */
/* 発展課題１をレポートに含めるときは，以下で作成した関数をそのままレポートに貼り付けること */

double NN(double input[], double v[][NUM_INPUT + 1], double w[], double z[]) {

	int i, j;
	double x[NUM_INPUT + 1];	/* 入力値 */
	double u_h[NUM_HIDDEN];		/* 中間層ユニットの内部状態 */
	x[NUM_INPUT] = 1.0;			/* 閾値ユニットへの入力は常に１ */
	z[NUM_HIDDEN] = 1.0;		/* 閾値ユニットへの入力は常に１ */

	double u_y;					/* 出力ユニットの内部状態 */
	double y;					/* 出力ユニットの出力 */

	//【入力から出力を計算する】
	for (i = 0; i < NUM_INPUT; i++) {
		x[i] = input[i];
	}

	/* 入力xから出力yを求めるプログラムを記述する（課題１とほとんど同じ）（実習） */
	for(j = 0; j < NUM_HIDDEN; j++){
		u_h[j] = 0.0;
		for(i = 0; i < NUM_INPUT + 1; i++){
			u_h[j] += v[j][i] * x[i]; 
		}
		z[j] = f(u_h[j]);
	}
	/* 中間層から出力層の出力yを計算（実習）*/
	u_y = 0.0;
	for(j = 0; j < NUM_HIDDEN + 1; j++){
		u_y += w[j] * z[j];
	}
	y = u_y;					// NNの出力（シグモイド関数を通さない）

	return y;
}

/* 二次元正規分布（無相関）の値を返す関数 */
double rand_normal(double x_test[], double mu, double sigma) {
	double z1,z2,z;
	z1 = (1.0/sqrt(2.0*M_PI*pow(sigma,2.0))) * exp(-1.0*pow(x_test[0]-mu,2.0)/(2.0*pow(sigma,2.0)));
	z2 = (1.0/sqrt(2.0*M_PI*pow(sigma,2.0))) * exp(-1.0*pow(x_test[1]-mu,2.0)/(2.0*pow(sigma,2.0)));
	z = z1 * z2;
	return z;
}