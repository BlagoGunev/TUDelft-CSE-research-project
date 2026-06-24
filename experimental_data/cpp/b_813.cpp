#include <bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
LL x,y,l,r;
LL a[5006];
main()
{
	scanf("%lld%lld%lld%lld",&x,&y,&l,&r);
	LL t=1,p=1;
	int cnt=0;
	for (int i=0;;++i)
	{
		p=1;
		for (int j=0;p<=r-t;++j)
		{
			if (l<=p+t) a[++cnt]=p+t;
			if (p>(r-t)/y) break;
			p*=y;
		}
		if (t>r/x) break;
		t*=x;
	}
	sort(a+1,a+cnt+1);
	cnt=unique(a+1,a+cnt+1)-a-1;
	LL ans=0;
	if (!cnt) return printf("%lld\n",r-l+1),0;
	ans=max(a[1]-l,ans);
	ans=max(r-a[cnt],ans);
	for (int i=2;i<=cnt;++i) ans=max(ans,a[i]-a[i-1]-1);
	printf("%lld\n",ans); 
}