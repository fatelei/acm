#include <stdio.h>
#include <string.h>


void convert_to_binary(unsigned int target) {
    char binary[100];
    int i = 0;
    int j = 0;
    int length = 0;
    memset(binary, 0, sizeof(binary));
    while (target) {
        binary[i++] = target%2 + '0';
        target /= 2;
    }
    binary[i] = 0x0;
    length = strlen(binary);
    for (i = length - 1; i >= 0; i--) {
        if (binary[i] != '0') {
            break;
        }
    }
    if (i == 0) {
        return;
    } else {
        for (j = i; j >= 0; j--) {
            printf("%c", binary[j]);
        }
    }
    printf("\n");
}


int main() {
    int n;
    unsigned int target;
    scanf("%d", &n);
    getchar();
    while (n--) {
        scanf("%d", &target);
        if (target == 0) {
            printf("%d\n", target);
            continue;
        }
        convert_to_binary(target);
    }
    return 0;
}
