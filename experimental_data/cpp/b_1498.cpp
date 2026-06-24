#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, W;
    cin >> n >> W;
    vector <int> w(n);
    for (int i = 0; i < n; ++i) {
      cin >> w[i];
    }
    int total = n;
    vector <int> cnt(20);
    for (int i = 0; i < n; ++i) {
      cnt[31 - __builtin_clz(w[i])] += 1;
    }
    int ans = 0;
    while (total > 0) {
      int64_t sum = 0;
      for (int i = 19; i >= 0; --i) {
        while (cnt[i] && sum + (1 << i) <= W) {
          total -= 1;
          cnt[i] -= 1;
          sum += (1 << i);
        }
      }
      ans += 1;
    }
    cout << ans << "\n";
  }
  return 0;
}