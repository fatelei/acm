#include <stdio.h>

int main() {
  int a, b;
  int c;
  scanf("%d/%d", &a, &b);

  printf("%d/%d = ", a, b);
  while (b%a != 0) {
    c = b/a + 1;
    a = a *c - b;
    b = b * c;
    printf("1/%d + ", c);
  }

  printf("1/%d\n", b/a);

  return 0;
}
