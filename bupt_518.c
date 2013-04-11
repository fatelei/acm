#include <stdio.h>

int main() {
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF) {
        if (n >= k) {
            if ((n*2)%k == 0) {
                printf("%d\n", (n*2)/k);
            } else {
                printf("%d\n", (n*2)/k+1);
            }
        } else {
            printf("2\n");
        }
    }
    return 0;
}
