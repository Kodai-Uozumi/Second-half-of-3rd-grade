#include <stdio.h> // scanf, printf用
int main(void)
{
  int fibo0 = 0, fibo1 = 1, fibon, n, cnt = 0, i; // cntは加算回数カウント用
  scanf("%d", &n);
  if(n > 1){ // Fnのnが2以上の場合
    for(i = 1; i < n; i++){
      fibon = fibo0 + fibo1;
      fibo0 = fibo1;
      fibo1 = fibon;
      cnt++;
    }
  }
  else if(n == 1){ // F1の場合
    fibon = fibo1;
  }
  else{ // F0の場合
    fibon = fibo0;
  }
  printf("F=%d, 加算回数%d回\n", fibon, cnt);
}
