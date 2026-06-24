#include<bits/stdc++.h>

#define Cn const

#define CI Cn int&

#define N 4000

#define LL long long

using namespace std;

int n,m,a[N+5],St[N+5],S[N+5][2],g[N+5];LL f[N+5][N+5];

int v[N+5];void dfs(int x)

{

	int lc=S[x][0],rc=S[x][1];lc&&(v[lc]=a[lc]-a[x],dfs(lc),0),rc&&(v[rc]=a[rc]-a[x],dfs(rc),0);

	int i,j;for(g[x]=g[lc]+g[rc]+1,i=0;i<=g[x];++i) f[x][i]=-1e18;

	for(i=0;i<=g[lc];++i) for(j=0;j<=g[rc]&&j<=m-i;++j) f[x][i+j]=max(f[x][i+j],f[lc][i]+f[rc][j]);

	for(i=min(m,g[x]);i;--i) f[x][i]=max(f[x][i],f[x][i-1])+1LL*i*(m-i)*v[x];

}

int main()

{

	int i;for(scanf("%d%d",&n,&m),i=1;i<=n;++i) scanf("%d",a+i);

	int T=0;for(i=1;i<=n;++i) {while(T&&a[St[T]]>a[i]) S[St[T]][1]=S[i][0],S[i][0]=St[T--];St[++T]=i;}

	int rt=St[1];while(--T) S[St[T]][1]=St[T+1];return dfs(rt),printf("%lld\n",f[rt][m]),0;

}