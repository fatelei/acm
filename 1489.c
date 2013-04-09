#include <stdio.h>

int a[2][3];
int b[3][2];
int c[2][2];

int main() {
    int i, j, k;
    int tmp = 0;
    while (scanf("%d %d %d", &a[0][0], &a[0][1], &a[0][2]) != EOF) {
        for (i = 1; i < 2; i++) {
            for (j = 0; j < 3; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 2; j++) {
                scanf("%d", &b[i][j]);
            }
        }
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 3; j++) {
                tmp = 0;
                for (k = 0; k < 3; k++) {
                    tmp += a[i][k] * b[k][j];
                }
                c[i][j] = tmp;
            }
        }
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
