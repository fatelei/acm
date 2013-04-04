#include <stdio.h>
#include <math.h>

int main() {
    int a, b;
    int min;
    int i;
    int mid;
    int count;
    while (scanf("%d %d", &a, &b) != EOF) {
        count = 0;
        min = a < b ? a : b;
        mid = (int)sqrt(min);
        for (i = 1; i <= mid; i++) {
            if ((a%i == 0) && (b%i == 0)) {
                count += 1;
                if (a < b) {
                    if (b%(a/i) == 0 && a/i != i) {
                        count += 1;
                    }
                } else {
                    if (a%(b/i) == 0 && b/i != i) {
                        count += 1;
                    }
                }
            } else {
                if (a > b) {
                    if (b%i == 0 && (a%(b/i) == 0)) {
                        count += 1;
                    }
                } else {
                    if (a%i == 0 && (b%(a/i) == 0)) {
                        count += 1;
                    }
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
