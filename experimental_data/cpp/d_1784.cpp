// LUOGU_RID: 101785350
#include <cstdio>

#include <cmath>

#include <iostream>

#include <cstring>

#include <algorithm>

#include <queue>

#include <vector>

#include <map>

#include <unordered_map>

#define ll long long

#define reg register

#define fo(a,b,c) for(reg ll a=b;a<=c;a++)

#define re(a,b,c) for(reg ll a=b;a>=c;a--)

#define pb push_back

#define mp make_pair

#define pii pair<ll,ll>

#define fi first

#define se second

#define mod 998244353

using namespace std;

inline ll gi(){

    ll x = 0, f = 1;

    char ch = getchar();

    while(ch < '0' || ch > '9'){

        if (ch == '-')

            f = -1;

        ch = getchar();

    }

    while(ch >= '0' && ch <= '9'){

        x = (x<<1) + (x<<3) + (ch^48);

        ch = getchar();

    }

    return x * f;

}

ll _=1;

ll dp[3][2000005],sum[3][2000005],fac[2000005],ifac[2000005];

ll ksm(ll a,ll b)

{

	ll c=1;

	while(b)

	{

		if(b&1) c=c*a%mod;

		a=a*a%mod;

		b/=2;

	}

	return c;

}

ll C(ll a,ll b)

{

    if(a<b) return 0;

	return fac[a]*ifac[b]%mod*ifac[a-b]%mod;

}

void sol()

{

	ll n=gi();

	fac[0]=1;

	fo(i,1,(1<<n))

	{

		sum[0][i]=1;

		fac[i]=fac[i-1]*i%mod;

	}

	ifac[(1<<n)]=ksm(fac[(1<<n)],mod-2);

	re(i,(1<<n)-1,0)

	{

		ifac[i]=ifac[i+1]*(i+1)%mod;

	}

	sum[0][0]=1;

	dp[0][0]=1;

	fo(i,1,n)

	{

		fo(j,0,(1<<n))

		{

			sum[(i&1)][j]=0;

		}

		fo(j,1,(1<<n))

		{

			ll z=1<<n;

			ll zz=1<<(n-i);

			z=z-zz-j;

			dp[(i&1)][j]=sum[((i&1)^1)][j-1]*fac[(1<<(n-i))]%mod*2%mod*C(z,zz-1)%mod;

			sum[(i&1)][j]=dp[(i&1)][j]+sum[(i&1)][j-1];

			sum[(i&1)][j]%=mod;

		}

	}

	fo(i,1,1<<n)

	{

//		cout<<i<<" ";

		cout<<sum[(n&1)][i-1]<<"\n";

	}

}

int main()

{

//	_=gi();

	while(_--)

	{

		sol();

//		printf("\n");

	}

	return 0;

}