/*** client.c ***/
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#define PORT 8888 /* ポート番号 */
int main(int argc, char* argv[]){
  int ip[4]; /* サーバのIPアドレスを格納する配列 */
  struct sockaddr_in server;/*サーバの情報を格納する構造体*/
  int s; /* ソケットディスクリプタ */
  int len; /* サーバから受信したデータのバイト数 */
  char buf[512]; /* 〃 データを格納する配列 */
/* (1)ソケットの生成 */
  s = socket(AF_INET, SOCK_STREAM, 0);
/* (5)コネクション確立要求 */
/* 起動時にユーザが指定したサーバのIPアドレスを配列ipに格納する */
  sscanf(argv[1], "%d.%d.%d.%d",
	 &ip[0],&ip[1],&ip[2],&ip[3]);
/* サーバに関する情報をserverという構造体にセットする */
  bzero((char *)&server, sizeof(server)); /* 初期化 */
  sprintf((char*)&server.sin_addr.s_addr,
	  "%c%c%c%c", ip[0], ip[1], ip[2], ip[3]);
  server.sin_family = AF_INET; /* ドメイン */
  server.sin_port = PORT; /* ポート番号 */
  connect(s, (struct sockaddr*)&server, sizeof(server));
/* (6)データの送受信 */
  len = read(s, buf, sizeof(buf));
  write(1, buf, len);
/* (7)ソケットの解放 */
  close(s);
}
