#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>
#include "pnmimg.h"

#include <math.h>


#ifdef __STDC__
int
main( int argc, char *argv[] )
#else
int
main( argc, argv )
     int argc ;
     char *argv[] ;
#endif
{
  char *name_out = "output1.ppm" ;  /* 出力画像ファイル名 */
  RGB_PACKED_IMAGE *image ; /* カラー画像用構造体 */
  int cols;  /* 画像の横幅 */
  int rows;  /* 画像の縦幅 */
  int x, y;


/** コマンドラインでファイル名が与えられた場合の処理 **/
  if ( argc >= 2 ) name_out = argv[1] ;

/** 画像作成 **/
/* 1. 画像領域確保 */
  cols = 320;  rows = 240;  /* 作成する画像の大きさを指定 */
  image = allocRGBPackedImage(cols, rows);  /* 空画像を作成 */

/* 2. 大きさ200x200の矩形を描画 */
  for(y=0; y<200; y++){
    for(x=0; x<200; x++){
      image->p[y][x].r = 
	255*sqrt(x*x+y*y)/sqrt(200*200+200*200);  /* 画素値をセット */
      image->p[y][x].b = 255;  /* 画素値をセット */
    }
  }


/** 出力画像ファイルのオープンと画像データの書込み **/
  if ( writeRGBPackedImage( image, name_out ) == HAS_ERROR ) {
    printError( name_out ) ;
    return(1) ;
  }

  return(0) ;
}

