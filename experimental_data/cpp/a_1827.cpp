#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
typedef long long ll;
using namespace std;
const int M = (int) 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  sort(all(a));
  sort(all(b));
  vector<int> g;
  for (auto x : a) {
    if (x <= b[0]) {
      cout << "0\n";
      return;
    }
    int i = lower_bound(all(b), x) - b.begin();
    g.pb(i);
  }
  int ans = 1;
  for (int i = 0; i < n; i++) {
    if (g[i] <= i) {
      ans = 0;
      break;
    }
    ans *= (g[i] - i);
    ans %= M;
  }
  cout << ans << '\n';

}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}