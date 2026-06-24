/* -*- coding: utf-8 -*-
 *
 * 0649C.cc: C. ﾐ渙ｵﾑ・ｰﾑび・ﾑτ・ｻﾐｾﾐｲﾐｸﾐｹ
 */

#include<cstdio>
#include<algorithm>

using namespace std;

/* constant */

const int MAX_N = 200000;

/* typedef */

/* global variables */

int as[MAX_N];

/* subroutines */

/* main */

int main() {
  int n, x, y;
  scanf("%d%d%d", &n, &x, &y);
  for (int i = 0; i < n; i++) scanf("%d", as + i);
  sort(as, as + n);

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int c2 = min(as[i] / 2, x);
    as[i] -= c2 * 2, x -= c2;
    if (y < as[i]) {
      if (x == 0) break;
      as[i] = 0, x--;
    }
    y -= as[i];
    cnt++;
  }

  printf("%d\n", cnt);
  
  return 0;
}