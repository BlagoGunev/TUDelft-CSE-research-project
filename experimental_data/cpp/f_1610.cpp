// Fresh Peach Heart Shower
#include <bits/stdc++.h>
#define reg
#define ALL(x) (x).begin(),(x).end()
#define mem(x,y) memset(x,y,sizeof x)
#define ln putchar('\n')
#define lsp putchar(32)
#define pb push_back
#define MP std::make_pair
#ifdef _LOCAL_
#define dprintf(x...) std::fprintf(stderr,x)
#else
#define dprintf(x...) 42
#endif
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
typedef std::pair<int,int> pii;
typedef std::vector<int> poly;
template <class t> inline void read(t &s){s=0;
signed f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
while(isdigit(c))s=(s<<3)+(s<<1)+(c^48),c=getchar();;s*=f;}
template<class t,class ...A> inline void read(t &x,A &...a){read(x);read(a...);}
template <class t> inline void write(t x){if(x<0)putchar('-'),x=-x;
static int buf[50],top=0;while(x)buf[++top]=x%10,x/=10;if(!top)buf[++top]=0;
while(top)putchar(buf[top--]^'0');}
inline void setIn(std::string s){freopen(s.c_str(),"r",stdin);return;}
inline void setOut(std::string s){freopen(s.c_str(),"w",stdout);return;}
inline void setIO(std::string s=""){setIn(s+".in");setOut(s+".out");return;}
template <class t>inline bool ckmin(t&x,t y){if(x>y){x=y;return 1;}return 0;}
template <class t>inline bool ckmax(t&x,t y){if(x<y){x=y;return 1;}return 0;}
inline int lowbit(int x){return x&(-x);}
#define fi first
#define se second
const int MaxN=6e5+50;
std::vector<pii > G[MaxN];
struct Edge{int u,v,w;}E[MaxN];
int d[3][MaxN],vis[MaxN],ans[MaxN],n,m;
int used[MaxN<<1];
inline void dfs(int u)
{
	vis[u]=1;
	while(G[u].size())
	{
		auto v=G[u].back();G[u].pop_back();
		if(used[std::abs(v.se)])continue;
		used[std::abs(v.se)]=1,dfs(v.fi);
		if(std::abs(v.se)<=m)ans[std::abs(v.se)]=(v.se>0?1:2);
	}
}
signed main(void)
{
	int cnt=MaxN<<1;
	read(n,m);
	rep(i,1,m)read(E[i].u,E[i].v,E[i].w),++d[E[i].w][E[i].u],++d[E[i].w][E[i].v];
	rep(i,1,m)if(E[i].w==1)G[E[i].u].pb(MP(E[i].v,+i)),G[E[i].v].pb(MP(E[i].u,-i));
		else G[E[i].u+n].pb(MP(E[i].v+n,+i)),G[E[i].v+n].pb(MP(E[i].u+n,-i));
	int s=0;
	rep(i,1,n)
		if((d[1][i]&1)&&(d[2][i]&1))--cnt,G[i].pb(MP(i+n,cnt)),G[i+n].pb(MP(i,cnt)),++s;
		else if(d[1][i]&1)--cnt,G[i].pb(MP(0,cnt)),G[0].pb(MP(i,cnt)),++s;
		else if(d[2][i]&1)--cnt,G[i+n].pb(MP(0,cnt)),G[0].pb(MP(i+n,cnt));
	rep(i,0,2*n)if(!vis[i])dfs(i);
	write(s),ln;
	rep(i,1,m)write(ans[i]);ln;
	return 0;
}

/*
 * Check List:
 * 1. Input / Output File (OI)
 * 2. long long 
 * 3. Special Test such as n=1
 * 4. Array Size
 * 5. Memory Limit (OI) int is 4 and longlong is 8
 * 6. Mod (a*b%p*c%p not a*b*c%p  ,  (a-b+p)%p not a-b )
 * 7. Name ( int k; for(int k...))
 * 8. more tests , (T=2 .. more)
 * 9. blank \n after a case
*/