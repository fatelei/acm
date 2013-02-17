#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(char *str1, char *str2) {
	int tmp1;
	int tmp2;
	int pos;
	int i;
	tmp1 = (str1[0] - '0')*10 + (str1[1] - '0');
	tmp2 = (str2[0] - '0')*10 + (str2[1] - '0');
	if (tmp1 > tmp2) {
		return 1;
	} else if (tmp1 < tmp2) {
		return -1;
	} else {
		tmp1 = (str1[3] - '0')*10 + (str1[4] - '0');
		tmp2 = (str2[3] - '0')*10 + (str2[4] - '0');
		if (tmp1 > tmp2) {
			return 1;
		} else if (tmp1 < tmp2) {
			return -1;
		} else {
			tmp1 = (str1[6] - '0')*10 + (str1[7] - '0');
			tmp2 = (str2[6] - '0')*10 + (str2[7] - '0');
			if (tmp1 > tmp2) {
				return 1;
			} else if (tmp1 < tmp2) {
				return -1;
			} else {
				return 0;
			}
		}
	}
}

int main() {
	int total;
	int num;
	int i, j;
	char first[20];
	char last[20];
	char id[20];
	char stime[20];
	char etime[20];
	char cstime[20];
	char cetime[20];
	scanf("%d", &total);
	for (i = 0; i < total; i++) {
		scanf("%d", &num);
		memset(first, '\0', sizeof(first));
		memset(last, '\0', sizeof(last));
		memset(cstime, '\0', sizeof(cstime));
		memset(cetime, '\0', sizeof(cetime));
		if (num == 1) {
			scanf("%s %s %s", id, stime, etime);
			printf("%s %s\n", id, id);
		} else {
			for (j = 0; j < num; j++) {
				memset(id, '\0', sizeof(id));
				memset(stime, '\0', sizeof(stime));
				memset(etime, '\0', sizeof(etime));
				scanf("%s %s %s", id, stime, etime);
				if (strlen(first) == 0 && strlen(last) == 0) {
					strncpy(first, id, strlen(id));
					strncpy(last, id, strlen(id));
					strncpy(cstime, stime, strlen(stime));
					strncpy(cetime, etime, strlen(etime));
				} else {
					if (compare(cstime, stime) > 0) {
						strncpy(first, id, strlen(id));
						strncpy(cstime, stime, strlen(stime));
					}
					if (compare(cetime, etime) < 0) {
						strncpy(last, id, strlen(id));
						strncpy(cetime, etime, strlen(etime));
					}
				}
			}
			printf("%s %s\n", first, last);
		}
	}
	return 0;
}
