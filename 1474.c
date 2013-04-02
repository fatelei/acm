#include <stdio.h>
#include <string.h>

unsigned int ary[20][20];

void calc_power(int n, int k) {
    unsigned int rst[20][20];
    unsigned int last[20][20];
    int i, j, p, q;
    int tmp = 0;
    memset(rst, 0, sizeof(rst));
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            rst[i][j] = ary[i][j];
        }
    }
    for (i = 1; i < k; i++) {
       for (j = 0; j < n; j++) {
            for (p = 0; p < n; p++) {
                tmp = 0;
                for (q = 0; q < n; q++) {
                    tmp += rst[j][q]*ary[q][p];
                }
                //printf("<%d, %d>: %d\n", j, p, tmp);
                last[j][p] = tmp;
            }
       }
       for (j = 0; j < n; j++) {
            for (p = 0; p < n; p++) {
                rst[j][p] = last[j][p];
            }
       }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            printf("%d ", rst[i][j]);
        }
        printf("%d\n", rst[i][n-1]);
    }
}

int main() {
    int t;
    int n, k;
    int i, j;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                scanf("%d", &ary[i][j]);
            }
        }
        calc_power(n, k);
    }
    return 0;
}
