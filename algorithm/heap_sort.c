#include <stdio.h>

void swap(int a[], int i, int j) {
    int tmp;

    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void adjust_heap(int a[], int index, int size) {
    int lchild = index * 2;
    int rchild = index * 2 + 1;
    int max = index;

    if (index <= size/2) {
        if (lchild <= size && a[lchild] > a[max]) {
            max = lchild;
        }

        if (rchild <= size && a[rchild] > a[max]) {
            max = rchild;
        }

        if (max != index) {
            swap(a, index, max);

            adjust_heap(a, max, size);
        }
    }
}

void build_heap(int a[], int size) {
    int i;
    for (i = size/2; i >= 1; i--) {
        adjust_heap(a, i, size);
    }
}

void heap_sort(int a[], int size) {
    int i;
    build_heap(a, size);

    for (i = size; i >= 1; i--) {
        swap(a, 1, i);
        adjust_heap(a, 1, i -1);
    }
}

int main() {
    int a[10];
    int i;

    for (i = 1; i <= 6; i++) {
        scanf("%d", &a[i]);
    }

    heap_sort(a, 6);

    for (i = 1; i <= 6; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}

