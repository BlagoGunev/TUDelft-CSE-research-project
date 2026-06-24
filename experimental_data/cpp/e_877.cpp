#include<bits/stdc++.h>
#define rep(i,a,b)	for(int i=a;i<=b;i++)
#define rev(i,a,b)	for(int i=a;i>=b;i--)
#define reg(i,g,u)	for(int i=h[u];i;i=g[i].nxt)
#define LL long long
#define INF (2147483647)
#define sqr(x)  ((x)*(x))
#define mod (1000000007)
using namespace std;
inline void read(int &data){
    data=0; 
	int w=1; char ch=0;
    while (ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if (ch=='-') w=-1,ch=getchar();
    while  (ch>='0' && ch<='9') data=data*10+ch-'0',ch=getchar();
    data=data*w;
}
inline void read(LL &data){
    data=0;
	int w=1; char ch=0;
    while (ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if (ch=='-') w=-1,ch=getchar();
    while  (ch>='0' && ch<='9') data=data*10+ch-'0',ch=getchar();
    data=data*w;
}
inline void write(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
} 
inline void write(LL x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int maxn=2e5+5;
struct str1{
	int nxt,v;
}g[maxn*2];
int L[maxn],R[maxn],h[maxn<<1],val[maxn],ret[maxn],tot,fa[maxn];
int a[maxn],cnt=0;
int tr[maxn<<2],f[maxn<<2];
void dfs(int u){
	val[++cnt]=u;
	L[u]=cnt;ret[u]=cnt;
	reg(i,g,u){
		int v=g[i].v;
		if (v==fa[u])	continue;
		dfs(v);
	}
	R[u]=cnt;
}
void pushup(int node){
	tr[node]=tr[node<<1]+tr[node<<1|1];
}
void build(int l,int r,int node){
	if (l!=r){
		int mid=(l+r)>>1;
		build(l,mid,node<<1),build(mid+1,r,node<<1|1);pushup(node);
		return;
	}
	tr[node]=a[val[l]],f[node]=0;
}
void pushdown(int l,int r,int node){
	if (f[node]){
		f[node<<1]^=1,f[node<<1|1]^=1,f[node]^=1;
		int mid=(l+r)>>1;
		tr[node<<1]=mid-l+1-tr[node<<1],tr[node<<1|1]=r-mid-tr[node<<1|1];
		return;
	}
}
void change(int l,int r,int node,int L,int R){
	if (L<=l&&R>=r){
		tr[node]=r-l+1-tr[node],f[node]^=1;
		return;
	}
	pushdown(l,r,node);
	int mid=(l+r)>>1;
	if (L<=mid)	change(l,mid,node<<1,L,R);
	if (R>mid)	change(mid+1,r,node<<1|1,L,R);
	pushup(node);
}
int query(int l,int r,int node,int L,int R){
	if (L<=l&&R>=r)
		return tr[node];
	pushdown(l,r,node);
	int mid=(l+r)>>1,ans=0;
	if (L<=mid)	ans+=query(l,mid,node<<1,L,R);
	if (R>mid)	ans+=query(mid+1,r,node<<1|1,L,R);
	pushup(node);return ans;
}
void add(int u,int v){
	g[++tot].nxt=h[u],g[tot].v=v,h[u]=tot;
}
int main(){
	int n;read(n);
	rep(i,2,n){
		read(fa[i]);
		add(fa[i],i);
	}
	rep(i,1,n)	read(a[i]);
	dfs(1);int m;read(m);
	build(1,n,1);int k;
	rep(i,1,m){
		char ch[5];scanf("%s",ch),read(k);
		if (ch[0]=='g')	write(query(1,n,1,L[k],R[k])),puts("");
		else change(1,n,1,L[k],R[k]);
	}
}