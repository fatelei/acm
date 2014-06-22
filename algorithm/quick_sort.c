#include <stdio.h>

void quick_sort(int a[], int l, int r) {
    int i, j, x;
    if (l < r) {
        i = l;
        j = r;
        x = a[l];

        while (i < j) {
            while (i < j && a[j] > x) {
                j--;
            }

            if (i < j) {
                a[i] = a[j];
                i++;
            }

            while (i < j && a[i] < x) {
                i++;
            }

            if (i < j) {
                a[j] = a[i];
                j--;
            }
        }
        a[i] = x;
        quick_sort(a, l, i - 1);
        quick_sort(a, i + 1, r);
    }
}

int main() {
    int array[10];
    int i;
    for (i = 0; i < 10; i++) {
        scanf("%d", &array[i]);
    }
    quick_sort(array, 0, 9);

    for (i = 0; i < 9; i++) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[9]);
    return 0;
}