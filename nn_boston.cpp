#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_INPUT 12
#define NUM_HIDDEN 200				/* 中間層のユニット数 */
#define RAND (double)rand()/(double)RAND_MAX	/* 区間[0,1]の疑似一様乱数 */
#define ETA 0.01					/* η(イータ)：学習係数(小さい正の値) */
#define TRAINING_TIMES 1000			/* 学習回数 */
#define f(z) 1.0/(1.0+exp(-z))		/* シグモイド関数 */
#define MAX_DATA 500				/* 教師データの最大数（これより多く設定したい場合変更する */

/* プロトタイプ宣言 入力から出力を求める計算を関数化する場合 */
double NN(double x[], double v[][NUM_INPUT + 1], double w[], double z[]);

int main(void)
{
	int i, j, k;
	int t;

	double x[NUM_INPUT + 1];			/* 入力値 +1は閾値ユニット分*/
    double x_test[NUM_INPUT + 1];
	x[NUM_INPUT] = 1.0;					/* 閾値ユニットへの入力は常に１ */
    x_test[NUM_INPUT] = 1.0;

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
    double test_error;

	double data[MAX_DATA][NUM_INPUT +1];	/*  入力データ（行：データ番号，列：入力xと出力yのペアつまり教師データ）INPUT_+1は入力数と出力数の和の意味 */
    double data_test[MAX_DATA][NUM_INPUT + 1];

	srand(9999);				/* 乱数シード */

	double temp;
	int num_data = 0;
    int num_data_test = 0;
    FILE* f1 = fopen("boston_train.txt", "r");
	FILE* f2 = fopen("boston_curve.txt", "w");
	FILE* f3 = fopen("boston_y.txt", "w");


	/*  訓練データの読込み */
	printf("Reading training data\n");

	while (fscanf(f1, "%lf", &temp) != EOF) {
		printf("#%d\t", num_data+1);
        data[num_data][0] = temp;			
		printf("x[0]:%f\t", temp);
        for(i = 1; i < NUM_INPUT; i++){
            fscanf(f1, "%lf", &temp);
            data[num_data][i] = temp;
            printf("x[%d]:%f\t", i, temp);
        }
		fscanf(f1, "%lf", &temp);
		data[num_data][NUM_INPUT] = temp;	
		printf("yd:%f\n", temp);

		num_data++;
	}
    f1 = fopen("boston_test.txt", "r");
    while(fscanf(f1, "%lf", &temp) != EOF){
        data_test[num_data_test][0] = temp;
        printf("%f\t", temp);

        for(i = 1; i < NUM_INPUT + 1; i++){
            fscanf(f1, "%lf", &temp);
            data_test[num_data_test][i] = temp;
            printf("%f\t", temp);
        }
        num_data_test++;
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
		
		test_error = 0.0;
		for (i = 0; i < num_data_test; i++) {
            for (j = 0; j < NUM_INPUT; j++) {
                x_test[j] = data_test[i][j];
            }

            y = NN(x_test, v, w, z);
            
            yd = data_test[i][NUM_INPUT];
            test_error += 0.5 * (y - yd) * (y - yd);
        }
		fprintf(f2, "%f\n", test_error);

	}
	fclose(f2);
    for (i = 0; i < num_data_test; i++) {
            for (j = 0; j < NUM_INPUT; j++) {
                x_test[j] = data_test[i][j];
            }
            y = NN(x_test, v, w, z);
            yd = data_test[i][NUM_INPUT];
            fprintf(f3, "%f\t%f\n", y, yd);
            printf("%f\t%f\n", y, yd);
    }
    fclose(f3);
	return 0;
}

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