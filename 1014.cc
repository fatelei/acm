#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef struct student STU;

struct student {
	char id[30];
	int total;
};

STU students[1010];
int score[20];
int nums;
int n, m, g;

int cmp(const void *a, const void *b) {
	STU *c = (STU *)a;
	STU *d = (STU *)b;
	if (c->total != d->total) {
		return d->total - c->total;
	} else {
		if (strcmp(c->id, d->id) > 0)  {
			return 1;
		} else {
			return -1;
		}
	}
}

void process_input(string s) {
	int i, j, pos;
	int num = 0;
	int total = 0;
	char tmp1[30];
	char tmp2[30];
	i = 0;
	for (string::iterator it = s.begin(); it != s.end() && *it != ' '; it++) {
		tmp1[i++] = *it;
	}
	tmp1[i] = 0x0;
	pos = i + 1;
	i = 0;
	for (string::iterator it = s.begin() + pos; it != s.end() && *it != ' '; it++) {
		tmp2[i++] = *it;
	}
	tmp2[i] = 0x0;
	pos = pos + i + 1;
	num = atoi(tmp2);
	memset(tmp2, '\0', sizeof(tmp2));
	for (i = 0; i < num; i++) {
		j = 0;
		for (string::iterator it = s.begin() + pos; it != s.end() && *it != ' '; it++) {
			tmp2[j++] = *it;
		}
		tmp2[j] = 0x0;
		pos += j + 1;
		total += score[atoi(tmp2)];
	}
	if (total >= g) {
		strncpy(students[nums].id, tmp1, strlen(tmp1));
		students[nums].total = total;
		nums++;
	}
	return;
}

void initiate() {
	int i;
	for (i = 0; i < 1010; i++) {
		memset(students[i].id, '\0', sizeof(students[i].id));
		students[i].total = 0;
	}
}

int main() {
	int i;
	string tmp;
	while (1) {
		scanf("%d", &n);
		nums = 0;
		initiate();
		if (n == 0) {
			break;
		} else {
			scanf("%d %d", &m, &g);
			for (i = 1; i <= m; i++) {
				scanf("%d", &score[i]);
			}
			getchar();
			for (i = 0; i < n; i++) {
				getline(cin, tmp);
				process_input(tmp);
			}
			if (nums == 0) {
				printf("0\n");
			} else {
				qsort(students, nums, sizeof(students[0]), cmp);
				printf("%d\n", nums);
				for (i = 0; i < nums; i++) {
					printf("%s %d\n", students[i].id, students[i].total);
				}
			}
		}
	}
	return 0;
}
