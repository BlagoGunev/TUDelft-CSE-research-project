#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long 
#define MN 200005
#define INF 0x7FFFFFFF
using namespace std;
ll a[MN],sum,ans;
int n;
bool u;

inline int read()
{
	int n=0,f=1; char c=getchar();
	while (c<'0' || c>'9') {if(c=='-')f=-1; c=getchar();}
	while (c>='0' && c<='9') {n=n*10+c-'0'; c=getchar();}
	return n*f;
} 

int main()
{
	register int i;
	n=read();
	for (i=1;i<=n;++i) {a[i]=read(); a[i-1]=abs(a[i]-a[i-1]);}
	sum=0;
	for (i=1,u=0;i<n;++i,u^=1)
	{
		sum+=a[i]*(u?-1:1);
		if (sum<0) sum=0; else ans=max(ans,sum);
	}
	sum=0;
	for (i=2,u=0;i<n;++i,u^=1)
	{
		sum+=a[i]*(u?-1:1);
		if (sum<0) sum=0; else ans=max(ans,sum);
	}
	printf("%lld",ans); 
}