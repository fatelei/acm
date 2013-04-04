#include <stdio.h>
#include <string.h>
#define MIN 0x7fffff

int ary[200][200];

int calc_min_matrix(int row, int col, int n) {
    int sum = 0;
    int i, j;
    for (i = row; i < row + n; i++) {
        for (j = col; j < col + n; j++) {
            sum += ary[i][j];
        }
    }
    return sum;
}

int main() {
    int m, n;
    int i, j;
    int min;
    int part;
    int rst;
    while (scanf("%d %d", &m, &n) != EOF) {
        memset(ary, 0, sizeof(ary));
        min = 0x7fffff;
        for (i = 0; i < m; i++) {
            for (j = 0; j < m; j++) {
                scanf("%d", &ary[i][j]);
                if (min > ary[i][j]) {
                    min = ary[i][j];
                }            
            }
        }
        if (n == 1) {
            printf("%d\n", min);
        } else {
            min = 0x7fffff;
            part = m - n + 1;
            for (i = 0; i < part; i++) {
                for (j = 0; j < part; j++) {
                    rst = calc_min_matrix(i, j, n);
                    if (rst < min) {
                        min = rst;
                    }
                }               
            }
            printf("%d\n", min);
        }
    }
    return 0;
}
