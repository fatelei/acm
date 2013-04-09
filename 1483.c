#include <stdio.h>

int main() {
    int n;
    int i;
    int min;
    int max;
    int tmp;
    while (scanf("%d", &n) != EOF) {
        min = max = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &tmp);
            if (i == 0) {
                max = min = tmp;
            } else {
                if (tmp < min) {
                    min = tmp;
                }
                if (tmp > max) {
                    max = tmp;
                }
            }
        }
        printf("%d %d\n", max, min);
    }
    return 0;
}
