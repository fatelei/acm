#include <stdio.h>
#include <math.h>

int main() {
	int P, T, G1, G2, G3, GJ;
	int tmp;
	while (scanf("%d %d %d %d %d %d", &P, &T, &G1, &G2, &G3, &GJ) != EOF) {
		float rst = 0;
		if (abs(G1 - G2) <= T) {
			rst = ((float)(G1 + G2))/2;
		} else {
			if ((abs(G3 - G1) <= T) || (abs(G3 - G2) <= T)) {
				if ((abs(G3 - G1) <= T) && (abs(G3 - G2) <= T)) {
					tmp = G1 < G2 ? G2 : G1;
					tmp = tmp < G3 ? G3 : tmp;
					rst = (float)tmp;
				} else { 
					if ((abs(G3 - G1)) <= (abs(G3 - G2))) {
						rst = ((float)(G1 + G3))/2;
					} else {
						rst = ((float)(G2 + G3))/2;
					}
				}
			} else {
				rst = (float)GJ;
			}
		}
		printf("%.1f\n", rst);
	}
	return 0;
}
