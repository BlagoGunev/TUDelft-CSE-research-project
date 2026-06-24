//
// Copyright 2024 Turing Edu. All Rights Reserved.
//
// FileName: D.cc
// Author: Beiyu Li <[email protected]>
// Date: 2024-12-05
//
#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for (int i = 0; i < (n); i++)
#define For(i,s,t) for (__typeof(s) i = (s); i <= (t); i++)
#define Rof(i,s,t) for (__typeof(t) i = (s); i >= (t); i--)

using ll = long long;
using pii = pair<int, int>;
mt19937_64 randLL(chrono::steady_clock::now().time_since_epoch().count());

const int inf = 0x3f3f3f3f;
const ll infLL = 0x3f3f3f3f3f3f3f3fLL;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    vector<pii> seg(n * 4);
    vector<int> tag(n * 4);
    auto build = [&](auto&& build, int u, int l, int r) {
      if (l == r) {
        seg[u] = pii(s[l] - '0' - (l - 1), -l);
        return;
      }
      int mid = (l + r) / 2;
      build(build, u << 1, l, mid);
      build(build, u << 1 | 1, mid + 1, r);
      seg[u] = max(seg[u<<1], seg[u<<1|1]);
    };
    build(build, 1, 1, n);
    auto apply = [&](int u, int x) {
      seg[u].first += x, tag[u] += x;
    };
    auto pushdown = [&](int u) {
      if (tag[u]) {
        apply(u << 1, tag[u]);
        apply(u << 1 | 1, tag[u]);
        tag[u] = 0;
      }
    };
    auto update = [&](auto&& update, int u, int l, int r, int s, int t, int x) {
      if (s <= l && r <= t) {
        apply(u, x);
        return;
      }
      pushdown(u);
      int mid = (l + r) / 2;
      if (s <= mid) update(update, u << 1, l, mid, s, t, x);
      if (t > mid) update(update, u << 1 | 1, mid + 1, r, s, t, x);
      seg[u] = max(seg[u<<1], seg[u<<1|1]);
    };
    For(i,1,n) {
      cout << seg[1].first;
      int j = -seg[1].second;
      update(update, 1, 1, n, j, j, -inf);
      if (j < n) update(update, 1, 1, n, j + 1, n, 1);
    }
    cout << '\n';
  }

  return 0;
}