#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int T,n,a[N],x[N],y[N],v[N],maxn[N],d[N],num[N],w,p[N];
vector<int>son[N];
void dfs1(int x)
{
	maxn[x]=x;
	for(auto y:son[x])
	{
		d[y]=d[x]+1,dfs1(y);
		maxn[x]=max(maxn[x],maxn[y]);
	}
}
void solve()
{
	scanf("%lld %lld",&n,&w);
	for(int i=1;i<=n;i++)son[i].clear();
	for(int i=2;i<=n;i++)scanf("%lld",&p[i]),son[p[i]].push_back(i);
	dfs1(1);
	int sum=0;
	for(int i=1;i<n;i++)num[i]=d[i]+d[i+1]-d[p[i+1]]*2; 
	num[n]=d[n];
	int ans=n;
	for(int i=1;i<n;i++)
	{
		scanf("%lld %lld",&x[i],&y[i]),v[x[i]]=i;
		sum+=y[i]*2;
		w-=y[i];
		num[x[i]-1]--;
		if(num[x[i]-1]==0)ans--;
		num[maxn[x[i]]]--;
		if(num[maxn[x[i]]]==0)ans--;
		printf("%lld ",ans*w+sum);
	}
	printf("\n");
}
signed main()
{
	scanf("%lld",&T);
	while(T--)solve();
	return 0;
}