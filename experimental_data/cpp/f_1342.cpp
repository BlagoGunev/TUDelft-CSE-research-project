// LUOGU_RID: 102515959
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

	int x=0;

	char c=getchar();

	while(c<'0' || c>'9')	c=getchar();

	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();

	return x;

}

void write(int x)

{

	if(x>9)	write(x/10);

	putchar(x%10+'0');

}

const int inf=1e9;

typedef pair<int,int> P;

typedef vector<int> Poly;

typedef vector<P> PolyP;

#define mp make_pair

#define spc putchar(' ')

#define etr putchar('\n')

#define inlp(x,y) putchar(x==y?'\n':' ')

void Solve();

int main(){

	int T=read();

	while(T-->0)	Solve();

	return 0;

}

typedef tuple<int,int,int> triple;

#define val(x,i) (get<i>(x))

triple lst[16][15][1<<15];

int f[16][16][1<<15];

int sum[1<<15];

int n,a[15];

int rev[15];

void Solve()

{

	n=read();

	for(int i=0;i<n;++i)	a[i]=read(),rev[i]=i+1;

	for(int i=0;i<(1<<n);++i)	sum[i]=0;

	for(int i=0;i<(1<<n);++i)	for(int j=0;j<n;++j)	if((i>>j)&1)	sum[i]+=a[j];

	for(int i=0;i<=n;++i)	for(int j=0;j<=n;++j)	for(int S=0;S<(1<<n);++S)	f[i][j][S]=inf;

	f[0][0][0]=0;

	int U=(1<<n)-1;

	for(int i=0;i<n;++i)

	{

		for(int j=0;j<n;++j)

		{

			for(int S=0;S<(1<<n);++S)

			{

				if(f[i][j][S]>=inf)	continue;

				triple now=make_tuple(i,j,S);

				int cU=U^S;

				for(int T=cU;;T=(T-1)&cU)

				{

					if(sum[T]>f[i][j][S] && (T>>j))

					{

						int pi=i+1,pj=j+1+__builtin_ctz(T>>j),pS=S|T;

						if(sum[T]<f[pi][pj][pS])

						{

//							printf("%d %d %d -> %d %d %d\n",i,j,S,pi,pj,pS);

							f[pi][pj][pS]=sum[T];

							lst[pi][pj][pS]=now;

						}

					}

					if(!T)	break;

				}

			}

		}

	}

	triple u;

	for(int i=n;i;--i)

	{

		for(int j=1;j<=n;++j)

		{

			if(f[i][j][U]<inf)

			{

				u=make_tuple(i,j,U);

				goto succ;

			}

		}

	}

	succ:;

	write(n-val(u,0)),etr;

	while(val(u,0))

	{

		triple v=lst[val(u,0)][val(u,1)][val(u,2)];

		int T=val(u,2)^val(v,2);

		for(int i=0;i<n;++i)

		{

			if(((T>>i)&1) && ((i+1)^val(u,1)))

			{

				write(rev[i]),spc,write(rev[val(u,1)-1]),etr;

				for(int j=i+1;j<n;++j)	--rev[j];

			}

		}

		u=v;

	}

}