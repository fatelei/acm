#include <stdio.h>
#include <math.h>
#define PI 3.1415927

int main() {
  double radius;

  while(scanf("%lf", &radius) != EOF) {
    printf("%.3lf\n", (4 * PI * pow(radius, 3))/3);
  }
  return 0;
}