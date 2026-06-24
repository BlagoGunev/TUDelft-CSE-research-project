#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#define ll long long
#define N 200005
#define P 32
using namespace std;
int k,fir[N],f[N],dep[N],fa[N][P],n,m,cnt,q,vis[N],vis1[N];
ll sum[N],dis[50][N];
struct he{
	int l,r,c;
}a[N],e[50];
struct ha{
	int r,nx,c;
}b[N*2];
void add(int l,int r,int c){
	k++;b[k].r=r;b[k].c=c;b[k].nx=fir[l];fir[l]=k;
}
bool cmp(he a,he b){
	return a.c<b.c;
}
int gf(int x){
	if(x==f[x]) return x;return (f[x]=gf(f[x]));
}
bool check(int l,int r){
	l=gf(l);r=gf(r);
	if(l==r) return false;
	f[l]=r;
	return 1;
}
void dfs(int x){
	for(int i=1;i<P;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=fir[x];i!=-1;i=b[i].nx)
	if(fa[x][0]!=b[i].r){
		fa[b[i].r][0]=x;
		dep[b[i].r]=dep[x]+1;
		sum[b[i].r]=sum[x]+b[i].c;
		dfs(b[i].r);
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=P-1;i>=0;i--)
		if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
	if(u==v) return u;
	for(int i=P-1;i>=0;i--)
	if(fa[u][i]!=fa[v][i]){
		u=fa[u][i];v=fa[v][i];
	}
	return fa[u][0];
}
queue<int> Q;
void dfs1(int pos,int st){
	for(int i=1;i<=n;i++) dis[pos][i]=1e18,vis1[i]=0;
	while(!Q.empty()) Q.pop();
	dis[pos][st]=0;
	Q.push(st);
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		vis1[u]=0;
		for(int i=fir[u];i!=-1;i=b[i].nx){
			if(dis[pos][u]+b[i].c<dis[pos][b[i].r]){
				dis[pos][b[i].r]=dis[pos][u]+b[i].c;
				if(!vis1[b[i].r]){
					vis1[b[i].r]=1;
					Q.push(b[i].r);
				}
			}
		}
	}
}
int main(){
	memset(fir,-1,sizeof(fir));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].c);
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++)
	if(check(a[i].l,a[i].r)){
		add(a[i].l,a[i].r,a[i].c);
		add(a[i].r,a[i].l,a[i].c);
	}else{
		e[++cnt]=a[i];
	}
	fa[1][0]=0;dep[1]=1;
	dfs(1);
	for(int i=1;i<=cnt;i++){
		add(e[i].l,e[i].r,e[i].c);
		add(e[i].r,e[i].l,e[i].c);
	}
	int now=0;
	for(int i=1;i<=cnt;i++){
		if(!vis[e[i].l]){
			vis[e[i].l]=++now;
			dfs1(now,e[i].l);
		}
		if(!vis[e[i].r]){
			vis[e[i].r]=++now;
			dfs1(now,e[i].r);
		}
	}
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		int f=lca(l,r);
		ll ans=sum[l]+sum[r]-2*sum[f];
		for(int i=1;i<=cnt;i++){
			ans=min(ans,dis[vis[e[i].l]][l]+dis[vis[e[i].r]][r]+e[i].c);
			ans=min(ans,dis[vis[e[i].l]][r]+dis[vis[e[i].r]][l]+e[i].c);
		}
		printf("%I64d\n",ans);
	}
}