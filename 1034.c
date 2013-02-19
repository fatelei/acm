#include <stdio.h>
#include <stdlib.h>

int ary[100010];

int cmp(const void *a, const void *b) {
	int *p = (int *)a;
	int *q = (int *)b;
	return *q - *p;
}

int main() {
	int i;
	int n, m;
	while (1) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) {
			break;
		} else {
			for (i = 0; i < n; i++) {
				scanf("%d", &ary[i]);
			}
			qsort(ary, n, sizeof(int), cmp);
			if (m == 1) {
				printf("%d\n", ary[0]);
			} else if (n <= m) {
				for (i = 0; i < n - 1; i++) {
					printf("%d ", ary[i]);
				}
				printf("%d\n", ary[n-1]);
			} else {
				for (i = 0; i < m - 1; i++) {
					printf("%d ", ary[i]);
				}
				printf("%d\n", ary[m-1]);
			}
		}
	}
	return 0;
}
