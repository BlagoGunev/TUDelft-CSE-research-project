#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <string>
#include <complex>

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
#define adde(u,v) edg[++cnt]=Edge(u,v,g[u]),g[u]=cnt
#define addew(u,v,w) edg[++cnt]=Edge(u,v,g[u],w),g[u]=cnt 
#define addedg(u,v,w,cap) edg[++cnt]=Edge(u,v,g[u],w,cap),g[u]=cnt,edg[++cnt]=Edge(v,u,g[v],-w,0),g[v]=cnt
#define fson Edge *e;for(int i = g[u];~i&&(e=&edg[i]);i=e->next)
#define LB lower_bound
#define UB upper_bound
#define lenr(a,b,k) UB(A,b,k)-LB(A,b,k);
#define inp(n,a) ru(n);RP(i,1,n) ru(a[i]);
#define spf(s,a,n) t[0]=0;RP(i,1,n) t[i]=t[i-1]+a[i];
#define ppf(s,a,n) t[0]=1; RP(i,1,n) t[i]=(t[i-1]*(a[i]%mod))%mod;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define piii pair<pii,int>
#define plll pair<pll,ll>
#define mpt int mid = l+r>>1;
#define ls (k<<1)
#define rs (k<<1|1)
#define INF (1<<30)
#define LINF (1LL << 62)
#define ini(n,a) RP(i,1,n) a[i]=INF;
#define inl(n,a) RP(i,1,n) a[i]=LINF;
#define dsui(n,p) RP(i,1,n) p[i]=i;
#define all(a) a.begin(),a.end()
#define inr (ql<=l && r<=qr)
#define cpx complex<double>
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

struct Edge
{
	int  u, v, next;
	int w, p, cap, flow;
	Edge(int _u = 0, int _v = 0, int nxt = -1, int _w = 1, int _cap = 0)
	{
		u = _u;
		v = _v;
		w = _w;
		cap = _cap;
		flow = 0;
		next = nxt;
	}
};

int mod = 1e9 + 7;
const int maxn = 1e6 + 2;
const double pi = acos(-1.0);

int n, a[maxn];

int main()
{
	ru(n);
	RP(i, 1, n) ru(a[i]);
	int j;
	RP(i, 1, n / 2)
	{
		j = n - i + 1;
		if (i & 1)
		{
			swap(a[i], a[j]);
		}
	}
	RP(i, 1, n)
	{
		printf("%d ", a[i]);
	}
}