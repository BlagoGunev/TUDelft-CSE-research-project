#include<iostream>

#include<cstdio>

#include<cstring>

#include<algorithm>

#include<cmath>

#include<ctime>

#include<set>

#include<map>

#include<vector>

#include<queue>

#include<numeric>

#include<unordered_set>

#include<unordered_map>

#define fup(i,l,r) for(int i=l;i<=r;i++)

#define fdn(i,l,r) for(int i=r;i>=l;i--)

#define ll long long

#define ull unsigned long long

#define pii pair<int,int>

#define pdd pair<double,double>

#define pll pair<ll,ll>

#define pli pair<ll,int>

#define ld long double

#define eps (1e-8)

#define inf (int)(1e9)

#define x first//rem

#define y second//rem

#define maxn 100010//rem

#define maxt 34

#define mod 998244353//rem

#define mp make_pair

#define pb push_back

using namespace std;



bool up(int &x,int y) { return (x<y?x=y,true:false);}

bool down(int &x,int y) { return (x>y?x=y,true:false); }

void inc(int &x,int y) { x=(x+y)%mod; }

int ksm(int a,int b) { int r=1; for(;b;a=(ll)a*a%mod,b>>=1) if(b&1) r=(ll)r*a%mod; return r; }



int read()

{

	int x=0,flag=1;

	char ch=getchar();

	while(!isdigit(ch))

	{

		if(ch=='-') flag=-flag;

		ch=getchar();

	}

	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();

	return x*flag;

}





int n,a[maxn];

struct Seg{

	int l,r;

	Seg(int l=inf,int r=-inf):l(l),r(r){}

	Seg operator*(const Seg &W) const { return Seg(min(l,W.l),max(r,W.r)); }

	bool operator!=(const Seg &W) const { return l!=W.l||r!=W.r; }

	void in() { l=read(),r=read(); }

}f[maxt][maxn],tr[maxn],qq[maxn];



void init() { fup(i,1,n-1) tr[i]=Seg(); }

void add(int x,Seg v) { while(x<n) tr[x]=tr[x]*v,x+=(x&-x); }

Seg ask(int x) { Seg r; for(int i=x;i;i-=(i&-i)) r=r*tr[i]; return r; }



int tot,hd[maxn];

struct Edge{

	int v,w,nxt;

	Edge(int v=0,int w=0,int nxt=0):v(v),w(w),nxt(nxt){}

}e[maxn];

void ins(int u,int v,int w) { e[++tot]=Edge(v,w,hd[u]),hd[u]=tot; }



int stk[maxn],tp;

ll ans[maxn];



int main()

{

	n=read(); int q=read();

	if(n==1)

	{

		fup(i,1,q) puts("0");

		return 0;

	}

	

	fup(i,1,n) a[i]=read();

	fup(i,1,n-1)

		if(a[i]<=a[i+1]) f[0][i]=Seg(a[i],a[i+1]);

		else f[0][i]=Seg(a[i+1],a[i]);

		

	fup(i,1,maxt-1)

	{

		fup(j,1,n-1)

		{

			if(f[i-1][j].l>=f[i-1][j].r) f[i][j]=Seg();

			else ins(f[i-1][j].l,f[i-1][j].r-1,j);

		}

		init();

		fdn(j,1,n-1)

		{

			add(j,f[i-1][j]);

			//if(hd[j]) cout<<hd[j]<<endl;

			for(int k=hd[j];k;k=e[k].nxt)

			{

				//cout<<e[k].w<<endl;

				f[i][e[k].w]=ask(e[k].v);

			}

			hd[j]=0;

		}

		tot=0;

	}

	

	fup(i,1,q)

	{

		qq[i].in();

		if(qq[i].l==qq[i].r) ans[i]=-2;

		else ins(qq[i].l,qq[i].r-1,i);

	}

	init();

	

	fdn(i,1,n-1)

	{

		add(i,f[maxt-1][i]);

		for(int j=hd[i];j;j=e[j].nxt)

		{

			//cout<<e[j].w<<endl;

			if(i==1&&e[j].v==n-1) ans[e[j].w]=-1;

			else if(ask(e[j].v)!=Seg(1,n)) ans[e[j].w]=-2;

			else stk[++tp]=e[j].w;

		}

		hd[i]=0;

	}

	tot=0;

	

	fdn(i,0,maxt-2)

	{

		fup(j,1,tp) ins(qq[stk[j]].l,qq[stk[j]].r-1,stk[j]);

		init();

		fdn(j,1,n-1)

		{

			add(j,f[i][j]);

			for(int k=hd[j];k;k=e[k].nxt)

			{

				Seg tmp=ask(e[k].v);

				int id=e[k].w;

				if(tmp!=Seg(1,n)) ans[id]|=(1ll<<i),qq[id]=tmp;

			}

			hd[j]=0;

		}

		tot=0;

	}

	

	fup(i,1,q) printf("%lld\n",++ans[i]);

	

	return 0;

}