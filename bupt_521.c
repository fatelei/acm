#include <stdio.h>
#include <string.h>

int main() {
    char str[110];
    int nums;
    int length;
    int i;
    scanf("%d", &nums);
    while (nums--) {
        getchar();
        memset(str, '\0', sizeof(str));
        scanf("%s", str);
        length = strlen(str);
        for (i = 0; i < length; i++) {
            if (str[i] >= 'a' && str[i] <= 'z') {
                if (str[i] != 'z') {
                    printf("%c", str[i]+1);
                } else {
                    printf("a");
                }
            } else {
                if (str[i] != 'Z') {
                    printf("%c", str[i]+1);
                } else {
                    printf("A");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
