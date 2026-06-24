#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,p[100005],i,dep[100005],x[100005],r[100005],ans[100005],buc[1000005];
const int inf=2e5;
long long anss=0;
void solve()
{
	int v;
	memset(dep,0,sizeof(dep));
	memset(x,0,sizeof(x));
	memset(r,0,sizeof(r));
	memset(buc,0,sizeof(buc));
	dep[m+1]=0;
	for(i=m;i>0;i--)
	{
		if(buc[p[i]-i+inf])x[i]=buc[p[i]-i+inf];
		else x[i]=m+1;
		v=p[i]-i+1+inf;
		buc[v]=i;
	}
	for(i=1;i<=m;i++)
	{
		v=p[i]-i;
		if(v>0&&v<=n&&r[v]==0)r[v]=i;
	}
	for(i=m;i>0;i--)dep[i]=1+dep[x[i]];
	for(i=1;i<=n;i++)
	{
		if(r[i]==0)r[i]=min(n,i+m+1);
		else r[i]=min(n,i+m+1-dep[r[i]]);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)scanf("%d",&p[i]);
	if(n==1)
	{
		printf("0\n");
		return 0;
	}
	solve();
	for(i=1;i<=n;i++)ans[i]=r[i];
	for(i=1;i<=m;i++)p[i]=n-p[i]+1;
	solve();
	for(i=1;i<=n;i++)anss+=ans[i]-n+r[n-i+1];
	printf("%lld\n",anss);
	return 0;	
}