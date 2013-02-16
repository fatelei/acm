#include <stdio.h>

int ary[5][5];
int op[2];
int pos[2];

void clockwise_four() {
	int tmp;
	tmp = ary[pos[0]][pos[1] + 1];
	ary[pos[0]][pos[1] + 1] = ary[pos[0]][pos[1]];
	ary[pos[0]][pos[1]] = ary[pos[0] + 1][pos[1]];
	ary[pos[0] + 1][pos[1]] = ary[pos[0] + 1][pos[1] + 1];
	ary[pos[0] + 1][pos[1] + 1] = tmp;
}

void clockwise_nine() {
	int tmp;
	tmp = ary[pos[0]][pos[1]];
	ary[pos[0]][pos[1]] = ary[pos[0] + 1][pos[1]];
	ary[pos[0] + 1][pos[1]] = ary[pos[0] + 2][pos[1]];
	ary[pos[0] + 2][pos[1]] = ary[pos[0] + 2][pos[1] + 1];
	ary[pos[0] + 2][pos[1] + 1] = ary[pos[0] + 2][pos[1] + 2];
	ary[pos[0] + 2][pos[1] + 2] = ary[pos[0] + 1][pos[1] + 2];
	ary[pos[0] + 1][pos[1] + 2] = ary[pos[0]][pos[1] + 2];
	ary[pos[0]][pos[1] + 2] = ary[pos[0]][pos[1] + 1];
	ary[pos[0]][pos[1] + 1] = ary[pos[0]][pos[1]];
	ary[pos[0]][pos[1]] = ary[pos[0] + 1][pos[1]];
	ary[pos[0] + 1][pos[1]] = ary[pos[0] + 2][pos[1]];
	ary[pos[0] + 2][pos[1]] = ary[pos[0] + 2][pos[1] + 1];
	ary[pos[0] + 2][pos[1] + 1] = ary[pos[0] + 2][pos[1] + 2];
	ary[pos[0] + 2][pos[1] + 2] = ary[pos[0] + 1][pos[1] + 2];
	ary[pos[0] + 1][pos[1] + 2] = ary[pos[0]][pos[1] + 2];
	ary[pos[0]][pos[1] + 2] = tmp;
}

void inverse_clockwise_four() {
	int tmp;
	tmp = ary[pos[0] + 1][pos[1]];
	ary[pos[0] + 1][pos[1]] = ary[pos[0]][pos[1]];
	ary[pos[0]][pos[1]] = ary[pos[0]][pos[1] + 1];
	ary[pos[0]][pos[1] + 1] = ary[pos[0] + 1][pos[1] + 1];
	ary[pos[0] + 1][pos[1] + 1] = tmp;
}

void inverse_clockwise_nine() {
	int tmp;
	tmp = ary[pos[0]][pos[1]];
	ary[pos[0]][pos[1]] = ary[pos[0]][pos[1] + 1];
	ary[pos[0]][pos[1] + 1] = ary[pos[0]][pos[1] + 2];
	ary[pos[0]][pos[1] + 2] = ary[pos[0] + 1][pos[1] + 2];
	ary[pos[0] + 1][pos[1] + 2] = ary[pos[0] + 2][pos[1] + 2];
	ary[pos[0] + 2][pos[1] + 2] = ary[pos[0] + 2][pos[1] + 1];
	ary[pos[0] + 2][pos[1] + 1] = ary[pos[0] + 2][pos[1]];
	ary[pos[0] + 2][pos[1]] = ary[pos[0] + 1][pos[1]];
	ary[pos[0] + 1][pos[1]] = ary[pos[0]][pos[1]];
	ary[pos[0]][pos[1]] = ary[pos[0]][pos[1] + 1];
	ary[pos[0]][pos[1] + 1] = ary[pos[0]][pos[1] + 2];
	ary[pos[0]][pos[1] + 2] = ary[pos[0] + 1][pos[1] + 2];
	ary[pos[0] + 1][pos[1] + 2] = ary[pos[0] + 2][pos[1] + 2];
	ary[pos[0] + 2][pos[1] + 2] = ary[pos[0] + 2][pos[1] + 1];
	ary[pos[0] + 2][pos[1] + 1] = ary[pos[0] + 2][pos[1]];
	ary[pos[0] + 2][pos[1]] = tmp;
}


int main() {
	int i, j;
	while (scanf("%d %d %d %d %d", &ary[0][0], &ary[0][1], &ary[0][2], &ary[0][3], &ary[0][4]) != EOF) {
		for (i = 1; i < 5; i++) {
			for (j = 0; j < 5; j++) {
				scanf("%d", &ary[i][j]);
			}
		}
		scanf("%d %d %d %d", &op[0], &op[1], &pos[0], &pos[1]);
		pos[0] -= 1;
		pos[1] -= 1;
		if (op[0] == 1 && op[1] == 2) {
			clockwise_four();
		} else if (op[0] == 1 && op[1] == 3) {
			clockwise_nine();
		} else if (op[0] == 2 && op[1] == 2) {
			inverse_clockwise_four();
		} else if (op[0] == 2 && op[1] == 3) {
			inverse_clockwise_nine();
		}
		for (i = 0; i < 5; i++) {
			for (j = 0; j < 4; j++) {
				printf("%d ", ary[i][j]);
			}
			printf("%d\n", ary[i][4]);
		}
	}
	return 0;
}
