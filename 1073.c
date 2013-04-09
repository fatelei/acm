#include <stdio.h>

int ary[1010][1010];

void build_table() {
    int i, j;
    for (i = 0; i < 1001; i++) {
        ary[i][0] = ary[i][i] = 1;
    }
    for (i = 2; i < 1001; i++) {
        for (j = 1; j < i; j++) {
            ary[i][j] = ary[i-1][j-1] + ary[i-1][j];
        }
    }
}

int main() {
    int num;
    int i, j;
    build_table();
    while (scanf("%d", &num) != EOF) {
        for (i = 1; i < num; i++) {
            for (j = 0; j <= i - 1; j++) {
                printf("%d ", ary[i][j]);
            }
            printf("%d\n", ary[i][i]);
        }
    }
    return 0;
}
