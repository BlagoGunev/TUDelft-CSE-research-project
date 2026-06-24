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
struct Poi
{
	double x, y;
}p[maxn], a, b, t;
#define dist(_i, _j) sqrt((_i.x - _j.x) * (_i.x - _j.x) + (_i.y - _j.y) * (_i.y - _j.y))
bool vis[maxn];
struct Dist
{
	double d;
	int r;
	inline bool operator < (const Dist &that) const {return d < that.d; }
}d1[maxn], d2[maxn];
double d3[maxn];
#define inf 1e18
int main()
{
//	setfile();
	a = (Poi) {FastIn(), FastIn()};
	b = (Poi) {FastIn(), FastIn()};
	t = (Poi) {FastIn(), FastIn()};
	R double ans = 0;
	R int n = FastIn();
	for (R int i = 1; i <= n; ++i) p[i] = (Poi) {FastIn(), FastIn()};
	for (R int i = 1; i <= n; ++i)
	{
		d3[i] = dist(p[i], t);
		d1[i].d = dist(p[i], a) - d3[i];
		d2[i].d = dist(p[i], b) - d3[i];
		ans += d3[i] * 2;
		d1[i].r = i;
		d2[i].r = i;
	}
	std::sort(d1 + 1, d1 + n + 1);
	std::sort(d2 + 1, d2 + n + 1);
	if (d1[1].d < 0 && d2[1].d < 0)
	{
		R double tmp = inf;
		if (d1[1].r != d2[1].r) ans += d1[1].d + d2[1].d;
		else
		{
			cmin(tmp, d2[1].d);
			cmin(tmp, d2[1].d + d1[2].d);
			cmin(tmp, d1[1].d);
			cmin(tmp, d1[1].d + d2[2].d);
			ans += tmp;
		}
	}
	else
		ans += dmin(d1[1].d, d2[1].d);
	printf("%.10lf\n",ans );
	return 0;
}