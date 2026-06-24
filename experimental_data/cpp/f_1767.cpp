#include<bits/stdc++.h>

//#pragma GCC optimize(3)

//#pragma GCC target("avx")

#define vectorwyx maze

namespace vectorwyx{

#define pii pair<int,int>

#define fi first

#define se second

#define pb push_back

#define eb emplace_back

#define mk make_pair

#define sml(x,y) (x=min(x,y))

#define big(x,y) (x=max(x,y))

#define ll long long

#define uint unsigned

#define ull unsigned long long

#define umap unordered_map

#define db double

#define fo(i,x,y) for(int i=(x);i<=(y);++i)

#define go(i,x,y) for(int i=(x);i>=(y);--i)

#define ptc putchar

#define emp emplace

#define re return

#define co continue

#define brk break

#define HH (ptc('\n'))

#define bctz __builtin_ctz

#define bclz __builtin_clz

#define bppc __builtin_popcount

using namespace std;

ll seed=chrono::system_clock::now().time_since_epoch().count();

mt19937 rnd(seed);

inline int rm(int x,int y){return (int)(rnd()%(y-x+1ll)+x);}

inline int read(){signed ch=getchar();int x=0,f=1;while(!isdigit(ch)){if(ch==(int)('-'))f=-1;ch=getchar();}while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}return x*f;}

inline void out(int *a,int l,int r){fo(i,l,r) cout<<*(a+i)<<' ';puts("");}



//9:49~10:39

//10:39~11:57

const int N=2e5+5,M=N/600;

int B;

int a[N],siz[N],dep[N],bel[N],nd[N],num,dfn[N],ti,rk[N],fa[N],n;

int vis[N],l[N],r[N],ans[N],son[N];



namespace Ds{

int cnt[N],mx,vl;

void add(int x){

//	printf("add(%d)\n",x);

	cnt[x]++;

	if(cnt[x]>mx) mx=cnt[x],vl=x;

	else if(cnt[x]==mx) sml(vl,x);

}

inline int ask(int x=0){

	if(!x) re vl;//printf("mx=%d ret=%d\n",mx,vl),

	int tm=mx,tv=vl;

	fo(i,l[x],r[x]) add(rk[i]);

	int ret=vl;

	fo(i,l[x],r[x]) cnt[rk[i]]--;

	mx=tm,vl=tv;

	re ret;

}

inline void del(int x){cnt[x]--;}//printf("del(%d)\n",x);}

inline void clear(){

//	fo(i,1,n) cnt[i]=0;

	memset(cnt,0,sizeof cnt);

	mx=0,vl=0;

}

}

using Ds::ask;

using Ds::add;

using Ds::del;

using Ds::clear;



//改 rk,改 A 

vector<pii> g[N];

vector<int> e[N],key,A[N];



void dfs1(int x){

//	printf("dfs1(%d)\n",x);

	siz[x]=1;dep[x]=dep[fa[x]]+1;

	dfn[x]=l[x]=++ti;rk[ti]=a[x];

	int mx=0;

	for(int i:e[x]) if(i!=fa[x]){

		fa[i]=x,dfs1(i),siz[x]+=siz[i];

		if(siz[i]>mx) mx=siz[i],son[x]=i;

	}

	r[x]=l[x]+siz[x]-1;

}



void dfs2(int x){

//	printf("dfs2(%d)\n",x);

	int y=son[x];

	for(int i:e[x]) if(i!=fa[x]&&i!=y){

		dfs2(i);

		fo(j,l[i],r[i]) del(rk[j]);

		Ds::mx=Ds::vl=0;

	}

	if(y) dfs2(y);

	for(int i:e[x]) if(i!=fa[x]&&i!=y) fo(j,l[i],r[i]) add(rk[j]);

	add(a[x]);

	umap<int,int> mp_;

	for(auto i:g[x]){

		if(mp_[i.fi]) ans[i.se]=mp_[i.fi];

		else mp_[i.fi]=ans[i.se]=ask(i.fi);

	}

}



int rt;

void dfs3(int x){

//	printf("rt=%d dfs3(%d)\n",rt,x);

	int y=son[x];

//	pii tmp=mk(Ds::mx,Ds::vl);

	for(int i:e[x]) if(i!=fa[x]&&i!=y){

		pii tmp=mk(Ds::mx,Ds::vl);

		dfs3(i);

		fo(j,l[i],r[i]) del(rk[j]);

//		fo(j,l[i],r[i]) Ds::cnt[rk[j]]--;

		Ds::mx=tmp.fi,Ds::vl=tmp.se;

	}

//	Ds::mx=tmp.fi,Ds::vl=tmp.se;

	if(y) dfs3(y);

	for(int i:e[x]) if(i!=fa[x]&&i!=y) fo(j,l[i],r[i]) add(rk[j]);

	add(a[x]);

	for(auto i:g[x]){

		int X=i.fi;

//		assert(bel[X]==bel[rt]);

//		printf("%d:(%d,%d)\n",x,i.fi,i.se);

		pii tmp=mk(Ds::mx,Ds::vl);

		fo(j,l[X],l[rt]-1) add(rk[j]);

		fo(j,r[rt]+1,r[X]) add(rk[j]);

		ans[i.se]=ask();

		fo(j,l[X],l[rt]-1) del(rk[j]);

		fo(j,r[rt]+1,r[X]) del(rk[j]);

		Ds::mx=tmp.fi,Ds::vl=tmp.se;

	}

}



inline void key_it(){

	while(1){

		int x=0;

		fo(i,1,n) if(siz[i]>B&&!vis[i]&&dep[i]>dep[x]) x=i;

		if(!x) brk;

		nd[x]=++num;key.eb(x);

		int y=x,lst=0;

		while(y&&siz[y]-siz[x]<=B){

			bel[y]=num,vis[y]=1;

			if(lst){

				A[y].eb(a[y]);

				for(int i:e[y]) if(i!=fa[y]&&i!=lst)

					fo(j,l[i],r[i]) A[y].eb(rk[j]);

			}

			lst=y;y=fa[y];

		}

	}

}



int col[N],ct,cnt[N];

pii qry[N];

vector<int> G[N];



#define OK (n==2e5&&a[1]==156430)



signed main(){

//	freopen("gen.txt","r",stdin);freopen(".out","w",stdout);

	cin>>n;fo(i,1,n) a[i]=read();

	fo(i,2,n){

		int x=read(),y=read();

		e[x].eb(y),e[y].eb(x);

	}int q=read();B=(int)(n*sqrt(log2(n))/sqrt(q));

	B=2800;

//	sml(B,2000);

//	B=0;

//	printf("B=%d\n",B);

	dfs1(1);

	key_it();

//	if(n==2e5&&a[1]==18374){

//		printf("num=%d:",num);for(int i:key) cout<<i<<' ';HH;

//		re 0;

//	}

//	cout<<"bel:";out(bel,1,n);

	fo(i,1,q){

		int x=read(),y=read();

		if(siz[x]>siz[y]) swap(x,y);

		if(siz[x]<=B) g[y].emplace_back(x,i);

		else qry[i]=mk(x,y),G[bel[x]].eb(i); 

	}

	dfs2(1);clear();//re 0;

	fo(i,1,n) g[i].clear(); 

//re 0;

//	if(n==2e5&&a[1]==156430){

//		printf("num=%d:",num);for(int i:key) cout<<i<<' ';HH;

//		re 0;

//	}	

	fo(i,1,num){

		for(int j:G[i]) g[qry[j].se].eb(qry[j].fi,j);

		rt=key[i-1];fo(j,l[rt],r[rt]) add(rk[j]);

		dfs3(1);

		for(int j:G[i]) g[qry[j].se].clear();

		clear();

	}

	fo(i,1,q) cout<<ans[i]<<'\n';

	return 0;

}

}

/*

-------------------------------------------------

*/





















signed main(){re vectorwyx::main();}