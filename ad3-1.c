#include <stdio.h> // printf, rand 用
#include <stdlib.h> // malloc, free, exit 用
#include <string.h> // memcpy 用
#include <time.h> // clock 用
#define INIARRAYSIZE 1 // or 1000001 // (a) 配列の初期サイズ
int* pA; // 配列へのポインタ（各要素は pA[i] で参照できる）
int sA; // 配列の現在サイズ
int size; // 記憶中のデータ個数（データは pA[1],...,pA[size] に記憶）
void create(), insert(), show(), swap();
int deletemin(), empty(), min();
void create() {
  sA = INIARRAYSIZE; // 配列の現在サイズを初期化
  if ((pA = (int *) malloc(sizeof(int) * sA)) == NULL) exit(1);
  size = 0; // 記憶中のデータ個数を初期化
}
void insert(int x) {
  if (size == sA - 1) { // 配列が満杯ならば配列サイズを拡大しておく
    int* oldpA = pA; // 現在使用中の配列のアドレスを一時退避
    sA = sA * 2; // or sA = sA + 200; // (b) サイズの拡大量
    if ((pA = (int *) malloc(sizeof(int) * sA)) == NULL) exit(1);
    memcpy(pA, oldpA, sizeof(int) * (size + 1)); // 新配列へ旧配列の内容をコピー
    // or ; // (c) メモリーの解放
  };
  size++; // 記憶中のデータ個数の増加
  int i = size; // iに記憶中のデータ個数を代入
  pA[i] = x; // 要素を挿入
  while(i > 1 && pA[i] < pA[i / 2]){
    swap(i, i / 2); // 子<親の場合は親と子を入れ替える
    i /= 2; // iの値を子がいる場所にする
  }
}
void show(){
  int i;
  for(i = 1; i <= size; i++){
    printf("%d " , pA[i]); // 現在のヒープ内容全体を表示
  }
  printf("\n"); // 改行
}
void swap(int u, int v){ // 値入れ換え用
  int temp; // tempに一時的に片方の値を記憶しておく
  temp =  pA[u]; // 入れ換え作業
  pA[u] = pA[v];
  pA[v] = temp;
}
int deletemin(){
  int i = 1, k, m;
  if(empty()) exit(1); // ヒープが空なら終了
  m = min(); // これから削除する最小値を記憶する
  pA[1] = pA[size]; // 最小値を削除
  size--; // 記憶中のデータ個数の減少
  while(2 * i <= size){ // 親>子の間、親と子の値を入れ換える
    k = 2 * i; // kは左の子の番号
    if(k < size && pA[k] > pA[k + 1]) k++; // 左の子より右の子の方が小さい場合はkを右の子の番号にする
    if(pA[i] <= pA[k]) break; // 親<子または親=子のときは繰返しを終了
    swap(i, k); // 親と子を入れ換える
    i = k; // kの値を親の番号であるiに代入して次のループへ
  }
  return m; // 削除した最小値を返す
}
int empty(){
  return size == 0; // ヒープが空かどうかを判定し真偽値を返す
}
int min(){
  return pA[1]; // 最小値を返す
}
int main(void){ // 適当なデータをN=1000000回挿入した後N回削除する
  int i;
  double a;
  create(); // 空のヒープを生成
  for(i = 0; i < 1000000; i++){ // 適当なデータを1000000回挿入
    insert(rand());
  }
  for(i = 0; i < 1000000; i++){ // 適当なデータを1000000回削除
    deletemin();
  }
  a = (double)clock() / CLOCKS_PER_SEC; // プログラムの実行時間を秒に直す
  printf("%f\n", a); // プログラムの実行時間を表示
  return(0);
}
