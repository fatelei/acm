#include <stdio.h>
#include <math.h>
#include <string.h>
#define SIZE 11

int find_max(int a[], int size) {
    int max = -1;
    int i = 0;

    for (i = 0; i < size; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }
    return max;
}

int get_loop_times(int target) {
    int count = 0;

    while (1) {
        target = target / 10;
        count += 1;
        if (target == 0) {
            break;
        }
    }
    return count;
}

void insert_bucket(int a[], int base, int size) {
    int temp[10][20];
    int flag[10][20];
    int i, j, k;
    int dividend = (int)pow(10, base - 1);
    int index;

    memset(flag, 0, sizeof(flag));

    for (i = 0; i < size; i++) {
        index = (a[i] / dividend) % 10;
        for (j = 0; j < 20; j++) {
            if (flag[index][j] == 0) {
                temp[index][j] = a[i];
                flag[index][j]= 1;
                break;
            }
        }
    }

    k = 0;
    for (i = 0; i < size; i++) {
        for (j = 0; j < 20; j++) {
            if (flag[i][j]) {
                a[k++] = temp[i][j];
            }
        }
    }
}

void bucket_sort(int a[], int size) {
    int max = find_max(a, size);
    int loop_times = get_loop_times(max);
    int i;

    for (i = 1; i <= loop_times; i++) {
        insert_bucket(a, i, size);
    }
}

int main() {
    int a[SIZE] = {2,343,342,1,123,43,4343,433,687,654,3};
    int i;

    bucket_sort(a, SIZE);

    for (i = 0; i < SIZE; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}