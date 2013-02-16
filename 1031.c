#include <stdio.h>

int count;
int num;

void process() {
	if (num == 1) {
		return;
	}
	if (num%2 == 0) {
		count++;
		num /= 2;
		process();
	} else {
		count++;
		num = num*3 + 1;
		num /= 2;
		process();
	}
	return;
}

int main() {
	while (1) {
		scanf("%d", &num);
		count = 0;
		if (num == 0) {
			break;
		} else {
			if (num == 1) {
				printf("0\n");
			} else {
				process();
				printf("%d\n", count);
			}
		}
	}
	return 0;
}
