#include<bits/stdc++.h>
#define db double
#define ll long long
#define reg register
#define pb(x) push_back(x)
#define fup(i,x,y) for(reg int i=x;i<=y;++i)
#define fdw(i,x,y) for(reg int i=x;i>=y;--i)
using namespace std;
const int N=2e5+10;
int n,k,link[N],tot,son[N],deep[N],da[N];
ll ans;
struct edge{int next,y;}a[N<<1];
inline int read()
{
	int x=0,ff=1;
	char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-') ff=-1;ch=getchar();}
	while(isdigit(ch)) {x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*ff;
}
inline bool cmp(int x,int y) {return x>y;}
inline void add(int x,int y)
{
	a[++tot].y=y;a[tot].next=link[x];link[x]=tot;
}
inline void dfs(int x,int fa)
{
	son[x]=1;
	for(int i=link[x];i;i=a[i].next)
	{
		int y=a[i].y;
		if(y==fa) continue;
		deep[y]=deep[x]+1;
		dfs(y,x);
		son[x]+=son[y];
	}
	da[x]=deep[x]-(son[x]-1);
}
int main()
{
	//freopen("1.in","r",stdin);
	n=read();k=read();
	fup(i,1,n-1)
	{
		int x=read(),y=read();
		add(x,y);add(y,x);
	}
	dfs(1,0);
	ll ans=0;
	sort(da+1,da+n+1,cmp);
	fup(i,1,k) ans+=(ll)da[i];
	printf("%lld",ans);
	return 0;
}