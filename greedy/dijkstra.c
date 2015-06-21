#include <stdio.h>
#include <string.h>
#define MAX_DIS 0x7fffff

int n; // 顶点数
int e; // 边数
int matrix[1000][1000]; // 图
int visit[1000];

void dijkstra(int dis[], int path[], int source) {
	int i, j;

	// init
	for (i = 0; i < n; i++) {
		if (matrix[source][i] != -1 && i != source) {
			dis[i] = matrix[source][i];
			path[i] = source;
		}
		else {
			dis[i] = MAX_DIS;
			path[i] = -1;
		}
	}
	visit[source] = 1;
	path[source] = source;
	dis[source] = 0;

	for (i = 1; i < n; i++) {
		int min = MAX_DIS;
		int next;

		// find min
		for (j = 0; j < n; j++) {
			if (!visit[j] && dis[j] < min) {
				min = dis[j];
				next = j;
			}
		}

		// mark next is visited.
		visit[next] = 1;

		// relax;
		for (j = 0; j < n; j++) {
			if (!visit[j] && matrix[next][j] != -1) {
				if ((min + matrix[next][j]) < dis[j]) {
					dis[j] = min + matrix[next][j];
					path[j] = next;
				}
			}
		}
	}
}

int main() {
	int i, j, k;
	int distance;
	int source;
	int dis[1000];
	int path[1000];

	memset(matrix, -1, sizeof(matrix));
	scanf("%d %d", &n, &e);

	for (i = 0; i < e; i++) {
		scanf("%d %d %d", &j, &k, &distance);
		matrix[j][k] = distance;
	}

	scanf("%d", &source);
	dijkstra(dis, path, source);


	for (i = 1; i < n; i++) {
		printf("%d - %d: %d\n", source, i, dis[i]);
	}
	return 0;
}
