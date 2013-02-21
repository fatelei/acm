#include <stdio.h>
#include <stdlib.h>

int ary[1010];

int cmp(const void *a, const void *b) {
	int *c = (int *)a;
	int *d = (int *)b;
	if (*c < *d) {
		return -1;
	} else if (*c > *d) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	int n, k;
	int i;
	int count;
	int tmp;
	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++) {
			scanf("%d", &ary[i]);
		}
		scanf("%d", &k);
		qsort(ary, n, sizeof(int), cmp);
		if (k == 1) {
			printf("%d\n", ary[0]);
		} else {
			tmp = ary[0];
			count = 1;
			for (i = 1; i < n; i++) {
				if (tmp == ary[i]) {
					continue;
				} else {
					tmp = ary[i];
					count++;
					if (count == k) {
						printf("%d\n", ary[i]);
					}
				}
			}
		}
	}
	return 0;
}
