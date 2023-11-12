#include <stdio.h>

/*入力をオウム返しするプログラム*/
int main(void){
  printf("文字列を入力してください: \n");
  char s1[10] = "";
  scanf("%9s", s1); //最大9文字読み込む

  printf("以下の文字列が入力されました: \n");
  printf("%s", s1); //書式文字列を利用者がコントロールできないようにした
  printf("\n");
  
  return 0;
}