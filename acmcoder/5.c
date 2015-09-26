// http://acm.acmcoder.com/showproblem.php?pid=2011

#include <stdio.h>

int main() {
  int m;
  int ary[110];
  int i, j;
  double sum = 0;

  scanf("%d", &m);

  for (i = 0; i < m; i++) {
    scanf("%d", &ary[i]);
  }
  
  for (i = 0; i < m; i++) {
    sum = 0;

    for (j = 1; j <= ary[i]; j++) {
      if (j % 2 == 0) {
        sum = sum - (double)(1.0 / j);
      } else {
        sum = sum + (double)(1.0 / j);
      }
    }

    printf("%.2lf\n", sum);
  }
  return 0;
}