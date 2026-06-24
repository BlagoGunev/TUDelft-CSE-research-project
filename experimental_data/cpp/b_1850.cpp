#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void fast_io() {
  cin.tie(nullptr)->sync_with_stdio(false);
}

void solve() {
  int n; cin >> n;

  int ans = 0, val = 0;
  for (int i = 1; i <= n; i++) {
    int ai, bi; cin >> ai >> bi;
    if (ai > 10) continue;

    if (val < bi) {
      val = bi;
      ans = i;
    }
  }
  cout << ans << '\n';
}

int main() {
  fast_io();

  int t = 1;
  cin >> t;
  while (t--) solve();
}