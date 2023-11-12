#include <stdio.h>
int F[100]; // 計算履歴格納用配列：大域変数
int cnt = 0; // 加算回数カウント用
#define UNEVALUATED -1 // 未評価（未定義）フラグ
int main(void)
{
  int i, n;
  for (i = 0; i < 100; i++) F[i] = UNEVALUATED; // 履歴配列の初期化
  scanf("%d",&n);
  if (n >= 0){
    printf("F=%d, ", fibo(n));
    printf("加算回数%d回\n", cnt);
  }
}
int fibo(int n) // フィボナッチ数を求める再帰関数
{
  if (F[n] != UNEVALUATED) return F[n]; // 求値済みならば直ちに戻る
  if (n == 0) return F[0] = 0; // F[0] に値 0 を格納しその値を返す
  if (n == 1) return F[1] = 1; // F[1]に値1を格納しその値を返す
  F[n - 1] = fibo(n - 1);
  F[n - 2] =fibo(n - 2);
  cnt++;
  return F[n - 1] + F[n - 2]; // Fn = Fn-1 + Fn-2
}
