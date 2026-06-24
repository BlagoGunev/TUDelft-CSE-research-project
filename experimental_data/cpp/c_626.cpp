#include <iostream>

#include <cstring>

using namespace std;

typedef long long ll;

int n,m;

const long long inf=6e6;

bool check(ll x)

{

	//最大数x之前 至少有n个2的倍数,m个3的倍数

	if(x/2<n||x/3<m||(x/2+x/3-x/6)<n+m)//2 3倍数集合个数不小于为n+m 

	return false;

	else

	return true;

}

int main()

{

	cin>>n>>m;

	ll ans;

	ll l=0,r=inf;

	while(l<=r)

	{

		ll mid=(l+r)/2;

		if(check(mid))

		{

			r=mid-1;

			ans=mid;		

		}

		else

		l=mid+1;

	}

	cout<<ans<<endl;

	return 0;

}