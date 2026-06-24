#include <cstdio>

#include <iostream>

#include <algorithm>

using namespace std;

const int M = 500005;

#define int long long

int read()

{

	int x=0,f=1;char c;

	while((c=getchar())<'0' || c>'9') {if(c=='-') f=-1;}

	while(c>='0' && c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}

	return x*f;

}

int T,n,ans,a[M],b[M],c[M];

void add(int x)

{

	for(int i=x;i<=n;i+=i&(-i)) b[i]++;

}

int ask(int x)

{

	int r=0;

	for(int i=x;i>0;i-=i&(-i)) r+=b[i];

	return r;

}

void work()

{

	n=read();ans=0;

	for(int i=1;i<=n;i++) a[i]=read(),b[i]=0;

	for(int i=1;i<=n;i++)

	{

		int d=ask(a[i]);

		ans+=i-1-d;c[i]=i-1-2*d;

		add(a[i]);

	}

	for(int i=1;i<=n;i++) b[i]=0;

	for(int i=n;i>=1;i--)

		c[i]-=2*ask(a[i]),add(a[i]);

	sort(c+1,c+1+n,greater<int>());

	printf("%lld ",ans);

	for(int i=1;i<=n;i++)

	{

		ans-=c[i]+(i-1);

		printf("%lld ",ans);

	}

	puts("");

}

signed main()

{

	T=read();

	while(T--) work();

}