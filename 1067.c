#include <stdio.h>

long long func(long long n) {
	if (n == 1) {
		return 1;
	} else {
		return n*func(n-1);
	}
}

int main() {
	long long n;
	while (scanf("%lld", &n) != EOF) {
		printf("%lld\n", func(n));
	}
	return 0;
}
