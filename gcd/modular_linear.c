/*
 * 求解模线性同余方程
 */

#include <stdio.h>

int ex_gcd(int a, int b, int *x, int *y) {
  if (b == 0) {
    *x = 1;
    *y = 0;
    return a;
  } else {
    int d = ex_gcd(b, a % b, x, y);
    int tmp = *x;
    *x = *y;
    *y = tmp - (a / b) * (*y);
    return d;
  }
}

void modular_linear_equation(int a, int b, int n) {
  int x, y;
  int d = ex_gcd(a, b, &x, &y);

  if (b % d == 0) {
    int x0 = (x * (b/d)) % n;
    int i;

    for (i = 0; i < d; i++) {
      printf("%d\n", (x0 + (i * (n / d))) % n);
    }

  } else {
    printf("no solution\n");
  }
}

int main() {
  int a, b, n;
  scanf("%d %d %d", &a, &b, &n);
}
