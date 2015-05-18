#include <stdio.h>

int partition(int a[], int p, int r) {
    int x = a[r];
    int i = p - 1;
    int j;
    int tmp;

    for (j = p; j <= r - 1; j++) {
        if (a[j] <= x) {
            i = i + 1;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }

    tmp = a[i+1];
    a[i+1] = a[r];
    a[r] = tmp;
    return i + 1;
}

int find_mid_num(int a[], int p, int r, int target) {
    if (p == r) {
        return a[p];
    }

    if (p < r) {
        int q = partition(a, p, r);

        if (q == target) {
            return a[q];
        } else if (q < target) {
            return find_mid_num(a, q + 1, r, target - q);
        } else {
            return find_mid_num(a, p, q - 1, target);
        }
    }
}

int main() {
    int ary[100];
    int num;
    int i;
    int target;

    scanf("%d", &num);

    for (i = 1; i <= num; i++) {
        scanf("%d", &ary[i]);
    }

    target = (num + 1) / 2;

    printf("%d\n", find_mid_num(ary, 1, num, target));

    return 0;
}