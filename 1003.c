#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char data1[40];
char data2[40];
char a[40];
char b[40];

int main() {
	int i, j;
	int tmp1, tmp2;
	memset(data1, '\0', sizeof(data1));
	memset(data2, '\0', sizeof(data2));
	while (scanf("%s %s", data1, data2) != EOF) {
		i = 0;
		j = 0;
		memset(a, '\0', sizeof(a));
		memset(b, '\0', sizeof(b));
		while (1) {
			if (data1[i] == '\0') {
				i++;
				break;
			} else if (data1[i] == ',') {
				i++;
				continue;
			} else {
				a[j++] = data1[i];
				i++;
			}
		}
		a[j] = 0x0;
		i = 0;
		j = 0;
	    while (1) {
			if (data2[i] == '\n' || data2[i] == '\0') {
				break;
			} else if (data2[i] == ',') {
				i++;
				continue;
			} else {
				b[j++] = data2[i];
				i++;
			}
		}
		b[j] = 0x0;
		tmp1 = atoi(a);
		tmp2 = atoi(b);
		printf("%d\n", tmp1+tmp2);
		memset(data1, '\0', sizeof(data1));
		memset(data2, '\0', sizeof(data2));
	}
	return 0;
}
