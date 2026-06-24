#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define debug(...)
#endif

#define int long long
const int N = 1e7 + 5, MOD = 1e9 + 7, oo = 1e9;

int g[N], lp[N];

void solve() {
  int n; cin >> n;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x; ans ^= g[x];
  }

  cout << (ans ? "Alice" : "Bob") << '\n';
}

main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  g[0] = 0;
  g[1] = 1;
  int cnt = 1;
  for (int i = 2; i < N; ++i) {
    if (lp[i] == 0) {
      if (i > 2) {
        g[i] = ++cnt;
      }
      for (int j = i * i; j < N; j += i) {
        if (lp[j] == 0) {
          lp[j] = i;
        }
      }
    } else {
      g[i] = g[lp[i]];
    }
  }

  int T = 1; cin >> T;
  for (int _ = 0; _ < T; ++_) {
    solve();
  }

}