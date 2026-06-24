#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll s[100005];
ll n,sum,ans;
ll pd(ll x)
{
	if(x==0)
        return 1;
	priority_queue<ll> q;
	ll p=0;
	for(ll i=1;i<=n;i++)
	{
		if(q.size()<x)
		{
			q.push(s[i]+i*x);
			p+=s[i]+i*x;
		}
    else
        {
			if(q.top()>s[i]+i*x)
			{
				p-=q.top();
				q.pop();
				q.push(s[i]+i*x);
				p+=s[i]+i*x;
			}
		}
	}
	if(p<=sum)
	{
		ans=p;
		return 1;
	}
	return 0;
}
int main()
{
	scanf("%lld%lld",&n,&sum);
	for(ll i=1;i<=n;i++)
    {
		scanf("%lld",s+i);
	}
	ll l=0,r=n;
	while(l<r)
	{
		ll mid=(l+r+1)>>1;
		if(pd(mid))
		    l=mid;
		else r=mid-1;
	}
	cout<<l<<" "<<ans<<endl;
	return 0;
}