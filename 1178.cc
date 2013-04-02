#include <iostream>
#include <string>
#include <set>
#include <cstdio>
using namespace std;

#define POP(s) (s.find("Pop"))
#define INSERT(s) (s.find("Insert"))

void sort_set(set<string> &s) {

}

void insert_set(set<string> &s, string c) {
	s.insert(c);
	printf("SIZE = %d\n", s.size());
}

void pop_set(set<string> &s) {
	if (s.empty()) {
		printf("empty\n");
	} else {
	
	}
}

int main() {
	set<string> complexs;
	string command;
	int n;
	while (scanf("%d", &n) != EOF) {
		getchar();
		complexs.clear();
		while (n--) {
			getline(cin, command);
			if (POP(command) != -1) {
				pop_set(complexs);
			} else {
				insert(complexs, command);
			}
		}
	}
	return 0;
}
