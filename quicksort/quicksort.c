#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/**
 *  @brief   配列の要素v[i]とv[j]の値を入れ替える
 *  @param   v   配列
 *  @param   i, j: 値を入れ替える配列のインデックス
 */
void swap(int v[], int i, int j) {
    int c = v[i];
    v[i] = v[j];
    v[j] = c;
}

/**
 *  @brief   配列を小さい順にソートする v[0] <= v[1] <= ... <= v[len-1]
 *  @param   v   配列
 *  @param   len: 配列長
 *  @note    配列長が0のときは何もしない
 */
void quicksort(int v[], int len) {
    if (len <= 1)
        return;

    int p = rand() % len;
    swap(v, 0, p);

    int last = 0;
    for (int i = 1; i < len; ++i) {
        if (v[i] < v[0]) {
            swap(v, ++last, i); //後置インクリメントを前置インクリメントにした
        }
    }
    swap(v, 0, last);
    quicksort(v, last); //配列長をlast - 1からlastにした
    quicksort(v + last + 1, len - last - 1);
}

void verify_sorted(const int v[], int len, const char* message) {
    for (int i = 0; i < len - 1; ++i) {
        if (v[i] > v[i + 1]) {
            printf("%s\n", message);
            break;
        }
    }
}

int main(int argc, char* argv[])
{
    {
        int v[] = { 1 };
        int len = 0;
        quicksort(v, len);
        verify_sorted(v, len, "No.1 failed");
    }

    {
        int v[] = { 1 };
        int len = sizeof(v) / sizeof(int);
        quicksort(v, len);
        verify_sorted(v, len, "No.2 failed");
    }

    {
        int v[] = { 2, 1 };
        int len = sizeof(v) / sizeof(int);
        quicksort(v, len);
        verify_sorted(v, len, "No.3 failed");
    }

    {
        int v[] = { 1, 2 };
        int len = sizeof(v) / sizeof(int);
        quicksort(v, len);
        verify_sorted(v, len, "No.4 failed");
    }

    {
        int v[] = { 1, 1 };
        int len = sizeof(v) / sizeof(int);
        quicksort(v, len);
        verify_sorted(v, len, "No.5 failed");
    }

    {
        int v[] = { 5, 4, 3, 2, 1 };
        int len = sizeof(v) / sizeof(int);
        quicksort(v, len);
        verify_sorted(v, len, "No.6 failed");
    }

    {
        int v[] = {10, 5, 4, 2, 2, 3, 1 };
        int len = sizeof(v) / sizeof(int);
        quicksort(v, len);
        verify_sorted(v, len, "No.7 failed");
    }

    return 0;
}

