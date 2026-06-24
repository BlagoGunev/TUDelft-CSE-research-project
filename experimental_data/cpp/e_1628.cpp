#include <bits/stdc++.h>

#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;++i)

#define per(i,r,l) for (int i(r),_##i(l);i>=_##i; --i)

#define buildG(M) int tot;struct Edge {int to,nxt;}e[M+5];void add(int u,int v,int hd[]){e[++tot]=(Edge){v,hd[u]},hd[u]=tot;}

#define _buildG(M) int tot;struct Edge {int to,nxt,dis;}e[M+5];void add(int u,int v,int w,int hd[]){e[++tot]=(Edge){v,hd[u],w},hd[u]=tot;}

#define Go(i,u,v,hd) for (int i(hd[u]),v,w;v=e[i].to,i;i=e[i].nxt)

#pragma GCC optimize(3)

#pragma GCC target("avx")

#pragma GCC optimize("Ofast")

#pragma GCC optimize("inline")

#pragma GCC optimize("-fgcse")

#pragma GCC optimize("-fgcse-lm")

#pragma GCC optimize("-fipa-sra")

#pragma GCC optimize("-ftree-pre")

#pragma GCC optimize("-ftree-vrp")

#pragma GCC optimize("-fpeephole2")

#pragma GCC optimize("-ffast-math")

#pragma GCC optimize("-fsched-spec")

#pragma GCC optimize("unroll-loops")

#pragma GCC optimize("-falign-jumps")

#pragma GCC optimize("-falign-loops")

#pragma GCC optimize("-falign-labels")

#pragma GCC optimize("-fdevirtualize")

#pragma GCC optimize("-fcaller-saves")

#pragma GCC optimize("-fcrossjumping")

#pragma GCC optimize("-fthread-jumps")

#pragma GCC optimize("-funroll-loops")

#pragma GCC optimize("-fwhole-program")

#pragma GCC optimize("-freorder-blocks")

#pragma GCC optimize("-fschedule-insns")

#pragma GCC optimize("inline-functions")

#pragma GCC optimize("-ftree-tail-merge")

#pragma GCC optimize("-fschedule-insns2")

#pragma GCC optimize("-fstrict-aliasing")

#pragma GCC optimize("-fstrict-overflow")

#pragma GCC optimize("-falign-functions")

#pragma GCC optimize("-fcse-skip-blocks")

#pragma GCC optimize("-fcse-follow-jumps")

#pragma GCC optimize("-fsched-interblock")

#pragma GCC optimize("-fpartial-inlining")

#pragma GCC optimize("no-stack-protector")

#pragma GCC optimize("-freorder-functions")

#pragma GCC optimize("-findirect-inlining")

#pragma GCC optimize("-fhoist-adjacent-loads")

#pragma GCC optimize("-frerun-cse-after-loop")

#pragma GCC optimize("inline-small-functions")

#pragma GCC optimize("-finline-small-functions")

#pragma GCC optimize("-ftree-switch-conversion")

#pragma GCC optimize("-foptimize-sibling-calls")

#pragma GCC optimize("-fexpensive-optimizations")

#pragma GCC optimize("-funsafe-loop-optimizations")

#pragma GCC optimize("inline-functions-called-once")

#pragma GCC optimize("-fdelete-null-pointer-checks")

using namespace std;

const int SZ(1<<23);

unsigned char *S,*T,buf[SZ];

#define getchar() (S==T&&(T=buf+fread(S=buf,1,SZ,stdin)),S==T?EOF:*S++)

inline int frd(int x=0,char c=getchar(),bool f=true)

{

    for (;!isdigit(c);c=getchar()) f=c!='-';

    for (;isdigit(c);c=getchar()) x=x*10+(c^48);

    return f?x:-x;

}

const int N(3e5+5);

int n,m,f[N*2+5],hd[N*2+5],val[N*2+5],dfn[N*2+5],idfn[N*2+5],cntD,cntNode;

int dep[N*2+5],fir[N*2+5],st[23][N*4+5],len;

buildG(N*2+5);

int getf(int x)

{

	return x==f[x]?x:f[x]=getf(f[x]);

}

struct line {

	int a,b,w;

}li[N+5];

bool cmp(line a,line b)

{

	return a.w<b.w;

}

int chkmin(int a,int b)

{

	if(!a||!b) return a+b;

	return dep[a]<dep[b]?a:b;

}

void initST()

{

	for(int i(1);len>>i;++i)rep(j,1,len-(1<<i)+1)

		st[i][j]=chkmin(st[i-1][j],st[i-1][j+(1<<i-1)]);

}

int ask(int l,int r)

{

	int t(log2(r-l+1));

	return chkmin(st[t][l],st[t][r-(1<<t)+1]);

}

int lca(int u,int v)

{

	return ask(fir[u],fir[v]);

}

void dfs(int u)

{

	idfn[dfn[u]=++cntD]=st[0][fir[u]=++len]=u;

	Go(i,u,v,hd) dep[v]=dep[u]+1,dfs(v),st[0][++len]=u;

}

int tmx[N*4+5],tmn[N*4+5],mx[N*4+5],mn[N*4+5],tag[N*4+5];

void build(int rt,int L,int R) 

{

	tag[rt]=-1,tmn[rt]=INT_MAX,tmx[rt]=-INT_MAX;

	if(L==R) return (void)(mx[rt]=mn[rt]=dfn[L]);

	int mid(L+R>>1);

	build(rt<<1,L,mid),build(rt<<1|1,mid+1,R);

	mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);

	mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);

}

void update(int rt,bool ok)

{

	tag[rt]=ok;

	if(ok) tmn[rt]=mn[rt],tmx[rt]=mx[rt];

	else tmn[rt]=INT_MAX,tmx[rt]=-INT_MAX;

}

void pushdown(int rt)

{

	if(!~tag[rt]) return;

	update(rt<<1,tag[rt]),update(rt<<1|1,tag[rt]),tag[rt]=-1;

}

void modify(int rt,int L,int R,int l,int r,bool ok)

{

	if(l<=L&&R<=r) return update(rt,ok);

	int mid(L+R>>1); pushdown(rt);

	if(l<=mid) modify(rt<<1,L,mid,l,r,ok);

	if(r>mid) modify(rt<<1|1,mid+1,R,l,r,ok);

	tmx[rt]=max(tmx[rt<<1],tmx[rt<<1|1]);

	tmn[rt]=min(tmn[rt<<1],tmn[rt<<1|1]);

}

signed main()

{

	cntNode=n=frd(),m=frd();

	rep(i,1,n-1) li[i]=(line) {frd(),frd(),frd()};

	rep(i,1,n) f[i]=i,val[i]=-1;

	stable_sort(li+1,li+n,cmp);

	rep(i,1,n-1) {

		int fu(getf(li[i].a)),fv(getf(li[i].b));

		if(fu!=fv) {

			val[++cntNode]=li[i].w;

			f[fu]=f[fv]=f[cntNode]=cntNode;

			add(cntNode,fu,hd),add(cntNode,fv,hd);

		}

	} 

	dfs(cntNode),initST(),build(1,1,n);

	while(m--) {

		int opt(frd());

		if(opt<=2) {

			int l(frd()),r(frd());

			modify(1,1,n,l,r,2-opt);

		}else {

			int x(frd()),t1(tmn[1]),t2(tmx[1]);

			printf("%d\n",val[lca(idfn[min(t1,dfn[x])],idfn[max(t2,dfn[x])])]);

		}

	}

    return 0;

}