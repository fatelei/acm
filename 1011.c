#include <stdio.h>

int k;
int ary[10010];
int start;
int end;

int find_max_subseq() {
	int i;
	int curSum = 0;
	int maxSum = 0;
	int tmp = 0;
	for (i = 0; i < k; i++) {
		curSum = curSum + ary[i];
		if (curSum >= maxSum) {
			maxSum = curSum;
			end = i;
			start = tmp;
		}
		if (curSum < 0) {
			curSum = 0;
			tmp = i + 1 >= k ? i : i + 1;
		}
	}
	return maxSum;
}

int main() {
	int i;
	int max;
	while (1) {
		scanf("%d", &k);
		start = end = 0;
		if (k == 0) {
			break;
		} else {
			for (i = 0; i < k; i++) {
				scanf("%d", &ary[i]);
			}
			max = find_max_subseq();
			printf("%d %d %d\n", max, ary[start], ary[end]);
		}
	}
	return 0;
}
