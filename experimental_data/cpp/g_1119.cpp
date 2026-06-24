#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int n, m, t, h[1000100], s[1000100], sh;
set<pair<int, int>> v;

pair<int, int> coAt(int c) {
  int r = 0;
  int nc = 0;
  for (const pair<int, int> & a : v) {
    if (-a.first < c) {
      nc = max(nc, -a.first);
      return {r, nc};
    }
    r += -a.first / c;
    nc = max(nc, -a.first / (-a.first / c + 1));
    if (r >= t)
      return {r, nc};
  }
  return {r, nc};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> n >> m;
  for (int i = 0; i < m; i++)
    cin >> h[i], sh += h[i];
  t = (sh + n - 1) / n;
  h[0] += n * t - sh;
  for (int i = 0; i < m; i++)
    v.insert({-h[i], i});
  vector<vector<int>> a(t, vector<int>(m, 0));
  int ls = n;
  for (int i = 0; i < m && n && ls && !v.empty(); i++) {
    s[i] = min(min(n, ls), -v.begin()->first);
    pair<int, int> c = coAt(s[i]);
    while (c.first < t && s[i] > 0) {
      s[i] = c.second;
      if (s[i] == 0) {
        break;
      }
      c = coAt(s[i]);
    }
    if (s[i] == 0)
      break;
    n -= s[i];
    int ta = t;
    while (ta && !v.empty()) {
      auto it = v.begin();
      if (it->first + s[i] < 0)
        v.insert({it->first + s[i], it->second});
      a[t - ta][i] = it->second;
      v.erase(it);
      ta--;
    }
    ls = s[i];
  }
  cout << t << "\n";
  for (int i = 0; i < m; i++)
    cout << s[i] << (i < m - 1 ? " " : "\n");
  for (int i = 0; i < t; i++)
    for (int j = 0; j < m; j++)
      cout << a[i][j] + 1 << (j < m - 1 ? " " : "\n");
}