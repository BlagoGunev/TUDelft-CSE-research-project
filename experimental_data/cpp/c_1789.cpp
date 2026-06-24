#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    map<int, int> occ, freq;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      occ[a[i]] = 1;
    }
    long long ans = 1ll * n * (m + 1) * m;
    for(int i = 2; i <= m + 1; i++) {
      int p, x;
      cin >> p >> x;
      --p;
      freq[a[p]] += i - occ[a[p]];
      a[p] = x;
      occ[a[p]] = i;
    }
    for(int i = 0; i < n; i++) {
      freq[a[i]] += (m + 1) - occ[a[i]] + 1;
    }
    for(auto [x, y] : freq) {
      ans -= 1ll * y * (y - 1) / 2;
    }
    cout << ans << '\n';
  }
  return 0;
}