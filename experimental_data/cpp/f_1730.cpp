#include <bits/stdc++.h>
//Was yea ra,rra yea ra synk sphilar yor en me exec hymme METAFALICA waath!

#pragma GCC optimize("Ofast")

#pragma GCC optimize("unroll-loops")

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include<bits/stdc++.h>

using namespace std;

#define rg register

#define ll long long

#define ull unsigned ll

#define lowbit(x) (x&(-x))

#define djq 1000000007

const double eps=1e-10;

const short sint=0x3f3f;

const int inf=0x3f3f3f3f;

const ll linf=0x3f3f3f3f3f3f3f3f;

const double alpha=0.73;

const double PI=acos(-1);

inline void file(){

	freopen("1.in","r",stdin);

	freopen("1.ans","w",stdout);

}

char buf[1<<21],*p1=buf,*p2=buf;

inline int getc(){

    return p1==p2&&(p2=(p1=buf)+fread(buf,1,(1<<20)+5,stdin),p1==p2)?EOF:*p1++;

}

//#define getc getchar

inline ll read(){

	rg ll ret=0,f=0;char ch=getc();

    while(!isdigit(ch)){if(ch==EOF)exit(0);if(ch=='-')f=1;ch=getc();}

    while(isdigit(ch)){ret=ret*10+ch-48;ch=getc();}

    return f?-ret:ret;

}

inline void rdstr(char* s){

	char ch=getc();

	while(ch<'*'||ch>'/') ch=getc();

	while(ch>='*'&&ch<='/') (*s++)=ch,ch=getc();

}

#define ep emplace

#define epb emplace_back

#define all(x) (x).begin(),(x).end()

#define fi first

#define se second

#define it iterator

#define mkp make_pair

#define naive return 0*puts("Yes")

#define angry return 0*puts("No")

#define fls fflush(stdout)

#define rep(i,a) for(rg int i=1;i<=a;++i)

#define per(i,a) for(rg int i=a;i;--i)

#define rep0(i,a) for(rg int i=0;i<=a;++i)

#define per0(i,a) for(rg int i=a;~i;--i)

#define szf sizeof

typedef vector<int> vec;

typedef pair<int,int> pii;

struct point{ int x,y; point(int x=0,int y=0):x(x),y(y) {} inline bool operator<(const point& T)const{ return x^T.x?x<T.x:y<T.y; }; };

inline int ksm(int base,int p){int ret=1;while(p){if(p&1)ret=1ll*ret*base%djq;base=1ll*base*base%djq,p>>=1;}return ret;}

inline void pls(int& x,const int k){ x=(x+k>=djq?x+k-djq:x+k); }

//inline int add(const int a,const int b){ return a+b>=djq?a+b-djq:a+b; }

inline void sub(int& x,const int k){ x=(x-k<0?x-k+djq:x-k); }

inline int inc(const int a,const int b){ return a<b?a-b+djq:a-b; }

inline void ckmn(int& x,const int k){ x=(k<x?k:x); }

inline void ckmx(int& x,const int k){ x=(k>x?k:x); }

 

int n,k,p[5015],q[5015],ans;

int f[5015][1<<8];

int t[5015];

inline void add(int x,const int v){ while(x<=n+k) t[x]+=v,x+=(x&(-x)); }

inline int qry(int x){ int r(0); while(x) r+=t[x],x-=(x&(-x)); return r; }

inline int cost(int i,int j,int d){

	int ret=qry(n+k)-qry(q[i+d]);

	for(rg int t=0;t<k;++t) if((j>>t)&1) ret+=(q[i+t+1]>q[i+d]);

	return ret;

}

signed main(){

	//file(); 

	n=read(),k=read();

	rep(i,n) p[i]=read(),q[p[i]]=i;

	for(rg int i=n+1;i<=n+k;++i) p[i]=i,q[i]=i;

	memset(f,0x3f,sizeof(f));

	f[1][0]=0;

	rep(i,n){

		const int lim=(1<<min(k,n-i)),mn=min(k,n-i);

		for(rg int j=0;j<lim;++j){

			if(f[i][j]==inf) continue;

			for(rg int d=0;d<mn;++d) 

				if(((j>>d)&1)^1) ckmn(f[i][j^(1<<d)],f[i][j]+cost(i,j,d+1));

			int a=i+1,b=j;

			while(b&1) ++a,b/=2;

			ckmn(f[a][b/2],f[i][j]+cost(i,j,0)); 

		}

		add(q[i],1);

	}

	printf("%d\n",f[n+1][0]);

	return 0;

}