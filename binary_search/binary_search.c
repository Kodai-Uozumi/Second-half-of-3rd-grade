#include <assert.h>
#include <stdio.h>

/**
 * @brief ソート済みのint配列の二分探索を行う
 * @param v[] ソート済みの配列（昇順）
 * @param len 配列の長さ
 * @param K 検索対象の整数
 * @return 検索対象が見つかればその値が格納された配列の添字を返す
 *         検索対象が見つからなければ-1を返す
 */
int binary_search(const int v[], int len, int K){
    int low = 0;
    int high = len - 1;
    int mid = low;
    while (low <= high) { //v[]の要素が1つの場合にwhile文が実行されるようにした
        mid = low + (high - low) / 2;
        if (v[mid] > K) {
            if(low == high){ //low,mid,highが全て同じ値でここに行きついた場合-1を返す
                break;
            }
            high = mid;
        } else if (v[mid] < K) {
            if(low == high){ //low,mid,highが全て同じ値でここに行きついた場合-1を返す
                break;
            }else if(low + 1 == high){ //lowとhighが隣り合って位置する場合、v[high]がKと等しいか等しくないかで返す値が決まる
                if(v[high] == K){
                    return high;
                }else{
                    break;
                }
            }
            low = mid;
        } else {
            return mid;
        }
    }
    return -1;
}

int main(int argc, char *argv[])
{
    {   // No.0
        int v[] = { 1 };
        int K = 1;
        int len = 0;
        int i = binary_search(v, len, K);
        if (i != -1) {
            printf("No.0 failed\n");
        }
    }

    {   // No.1
        int v[] = { 1 };
        int K = 1;
        int len = sizeof(v) / sizeof(int);
        int i = binary_search(v, len, K);
        if (i != 0) {
            printf("No.1 failed\n");
        }
    }

    {   // No.2
        int v[] = { 1 };
        int K = 2;
        int len = sizeof(v) / sizeof(int);
        int i = binary_search(v, len, K);
        if (i != -1) {
            printf("No.2 failed\n");
        }
    }

    {   // No.3
        int v[] = { 1 };
        int K = 0;
        int len = sizeof(v) / sizeof(int);
        int i = binary_search(v, len, K);
        if (i != -1) {
            printf("No.3 failed\n");
        }
    }

    {   // No.4
        int v[] = { 0, 2 };
        int K = -1;
        int len = sizeof(v) / sizeof(int);
        int i = binary_search(v, len, K);
        if (i != -1) {
            printf("No.4 failed\n");
        }
    }

    {   // No.5
        int v[] = { 0, 2 };
        int K = 0;
        int len = sizeof(v) / sizeof(int);
        int i = binary_search(v, len, K);
        if (i != 0) {
            printf("No.5 failed\n");
        }
    }

    {   // No.6
        int v[] = { 0, 2 };
        int K = 1;
        int len = sizeof(v) / sizeof(int);
        int i = binary_search(v, len, K);
        if (i != -1) {
            printf("No.6 failed\n");
        }
    }

    {   // No.7
        int v[] = { 0, 2 };
        int K = 2;
        int len = sizeof(v) / sizeof(int);
        int i = binary_search(v, len, K);
        if (i != 1) {
            printf("No.7 failed\n");
        }
    }

    {   // No.8
        int v[] = { 0, 2 };
        int K = 3;
        int len = sizeof(v) / sizeof(int);
        int i = binary_search(v, len, K);
        if (i != -1) {
            printf("No.8 failed\n");
        }
    }


    {   // No.9
        int v[] = { 0, 0 };
        int K = 0;
        int len = sizeof(v) / sizeof(int);
        int i = binary_search(v, len, K);
        if (i != 0 && i != 1) {
            printf("No.9 failed\n");
        }
    }
    
    {   // No.10
        int v[] = { 0, 0 };
        int K = 1;
        int len = sizeof(v) / sizeof(int);
        int i = binary_search(v, len, K);
        if (i != -1) {
            printf("No.10 failed\n");
        }
    }
    
    {   // No.11
        int v[] = { 0, 0 };
        int K = -1;
        int len = sizeof(v) / sizeof(int);
        int i = binary_search(v, len, K);
        if (i != -1) {
            printf("No.11 failed\n");
        }
    }

    {   // No.12
        int v[] = { 1, 2, 4 };
        int K = 1;
        int len = sizeof(v) / sizeof(int);
        int i = binary_search(v, len, K);
        if (i != 0) {
            printf("No.12 failed\n");
        }
    }
    
    {   // No.13
        int v[] = { 1, 2, 2, 4 };
        int K = 2;
        int len = sizeof(v) / sizeof(int);
        int i = binary_search(v, len, K);
        if (i != 1 && i != 2) {
            printf("No.13 failed\n");
        }
    }
    
    {   // No.14
        int v[] = {1,2,3,5,6,7,10,11,14};
        int K = 10;
        int len = sizeof(v) / sizeof(int);
        int i = binary_search(v, len, K);
        if (i != 6) {
            printf("No.14 failed\n");
        }
    }
    
    return 0;
}
