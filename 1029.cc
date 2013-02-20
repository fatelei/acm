#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

typedef struct dict Dict;

struct dict {
	char incantation[30];
	char function[90];
};

Dict magic[100010];
int length;

void insert_dict(string s) {
	int i, pos;
	i = 0;
	for (string::iterator it = s.begin(); it != s.end() && *it != ']'; it++) {
		magic[length].incantation[i++] = *it;
	}
	magic[length].incantation[i++] = ']';
	magic[length].incantation[i] = 0x0;
	pos = i + 1;
	i = 0;
	for (string::iterator it = s.begin() + pos; it != s.end(); it++) {
		magic[length].function[i++] = *it;
	}
	magic[length].function[i] = 0x0;
	length++;
}

void find_magic(string s) {
	int i, j;
	for (i = 0; i < length; i++) {
		if (s.compare(magic[i].incantation) == 0) {
			printf("%s\n", magic[i].function);
			return;
		} else if (s.compare(magic[i].function) == 0) {
			for (j = 1; j < strlen(magic[i].incantation) - 1; j++) {
				printf("%c", magic[i].incantation[j]);
			}
			printf("\n");
			return;
		}
	}
	printf("what?\n");
	return;
}

int main() {
	string tmp;
	int n;
	int i;
	length = 0;
	while (1) {
		getline(cin, tmp);
		if (tmp.compare("@END@") == 0) {
			break;
		}
		insert_dict(tmp);
	}
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++) {
		getline(cin, tmp);
		find_magic(tmp);
	}
	return 0;
}
