#include <bits/stdc++.h>
using namespace std;

int solve() {
  int n;
  cin >> n;

  vector a(3, vector<int>(n, {}));

  for (int j : {0, 1, 2}) {
    for (int i = 0; i < n; ++i) {
      cin >> a[j][i];
    }
  }

  auto p = a[0];
  for (int i = 1; i < n; ++i) {
    if (p[i] == p[i - 1]) {
      p[i] = a[1][i];
    }
  }

  if (p.front() == p.back()) {
    for (int j : {0, 1, 2}) {
      if (a[j].back() != p.front() && a[j].back() != p.back() &&
          a[j].back() != p[n - 2]) {
        p.back() = a[j].back();
        break;
      }
    }
  }

  ranges::copy(p, ostream_iterator<int>(cout, " "));
  cout << "\n";

  return {};
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);

  int tests;
  cin >> tests;
  while (tests--) {
    solve();
  }

  return 0 ^ 0;
}