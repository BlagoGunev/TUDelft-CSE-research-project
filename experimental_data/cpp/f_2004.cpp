#include <bits/stdc++.h>
using namespace std;
void testCase() {
  int n;
  cin >> n;
  vector<long long> p(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    p[i] += p[i - 1];
  }
  map<long long, long long> mp, g;
  for (int l = 1; l <= n; l++) {
    g[p[l] + p[l]]++;
    for (int r = l; r <= n; r++) {
      mp[p[l - 1] + p[r]]++;
    }
  }
  long long ans = 0;
  for (int l = 1; l <= n; l++) {
    for (int r = l; r <= n; r++) ans += r - l;
  }
  for (auto [x, y] : mp) {
    ans -= y * (y - 1);
    if (g[x]) ans -= y;
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    testCase();
  }
  return 0;
}