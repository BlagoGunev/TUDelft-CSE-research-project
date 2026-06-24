// LUOGU_RID: 100951452
#include<iostream>

#include<stdio.h>

#include<ctype.h>

#include<random>

#include<algorithm>

#define ll long long

#define ld long double

#define fi first

#define se second

#define pii pair<int,int>

#define lowbit(x) ((x)&-(x))

#define popcount(x) __builtin_popcount(x)

#define inf 0x3f3f3f3f

#define infll 0x3f3f3f3f3f3f3f3f

#define umap unordered_map

#define all(x) x.begin(),x.end()

#define mk make_pair

#define pb push_back

#define ckmax(x,y) x=max(x,y)

#define ckmin(x,y) x=min(x,y)

#define rep(i,l,r) for(int i=l;i<=r;++i)

#define per(i,r,l) for(int i=r;i>=l;--i)

#define int long long

#define N 200005

using namespace std;

inline int read(){

	int x=0,f=0; char ch=getchar();

	while(!isdigit(ch)) f|=(ch==45),ch=getchar();

	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();

	return f?-x:x;

}

mt19937 rnd(114514);

struct FHQ{

	int ls,rs,lazy,val,sze;

}d[N];

int pool,rt;

inline int nd(int x){

	d[++pool].sze=1,d[pool].val=x;

	d[pool].lazy=d[pool].ls=d[pool].rs=0;

	return pool;

}

inline void pushup(int k){

	d[k].sze=d[d[k].ls].sze+d[d[k].rs].sze+1;

}

inline void pushdown(int k){

	if(!d[k].lazy) return;

	if(d[k].ls){

		d[d[k].ls].val+=d[k].lazy;

		d[d[k].ls].lazy+=d[k].lazy;

	}

	if(d[k].rs){

		d[d[k].rs].val+=d[k].lazy;

		d[d[k].rs].lazy+=d[k].lazy;

	}

	d[k].lazy=0;

}

void split(int k,int &x,int &y,int v){

	if(!k) return (void)(x=y=0);

	pushdown(k);

	if(d[d[k].ls].sze+1<=v){

		x=k;

		split(d[k].rs,d[x].rs,y,v-d[d[k].ls].sze-1);

	}

	else{

		y=k;

		split(d[k].ls,x,d[y].ls,v);

	}

	pushup(k);

}

int merge(int x,int y){

	if(!x || !y) return x|y;

	if(rnd()%(d[x].sze+d[y].sze)<d[x].sze){

		pushdown(x);

		d[x].rs=merge(d[x].rs,y);

		pushup(x);return x;

	}

	else{

		pushdown(y);

		d[y].ls=merge(x,d[y].ls);

		pushup(y);return y;

	}

}

int mx;

void find(int k,int K,int B,int x){

	if(!k) return;

	pushdown(k);

	if(d[k].val<=K*(x+d[d[k].ls].sze+1)-B){

		x+=d[d[k].ls].sze+1;

		ckmax(mx,x);

		find(d[k].rs,K,B,x);

	}

	else find(d[k].ls,K,B,x);

}

int res,now;

void dfs(int k){

	if(!k) return;

	pushdown(k);

	dfs(d[k].ls);

	now+=d[k].val;

	ckmin(res,now);

	dfs(d[k].rs);

}

// void print(int k){

	// if(!k) return;

	// pushdown(k);

	// print(d[k].ls);

	// cerr<<d[k].val<<' ';

	// print(d[k].rs);

// }

struct node{

	int k,c;

	bool operator < (const node &A)const{

		return k>A.k;

	}

}a[N];

int n,ans;

signed main(){

	for(int cas=read();cas--;){

		n=read(),res=1e18,now=pool=ans=rt=0;

		for(int i=1;i<=n;++i){

			a[i].k=read();int b=read(),A=read();

			ans+=b,a[i].c=b-A;

			now+=a[i].c;

		}

		sort(a+1,a+n+1);

		for(int i=1;i<=n;++i){

			mx=0;

			find(rt,a[i].k,a[i].c,0);

			int x,y;

			split(rt,x,y,mx);

			d[y].val+=a[i].k,d[y].lazy+=a[i].k;

			rt=merge(merge(x,nd(a[i].k*(mx+1)-a[i].c)),y);

		}

		ckmin(res,now);

		dfs(rt);

		printf("%lld\n",ans-res);

	}

	return 0;

}