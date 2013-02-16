#include <stdio.h>
#include <stdlib.h>

typedef struct data Data;

struct data {
	int x;
	int y;
};

Data ary[1001];

int cmp(const void *a, const void *b) {
	Data *c = (Data *)a;
	Data *d = (Data *)b;
	if (c->x != d->x) {
		return c->x - d->x;
	} else {
		return c->y - d->y;
	}
}

int main() {
	int n;
	int i;
	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++) {
			scanf("%d %d", &ary[i].x, &ary[i].y);
		}
		qsort(ary, n, sizeof(ary[0]), cmp);
		printf("%d %d\n", ary[0].x, ary[0].y);
	}
	return 0;
}
