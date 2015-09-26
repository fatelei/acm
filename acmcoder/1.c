#include <stdio.h>
#include <math.h>

int main() {
  double x1, y1, x2, y2;
  double disx;
  double disy;
  double rst;
  while(scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2) != EOF) {
    disx = x2 - x1;
    disy = y2 - y1;

    rst = sqrt(pow(disx, 2) + pow(disy, 2));
    printf("%.2lf\n", rst);
  }
  return 0;
}