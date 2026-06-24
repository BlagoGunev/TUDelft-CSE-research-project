// LUOGU_RID: 95416964
#include <bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;++i)

#define fd(i,a,b) for(int i=a;i>=b;--i)

#define max(a,b) ((a)>(b)?(a):(b))

#define min(a,b) ((a)<(b)?(a):(b))

using namespace std;

#define LL unsigned long long

mt19937_64 rd(time(0));

LL read()

{

	LL X=0,w=0;char ch=0;

	while(!isdigit(ch))w|=ch=='-',ch=getchar();

	while(isdigit(ch))X=(X<<3)+(X<<1)+(ch^48),ch=getchar();

	return w?-X:X;

}

LL nu[500005];

pair<LL,LL> zt[500005];

LL gcd(LL x,LL y)

{

	if(!y)return x;

	return gcd(y,x%y);

}

void solve()

{

	int n=read(),m=read();

	fo(i,1,n)nu[i]=rd(),zt[i]={0,read()};

	fo(i,1,m)

	{

		int x=read(),y=read();

		zt[y].first+=nu[x];

	}

	sort(zt+1,zt+n+1);

	LL ans=0;

	fo(i,1,n)

	{

		int j=i;

		LL su=0;

		while(zt[j].first==zt[i].first)su+=zt[j++].second;

		i=j-1;

		if(zt[i].first)ans=gcd(ans,su);

	}

	printf("%llu\n",ans);

}

int main()

{

	int T=read();

	while(T--)solve();

	return 0;

}