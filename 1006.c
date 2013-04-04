#include <stdio.h>
#include <string.h>

char str[1010];

int main() {
	char tmp;
	int i, j;
	int length = 0;
	int left = 0;
	int right = 0;
	int mid = 0;
	int cur = 0;
	while (scanf("%s", str) != EOF) {
		getchar();
		length = strlen(str);
		left = right = mid = 0;
		for (i = 0; i < length; i++) {
			if (str[i] == 'z') {
				break;
			} else {
				left++;
			}
		}
		cur = i + 1;
		for (i = cur; i < length; i++) {
			if (str[i] == 'j') {
				break;
			} else {
				mid++;
			}
		}
		cur = i + 1;
		for (i = cur; i < length; i++) {
			right++;
		}
		if ((left * mid) == right) {
			printf("Accepted\n");
		} else {
			printf("Wrong Answer\n");
		}
	}
	return 0;
}
