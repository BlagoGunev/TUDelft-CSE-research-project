#include <bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=35;
const LL dx[]={-1,1,0,0};
const LL dy[]={0,0,-1,1};
LL g[N][N],en[N],x[N],y[N];
LL n;
void dfs(LL u,LL fa,LL k,LL dis){
	LL f=0;
	for(LL i=1;i<=en[u];i++)
	{
		LL v=g[u][i];
		if(v==fa)continue;
		if(f==k)f++;
		x[v]=x[u]+dx[f]*dis,y[v]=y[u]+dy[f]*dis;
		dfs(v,u,f^1,dis>>1);
		f++;
	}
}
int main()
{
	scanf("%lld",&n);
	LL u,v;
	for(LL i=1;i<n;i++){
		scanf("%lld%lld",&u,&v);
		g[u][++en[u]]=v;
		g[v][++en[v]]=u;
	}
	for(LL i=1;i<=n;i++)
		if(en[i]>4)return !printf("NO\n");
	x[1]=y[1]=0;
	dfs(1,0,-1,1<<30);
	puts("YES");
	for(LL i=1;i<=n;i++)
		printf("%lld %lld\n",x[i],y[i]);
	return 0;
}