/*

わんわん……わんだほーいっ☆

Wonderhoy!

The only one hint to this problem is don't try to solve, it's not worth it.

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

const int B=316;

int ret[100005],bel[100005];

struct Query{

	int l,r,id;

	Query(){}

	Query(int L,int R,int I){l=L,r=R,id=I;}

	inline bool operator < (Query ano) const {return bel[l]==bel[ano.l]?r<ano.r:bel[l]<bel[ano.l];}

}qry[100005];

bool vis[100005];

int prime[35353],pcnt,rev[100005];

int smp[75],cnt;

int s1[100005][75],s2[100005];

void shai()

{

	vis[1]=true;

	for(int i=2;i<=100000;++i)

	{

		if(!vis[i])

		{

			prime[rev[i]=++pcnt]=i;

			if(i<=B)	smp[++cnt]=i;

		}

		for(int j=1;j<=pcnt && prime[j]*i<=100000;++j)

		{

			vis[prime[j]*i]=true;

			if(i%prime[j]==0)	break;

		}

	}

}

int n,m,C,q;

vector<int> F[100005];

int app[100005];

void add(int p)

{

	for(int d:F[p])

	{

		if(d>=B)

		{

			if(!app[d])	++s2[C/d];

			++app[d];

		}

	}

}

void sub(int p)

{

	for(int d:F[p])

	{

		if(d>=B)

		{

			--app[d];

			if(!app[d])	--s2[C/d];

		}

	}

}

map<__int128,int> M;

int scnt,tpr[75];

int tar[B+5];

int dfs(int u,int p,int c)

{

	if(p>C)	return 0;

	if(u>scnt || C/p<tpr[u])	return (c&1)?-(C/p):C/p;

	return dfs(u+1,p,c)+dfs(u+1,p*tpr[u],c+1);

}

int main(){

	n=read(),m=read(),C=read(),q=read();

	shai();

	for(int i=1;i<=n;++i)

	{

		int c=read();

		bel[i]=(i-1)/B+1;

		for(int j=1;j<=cnt;++j)	s1[i][j]=s1[i-1][j];

		for(int j=2;j*j<=c;++j)

		{

			if(c%j==0)	++s1[i][rev[j]],F[i].push_back(j);

			while(c%j==0)	c/=j;

		}

		if(c^1)

		{

			F[i].push_back(c);

			if(c<=B)	++s1[i][rev[c]];

		}

	}

	for(int i=1;i<=q;++i)	qry[i].l=read(),qry[i].r=read(),qry[i].id=i;

	sort(qry+1,qry+1+q);

	for(int l=1,r=0,ic=1;ic<=q;++ic)

	{

		int L=qry[ic].l,R=qry[ic].r,id=qry[ic].id;

		while(r<R)	add(++r);

		while(l>L)	add(--l);

		while(l<L)	sub(l++);

		while(r>R)	sub(r--);

		scnt=0;

		__int128 S=0;

		for(int i=1;i<=B;++i)	tar[i]=1;

		for(int i=1;i<=cnt;++i)

		{

			S<<=1;

			if(s1[R][i]^s1[L-1][i])

			{

				S|=1;

				tpr[++scnt]=prime[i];

				for(int j=prime[i];j<=B;j+=prime[i])	tar[j]=0;

			}

		}

		int ans=0;

		if(M[S])	ans=M[S];

		else	M[S]=ans=dfs(1,1,0);

		for(int i=1;i<=B;++i)	tar[i]+=tar[i-1],ans-=tar[i]*s2[i];

		ret[id]=ans;

	}

	for(int i=1;i<=q;++i)	write(ret[i]),puts("");

	return 0;

}