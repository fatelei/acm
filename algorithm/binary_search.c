#include <stdio.h>
#include <stdlib.h>
#define SIZE 11


int cmp(const void *a, const void *b) {
    int *p = (int *)a;
    int *q = (int *)b;

    if (*p > *q) {
        return 1;
    } else {
        return -1;
    }
}

int binary_search(int a[], int target, int l, int r) {
    int low = l;
    int high = r - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (a[mid] > target) {
            high = mid - 1;
        } else if (a[mid] < target) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    int a[SIZE] = {2,343,342,1,123,43,4343,433,687,654,3};
    qsort(a, SIZE, sizeof(a[0]), cmp);
    int rst = binary_search(a, 2, 0, SIZE);
    printf("%d\n", rst);
}