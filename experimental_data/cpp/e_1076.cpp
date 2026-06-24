#include <bits/stdc++.h>
#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define for4(i,x) for(int i=head[x],y=e[i].go;i;i=e[i].next,y=e[i].go)
#define maxn (400000+5)
#define mod (1000000007)
#define ll long long
#define inf 1000000000
#define upmo(a,b) (((a)=((a)+(b))%mo)<0?(a)+=mo:(a))
#define mmo(a,b) (((a)=1ll*(a)*(b)%mo)<0?(a)+=mo:(a))
#define pa pair<int,int>
template<typename T,typename S>inline bool upmin(T&a,const S&b){return a>b?a=b,1:0;}
template<typename T,typename S>inline bool upmax(T&a,const S&b){return a<b?a=b,1:0;}
using namespace std;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
inline bool is_down(char x) { return ('a' <= x && x <= 'z'); }
inline bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
inline bool is_digit(char x) { return ('0' <= x && x <= '9'); }
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
inline ll readll()
{
	ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
long long gcd(long long x,long long y){return y?gcd(y,x%y):x;}
long long power(long long x,long long y)
{
	long long t=1;
	for(;y;y>>=1,x=x*x%mod)
		if(y&1)t=t*x%mod;
	return t;
}
struct edge
{
	int go,next;
}e[2*maxn];
vector<pa>G[maxn];
ll s[maxn],ans[maxn];
int n,m,tot,head[maxn],dep[maxn];
void insert(int x,int y)
{
	e[++tot]=(edge){y,head[x]};head[x]=tot;
	e[++tot]=(edge){x,head[y]};head[y]=tot;
}
ll query(int x)
{
	ll ret=0;
	while(x)
	{
		ret+=s[x];
		x-=x&(-x);
	}
	return ret;
}
void add(int x,int y)
{
	for(;x<=n;x+=x&(-x))s[x]+=y;
}
void dfs(int x,int fa)
{
	for(int i=0;i<G[x].size();i++)
	{
		int y=min(n,G[x][i].first+dep[x]),z=G[x][i].second;
		add(y,z);
	}
	ans[x]=query(n)-query(dep[x]-1);
	
	for4(i,x)if(y!=fa)
	{
		dep[y]=dep[x]+1;
		dfs(y,x);
	}
	
	for(int i=0;i<G[x].size();i++)
	{
		int y=min(n,G[x][i].first+dep[x]),z=G[x][i].second;
		add(y,-z);
	}
}
int main()
{
	n=read();
	rep(i,1,n-1)insert(read(),read());
	m=read();
	rep(i,1,m)
	{
		int x=read(),y=read(),z=read();
		G[x].push_back(pa(y,z)); 
	}
	dep[1]=1;
	dfs(1,0);
//	rep(i,1,n)cout<<i<<' '<<dep[i]<<endl;
	rep(i,1,n)printf("%lld ",ans[i]);
	return 0;
}