#include <bits/stdc++.h>

using namespace std;

#include <cstdio>
inline int RD()
{
	int res;char cr;
	while( (cr=getchar())<'0' || cr>'9'); res=cr-'0';
	while( (cr=getchar())>='0' && cr<='9') res=res*10+cr-'0';
	return res;
}

#define N 100050
#define Min(a,b) (a<b?a:b)
int a[N];
int main()
{
	int n,k;n=RD();k=RD();
	for(int i=1;i<=n;i++)
		a[i]=RD();
	int mn=a[1];
	for(int i=1;i<=n;i++)
		mn=Min(mn,a[i]);
	for(int i=1;i<=n;i++)
		a[i]-=mn;
	long long ans=0;
	bool failed=0;
	for(int i=1;i<=n;i++)
		if(a[i]%k==0)
			ans+=a[i]/k;
		else failed=1;
	if(failed) puts("-1");
	else printf("%lld\n",ans);
}