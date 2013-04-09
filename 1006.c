#include <stdio.h>
#include <string.h>

char str[1010];

int main() {
	char tmp;
	int i;
	int count1, count2;
	while (scanf("%s", str) != EOF) {
		getchar();
		count1 = count2 = 0;
		i = 0;
		while (str[i] == 'o') {
		    count1++;
		    i++;  
		}
		if (str[i] != 'z') {
		    printf("Wrong Answer\n");
		    continue;
		}
		i++;
		if (str[i] != 'o') {
		    printf("Wrong Answer\n");
		    continue;
		}
		while (str[i] == 'o') {
		    i++;
		}
		if (str[i] != 'j') {
		    printf("Wrong Answer\n");
		    continue;
		}
		i++;
		while (str[i] == 'o') {
		    count2++;
		    i++;
		}
		if (count1 <= count2 && str[i] == 0) {
		    if (count1 == 0 && count2 != 0) {
		        printf("Wrong Answer\n");
		        continue;
		    } else {
		        printf("Accepted\n");
		        continue;
		    }
		} else {
		    printf("Wrong Answer\n");
		    continue;
		}
	}
	return 0;
}
