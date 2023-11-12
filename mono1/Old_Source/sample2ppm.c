#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>
#include "pnmimg.h"

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
  char *name_img = "sample.ppm" ;   /* 入力画像ファイル名 */
  char *name_out = "output2.ppm" ;  /* 出力画像ファイル名 */
  RGB_PACKED_IMAGE *image ; /* カラー画像用構造体 */


/* コマンドラインでファイル名が与えられた場合の処理 */
  if ( argc >= 2 ) name_img = argv[1] ;
  if ( argc >= 3 ) name_out = argv[2] ;

/* 入力画像ファイルのオープンと画像データ獲得 */
  if (!( image = readRGBPackedImage( name_img ))) {
    printError( name_img ) ;
    return(1) ;
  }



/** ここに画像の処理を書き込む **/




/* 出力画像ファイルのオープンと画像データの書込み */
  if ( writeRGBPackedImage( image, name_out ) == HAS_ERROR ) {
    printError( name_out ) ;
    return(1) ;
  }

  return(0) ;
}
