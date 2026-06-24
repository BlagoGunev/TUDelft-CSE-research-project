#include <bits/stdc++.h>
using namespace std;
#define debug(fmt, ...) \
  fprintf(stderr, "[%d] : " fmt "\n", __LINE__, ##__VA_ARGS__)
template <class _Tp>
inline _Tp& read(_Tp& x) {
  bool sign = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) sign |= (ch == '-');
  for (x = 0; isdigit(ch); ch = getchar()) x = x * 10 + (ch ^ 48);
  return sign ? (x = -x) : x;
}
template <class _Tp>
inline void write(_Tp x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar((x % 10) ^ 48);
}
using ll = long long;
const int N = 2e5 + 10;
int n, k, a[N], ans[N];
bool vis[N];
vector<vector<int>> vecs[N];
int qpow(int x, int y, int mod) {
  int ret = 1;
  for (; y; y >>= 1, x = 1LL * x * x % mod)
    if (y & 1) ret = 1LL * ret * x % mod;
  return ret;
}
void mian() {
  read(n), read(k);
  for (int i = 1; i <= n; ++i) read(a[i]);
  for (int i = 1; i <= n; ++i) vecs[i].clear();
  fill(vis + 1, vis + n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
    vector<int> cir;
    for (int j = i; !vis[j]; j = a[j])
      cir.push_back(j), vis[j] = 1;
    vecs[cir.size()].push_back(cir);
  }
  int pw2k = (k < 20 ? 1 << k : -1);
  for (int i = 1; i <= n; ++i) {
    if (vecs[i].empty()) continue;
    int num = vecs[i].size();
    auto add_circle = [&](int l, int r) {
      int sz = i * (r - l);
      vector<int> cur(sz);
      int rnd = qpow(2, k, sz);
      for (int p = l; p < r; ++p)
        for (int j = 0, q = p - l; j < i; ++j)
          cur[q] = vecs[i][p][j], q = (q + rnd) % sz;
      for (int j = 0; j < sz; ++j) ans[cur[j]] = cur[(j + 1) % sz];
    };
    if (i & 1) {
      for (int p = min(k, 20); ~p; --p)
        while (num >= (1 << p))
          add_circle(num - (1 << p), num), num -= 1 << p;
    } else {
      if (pw2k == -1) return puts("NO"), void();
      if (num % pw2k != 0) return puts("NO"), void();
      while (num) add_circle(num - pw2k, num), num -= pw2k;
    }
  }
  puts("YES");
  for (int i = 1; i <= n; ++i)
    write(ans[i]), putchar(" \n"[i == n]);
}
int main() {
  int cas;
  read(cas);
  while (cas--) mian();
  return 0;
}