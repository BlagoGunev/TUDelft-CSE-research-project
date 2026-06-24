// BLuemoon_
#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int kMaxN = 1e5 + 5;

LL t, n, m, k[kMaxN], a, b, c;

int main() {
  for (cin >> t; t; t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> k[i];
    }
    sort(k + 1, k + n + 1);
    for (; m; m--) {
      cin >> a >> b >> c;
      int x = lower_bound(k + 1, k + n + 1, b) - k;
      if (x != n + 1 && (b - k[x]) * (b - k[x]) < 4 * a * c) {
        cout << "YES\n" << k[x] << '\n';
      } else if (x != 1 && (b - k[x - 1]) * (b - k[x - 1]) < 4 * a * c) {
        cout << "YES\n" << k[x - 1] << '\n';
      } else {
        cout << "NO\n";
      }
    }
    cout << '\n';
  }
  return 0;
}