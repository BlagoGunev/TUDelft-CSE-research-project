#include<iostream>

#include<cstdio>

#include<vector>

#include<cmath>

#define ll long long

#define poly vector<int>

const int N=1e5+5,M=666,mod=998244353;

using namespace std;

struct edge{

	int x,y;

}g[N<<1];

int k[N],sg[N];

int su=0;

bool v[N],usd[N];

long long tmp[M];

inline char gc()

{

	static char buf[1<<16],*S,*T;

	if(S==T)

	{

		T=(S=buf)+fread(buf,1,1<<16,stdin);

		if(S==T)return EOF;

	}

	return *(S++);

}

#define getchar gc

inline ll read()

{

	char h=getchar();

	ll y=0;

	while(h<'0'||h>'9')h=getchar();

	while(h>='0'&&h<='9')y=y*10+h-'0',h=getchar();

	return y;

}

inline int qpow(int a,int b)

{

	int j=1;

	for(;b;b>>=1,a=1ll*a*a%mod)if(b&1)j=1ll*j*a%mod;

	return j;

}

struct setpoly{//集合幂级数封装卡常板 

	inline void SoS(poly &f,int v,int ty)//ty=0:pre   ty=1:suf 

	{

		int n=f.size(),m=0;

		while((1<<m)<n)m++;

		for(int i=0;i<n;i++)tmp[i]=f[i];

		for(int i=0;i<m;i++)

		for(int j=0;j<n;j++)if(ty^((j>>i)&1))tmp[j]=(tmp[j]+v*tmp[j^(1<<i)]);

		for(int i=0;i<n;i++)f[i]=(tmp[i]%mod+mod)%mod;

	}

	inline poly OR(poly a,poly b)

	{

		int n=a.size();

		SoS(a,1,0);SoS(b,1,0);

		for(int i=0;i<n;i++)a[i]=1ll*a[i]*b[i]%mod;

		SoS(a,-1,0);

		return a;

	}

	inline poly AND(poly a,poly b)

	{

		int n=a.size();

		SoS(a,1,1);SoS(b,1,1);

		for(int i=0;i<n;i++)a[i]=1ll*a[i]*b[i]%mod;

		SoS(a,-1,1);

		return a;

	}

	inline void trans(poly &f)

	{

		int n=f.size(),m=0;

		while((1<<m)<n)m++;

		for(int i=0;i<n;i++)tmp[i]=f[i];

		for(int i=0;i<m;i++)

		for(int j=0;j<n;j++)if((j>>i)&1)

		{

			long long x=tmp[j^(1<<i)],y=tmp[j];

			tmp[j]=(x-y);tmp[j^(1<<i)]=(x+y);

		}

		for(int i=0;i<n;i++)f[i]=(tmp[i]%mod+mod)%mod;

	}

	inline poly XOR(poly a,poly b)

	{

		int n=a.size();

		trans(a);trans(b);

		for(int i=0;i<n;i++)a[i]=1ll*a[i]*b[i]%mod;

		trans(a);

		for(int inv=qpow(n,mod-2),i=0;i<n;i++)a[i]=1ll*a[i]*inv%mod;

		return a;

	}

}S;

inline void add(int a,int b)

{

	g[++su]=(edge){k[a],b};

	k[a]=su;

}

void dfs(int x)

{

	usd[x]=1;

	for(int y,i=k[x];i;i=g[i].x)if(!usd[(y=g[i].y)])dfs(y);

	for(int i=k[x];i;i=g[i].x)v[sg[g[i].y]]=1;

	for(int i=0;;i++)if(!v[i]){sg[x]=i;break;}

	for(int i=k[x];i;i=g[i].x)v[sg[g[i].y]]=0;

}

int main()

{

	int n=read(),m=read(),inv=qpow(n+1,mod-2),l=0;

	for(int a,b,i=1;i<=m;i++)a=read(),b=read(),add(a,b);

	for(int i=1;i<=n;i++)if(!usd[i])dfs(i);

	m=m;//显然不知道sg函数值域的性质这里直接写m也没有任何问题，复杂度还是可以过

	while((1<<l)<=m)l++;

	m=1<<l;

	poly f(m);

	for(int i=1;i<=n;i++)f[sg[i]]=(f[sg[i]]+inv)%mod;

	S.trans(f);

	for(int i=0;i<m;i++)f[i]=1ll*inv*qpow(1-f[i]+mod,mod-2)%mod;

	S.trans(f);

	cout<<(1-1ll*f[0]*qpow(m,mod-2)%mod+mod)%mod<<"\n";

}