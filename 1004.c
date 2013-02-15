#include <stdio.h>

int a[3000001];
int b[1000001];
int c[1000001];

int main() {
	int i, j, k;
	int n, m;
	while (scanf("%d", &n) != EOF) {
		k = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &b[i]);
		}
		scanf("%d", &m);
		for (i = 0; i < m; i++) {
			scanf("%d", &c[i]);
		}
		for (i = 0, j = 0; i < n && j < m;) {
			if (b[i] < c[j]) {
				a[k] = b[i];
				i++;
			} else {
				a[k] = c[j]; 
				j++;
			}
			k++;
		}
		if (i < n) {
			while (i < n) {
				a[k++] = b[i++];
			}
		} else if (j < m) {
			while (j < m) {
				a[k++] = c[j++];
			}
		}
		printf("%d\n", a[(m+n-1)/2]);
	}
	return 0;
}
