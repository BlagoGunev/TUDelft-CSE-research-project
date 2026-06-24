#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5005;
const ll mod=998244353;
int n,head[N],edgenum,k,s[N],sum[N],siz[N];
ll ans;
struct edge{int v,next;}e[N<<1];
void add(int u,int v){
	e[++edgenum]=edge{v,head[u]};
	head[u]=edgenum;
}
ll Pow(ll a,ll b){
	ll rec=1;
	for(;b;b>>=1,a=a*a%mod)
		if(b&1)rec=rec*a%mod;
	return rec;
}
struct nade{
	ll w[70];
	nade(){memset(w,0,sizeof w);}
	nade operator + (const nade &b)const{
		nade c;
		for(int s=0;s<(1<<k);s++)if(b.w[s])
			for(int tt=(((1<<k)-1)^s),t=tt;;t=(t-1)&tt){
				c.w[s^t]=(c.w[s^t]+b.w[s]*w[t])%mod;
				if(!t)break;
			}
		return c;
	}
}f[N],up[N],pre[N],suf[N];
void make(nade &f,int siz){
	for(int s=0;s<(1<<k);s++)
		if(sum[s]==siz)f.w[s]=(f.w[s]+f.w[s^(s&-s)])%mod;
}
void dfs(int u,int fa){
	siz[u]=1;f[u].w[0]=1;
	for(int i=head[u],v;i;i=e[i].next){
		if((v=e[i].v)==fa)continue;
		dfs(v,u);siz[u]+=siz[v];
		f[u]=f[u]+f[v];
	}make(f[u],siz[u]);
}
#define pb push_back
void dfs2(int u,int fa){
	vector<int>id;
	for(int i=head[u],v;i;i=e[i].next)
		if((v=e[i].v)^fa)id.pb(v);
	if(!id.size()){
		nade now=up[u];make(now,n);
		ans+=now.w[(1<<k)-1];return;
	}pre[0]=f[id[0]];suf[id.size()-1]=f[id.back()];
	for(int i=1;i<id.size();i++)pre[i]=pre[i-1]+f[id[i]];
	for(int i=(int)id.size()-2;i>=0;i--)suf[i]=suf[i+1]+f[id[i]];
	for(int i=0;i<id.size();i++){
		int v=id[i];up[v]=up[u];
		if(i)up[v]=up[v]+pre[i-1];
		if(i+1<id.size())up[v]=up[v]+suf[i+1];
		make(up[v],n-siz[v]);
	}nade now=suf[0]+up[u];
	make(now,n);ans+=now.w[(1<<k)-1];
	for(int i=0;i<id.size();i++)dfs2(id[i],u);
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}scanf("%d",&k);s[k+1]=n;
	for(int i=1;i<=k;i++)scanf("%d",&s[i]);
	reverse(s+1,s+k+1);
	for(int s=1;s<(1<<k);s++){
		int p=__lg(s&-s)+1;
		sum[s]=sum[s^(s&-s)]+::s[p+1]-::s[p];
	}up[1].w[0]=1;
	dfs(1,0);dfs2(1,0);
	printf("%lld\n",ans%mod*Pow(s[1],mod-2)%mod);
}