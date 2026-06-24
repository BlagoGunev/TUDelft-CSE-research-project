#include <cstdio>
#include <cstring>
#include <algorithm>

#define DEBUG(args...) fprintf(stderr, args)

#define FOR(i, l, r) for(int i = (l), i##_end = (r); i <= i##_end; ++i)
#define REP(i, l, r) for(int i = (l), i##_end = (r); i <  i##_end; ++i)
#define DFR(i, l, r) for(int i = (l), i##_end = (r); i >= i##_end; --i)
#define DRP(i, l, r) for(int i = (l), i##_end = (r); i >  i##_end; --i)

typedef long long LL;

template<class T>T Min(const T &a, const T &b) {return a < b ? a : b;}
template<class T>T Max(const T &a, const T &b) {return a > b ? a : b;}
template<class T>bool Chkmin(T &a, const T &b) {return a > b ? a = b, 1 : 0;}
template<class T>bool Chkmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

class fast_input {
private:
 static const int SIZE = 1 << 15 | 1;
 char buf[SIZE], *front, *back;

 void Next(char &c) {
     if(front == back) back = (front = buf) + fread(buf, 1, SIZE, stdin);
  c = front == back ? (char)EOF : *front++;
 }

public :
 template<class T>void operator () (T &x) {
  char c, f = 1;
  for(Next(c); c > '9' || c < '0'; Next(c)) if(c == '-') f = -1;
  for(x = 0; c >= '0' && c <= '9'; Next(c)) x = x * 10 + c - '0';
  x *= f;
 }
 void operator () (char &c, char l = 'a', char r = 'z') {
  for(Next(c); c > r || c < l; Next(c)) ;
 }
}input;

const int SN = 1000000 + 47;
const int SX = 1 << 17 | 1;
const int MAX_BIT = 17;
const int MOD = 1000000007;
const int NI = 500000004;

const int AND = 0;
const int OR = 1;
const int XOR = 2;

int f[SX], g[SX], h[SX], s[SX];
int a[SN], fib[SX], n;
int t[SX], tt[SX];
int dp[MAX_BIT + 1][SX], sz[SX], dp2[MAX_BIT + 1][SX];

void FWT(int *, int, int);
void IFWT(int *, int, int);
int F(int);
int DF(int);

int main() {

#ifdef Cai
 freopen("s.in", "r", stdin);
#endif

 int x, y, z;

 input(n);
 FOR(i, 1, n) input(a[i]);

 fib[0] = 0, fib[1] = 1;
 REP(i, 2, SX) fib[i] = F(fib[i - 1] + fib[i - 2]);

 REP(i, 0, 1 << MAX_BIT) sz[i] = sz[i >> 1] + (i & 1);
 
 FOR(i, 1, n) ++dp[sz[a[i]]][a[i]];
 REP(i, 0, MAX_BIT + 1) FWT(dp[i], MAX_BIT, OR);
 REP(i, 0, MAX_BIT + 1) FOR(j, 0, i) REP(k, 0, 1 << MAX_BIT)
  dp2[i][k] = (dp2[i][k] + 1LL * dp[j][k] * dp[i - j][k]) % MOD;
 REP(i, 0, MAX_BIT + 1) IFWT(dp2[i], MAX_BIT, OR);
 REP(i, 0, 1 << MAX_BIT) f[i] = 1LL * dp2[sz[i]][i] * fib[i] % MOD;

 FOR(i, 1, n) g[a[i]] = F(g[a[i]] + fib[a[i]]);

 FOR(i, 1, n) ++h[a[i]];
 FWT(h, MAX_BIT, XOR);
 REP(i, 0, 1 << MAX_BIT) h[i] = 1LL * h[i] * h[i] % MOD;
 IFWT(h, MAX_BIT, XOR);
 REP(i, 0, 1 << MAX_BIT) h[i] = 1LL * h[i] * fib[i] % MOD;

 FWT(f, MAX_BIT, AND), FWT(g, MAX_BIT, AND), FWT(h, MAX_BIT, AND);
 REP(i, 0, 1 << MAX_BIT) s[i] = 1LL * f[i] * g[i] % MOD * h[i] % MOD;
 IFWT(s, MAX_BIT, AND);
 
 int ans = 0;
 for(int i = 1; i < 1 << MAX_BIT; i <<= 1) ans = F(ans + s[i]);

 printf("%d\n", ans);

 return 0;

}

void FWT(int *x, int max_bit, int opt) {
 int p, q;
 FOR(i, 1, max_bit) for(int j = 0; j < 1 << max_bit; j += 1 << i)
  REP(k, 0, 1 << i - 1) {
   p = x[j + k], q = x[j + k + (1 << i - 1)];
   if(opt == AND) 
    x[j + k] = F(p + q);
   else if(opt == OR)
    x[j + k + (1 << i - 1)] = F(p + q);
   else if(opt == XOR)
    x[j + k] = F(p + q), x[j + k + (1 << i - 1)] = DF(p - q);
  }
}

void IFWT(int *x, int max_bit, int opt) {
 int p, q;
 FOR(i, 1, max_bit) for(int j = 0; j < 1 << max_bit; j += 1 << i)
  REP(k, 0, 1 << i - 1) {
   p = x[j + k], q = x[j + k + (1 << i - 1)];
   if(opt == AND)
    x[j + k] = DF(p - q);
   else if(opt == OR)
    x[j + k + (1 << i - 1)] = DF(q - p);
   else if(opt == XOR) {
    x[j + k] = 1LL * NI * (p + q) % MOD;
    x[j + k + (1 << i - 1)] = 1LL * NI * (p - q + MOD) % MOD;
   }
  }
}

int F(int x) {
 return x >= MOD ? x - MOD : x;
}

int DF(int x) {
 return x < 0 ? x + MOD : x;
}