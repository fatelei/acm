#include <stdio.h>
#include <ctype.h>
#include <string.h>

inline int ctoi(char *c) {
    return isdigit(*c) ? *c - '0' : *c - 'a' + 10;
}

inline int ctoi1(char *p) {
    return 16*ctoi(p) + ctoi(p+1);
}

inline int ctoi2(char *p) {
    return 256*16*ctoi(p) + 256*ctoi(p+1)+16*ctoi(p+3)+ctoi(p+4);
}

int main() {
    int cases;
    int i;
    char str[200];
    int ip_header;
    scanf("%d", &cases);
    for (i = 1; i <= cases; i++) {
        gets(str);
        ip_header = ctoi(str+1)*12;
        printf("Case #%d\n", i);
        printf("Total Length = %d bytes\n", ctoi2(str+6));
        printf("Source = %d.%d.%d.%d\n", ctoi1(str + 36), ctoi1(str + 39), ctoi1(str + 42), ctoi1(str + 45));
        printf("Destination = %d.%d.%d.%d\n", ctoi1(str + 48), ctoi1(str + 51), ctoi1(str + 54), ctoi1(str + 57));
        printf("Source Port = %d\n", ctoi2(str + ip_header));
        printf("Destination Port = %d\n\n", ctoi2(str + ip_header + 6));
    }
    return 0;
}
