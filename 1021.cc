#include <iostream>
#include <string>
using namespace std;

string target;

int statitcs(char s) {
	int count = 0;
	for (string::iterator it = target.begin(); it != target.end(); it++) {
		if (*it == s) {
			count++;
		}
	}
	return count;
}

int main() {
	string s;
	while (1) {
		getline(cin, s);
		getline(cin, target);
		if (s.compare("#") == 0) {
			break;
		} else {
			for (string::iterator it = s.begin(); it != s.end(); it++) {
				cout << *it << ' ' << statitcs(*it) << endl;
			}
		}
	}
	return 0;
}
