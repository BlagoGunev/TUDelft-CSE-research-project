#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;

#define fst first
#define snd second
#define mp std::make_pair
#define SZ(x) (int)((x).size())
#define ALL(x) x.begin(), x.end()

template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}

template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}

inline bool isDigit(char x) {
  return x >= '0' && x <= '9';
}

inline int read() {
  static char ch;
  bool sgn = false;
  while (!isDigit(ch = getchar()))
    if (ch == '-') sgn = true;
  int ret = ch - 48;
  while (isDigit(ch = getchar()))
    ret = ret * 10 + ch - 48;
  return (sgn ? -ret : ret);
}

const int N = 205, M = 1005;
const int mod = 1e9 + 7;
int n, m, a[N], f[2][N][M];

int main() {
  n = read(); m = read();
  for (int i = 1; i <= n; ++i)
    a[i] = read();
  a[0] = 0;
  std::sort(a + 1, a + n + 1);
  
  f[0][0][0] = 1;
  for (int i = 0; i < n; ++i) {
    int cur = i & 1, nxt = cur ^ 1;
    for (int j = 0; j <= n; ++j) {
      for (int k = 0; k <= m; ++k) {
        int v = f[cur][j][k];
        f[cur][j][k] = 0;
        if (!v) continue;
        int sum = (a[i + 1] - a[i]) * j + k;
        if (sum > m) continue;
        (f[nxt][j + 1][sum] += v) %= mod;
        (f[nxt][j][sum] += (long long)v * j % mod) %= mod;
        if (j) (f[nxt][j - 1][sum] += (long long)v * j % mod) %= mod;
        (f[nxt][j][sum] += v) %= mod;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= m; ++i)
    (ans += f[n & 1][0][i]) %= mod;
  printf("%d\n", ans);
  return 0;
}