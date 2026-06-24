#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
#define MAXN 500005
#define MAXM 500005
#define INF 0x7fffffff
#define ll long long

ll nxt[MAXN<<1],cst[MAXN<<1],cnt,ans;
ll hd[MAXN],to[MAXN<<1],A[MAXN],dp[MAXN];

inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())
		if(c=='-')
			f=-1;
	for(;isdigit(c);c=getchar())
		x=x*10+c-'0';
	return x*f;
}

inline void addedge(ll u,ll v,ll w){
	to[++cnt]=v,cst[cnt]=w;
	nxt[cnt]=hd[u];hd[u]=cnt;
	return;
}

inline void dfs(ll u,ll fa){
	ll mx=0,cmx=0;
	for(ll i=hd[u];i;i=nxt[i]){
		ll v=to[i],w=cst[i];
		if(v==fa) continue;
		dfs(v,u);
		ll now=dp[v]-w;
		if(now>mx) cmx=mx,mx=now;
		else if(now>cmx) cmx=now; 
	} 
	ans=max(ans,mx+cmx+A[u]);
	dp[u]=A[u]+mx;
	return;
}

int main(){
	ll N=read();
	for(ll i=1;i<=N;i++) A[i]=read();
	for(ll i=1;i<N;i++){
		ll u=read(),v=read(),w=read();
		addedge(u,v,w);addedge(v,u,w);
	}
	dfs(1,0);
	printf("%I64d\n",ans);
	return 0;
}