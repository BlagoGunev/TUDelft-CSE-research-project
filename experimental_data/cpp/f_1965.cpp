#include <bits/stdc++.h>
using namespace std;
#define debug(fmt, ...) \
  fprintf(stderr, "[%d] " fmt "\n", __LINE__, ##__VA_ARGS__)
template <class _Tx, class _Ty>
inline void chkmin(_Tx& x, const _Ty& y) { if (y < x) x = y; }
template <class _Tx, class _Ty>
inline void chkmax(_Tx& x, const _Ty& y) { if (x < y) x = y; }
bool Mbe;
using ll = long long;
constexpr int N = 2e5 + 10;
int n, m, ans[N], cntl[N], cntr[N];
vector<int> vecl[N], vecr[N];
priority_queue<int> pqr;
priority_queue<int, vector<int>, greater<int>> pql;
bool Med;
int main() {
  // debug("Mem: %.4lfMB.", fabs(&Med - &Mbe) / 1048576);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int l, r;
    cin >> l >> r;
    vecl[l].push_back(r);
    chkmax(m, r);
  }
  for (int i = 1; i <= m; ++i) {
    for (auto it : vecl[i]) pql.push(it);
    while (!pql.empty() && pql.top() < i) pql.pop();
    if (!pql.empty()) {
      int p = pql.top();
      pql.pop(), vecr[p].push_back(i);
    }
  }
  for (int i = m; i >= 1; --i) {
    for (auto it : vecr[i]) pqr.push(it);
    while (!pqr.empty() && pqr.top() > i) pqr.pop();
    if (!pqr.empty()) {
      int p = pqr.top();
      pqr.pop(), ++cntl[p], ++cntr[i];
    }
  }
  for (int l = 1, r, cur = 0; l <= m; ++l) {
    chkmax(r, l - 1);
    cur = max(0, cur - cntr[l - 1]);
    while (r < m && cur + cntl[r + 1] >= r - l + 2) cur += cntl[++r];
    ++ans[min(n, r - l + 1)];
  }
  for (int i = n; i >= 1; --i) ans[i] += ans[i + 1];
  for (int i = 1; i <= n; ++i) cout << ans[i] << '\n';
  return 0;
}
/*
g++ -std=c++14 -O2 -o F F.cpp -Wall -Wextra
-Wshadow -fsanitize=address,undefined -g
*/