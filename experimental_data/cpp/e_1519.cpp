#include <cstdio>

#include <cctype>

#include <cstring>

#include <map>

#include <vector>

#include <numeric>

#include <algorithm>

#ifdef ONLINE_JUDGE

#define freopen(a, b, c)

#endif



typedef long long int ll;



namespace IPT {



const int L = 1 << 21;

char buf[L], *front=buf, *end=buf;

char GetChar() {

  if (front == end) end = buf + fread(front = buf, 1, L, stdin);

  return (front == end) ? -1 : *(front++);

}

template <typename T>

inline void qr(T &x) {

  char ch = GetChar(), lst = 0; x = 0;

  while (!isdigit(ch)) lst = ch, ch = GetChar();

  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = GetChar();

  if (lst == '-') x = -x;

}

template <typename T>

void qra(T *const __ary, int __n) {

  for (int i = 0; i < __n; ++i) qr(__ary[i]);

}

template <typename T>

int qrs(T *p) {

  T *beg = p;

  do *p = GetChar(); while (!isalnum(*p));

  do *(++p) = GetChar(); while (isalnum(*p));

  *p = 0;

  return p - beg;

}

template <typename T>

void qrdb(T &x) {

  char ch = GetChar(), lst = 0; x = 0;

  while (!isdigit(ch)) lst = ch, ch = GetChar();

  while (isdigit(ch)) { x = x * 10 + (ch - '0'); ch = GetChar(); }

  if (ch == '.') {

    ch = GetChar();

    for (double t = 0.1; isdigit(ch); t *= 0.1) {

      x += (t * (ch - '0'));

      ch = GetChar();

    }

  }

  if (lst == '-') x = -x;

}



} // namespace IPT



namespace OPT {



const int L = 30;

char buf[L];



template <typename T>

inline void qw(T x, const char aft = 0) {

  if (x < 0) { x = -x, putchar('-'); }

  int top = 0;

  do { buf[++top] = static_cast<char>(x % 10 + '0'); } while (x /= 10);

  while (top) putchar(buf[top--]);

  if (aft) putchar(aft);

}

template <typename T>

void qwa(T *const __ary, int __n, const char e1, const char e2) {

  int __dn = __n - 1;

  for (int i = 0; i < __dn; ++i) qw(__ary[i], e1);

  qw(__ary[__dn], e2);

}

template <typename T>

void qws(T *p, const int __n, const char ed) {

  for (int i = 0; i < __n; ++i) putchar(p[i]);

  if (ed) putchar(ed);

}

template <typename T>

void qws(T *p, const char ed) {

  while (*p) putchar(*p++);

  if(ed) putchar(ed);

}



} // namespace OPT



using IPT::qr;

using IPT::qra;

using IPT::qrs;

using IPT::qrdb;

using OPT::qw;

using OPT::qwa;

using OPT::qws;



namespace Fusu { void Main(); }



int main() {

  freopen("1.in", "r", stdin);

  Fusu::Main();

  return 0;

}



namespace Fusu {



const int maxn = 400005;



int nn, n, ecnt, vistime;

int dfn[maxn];



std::map<std::pair<ll, ll>, int> g;

int pnt[maxn], mch[maxn];

std::vector<std::pair<int, int> > e[maxn], ovo[maxn];

std::vector<std::pair<int, int> > ans;



int Id(ll y, ll x) {

  ll k = std::__gcd(x, y);

  x /= k; y /= k;

  return g[{x, y}] ? g[{x, y}] : (g[{x, y}] = ++n);

}



void link(int x, int y, int p) {

  e[x].push_back({++ecnt, y}); e[y].push_back({ecnt, x});

  pnt[ecnt] = p;

}



void dfs(int u) {

  dfn[u] = ++vistime;

  int pre = 0;

  for (auto &E : e[u]) if (dfn[E.second] == 0) {

    int v = E.second;

    dfs(v);

    if (mch[v]) {

      ans.push_back({pnt[mch[v]], pnt[E.first]});

      E.first = 0;

    } else {

      if (pre) {

        ans.push_back({pnt[pre], pnt[E.first]});

        pre = 0;

      } else pre = E.first;

    }

  } else if (dfn[E.second] > dfn[u]) {

    if (pre) {

      ans.push_back({pnt[pre], pnt[E.first]});

      pre = 0;

    } else pre = E.first;

  }

  mch[u] = pre;

}



void Main() {

  qr(nn);

  for (int a, b, c, d, i = 1; i <= nn; ++i) {

    qr(a); qr(b); qr(c); qr(d);

    int x = Id(1ll * (d + c) * b, 1ll * a * d), y = Id(1ll * c * b, 1ll * (a + b) * d);

    link(x, y, i);

  }

  for (int i = 1; i <= n; ++i) if (dfn[i] == 0) {

    dfs(i);

  }

  printf("%llu\n", ans.size());

  for (auto u : ans) {

    printf("%d %d\n", u.first, u.second);

  }

}



} // namespace Fusu