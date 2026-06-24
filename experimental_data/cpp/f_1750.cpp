#include <bits/stdc++.h>
#define st first
#define nd second
#define db double
#define re register
#define pb push_back
#define mk make_pair
#define int long long
#define ldb long double
#define pii pair<int, int>
#define ull unsigned long long
#define mst(a, b) memset(a, b, sizeof(a))
const int N = 5e3 + 10;
using namespace std;
inline int read()
{
  int s = 0, w = 1;
  char ch = getchar();
  while(ch < '0' || ch > '9') { if(ch == '-') w *= -1; ch = getchar(); }
  while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
int n, mod;
int f[N], g[N][N], s[N], h[N][N];
inline int power(int x, int k)
{
  int res = 1;
  while(k){
    if(k & 1) res = res * x % mod;
    x = x * x % mod, k >>= 1;
  }
  return res;
}
signed main(){
  n = read(), mod = read();
  s[1] = f[1] = g[1][1] = 1;
  for(re int i = 2; i <= n; i++){
    for(re int j = 1; 2 * (j - 1) < i; j++)
      g[i][j] = f[j] * s[i - 2 * (j + 1)] % mod;
    f[i] = power(2, i - 2);
    for(re int j = 1; j <= i; j++) f[i] = (f[i] - g[i][j] + mod) % mod;
    g[i][i] = (g[i][i] + f[i]) % mod;
    for(re int j = 1; j <= i; j++)
      h[i][j] = (h[i - 1][j + 1] + g[i][j]) % mod;
    s[i] = (s[i - 1] + h[i][1]) % mod;
  }
  printf("%lld\n", f[n]);
  return 0;
}