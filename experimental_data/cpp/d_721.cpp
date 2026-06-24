#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

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
	#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout)
#endif

#define R register
#define getc() (S == T && (T = (S = B) + fread(B, 1, 1 << 15, stdin), S == T) ? EOF : *S++)
#define dmax(_a, _b) ((_a) > (_b) ? (_a) : (_b))
#define dmin(_a, _b) ((_a) < (_b) ? (_a) : (_b))
#define cmax(_a, _b) (_a < (_b) ? _a = (_b) : 0)
#define cmin(_a, _b) (_a > (_b) ? _a = (_b) : 0)
#define cabs(_x) ((_x) < 0 ? (- (_x)) : (_x))
char B[1 << 15], *S = B, *T = B;
inline int F()
{
	R char ch; R int cnt = 0; R bool minus = 0;
	while (ch = getc(), (ch < '0' || ch > '9') && ch != '-') ;
	ch == '-' ? minus = 1 : cnt = ch - '0';
	while (ch = getc(), ch >= '0' && ch <= '9') cnt = cnt * 10 + ch - '0';
	return minus ? -cnt : cnt;
}
#define maxn 200010
long long a[maxn];
struct cmp
{
	inline bool operator () (const int &x, const int &y) const
	{
		return cabs(a[x]) > cabs(a[y]);
	}
};
priority_queue<int, vector<int>, cmp >q;
int main()
{
//	setfile();
	R int n = F(), k = F(), x = F(), cnt = 0;
	for (R int i = 1; i <= n; ++i)
	{
		a[i] = F();
		q.push(i);
		a[i] < 0 ? cnt ^= 1 : 0;
	}
	if (cnt)
	{
		for (R int i = 1; i <= k; ++i)
		{
			R int pos = q.top(); q.pop();
			a[pos] >= 0 ? a[pos] += x : a[pos] -= x;
			q.push(pos);
		}
		for (R int i = 1; i <= n; ++i)
			printf("%lld ", a[i] );
	}
	else
	{
		R int pos = q.top(); q.pop(); R bool minus = a[pos] >= 0;
		while (k && cabs(a[pos]) >= x) (minus ? a[pos] -= x : a[pos] += x), --k;
		if (k) (minus ? a[pos] -= x : a[pos] += x), --k, cnt ^= 1;
		q.push(pos);
		for (; k; --k)
		{
			R int pos = q.top(); q.pop();
			a[pos] >= 0 ? a[pos] += x : a[pos] -= x;
			q.push(pos);
		}
		for (R int i = 1; i <= n; ++i)
			printf("%lld ", a[i] );
	}
	return 0;
}