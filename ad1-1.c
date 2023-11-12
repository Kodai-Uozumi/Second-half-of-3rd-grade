#include <stdio.h> // scanf, printf 用
int cnt = 0; // 加算回数カウント用
int fibo();
int main(void)
{
  int a;
  scanf("%d", &a);
  printf("F=%d\n", fibo(a));
  printf("加算回数%d回\n", cnt);
}
int fibo(int n) // フィボナッチ数を求める再帰関数
{
  if (n == 0) return 0;
  if (n == 1) return 1;
  if (n >= 2){
    cnt++;
    return fibo(n - 1) + fibo(n - 2);
  }
}
