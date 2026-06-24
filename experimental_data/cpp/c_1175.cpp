#pragma GCC optimize("O2,Ofast,inline,unroll-all-loops,-ffast-math")
#pragma GCC target("popcnt")
#include <bits/stdc++.h>
#define maxn 400010
#define ll long long
#define ull unsigned long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define IL inline
#define ss system
using namespace std;

int a[maxn], n, k;
template <class T> void read(T &x) {
  char ch = x = 0;
  bool fl = false;
  while (!isdigit(ch))
    fl |= ch == '-', ch = getchar();
  while (isdigit(ch))
    x = x * 10 + ch - '0', ch = getchar();
  x = fl ? -x : x;
}
void solve() {
  read(n), read(k), k++;
  for (int i = 1; i <= n; i++) {
    read(a[i]);
  }
  pii ans = {1 << 30, 0};
  for (int i = 1; i + k - 1 <= n; i++) {
    int tmp = (a[i] + a[i + k - 1]) / 2;
    ans = min(ans, (pii){max(abs(a[i] - tmp), abs(a[i + k - 1] - tmp)), tmp});
  }
  printf("%d\n", ans.se);
}
int main() {
  int T;
  for (read(T); T--; solve());
  return 0;
}