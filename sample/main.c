
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int* calc_fibonatti_series(int length) {
    assert(length > 2);
    int* p = (int*) malloc(sizeof(int) * length);
    if (!p) return NULL;
    
    p[0] = 0; p[1] = 1;
    for (int i = 0; i < length-2; ++i) {
        p[i+2] = p[i] + p[i+1];
    }
    return p;
}

int main(int argc, char* argv[]) {
    size_t fibbonatti_len = 10;
    int* p = calc_fibonatti_series(fibbonatti_len);
    if (!p) return 1;
    for (int i = 0; i < fibbonatti_len; ++i) {
        printf("%d: %d\n", i, p[i]);
    }
    free(p);
    return 0;
}
