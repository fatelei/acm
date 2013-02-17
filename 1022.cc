#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

typedef struct data Data;

struct data {
	int flag;
	int time;
	char stime[10];
	char etime[10];
};

Data ary[110];

void initiate() {
	int i;
	for (i = 1; i <= 100; i++) {
		ary[i].flag = 0;
		ary[i].time = 0;
		memset(ary[i].stime, '\0', sizeof(ary[i].stime));
		memset(ary[i].etime, '\0', sizeof(ary[i].etime));
	}
}

void calculate_time(int num) {
	int sh, sm, eh, em;
	int i;
	sh = sm = eh = em = 0;
	if (strlen(ary[num].stime) != 0 && strlen(ary[num].etime) != 0) {
		sh = (ary[num].stime[0] - '0') * 10 + (ary[num].stime[1] - '0');
		sm = (ary[num].stime[3] - '0') * 10 + (ary[num].stime[4] - '0');
		eh = (ary[num].etime[0] - '0') * 10 + (ary[num].etime[1] - '0');
		em = (ary[num].etime[3] - '0') * 10 + (ary[num].etime[4] - '0');
		ary[num].time = (eh - sh) * 60 + (em - sm);
		ary[num].flag = 1;
	}
	return;
}

void print_average() {
	int i;
	int count = 0;
	int total = 0;
	double tmp;
	for (i = 1; i <= 100; i++) {
		if (ary[i].flag) {
			count++;
			total += ary[i].time;
		}
	}
	tmp = (double)total;
	if (count == 0) {
		printf("%d %d\n", count, total);
	} else {
		tmp = tmp/count + 0.5;
		printf("%d %d\n", count, (int)tmp);
	}
}

void process_input(string input, int *num, char *op, char *time) {
	int i, j, k;
	int pos;
	char tmp[100];
	char numtmp[10];
	char timetmp[10];
	strncpy(tmp, input.c_str(), input.length() + 1);
	j = 0;
	for (i = 0; i < strlen(tmp) && tmp[i] != ' '; i++) {
		numtmp[j++] = tmp[i];
	}
	numtmp[j] = 0x0;
	*num = atoi(numtmp);
	if (*num == -1) {
		return;
	}
	pos = i + 1;
	*op = tmp[pos];
	pos = pos + 2;
	j = 0;
	for (i = pos; i < strlen(tmp); i++) {
		timetmp[j++] = tmp[i];
	}
	timetmp[j] = 0x0;
	strncpy(time, timetmp, strlen(timetmp));
}

int main() {
	int num;
	char op;
	char time[10];
	int flag = 0;
	string input;
	while (1) {
		initiate();
		while (1) {
			memset(time, '\0', sizeof(time));
			getline(cin, input);
			process_input(input, &num, &op, time);
			if (num == -1) {
				flag = 1;
				break;
			} else {
				if (num == 0) {
					print_average();
					break;
				} else {
					if (op == 'S') {
						strncpy(ary[num].stime, time, strlen(time));
					} else if (op == 'E') {
						strncpy(ary[num].etime, time, strlen(time));
						calculate_time(num);
					}
				}
			}
		}
		if (flag) {
			break;
		}
	}
	return 0;
}
