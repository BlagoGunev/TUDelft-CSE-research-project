#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
typedef long long ll;
int I(){
	int s=0,f=1;char ch=getchar();
	while (ch<'0' || ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while (ch>='0' && ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*f;
}
const int N=200005;
int n,m,fa[N],cnt;
int fi[N],ne[N<<1],j[N<<1],step,val[N];
ll sum,v[N];
bool pd[N];
struct node{
	int id;ll val;
	node(){}
	node(int x,ll y){id=x;val=y;}
	friend bool operator < (node i,node j){
		return i.val>j.val;
	}
}q[N];
int maxn,root;
void addedge(int fr,int to){
	j[++step]=to;ne[step]=fi[fr];fi[fr]=step;
	j[++step]=fr;ne[step]=fi[to];fi[to]=step;
}
void dfs(int ro,int pre,int dis){
	if (dis>maxn){
		maxn=dis,root=ro;
	}
	for (int u=fi[ro];u;u=ne[u])
		if (j[u]!=pre)dfs(j[u],ro,dis+1);
}
void dfs1(int ro,int pre,ll dis){
	fa[ro]=pre;bool flag=0;
	for (int u=fi[ro];u;u=ne[u]){
		if (j[u]==pre)continue;
		dfs1(j[u],ro,dis+val[j[u]]);
		flag=1;
	}
	if (!flag)q[++cnt]=node(ro,dis);
}
void dfs2(int ro){
	sum+=val[ro];
	val[ro]=0;pd[ro]=1;
	if (pd[fa[ro]])return;
	dfs2(fa[ro]);
}
int main (){
	n=I();
	for (int i=1;i<=n;++i)val[i]=1;
	for (int i=1;i<n;++i)
		addedge(I(),I());
	dfs(1,0,0);
	dfs1(root,0,val[root]);
	sort(q+1,q+cnt+1);
	for (int i=1;i<=cnt;++i){
		sum=0;
		dfs2(q[i].id);
		v[i]=sum;
	}
	sort(v+1,v+cnt+1);sum=0;
	printf ("%d ",1);
	for (int i=cnt;i>=1;--i){
		sum+=v[i];
		printf ("%d ",sum);
	}
	for (int i=1;i<=n-cnt-1;++i)
		printf ("%d ",sum);
	return 0;
}