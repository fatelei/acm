#include <stdio.h>
#include <string.h>

int a[20][20];
int b[20][20];
int c[20][20];


int main() {
	int m, n;
	int i, j;
	int count;
	while (1) {
		scanf("%d", &m);
		if (m == 0) {
			break;
		} else {
			scanf("%d", &n);
			memset(c, 0, sizeof(c));
			count = 0;
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					scanf("%d", &a[i][j]);
				}
			}
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					scanf("%d", &b[i][j]);
				}
			}
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					c[i][j] = a[i][j] + b[i][j];
				}
			}
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					if (c[i][j] != 0) {
						break;
					} else if (j == n - 1) {
						count++;
					}
				}
			}
			for (j = 0; j < n; j++) {
				for (i = 0; i < m; i++) {
					if (c[i][j] != 0) {
						break;
					} else if (i == m - 1) {
						count++;
					}
				}
			}
			printf("%d\n", count);
		}    
	}        
	return 0 ;
}           
