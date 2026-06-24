#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#ifdef WIN32
	#define LL "%I64d"
#else
	#define LL "%lld"
#endif

#ifdef CT
	#define debug(...) printf(__VA_ARGS__)
	#define setfile() 
#else
	#define debug(...)
	#define filename ""
	#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);
#endif

#define R register
#define getc() (S == T && (T = (S = B) + fread(B, 1, 1 << 15, stdin), S == T) ? EOF : *S++)
#define dmax(_a, _b) ((_a) > (_b) ? (_a) : (_b))
#define dmin(_a, _b) ((_a) < (_b) ? (_a) : (_b))
#define cmax(_a, _b) (_a < (_b) ? _a = (_b) : 0)
#define cmin(_a, _b) (_a > (_b) ? _a = (_b) : 0)
char B[1 << 15], *S = B, *T = B;
inline int FastIn()
{
	R char ch; R int cnt = 0; R bool minus = 0;
	while (ch = getc(), (ch < '0' || ch > '9') && ch != '-') ;
	ch == '-' ? minus = 1 : cnt = ch - '0';
	while (ch = getc(), ch >= '0' && ch <= '9') cnt = cnt * 10 + ch - '0';
	return minus ? -cnt : cnt;
}
#define maxn 100010
int a[maxn], b[maxn], next[maxn], prev[maxn], n, tim[maxn], ans[maxn];
int main()
{
//	setfile();
	n = FastIn();
	for (R int i = 1; i <= n; ++i)
		a[i] = b[i] = FastIn();
	std::sort(b + 1, b + n + 1);
	for (R int i = 1; i <= n; ++i)
		a[i] = std::lower_bound(b + 1, b + n + 1, a[i]) - b, 
		tim[a[i]] = i, next[i] = i + 1, prev[i] = i - 1;
	tim[0] = tim[n + 1] = 0;
	for (R int i = n; i > 1; --i)
	{
		next[prev[a[i]]] = next[a[i]];
		prev[next[a[i]]] = prev[a[i]];
		ans[i] = b[tim[next[a[i]]] > tim[prev[a[i]]] ? next[a[i]] : prev[a[i]]];
	}
	for (R int i = 2; i <= n; ++i) printf("%d ", ans[i] );
	return 0;
}