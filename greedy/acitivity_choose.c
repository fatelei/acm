/*
 * input
 * 11
 * 1 4
 * 3 5
 * 0 6
 * 5 7
 * 3 9
 * 5 9
 * 6 10
 * 8 11
 * 8 12
 * 2 14
 * 12 16
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct activity ACTIVITY;

struct activity {
	int s;
	int f;
};

ACTIVITY ary[1000];
int rst[100];
int cursor;

int cmp(const void *a, const void *b) {
	ACTIVITY *p = (ACTIVITY *)a;
	ACTIVITY *q = (ACTIVITY *)b;

	if (p->f < q->f) {
		return -1;
	}

	if (p->f > q->f) {
		return 1;
	}

	return 0;
}

void activity_selector(int cur, int n) {
	int m = cur + 1;

	while (m <= n && ary[m].s < ary[cur].f) {
		m = m + 1;
	}

	if (m <= n) {
		rst[cursor++] = m;
		activity_selector(m, n);
	}
	return;
}

int main() {
	int n;
	int i;
	cursor = 0;
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		scanf("%d %d", &ary[i].s, &ary[i].f);
	}

	qsort(ary, n, sizeof(ACTIVITY), cmp);
	rst[cursor++] = 1;
	activity_selector(1, n);
	for (i = 0; i < cursor-1; i++) {
		printf("%d ", rst[i]);
	}

	printf("%d\n", rst[i]);
	return 0;
}
