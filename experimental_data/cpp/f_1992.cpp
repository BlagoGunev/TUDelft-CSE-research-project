#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.hpp"
#else
#define debug(...) "MJ >> LAMELO"
#endif

void solve() {
  int n, x;
  cin >> n >> x;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 1;
  set<int> divs = {1};
  for (int i = 0; i < n; i++) {
    set<int> new_divs = divs;
    for (int d : divs) {
      if (x % (d * a[i]) == 0) {
        new_divs.insert(d * a[i]);
      }
    }
    if (new_divs.find(x) != new_divs.end()) {
      ans++;
      new_divs = set<int> {1};
      if (x % a[i] == 0) {
        new_divs.insert(a[i]);
      }
    }
    swap(divs, new_divs);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}