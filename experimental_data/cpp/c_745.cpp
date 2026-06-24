#include <cstdio>
#include <cstring>
#include <algorithm>
#define MN 1005
using namespace std;
bool mp[MN];
int n,m,mxi,mx,fa[MN],p,a[MN],pin,sum,ans;
char c[1005][1005];
inline int read()
{
	int n=0,f=1; char c=getchar();
	while (c<'0' || c>'9') {if(c=='-')f=-1; c=getchar();}
	while (c>='0' && c<='9') {n=n*10+c-'0'; c=getchar();}
	return n*f;
}

int getf(int x) {return fa[x]<0?x:fa[x]=getf(fa[x]);}
inline void gather(int x,int y)
{
	if (x==y) return;
	if (mp[y]) swap(x,y);
	fa[x]+=fa[y]; fa[y]=x;
}

int main()
{
//	freopen("test.in","r",stdin);
	int i,j,k,lt,x,y;
	n=read(); m=read(); p=read();
	for (i=1;i<=n;++i) fa[i]=-1;
	for (i=1;i<=p;++i) mp[read()]=1;
	for (i=1;i<=m;++i)
	{
		x=read(); y=read();
		gather(getf(x),getf(y));
	}
	for (i=1;i<=n;++i)
		if (fa[i]<0) 
			if (mp[i]) {a[++pin]=-fa[i]; if(-fa[i]>mx){mx=-fa[i];mxi=pin;}}else sum+=-fa[i];
	a[mxi]+=sum;	
//	printf("%d\n",mxi);
//	for (i=1;i<=n;++i) printf("%d ",fa[i]); puts("");
	for (i=1;i<=pin;++i)
		ans+=(a[i]-1)*a[i]/2;
	printf("%d",ans-m);
}