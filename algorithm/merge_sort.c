#include <stdio.h>

void merage_array(int a[], int first, int mid, int last, int temp[]) {
    int i = first;
    int j = mid + 1;
    int m = mid;
    int n = last;
    int k = 0;

    while (i <= m && j <= n) {
        if (a[i] < a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    while (i <= m) {
        temp[k++] = a[i++];
    }

    while (j <= n) {
        temp[k++] = a[j++];
    }

    for (i = 0; i < k; i++) {
        a[first + i] = temp[i];
    }
}

void merge_sort(int a[], int first, int last, int temp[]) {
    if (first < last) {
        int mid = (first + last) / 2;
        merge_sort(a, first, mid, temp);
        merge_sort(a, mid + 1, last, temp);
        merage_array(a, first, mid, last, temp);
    }
}

int main() {
    int ary[10] = {5, 8, 3, 1, 14, 13, 12, 11, 9, 2};
    int temp[10];
    int i;

    merge_sort(ary, 0, 9, temp);

    for (i = 0; i < 9; i++) {
        printf("%d ", ary[i]);
    }
    printf("%d\n", ary[9]);
    return 0;
}