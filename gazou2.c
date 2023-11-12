#include <stdio.h>
#include <stdlib.h>
#include <png.h>
#include "imageProc.c"
int main( int argc, char **argv )
{
  Image img1, img2, img3, img4, img5, img6, img7, img8;
 Size s;
 int a;
 readPNG( &img1, "Cat-noise.png" );
 s.x = img1.s.x;
 s.y = img1.s.y;
 
 imageAlloc( s, &img2 );
 median( &img1, 3, &img2 );
 writePNG(&img2, "cat-bin1.png");
 imageAlloc( s, &img3 );
 binalization( &img2, 128, &img3 );
 imageAlloc(s, &img4);
 multi(&img3, 255.0, &img4);
 writePNG(&img4, "cat-bin2.png");
 imageAlloc(s, &img5);
 labeling(&img3, &img5, &a);
 imageAlloc(s, &img6);
 smallComponentElimination(&img5, 128, &img6);
 writePNG(&img6, "cat-bin3.png");
 imageAlloc(s, &img7);
 binalization(&img6, 1, &img7);
 imageAlloc( s, &img8 );
 multi( &img7, 255.0, &img8 );
 writePNG( &img8, "cat-bin.png");
 return(0);
}
