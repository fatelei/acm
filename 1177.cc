#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

void flip(string &s, string &c) {
	int start = (c.substr(1, 1)).c_str()[0] - '0';
	int length = (c.substr(2, 1)).c_str()[0] - '0';
	char *tmp = new char[length + 1];
	char tmp2;
	string tmp1 = s.substr(start, length);
	strncpy(tmp, tmp1.c_str(), length + 1);
	int i, j;
	for (i = 0, j = length - 1; i < j && i != j; i++, j--) {
		tmp2 = tmp[i];
		tmp[i] = tmp[j];
		tmp[j] = tmp2;
	}
	s.replace(start, length, tmp);
	tmp = NULL;
	free(tmp);
}

void replace(string &s, string &c) {
	int start = (c.substr(1, 1)).c_str()[0] - '0';
	int length = (c.substr(2, 1)).c_str()[0] - '0';
	string tmp = c.substr(3);
	s.replace(start, length, tmp);
}

int main() {
	string target;
	string command;
	int n;
	int i;
	while (getline(cin, target)) {
		scanf("%d", &n);
		getchar();
		for (i = 0; i < n; i++) {
			getline(cin, command);
			if ((command.substr(0, 1)).compare("0") == 0) {
				flip(target, command);
			} else {
				replace(target, command);
			}
			cout << target << endl;
		}
	}
	return 0;
}
