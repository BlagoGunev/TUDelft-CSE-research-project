#include<bits/stdc++.h>
#define reg register
// #define int long long
inline int read(){
	reg int k=1,x=0;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-') k=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	return k*x;
}
inline int min(reg int x,reg int y){return x<y?x:y;}
const int N=1e6+10,mod=998244353;
int n,m,a[N],b[N];
int fa[N],sz[N],dfc,dfn[N],dep[N],id[N],bel[N],Sz[N];
std::vector<int> G[N];
void dfs(reg int u,reg int rt){
	sz[u]=1,dfn[u]=++dfc,bel[u]=rt;
	for (auto v:G[u]) if (!id[v]) dep[v]=dep[u]+1,dfs(v,rt),sz[u]+=sz[v];
}
int find(reg int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline bool can(reg int g,reg int x,reg int len){
	if (find(g)!=find(x)) return 0; 
	if (id[g]){
	// std::cerr<<g<<" "<<x<<" "<<len<<"\n";
	// std::cerr<<dep[bel[x]]<<" "-dep[bel[x]]+dep[x]<<"\n";
		return (id[g]-id[bel[x]]+Sz[find(x)])%Sz[find(x)]-dep[bel[x]]+dep[x]<=len;
	}
	if (bel[x]!=bel[g]) return 0;
	if (!(dfn[g]<=dfn[x]&&dfn[x]<dfn[g]+sz[g])) return 0;
	return dep[x]-dep[g]<=len;
}
inline bool check(reg int len){
	for (reg int i=1,j=1;i<=n;i++){
		while (j<=m&&!can(j,a[i],len)) j++;
		if (j>m) return 0;
	}
	return 1;
}
inline void work(){
	n=read(),m=read();
	for (reg int i=1;i<=m;i++) fa[i]=i,G[i].clear(),dep[i]=dfn[i]=id[i]=0; dfc=0;
	for (reg int i=1;i<=n;i++) a[i]=read();
	for (reg int i=1;i<=m;i++) G[b[i]=read()].push_back(i),fa[find(i)]=find(b[i]);
	for (reg int i=1;i<=m;i++) if (find(i)==i){
		reg int x=i; std::vector<int> vc; 
		do vc.push_back(x),x=b[x]; while (x!=i);  Sz[find(i)]=vc.size();
		for (reg int j=0;j<vc.size();j++) id[vc[j]]=j+1,dfs(vc[j],vc[j]);
	}
	reg int ans=m+1,l=0,r=m;
	// std::cerr<<check(1)<<"\n";
	// std::cerr<<can(5,1,1)<<"\n";
	while (l<=r){
		reg int mid=l+r>>1;
		if (check(mid)) r=mid-1,ans=mid; else l=mid+1;
	}
	if (ans>m) puts("-1"); else printf("%d\n",ans);
}
signed main(){
	for (reg int _=read();_--;) work();
	return 0;
}