/* -*- coding: utf-8 -*-
 *
 * 0648D.cc: D. ﾐ｡ﾐｾﾐｱﾐｰﾑ・ｺﾐｸ ﾐｸ ﾐｼﾐｸﾑ・ｺﾐｸ
 */

#include<cstdio>
#include<set>
#include<algorithm>
#include<utility>

using namespace std;

/* constant */

const int MAX_N = 200000;
const int MAX_M = 200000;

/* typedef */

using pii = pair<int,int>;
using msi = multiset<int>;

/* global variables */

int xs[MAX_N], us[MAX_M], ts[MAX_M];
pii ps[MAX_M];

/* subroutines */

/* main */

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", xs + i);
  for (int i = 0; i < m; i++) scanf("%d%d", us + i, ts + i);

  sort(xs, xs + n);
  int k = 0;
  for (int i = 0; i < m; i++) {
    int l = lower_bound(xs, xs + n, us[i] - ts[i]) - xs;
    int r = upper_bound(xs, xs + n, us[i] + ts[i]) - xs;
    if (l < r) ps[k++] = {l, r};
  }
  sort(ps, ps + k);
  //for (int i = 0; i < k; i++) printf(" %d,%d", ps[i].first, ps[i].second);
  //putchar('\n');

  int cnt = 0;
  msi rs;
  for (int i = 0, x = 0; i < k || ! rs.empty();) {
    if (rs.empty() && i < k && x < ps[i].first) x = ps[i].first;
    while (i < k && ps[i].first <= x) rs.insert(ps[i++].second);

    while (! rs.empty() && *rs.begin() <= x) rs.erase(rs.begin());
    if (! rs.empty() && x < *rs.begin()) {
      rs.erase(rs.begin());
      cnt++;
      x++;
    }
  }

  printf("%d\n", cnt);
  
  return 0;
}