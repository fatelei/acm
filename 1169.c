#include <stdio.h>

int main() {
	int oddc;
	int evenc;
	int n;
	int i;
	int tmp;
	while (scanf("%d", &n) != EOF) {
		evenc = oddc = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &tmp);
			if (tmp%2 == 0) {
				evenc++;
			} else {
				oddc++;
			}
		}
		if (evenc > oddc) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}
	return 0;
}
