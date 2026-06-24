#include <bits/stdc++.h>
#define sz(a) (int) a.size()
#define all(a) a.begin(), a.end()
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> t, m;
    for (int i = 0; i < n; ++i) {
      char c;
      cin >> c;
      (c == 'T' ? t : m).push_back(i);
    }
    if (sz(t) != sz(m) * 2) {
      cout << "NO\n";
      continue;
    }
    bool ok = true;
    for (int i = 0; i < sz(m); ++i) {
      ok &= t[i] < m[i] && m[i] < t[i + sz(m)];
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}