#include<bits/stdc++.h>
#define ll long long
#define int ll
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define r1 rt<<1
#define r2 rt<<1|1
#define fi first
#define se second
#define db double
#define ld long db
#define ri register int
#define rep(i,a,b) for(ri i=(a);i<=(b);++i)
#define rep2(i,a,b,c) for(ri i=(a);i<=(b);i+=(c))
#define REP(i,a,b) for(ri i=(a);i>=(b);--i)
#define REP2(i,a,b,c) for(ri i=(a);i>=(b);i-=(c))
using namespace std;

inline ll read(){
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x*f;
}
const int N=2e5+5;
int n,dep[N],fa[N],g1[N],g2[N],f1[N],f2[N],ans,u1,u2;
bool vis[N];
vector<int>g[N];
inline void dfs(ri u){
	g1[u]=u;dep[u]=dep[fa[u]]+1;
	for(ri v:g[u]){
		if(v==fa[u])continue;
		fa[v]=u;dfs(v);
		if(f1[v]+1>f1[u]){
			f2[u]=f1[u];g2[u]=g1[u];
			f1[u]=f1[v]+1;g1[u]=g1[v];
		}
		else if(f1[v]+1>f2[u]){
			f2[u]=f1[v]+1;g2[u]=g1[v];
		}
	}
	//cout<<u<<":"<<f1[u]<<' '<<g1[u]<<"     "<<f2[u]<<' '<<g2[u]<<endl;
	if(!f2[u]){
		if(f1[u]>ans){
			ans=f1[u];u1=u;u2=g1[u];
		}
	}
	else{
		if(f1[u]+f2[u]>ans){
			ans=f1[u]+f2[u];u1=g1[u];u2=g2[u];
		}
	}
}
int mxd,mxu;
inline void dfs2(ri u,ri f,ri d){
	if(d>mxd)mxd=d,mxu=u;
	for(ri v:g[u]){
		if(v==f||vis[v])continue;
		dfs2(v,u,d+1);
	}
}
signed main()
{
	n=read();
	rep(i,1,n-1){
		ri u=read(),v=read();
		g[u].pb(v);g[v].pb(u);
	}
	dfs(1);//cerr<<"u1 u2 ans:"<<u1<<' '<<u2<<' '<<ans<<endl;
	ri tu1=u1,tu2=u2;
	while(dep[u1]>dep[u2]){
		vis[u1]=1;
		for(ri v:g[u1])g[n+1].pb(v);
		u1=fa[u1];
	}
	while(dep[u2]>dep[u1]){
		vis[u2]=1;
		for(ri v:g[u2])g[n+1].pb(v);
		u2=fa[u2];
	}
	while(u1!=u2){
		vis[u1]=1;vis[u2]=1;
		for(ri v:g[u1])g[n+1].pb(v);
		for(ri v:g[u2])g[n+1].pb(v);
		u1=fa[u1];u2=fa[u2];
	}
	vis[u1]=1;
	for(ri v:g[u1])g[n+1].pb(v);
	dfs2(n+1,0,0);if(mxu==0){++mxu;while(mxu==tu1||mxu==tu2)++mxu;}
	cout<<ans+mxd<<endl<<tu1<<' '<<tu2<<' '<<mxu<<endl;
	return 0; 
}