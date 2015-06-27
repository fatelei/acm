#include <stdio.h>
#include <string.h>
#define RADIX 10

int get_cur_digit(int num, int base) {
	return (num / base) % 10;
}

int get_base(int count) {
	int i;
	int base = 1;

	for (i = 1; i < count; i++) {
		base = RADIX * base;
	}
	return base;
}

int get_d(int ary[], int length) {
	int i = 0;
	int max = ary[0];
	for (i = 1; i < length; i++) {
		if (max < ary[i]) {
			max = ary[i];
		}
	}

	int d = 0;
	while (max) {
		d += 1;
		max /= 10;
	}
	return d;
}

void radix_sort(int ary[], int length, int d) {
	int bucket[10];
	int i, j;
	int count[10];
	int tmp;
	int radix[10];
	int base;

	for (i = 1; i <= d; i++) {
		memset(count, 0, sizeof(count));
		memset(radix, -1, sizeof(radix));

		base = get_base(i);

		for (j = 0; j < length; j++) {
			tmp = get_cur_digit(ary[j], base);
			count[tmp]++;
			radix[j] = tmp;
		}

		// cal index.
		for (j = 1; j < length; j++) {
			count[j] = count[j] + count[j - 1];
		}

		// put into bucket.
		for (j = length - 1; j >=0; j--) {
			tmp = radix[j];
			bucket[count[tmp] - 1] = ary[j];
			--count[tmp];
		}

		// copy back.
		for (j = 0; j < length; j++) {
			ary[j] = bucket[j];
		}
	}
}

int main() {
	int i;
	int ary[10] = { 20, 80, 90, 589, 998, 965, 852, 123, 456, 789 };

	int d = get_d(ary, 10);
	radix_sort(ary, 10, d);

	for (i = 0; i < 10; i++) {
		printf("%d\n", ary[i]);
	}
	return 0;
}
