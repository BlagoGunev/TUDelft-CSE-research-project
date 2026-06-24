#include <bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#define N 100005
#define ll long long
using namespace std;
int n,m,x,i,c[N],ok[N];ll Ans,sum;
inline int read()
{
	char c=getchar();int t=0;for(;c<48||c>57;c=getchar());
	for(;c>47&&c<58;c=getchar())t=(t<<1)+(t<<3)+c-48;return t;
}
int main()
{
	n=read();m=read();
	for(i=1;i<=n;i++)
		c[i]=read(),sum+=c[i];
	for(i=1;i<n;i++)
		Ans+=c[i]*c[i+1];
	Ans+=c[n]*c[1];
	for(i=1;i<=m;i++)
	{
		x=read();
		ok[x]=1;
	}
	for(i=1;i<=n;i++)
		if (ok[i])
		{
			ll rest=sum-c[i];
			if (i==1)
			{
				rest-=c[n];
				rest-=c[2];
			}
			else
			if (i==n)
			{
				if (!ok[1])
					rest-=c[1];
				if (!ok[n-1])
					rest-=c[n-1];
			}
			else
			{
				if (!ok[i-1])
					rest-=c[i-1];
				rest-=c[i+1];
			}
			Ans+=rest*c[i];
			sum-=c[i];
		}
	printf("%lld\n",Ans);
	return 0;
}