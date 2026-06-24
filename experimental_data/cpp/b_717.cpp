#include <stdio.h>

#include <string.h>

#include <bitset>

#include <algorithm>

#include <cassert>

#include <vector>

#include <string>

#include <iostream>

#include <set>

#include <map>

#include <numeric>

#include <cmath>

#include <queue>

using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)



typedef long long ll;



ll n,c0,c1;



ll cnk(ll n, ll k)

{

	ll res=1;

	for(int i=1;i<=k;i++)

		res=res*(n-i+1)/i;

	return res;

}



ll count(ll x)

{

	ll res=0;

	for(int j=0;(1<<j)<=n;j++)

	{

		if(x<j*c1) break;

		ll l=(x-j*c1)/c0;

		res+=cnk(j+l+1,j+1);

	}

	return res;

}



ll get_cost(ll x)

{

	ll res=0;

	for(int j=0;(1<<j)<=n;j++)

	{

		if(x<j*c1) break;

		ll l=(x-j*c1)/c0;

		res+=l*(l+1)*cnk(j+l+1,j)/(j+2)*c0+j*c1*cnk(j+l+1,j+1);

	}

	return res;

}





int main()

{

	cin>>n>>c0>>c1;

	if(c0==0 || c1==0)

		printf("%lld\n",(c0+c1)*(n-1));

	else

	{

		if(c0>c1) swap(c0,c1);

		n--;

		ll l=1;

		ll r=1;

		while(count(r)<n)

			r*=2;

		while(l<r)

		{

			ll c=(l+r)/2;

			if(count(c)<n)

				l=c+1;

			else

				r=c;

		}

		ll res=(c0+c1)*n;

		res+=(n-count(r-1))*r;

		res+=get_cost(r-1);

		cout<<res<<endl;

	}

	return 0;

}