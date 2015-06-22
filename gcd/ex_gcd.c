#include <stdio.h>

int ex_gcd(int a, int b, int *x, int *y) {
	if (b == 0) {
		*x = 1;
		*y = 0;
		return a;
	}
	else {
		int d = ex_gcd(b, a % b, x, y);
		int tmp = *x;
		*x = *y;
		*y = tmp - (a / b) * (*y);
		return d;
	}
}

int main() {
	int a, b;
	int x, y;
	scanf("%d %d", &a, &b);

	printf("%d\n", ex_gcd(a, b, &x, &y));
	printf("%d %d", x, y);
	return 0;
}
