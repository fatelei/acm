#include <stdio.h>
#define MAX_DIS 0x7fffff
int map[100][100];
int visit[100];

int prim(int dis[], int root, int n) {
	int i, j;
	int min;
	int next;
	int sum = 0;

	// init distance
	for (i = 0; i < n; i++) {
		if (i != root) {
			dis[i] = map[root][i];
		}
	}

	visit[root] = 1;

	for (i = 1; i < n; i++) {
		min = MAX_DIS;

		for (j = 0; j < n; j++) {
			if (!visit[j] && dis[j] < min) {
				min = dis[j];
				next = j;
			}
		}

		visit[next] = 1;
		sum += min;

		// relax
		for (j = 0; j < n; j++) {
			if (!visit[j] && dis[j] > map[next][j]) {
				dis[j] = map[next][j];
			}
		}
	}
	return sum;
}

int main() {
	int i, j, n;
	int distance[100];
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	printf("%d\n", prim(distance, 0, n));
	return 0;
}
