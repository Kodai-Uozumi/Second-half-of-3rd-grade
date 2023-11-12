#include <stdio.h>
#include <unistd.h>
int main(void){
  int year, month;
  char syear[5], smonth[3];
  printf("年を入力してください:");
  scanf("%d", &year);
  printf("月を入力してください:");
  scanf("%d", &month);
  sprintf(syear, "%d", year);
  sprintf(smonth, "%d", month);
  execlp("cal", "cal", smonth, syear, NULL);
}
