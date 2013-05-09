#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string cards;
	string put_cards;
	string tmp;
	int length;
	int i;
	while (getline(cin, cards)) {
		getline(cin, put_cards);
		length = put_cards.length();
		for (i = 0; i < cards.length() + 1; i++) {
			if (i + length ==  cards.length()) {
				tmp = cards.substr(i, length);
				if (tmp.compare(put_cards) > 0) {
					printf("YES\n");
					break;
				} else {
					printf("NO\n");
				}
			} else {
				tmp = cards.substr(i, length);
				if (tmp.compare(put_cards) > 0) {
					printf("YES\n");
					break;
				}
			}
		}
	}
	return 0;
}
