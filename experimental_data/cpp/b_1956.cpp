#include <bits/stdc++.h>

using namespace std;

const int nmax = 2e5;
int a[5 + nmax], fr[5 + nmax];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    fr[a[i]]++;
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (fr[i] == 2)
      cnt++;
    fr[i] = 0;
  }
  cout << cnt << '\n';
}

void precalc() {

}

signed main() {
  #ifdef LOCAL
    freopen("input", "r", stdin);
  #endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  precalc();
  int t = 1;
  cin >> t;
  while (t--)
    solve();
  return 0;
}