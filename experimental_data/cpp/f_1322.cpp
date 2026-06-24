// LUOGU_RID: 98244252
#include <bits/stdc++.h>

using namespace std;

const int N=5e5+5;

int n,m,k,sz[N],d[N],so[N],tp[N],fa[N],s[N],h[N],c[N*2],b[N*2],p[N*2],f[N*2];

vector<int> e[N],g[N];

inline void cmi(int&x,int y) {if(x>y) x=y;}

inline void cmx(int&x,int y) {if(x<y) x=y;}

int getf(int x) {return f[x]==x?x:f[x]=getf(f[x]);}

void merge(int x,int y){

	b[x]=b[y]=1;

	x=getf(x);y=getf(y);

	if(x==y) return;

	f[x]=y;

}

void dfs1(int x){

	sz[x]=1;

	for(int y:e[x]) if(y!=fa[x]){

		d[y]=d[fa[y]=x]+1;

		dfs1(y);sz[x]+=sz[y];

		if(sz[y]>sz[so[x]]) so[x]=y;

	}

}

void dfs2(int x){

	if(!tp[x]) tp[x]=x;

	if(so[x]) tp[so[x]]=tp[x],dfs2(so[x]);

	for(int y:e[x]) if(y!=fa[x]&&y!=so[x]) dfs2(y);

}

int lca(int x,int y){

	while(tp[x]!=tp[y])

		if(d[tp[x]]<d[tp[y]]) y=fa[tp[y]];

		else x=fa[tp[x]];

	return d[x]<d[y]?x:y;

}

int anc(int x,int y){

	while(tp[x]!=tp[y]){

		if(fa[tp[x]]==y) return tp[x];

		x=fa[tp[x]];

	}

	return so[y];

}

void dfs3(int x){

	for(int y:e[x]) if(y!=fa[x]) dfs3(y),s[x]+=s[y];

	if(s[x]) merge(x,fa[x]),merge(x+n,fa[x]+n);

}

bool solve(int x){

	int l=1,r=k,tl=1,tr=(k+1)/2;

	for(int y:e[x]) if(y!=fa[x]){

		if(!solve(y)) return 0;

		if(!b[y]) continue;

		if(f[x]==f[y]) cmx(l,h[y]+1);

		else if(f[x+n]==f[y]) cmi(r,k-h[y]);

		else if(f[y]<=n) cmx(p[f[y]],h[y]+1);

		else cmi(p[f[y]],k-h[y]);

	}

	for(int y:g[x]){

		if(p[y]>p[y+n]) return 0;

		cmx(tl,min(p[y],k-p[y+n]+1));

		cmi(tr,min(p[y+n],k-p[y]+1));

	}

	cmx(l,tl);cmi(r,k-tl+1);

	int rr=k+1-tr;

	if(l>r||(tr<l&&r<rr)) return 0;

	return (h[x]=(l<=tr||l>=rr)?l:rr);

}

bool chk(){

	fill_n(p+1,n,1);fill_n(p+n+1,n,k);

	return solve(1);

}

void print(int x,int op){

	for(int y:e[x]) if(y!=fa[x]){

		if(!b[y]) {print(y,0);continue;}

		if(f[x]==f[y]) print(y,op);

		else if(f[x+n]==f[y]) print(y,op^1);

		else if(f[y]<=n) c[f[y]]|=h[y]>=h[x];

		else c[f[y]]|=h[x]>=k-h[y]+1;

	}

	for(int y:e[x]) if(y!=fa[x]&&b[y]&&f[x]!=f[y]&&f[x+n]!=f[y]){

		int t=f[y]-(f[y]>n)*n;

		print(y,op^(f[y]>n)^(c[t]||c[t+n]));

	}

	if(op) h[x]=k-h[x]+1;

}

int main(){

	scanf("%d%d",&n,&m);

	iota(f,f+n*2+1,0);

	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),e[u].push_back(v),e[v].push_back(u);

	dfs1(1);dfs2(1);

	for(int u,v;m--;){

		scanf("%d%d",&u,&v);

		if(d[u]>d[v]) swap(u,v);

		int l=lca(u,v),fu,fv;

		s[v]++;s[fv=anc(v,l)]--;

		if(l!=u) s[u]++,s[fu=anc(u,l)]--,merge(fu,fv+n),merge(fu+n,fv);

		else b[fv]=b[fv+n]=1;

	}

	dfs3(1);

	for(int i=1;i<=n;i++) if(getf(i)==getf(i+n)) return puts("-1"),0;

	for(int x=1;x<=n;x++){

		for(int y:e[x]) if(f[x]!=f[y]&&f[x+n]!=f[y]&&f[y]<=n) g[x].push_back(f[y]);

		sort(g[x].begin(),g[x].end());

		g[x].erase(unique(g[x].begin(),g[x].end()),g[x].end());

	}

	int l=1,r=n,ans=0;

	while(l<=r){

		k=l+r>>1;

		if(chk()) r=(ans=k)-1;

		else l=k+1;

	}

	printf("%d\n",k=ans);

	chk();print(1,0);

	for(int i=1;i<=n;i++) printf("%d ",h[i]);

	return 0;

}