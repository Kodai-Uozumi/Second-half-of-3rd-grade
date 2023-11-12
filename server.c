/*** server.c ***/
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#define PORT 8888 /* ポート番号 */
int main(int argc, char* argv[]){
  struct sockaddr_in server; /*サーバの情報を格納する構造体*/
  struct sockaddr_in client; /*クライアントの情報を格納する構造体*/
  int s_wait; /* クライアントからの接続要求を待つためのソケット */
  int s; /* クライアントと通信するためのソケット */
  unsigned char* client_addr; int client_len; char buf[128];
/* (1)ソケット生成 */
  s_wait = socket(AF_INET, SOCK_STREAM, 0);
/* (2)アドレス割当て */
  bzero((char *)&server, sizeof(server)); /* 初期化 */
  server.sin_addr.s_addr = htonl(INADDR_ANY); /*クライアント*/
  server.sin_family = AF_INET; /* ドメイン */
  server.sin_port = PORT; /* ポート番号 */
  bind(s_wait, (struct sockaddr*)&server, sizeof(server));
/* (3)ソケットをサーバに設定 */
  listen(s_wait, 5);
/* (4)コネクション確立待ち */
  client_len = sizeof(client);
  s = accept(s_wait, (struct sockaddr*)&client, &client_len);
  close(s_wait); /* 接続要求待ちソケットは不要なので閉じる */
  client_addr = (unsigned char*)&(client.sin_addr.s_addr);
  printf("connected to %d.%d.%d.%d.\n",client_addr[0],
	 client_addr[1],client_addr[2],client_addr[3]);
/* (5)データ送信 */
  sprintf(buf,"Hello, %d.%d.%d.%d!\n",client_addr[0],
	  client_addr[1],client_addr[2],client_addr[3]);
  write(s, buf, strlen(buf));
/* (6)ソケット解放 */
  close(s);
}
