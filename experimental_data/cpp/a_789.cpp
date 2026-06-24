#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <string>
#include <complex>
#include <bitset>
#include <cmath>

using namespace std;

#define mst(x,v) memset(x,v,sizeof(x))
#define rp(k,x,v) for(int k = x;k<v;++k)
#define RP(k,x,v) for(int k = x;k<=v;++k)
#define lp(k,x,v) for(int k = x;k>v;--k)
#define LP(k,x,v) for(int k = x;k>=v;--k)
#define ll long long
#define ull unsigned long long
#define fr(file) freopen(file,"r",stdin);
#define fw(file) freopen(file,"w",stdout);
#define lowbit(x) (x&-x)
#define adde(u,v) edg[++ecnt]=Edge(u,v,g[u]),g[u]=ecnt
#define addew(u,v,w) edg[++ecnt]=Edge(u,v,g[u],w),g[u]=ecnt
#define addedg(u,v,w,cap) edg[++ecnt]=Edge(u,v,g[u],w,cap),g[u]=ecnt,edg[++ecnt]=Edge(v,u,g[v],-w,0),g[v]=ecnt
#define fson Edge *e=0;for(int i = g[u];~i&&(e=&edg[i]);i=e->next)
#define LB lower_bound
#define UB upper_bound
#define inp(n,a) RP(i,1,n) ru(a[i]);
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pdd pair<double,double>
#define piii pair<pii,int>
#define plll pair<pll,ll>
#define mpt int mid = l+r>>1;
#define ls (k<<1)
#define rs (k<<1|1)
#define INF (1<<28)
#define LINF (1LL << 60)
#define initi(n,a) RP(i,1,n) a[i]=INF;
#define initl(n,a) RP(i,1,n) a[i]=LINF;
#define dsui(n,p) RP(i,1,n) p[i]=i;
#define all(a) a.begin(),a.end()
#define inr (ql<=l && r<=qr)
#define cpx complex<double>
#define spf(s,a) RP(i,1,n) s[i]=s[i-1]+a[i];
#define ssf(s,a) lp(i,n,0) s[i]=s[i+1]+a[i];
#define upmax(a,b) a=max(a,b);
#define upmin(a,b) a=min(a,b);

char READ_DATA;
int SIGNAL_INPUT;
template <typename Type>
inline char ru(Type &v)
{
	SIGNAL_INPUT = 1;
	while ((READ_DATA = getchar()) < '0' || READ_DATA > '9')
		if (READ_DATA == '-')
			SIGNAL_INPUT = -1;
		else if (READ_DATA == EOF)
			return EOF;
	v = READ_DATA - '0';
	while ((READ_DATA = getchar()) >= '0' && READ_DATA <= '9')
		v = v * 10 + READ_DATA - '0';
	v *= SIGNAL_INPUT;
	return 1;
}

template<typename A, typename B > inline char ru(A&x, B&y) { if (ru(x) == EOF) return EOF; ru(y); return 2; }
template<typename A, typename B, typename C>inline char ru(A&x, B&y, C&z) { if (ru(x) == EOF) return EOF; ru(y); ru(z); return 3; }
template<typename A, typename B, typename C, typename D>inline char ru(A&x, B&y, C&z, D&w) { if (ru(x) == EOF) return EOF; ru(y); ru(z); ru(w); return 4; }

struct Vector
{
	int x, y;
	Vector(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
	}
	int operator<(const Vector &cmp) const
	{
		return x < cmp.x || (x == cmp.x && y < cmp.y);
	}
};
typedef Vector Point;

struct Edge
{
	int  u, v, next;
	ll w, cap, flow;
	Edge(int _u = 0, int _v = 0, int nxt = -1, ll _w = 1, ll _cap = 0)
	{
		u = _u;
		v = _v;
		w = _w;
		cap = _cap;
		flow = 0;
		next = nxt;
	}

	int operator<(const Edge &b) const
	{
		return w < b.w;
	}
};

ll key = 57;
ll mod = 1e9 + 7;
const int maxn = 3e6 + 10, maxp = 1e6;
const double pi = acos(-1.0), alpha = 0.65, eps = 1e-6;
inline int dcmp(double a, double b) { return abs(a - b) < eps; }

int n, k, ans;

int main()
{
	int w;
	ru(n, k);
	while (n--)
	{
		ru(w);
		ans += (int)ceil((double)w / k);
	}
	printf("%d", (int)ceil(ans/2.0));
}