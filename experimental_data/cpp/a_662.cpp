#include <bits/stdc++.h>
#include<cstdio>

using namespace std;

typedef long long ll;

const ll N=500500;

ll i,j,k,n,sum,ch,t,ans,num;

ll a[N],b[N],c[N];

void R(ll &x)

{

	x=0;ch=getchar();

	while (ch<'0' || '9'<ch) ch=getchar();

	while ('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();

}

int main()

{

	R(n);

	for (i=1;i<=n;i++)

	{

		R(a[i]);R(b[i]);

		c[i]=a[i]^b[i];

		sum^=a[i];

	}

	k=60;

	for (i=1;i<=n;i++)

	{

		for (j=i+1;j<=n;j++) if (c[i]<c[j]) t=c[i],c[i]=c[j],c[j]=t;

		if (!c[i]) break;

		while (!(c[i]&1ll<<k)) k--;

		for (j=i+1;j<=n;j++) if (c[j]&1ll<<k) c[j]^=c[i];

	}

	num=i-1;

	ans=1ll<<num;

	j=60;

	for (i=1;i<=num;i++)

	{

		while (!(c[i]&1ll<<j)) j--;

		if (sum&1ll<<j) sum^=c[i];

	}

	if (sum) puts("1/1");

	else printf("%lld/%lld\n",ans-1,ans);

}