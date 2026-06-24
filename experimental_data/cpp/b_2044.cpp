#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.cpp"
#else
#define debug(...) 42
#define debugArr(...) 42
#endif
using namespace std;

template <class X, class Y> bool mini(X &x, const Y &y) {
  if (x > y) {
    x = y;
    return true;
  }
  return false;
}
template <class X, class Y> bool maxi(X &x, const Y &y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  for (char &c : s) {
    if (c == 'p') {
      cout << 'q';
    } else if (c == 'q') {
      cout << 'p';
    } else {
      cout << 'w';
    }
  }
  cout << "\n";
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
}