#include <stdio.h>

int main() {
  int i, j, k;
  int ary[11000];
  int max, cur;
  int s, e;

  while (1) {
    scanf("%d", &k);
    if (k == 0) {
      break;
    }

    s = 0;
    e = k - 1;
    max = -1;
    cur = 0;
    j = 0;

    for (i = 0; i < k; i++) {
      scanf("%d", &ary[i]);
      cur += ary[i];

      if (cur > max) {
        max = cur;
        e = i;
        s = j;
      }

      if (cur < 0) {
        cur = 0;
        j = i + 1;
      }

    }

    if (max < 0) {
      max = 0;
    }
    printf("%d %d %d\n", max, ary[s], ary[e]);
  }
  return 0;
}