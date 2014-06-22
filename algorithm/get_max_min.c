/*
 * get max min in o(n)
 *
 */

#include <stdio.h>

void get_max_min(int a[], int length, int *max, int *min) {
    int i;
    int max_tmp;
    int min_tmp;

    if (length % 2 == 0) {
        if (a[0] > a[1]) {
            *max = a[0];
            *min = a[1];
        } else {
            *max = a[1];
            *min = a[0];
        }
    } else {
        *max = a[0];
        *min = a[0];
    }

    for (i = 2; i < length; i += 2) {
        if (a[i] > a[i+1]) {
            max_tmp = a[i];
            min_tmp = a[i+1];
        } else {
            max_tmp = a[i+1];
            min_tmp = a[i];
        }

        if (*max < max_tmp) {
            *max = max_tmp;
        }

        if (*min > min_tmp) {
            *min = min_tmp;
        }
    }
}

int main() {
    int datas[10] = {23,12,34,26,78,45,87,15,60,19};
    int max;
    int min;

    get_max_min(datas, 10, &max, &min);
    printf("max=%d\nmin=%d\n", max, min);
}