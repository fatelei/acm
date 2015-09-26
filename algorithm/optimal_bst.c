#include <stdio.h>
#include <string.h>
#define MAXVAL 99999999.0

int N = 5;

double e[6][6];
double w[6][6];
int root[6][6];

double p[7] = {0, 0.15, 0.1, 0.05, 0.1, 0.2};
double q[7] = {0.05, 0.1, 0.05, 0.05, 0.05, 0.1};

void optimal_bst() {
    int i;
    int l;
    int j;
    int r;
    double tmp;

    for (i = 1; i <= N+1; i++) {
        e[i][i-1] = q[i-1];
        w[i][i-1] = q[i-1];
    }

    for (l = 1; l <= N; l++) {
        for (i = 1; i <= N - l + 1; i++) {
            j = i + l - 1;
            e[i][j] = MAXVAL;
            w[i][j] = w[i][j-1] + p[j] + q[j];
            for (r = i; r <= j; r++) {
                tmp = e[i][r-1] + e[r+1][j] + w[i][j];
                if (tmp < e[i][j]) {
                    e[i][j] = tmp;
                    root[i][j] = r;
                }
            } 
        }
    }
}


void print_bst(int i, int j, int parent) {
    int tmp;

    tmp = root[i][j];

    if (tmp == root[1][N]) {
        printf("Parent is %d\n", tmp);
        print_bst(i, tmp - 1, tmp);
        print_bst(tmp + 1, j, tmp);
        return;
    }

    if (j < i - 1) {
        return;
    }

    if (j == i - 1) {
        if (j < parent) {
            printf("d %d is left child of %d\n", j, parent);
        } else {
            printf("d %d is right child of %d\n", j, parent);
        }
    } else {
        if (j < parent) {
            printf("k %d is left child of %d\n", j, parent);
        } else {
            printf("k %d is right child of %d\n", j, parent);
        }
        print_bst(i, tmp - 1, tmp);
        print_bst(tmp + 1, j, tmp);
    }
}


int main() {
    memset(root, -1, sizeof(root));
    optimal_bst();
    print_bst(1, N, -1);
} 