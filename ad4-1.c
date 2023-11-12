#include <stdio.h> // printf 用
#include <math.h> // ceil, log, pow 用．コンパイル時オプション-lm
#define Tw(n) (int)((n)*ceil(log(n)/log(2))-pow(2,ceil(log(n)/log(2)))+1) // 最悪比較演算回数の理論値
#define N 8 // 入力データサイズ
int cnt = 0; // データどうしの比較演算回数カウント用
void msort(), merge(), show_addr(), show();
void show_addr(int Z[], int n){
  int i;
  for(i = 0; i < n; i++) printf(" %x", &Z[i]); // 各要素のアドレス表示
  printf("\n");
}
int main(){
  int X[N] = {6, 18, 12, 21, 7, 19, 14, 37}; // 入力配列の宣言
  int Y[N]; // 出力配列の宣言
  show_addr(X,N);show_addr(Y,N); // 各配列の占有アドレスの表示
  show(X, N); // 入力配列の内容表示
  msort(X, N, Y); // ソートの実行
  show(Y, N); // 出力配列の内容表示
  printf("cnt=%d : Tw(%d)=%d\n", cnt, N, Tw(N)); // 比較演算回数の表示
}
void msort(int X[], int n, int Y[]){
  int n1 = n / 2, n2 = n - n1, i; // n>=0 のとき，n1=floor(n/2), n2=ceil(n/2)
  int X1[n1], X2[n2], Y1[n1], Y2[n2]; // 作業用配列の宣言
  show_addr(X1,n1);show_addr(X2,n2);show_addr(Y1,n1);show_addr(Y2,n2);
  for(i = 0; i < n; i++){ //X1とX2にXの値を代入
    if(i < n1){
      X1[i] = X[i];
    }else{
      X2[i - n1] = X[i];
    }
  }
  if(n > 1){ //配列の長さが1より大きい場合
    msort(X1, n1, Y1); //再帰
    msort(X2, n2, Y2); //再帰
    merge(Y1, n1, Y2, n2, Y); //併合
  }else if(n == 1) Y[0] = X[0]; //配列の長さが1の場合はYにXを代入
}
void merge(int Y1[], int n1, int Y2[], int n2, int Y[]){
  int i = 0, j = 0, k;
  for(k = 0; k < n1 + n2; k++){
    if(j == n2 || (i < n1 && Y1[i] <= Y2[j])){ //Y2の要素が残っていないまたはY1の要素が残っている状態でY1[i]<=Y2[j]の場合
      Y[k] = Y1[i++]; //YにY1を代入してY1は次の値へ
      if(j != n2) cnt++; //比較カウント
    }else{ //その他の場合
      Y[k] = Y2[j++]; //YにY2を代入してY2は次の値へ
      if(i != n1) cnt++; //比較カウント
    }
  }
}
void show(int X[], int n){
  int i;
  for(i = 0; i < n; i++) printf(" %d", X[i]); //各要素の内容表示
  printf("\n");
}
