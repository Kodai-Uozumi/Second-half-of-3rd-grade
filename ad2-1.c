#include <stdio.h> //printf用
#include <stdlib.h> //malloc, free用
struct cell{ //構造体定義
  int data; //データ
  struct cell *next; //ポインタ
}*a; //構造体変数宣言
void push(), show(); int pop(), empty();
void push(int x){ //push
  struct cell *b; //構造体変数宣言
  b = (struct cell *) malloc(sizeof(struct cell)); //領域を確保
  b->data = x; //データを代入
  b->next = a; //前と繋げる
  a = b; //スタックのポインタを新たにできたcellに持ってくる
}
int pop(){ //pop
  int data; //popでの返り値用
  if(empty()){ //空なら0
    data = 0;
  }else{ //dataに一番後にpushした値を代入し、ポインタを前に移動させ、メモリを解放する
    data = a->data;
    struct cell *c = a;
    a = a->next;
    free(c);
  }
  return data; //dataの値を返す
}
int empty(){ //空の判定
  return a==NULL;
}
void show(){ //出力
  if(empty()){ //空の場合
    printf("なし\n");
  }else{ //空ではない場合
    while(a != NULL){
      printf("%d", a->data);
      a = a->next;
    }
    printf("\n");
  }
}
int main(void){
  char k[10]; //文字列を入れる
  int a=0, b, c[10], i, j; //カウント用、for文用
  scanf("%s", k); //文字列の読取
  for(i=0; i<10; i++){
    if(k[i] == '['){ //[のときはpushする
      push(k[i]);
      a = a + 1;
      b = a;
      printf("%c%d", k[i], a); //出力
    }else{
      if(empty()){ //空で繰返し終わり
	break;
      }else{ //]のときはpopする
	pop();
	for(j=0; j<10; j++){
	  if(b == c[j]){
	    b = b - 1;
	  }
	}
	printf("%c%d", k[i], b); //出力
	c[i] = b;
	b = b - 1;
      }
    }
  }
  printf("\n");
  return(0);
}
