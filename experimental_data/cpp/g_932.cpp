#include <bits/stdc++.h>

using namespace std;

#define ll    long long
#define db   double
#define up(i,j,n)  for (int i = j; i <= n; i++)
#define down(i,j,n) for (int i = j; i >= n; i--)
#define cadd(a,b)  a = add (a, b)
#define cpop(a,b)  a = pop (a, b)
#define cmul(a,b)  a = mul (a, b)
#define pr   pair<int, int>
#define fi   first
#define se   second
#define SZ(x)  (int)x.size()
#define bin(i)  (1 << (i))
#define Auto(i,node) for (int i = LINK[node]; i; i = e[i].next)

template<typename T> inline bool cmax(T & x, T y){return y > x ? x = y, true : false;}
template<typename T> inline bool cmin(T & x, T y){return y < x ? x = y, true : false;}

const int MAXN = 1e6 + 5;
const int oo = 0x3f3f3f3f;

const int mod = 1e9 + 7;

inline int add(int a, int b){a += b; return a >= mod ? a - mod : a;}
inline int pop(int a, int b){a -= b; return a < 0 ? a + mod : a;}
inline int mul(int a, int b){return 1LL * a * b % mod;}

int N;

int cnt = 1, now, son[MAXN][26], pre[MAXN], spre[MAXN], len[MAXN], diff[MAXN];

char s[MAXN], ss[MAXN];

int f[MAXN], g[MAXN];

void extend(int o, int nxt){
 while (s[o - len[now] - 1] != s[o]) now = pre[now];
 if (!son[now][nxt]) {
  int np = ++cnt;
  len[np] = len[now] + 2;
  int anc = pre[now];
  while (s[o - len[anc] - 1] != s[o]) anc = pre[anc];
  pre[np] = son[anc][nxt];
  son[now][nxt] = np;
  diff[np] = len[np] - len[pre[np]];
  spre[np] = diff[np] == diff[pre[np]] ? spre[pre[np]] : pre[np];
 }
 now = son[now][nxt];
}

int main(){
 scanf("%s", ss + 1);
 N = strlen(ss + 1);
 up (i, 1, N / 2) s[(i << 1) - 1] = ss[i];
 up (i, 1, N / 2) s[i << 1] = ss[N - i + 1];
 pre[0] = pre[1] = 1; len[1] = -1;
 f[0] = 1;
 up (i, 1, N) {
  extend(i, s[i] - 'a');
  for (int v = now; len[v] > 0; v = spre[v]) {
   g[v] = diff[v] == diff[pre[v]] ? g[pre[v]] : 0;
   int o = i - len[spre[v]] - diff[v];
   cadd(g[v], f[o]);
   cadd(f[i], g[v]);
  }
  if ((i & 1)) f[i] = 0;
 }
 printf("%d\n", f[N]);
 return 0;
}