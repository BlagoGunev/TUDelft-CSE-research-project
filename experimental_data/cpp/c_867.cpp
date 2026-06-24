#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
typedef pair<int,int> pii;

int n, m, s[100010];
vector<pii> tempa, tempb;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
struct data
{
	int a;
	int b;
}qaq[100005];
int main()
{
	n=read();m=read();
	ll cnt=0,coua=0,coub=0,ans=0;
	for(int i=0;i<n;i++)
	{
		s[i]=read();qaq[i].a=read();qaq[i].b=read();
		cnt+=s[i];
		if(qaq[i].a>qaq[i].b)
		{
			coua+=s[i];
			ans+=(ll)s[i]*qaq[i].a;
			tempa.push_back(pii(qaq[i].a-qaq[i].b,s[i]));
		}
		else
		{
			coub += s[i];
			ans += (ll)s[i] * qaq[i].b;
			tempb.push_back( pii(qaq[i].b-qaq[i].a, s[i]) );
		}
	}
	sort(tempa.begin(),tempa.end());
	sort(tempb.begin(),tempb.end());
	ll buy=(cnt/m)+(cnt%m?1:0);
	ll buya=(coua/m)+(coua%m?1:0);
	ll buyb=(coub/m)+(coub%m?1:0);
	if(buya+buyb>buy)
	{
		ll changea=coua%m,ansa=ans;
		ll changeb=coub%m,ansb=ans;
		for(int i=0;i<(int)tempa.size()&&changea;i++)
		{
			ll change=min(changea,(ll)tempa[i].second);
			ansa-=(ll)tempa[i].first*change;
			changea-=change;
		}
		for(int i=0;i<(int)tempb.size()&&changeb;i++)
		{
			ll change=min(changeb,(ll)tempb[i].second);
			ansb-=(ll)tempb[i].first*change;
			changeb-=change;
		}
		ans=max(ansa,ansb);
	}
	printf("%lld\n",ans);
	return 0;
}