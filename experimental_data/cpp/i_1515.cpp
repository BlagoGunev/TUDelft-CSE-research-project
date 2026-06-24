#include <cstdio>

#include <iostream>

#include <algorithm>

using namespace std;

const int M = 200005;

const int N = 800005;

#define int long long

const int inf = 1e18;

int read()

{

	int x=0,f=1;char c;

	while((c=getchar())<'0' || c>'9') {if(c=='-') f=-1;}

	while(c>='0' && c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}

	return x*f;

}

int n,m,k,w[M],v[M],a[M],p[M],id[M];

int sw[N][18],sv[N][18],ex[N][18];

void upd(int i,int x)

{

	for(int j=0;j<18;j++)

	{

		sw[i][j]=sv[i][j]=0;ex[i][j]=inf;

		if(w[x]<(1<<j))

			sw[i][j]+=a[x]*w[x],sv[i][j]+=a[x]*v[x];

		else if(w[x]<(1<<j+1) && a[x])

			ex[i][j]=w[x];

	}

}

void up(int i)

{

	for(int j=0;j<18;j++)

	{

		sw[i][j]=sw[i<<1][j]+sw[i<<1|1][j];

		sv[i][j]=sv[i<<1][j]+sv[i<<1|1][j];

		ex[i][j]=min(ex[i<<1][j],ex[i<<1|1][j]+sw[i<<1][j]);

	}

}

void add(int i,int l,int r,int id,int c)

{

	if(l==r) {a[p[l]]+=c;upd(i,p[l]);return ;}

	int mid=(l+r)>>1;

	if(mid>=id) add(i<<1,l,mid,id,c);

	else add(i<<1|1,mid+1,r,id,c);

	up(i);

}

int ask(int i,int l,int r,int &c)

{

	if(l==r)

	{

		int x=min(a[p[l]],c/w[p[l]]);

		c-=x*w[p[l]];return v[p[l]]*x;

	}

	int mid=(l+r)>>1;

	while(k && (1<<k-1)>c) k--;

	if(sw[i][k]<=c) return c-=sw[i][k],sv[i][k];

	if(sw[i][k-1]<=c && ex[i][k-1]>c)

		return c-=sw[i][k-1],sv[i][k-1];

	return ask(i<<1,l,mid,c)+ask(i<<1|1,mid+1,r,c);

}

signed main()

{

	n=read();m=read();

	for(int i=1;i<=n;i++)

		a[i]=read(),w[i]=read(),v[i]=read(),p[i]=i;

	sort(p+1,p+1+n,[&](int i,int j)

	{return v[i]==v[j]?w[i]<w[j]:v[i]>v[j];});

	for(int i=1;i<=n;i++)

		id[p[i]]=i,add(1,1,n,i,0);

	while(m--)

	{

		int op=read(),x=read();

		if(op==3)

		{

			k=17;

			printf("%lld\n",ask(1,1,n,x));

			continue;

		}

		int y=read();

		add(1,1,n,id[y],(op==1)?x:-x);

	}

}