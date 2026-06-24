#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define int long long

using namespace std;

void sol() {
  int n, m, k;
  string s;
  cin >> n >> m >> k >> s;
  int now = 0;
  int i = 0;
  int ans = 0;
  while (i < n) {
    if (s[i] == '0') {
      ++now;
    } else {
      now = 0;
    }
    if (now >= m) {
      ++ans;
      i += k;
      now = 0;
    } else {
      ++i;
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    sol();
  }
}