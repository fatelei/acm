#include <stdio.h>

int main() {
	int minx, miny;
	int maxx, maxy;
	int x, y;
	int count;
	int flag;
	while (1) {
		count = 0;
		flag = 0;
		minx = miny = maxx = maxy = 0;
		while (1) {
			scanf("%d %d", &x, &y);
			if (x == 0 && y == 0 && count == 0) {
				flag = 1;
				break;
			} else if (x == 0 && y == 0 && count != 0) {
				break;
			} else {
				if (count == 0) {
					minx = maxx = x;
					miny = maxy = y;
				} else {
					if (minx > x) {
						minx = x;
					} else if (maxx < x) {
						maxx = x;
					}
					if (miny > y) {
						miny = y;
					} else if (maxy < y) {
						maxy = y;
					}
				}
			}
			count++;
		}
		if (flag) {
			break;
		} else {
			printf("%d %d %d %d\n", minx, miny, maxx, maxy);
		}
	}
	return 0;
}
