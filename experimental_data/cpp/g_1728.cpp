/*

¤ï¤ó¤ï¤ó¡­¡­¤ï¤ó¤À¤Û©`¤¤¤Ã¡î

Wonderhoy!

*/

#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

typedef double DB;

char buf[1<<21],*p1=buf,*p2=buf;

#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<18,stdin),p1==p2)?EOF:*p1++)

int read()

{

	int x=0,f=1;

	char c=getchar();

	while(c<'0' || c>'9')	f=(c=='-'?-1:f),c=getchar();

	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();

	return x*f;

}

void write(int x)

{

	if(x>9)	write(x/10);

	putchar(x%10+'0');

}

constexpr int MOD=998244353;

inline int Add(int u,int v){return u+v>=MOD?u+v-MOD:u+v;}

inline int Sub(int u,int v){return u-v>=0?u-v:u-v+MOD;}

inline int Mul(int u,int v){return LL(u)*LL(v)%MOD;}

inline int add(int &u,int v){return u=Add(u,v);}

inline int sub(int &u,int v){return u=Sub(u,v);}

inline int mul(int &u,int v){return u=Mul(u,v);}

int QuickPow(int x,int p=MOD-2)

{

	int ans=1,base=x;

	while(p)

	{

		if(p&1)	mul(ans,base);

		mul(base,base);

		p>>=1;

	}

	return ans;

}

int Len,n,m;

struct node{

	int a,d;

	node(int A=0,int D=0){a=A,d=D;}

	inline bool operator < (node ano) const {return a<ano.a;}

	inline int operator () () const {return a;}

}lt[500005];

int p[505];

int f[505][505],g[505][505];

int pre[505],suf[505];

int main(){

//	freopen("lantern.in","r",stdin);

//	freopen("lantern.out","w",stdout);

	Len=read(),n=read(),m=read();

	for(int i=1;i<=n;++i)	lt[i].a=read();

	for(int i=1;i<=n;++i)	lt[i].d=Len;

	for(int i=1;i<=m;++i)	p[i]=read();

	sort(lt+1,lt+1+n),sort(p+1,p+1+m);

	p[0]=-2*Len,p[m+1]=3*Len;

	for(int L=0;L<=m+1;++L)

	{

		int w=1,pos=1,l=p[L];

		while(pos<=n && lt[pos]()<l)	++pos;

		for(int R=L+1;R<=m+1;++R)

		{

			int r=p[R];

			while(pos<=n && lt[pos]()-l<=r-lt[pos]())	mul(w,min(lt[pos].d+1,lt[pos]()-l)),++pos;

			f[L][R]=w;

		}

	}

	for(int R=1;R<=m+1;++R)

	{

		int w=1,pos=n,r=p[R];

		while(pos>=1 && lt[pos]()>r)	--pos;

		for(int L=R-1;~L;--L)

		{

			int l=p[L];

			while(pos>=0 && r-lt[pos]()<lt[pos]()-l)	mul(w,min(lt[pos].d+1,r-lt[pos]())),--pos;

			mul(f[L][R],w);	

		}

	}

	pre[0]=1,suf[m+1]=1;

	for(int i=1;i<=m+1;++i)	for(int j=0;j<i;++j)	sub(pre[i],Mul(f[j][i],pre[j]));

	for(int i=m;i>=0;--i)	for(int j=m+1;j>i;--j)	sub(suf[i],Mul(f[i][j],suf[j]));

	for(int i=1;i<=m;++i)	for(int j=i;j<=m;++j)	g[i][j]=(MOD-Mul(Mul(pre[i-1],suf[j+1]),f[i-1][j+1]))%MOD;

	for(int i=1;i<=m;++i)	for(int j=i;j<=m;++j)	add(g[i][j],g[i-1][j]);

	for(int i=1;i<=m;++i)	for(int j=m;j>=i;--j)	add(g[i][j],g[i][j+1]);

	int q=read();

	while(q-->0)

	{

		int P=read(),D=Len;

		int* pos=prev(upper_bound(p+1,p+1+m,P));

		int l=pos-p,r=pos-p+1;

		if(*pos==P)	--l;

		int ans=0,lstd=-1;

		while(lstd^D)

		{

			int w=min({D-lstd,P-p[l]-1-lstd,p[r]-P-1-lstd});

			add(ans,Mul(l+1==r?MOD-pre[m+1]:MOD-g[l+1][r-1],w));

			lstd+=w;

			if(P-lstd==p[l]+1)	--l;

			if(P+lstd==p[r]-1)	++r;

		}

		write(ans),puts("");

	}

	return 0;

}