// time-limit: 1000
// problem-url: https://codeforces.com/contest/652/problem/A
// Then which of Allah's favor will you deny?
// author: Mushfiq_Talha
#ifdef MUSHFIQ_DEBUG
#include "dbg.h"
#else
#define dbg(...) {}
#endif
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

signed main() {
  cin.tie(NULL)->sync_with_stdio(false);

  int h1, h2, a, b;
  cin >> h1 >> h2 >> a >> b;
  if (h1 + 8*a >= h2) {
    cout << 0;
    return 0;
  }

  h1 += 8*a - 12*b; h2 = max(h1, h2 - 12 * a);
  int d = max(0, a - b) * 12;
  if (d == 0) {
    cout << -1;
    return 0;
  }
  int ans = (h2 - h1 + d - 1) / d;
  cout << ++ans;

  return 0;
}