#pragma GCC optimize(3)

#include<bits/stdc++.h>

#define endl "\n"

#define pb push_back

using namespace std;

typedef long long ll;

typedef pair<int,int> PII;

const int mod=998244353;

const int N=2e5+10;

const int inf=0x3f3f3f3f;

const ll INF=0x3f3f3f3f3f3f3f3f;



int t,n,m;

ll a[N];



vector<ll> vec;

void prime(ll s)

{

	vec.clear();

	for(ll i=2;i*i<=s;i++)

	{

		if(s%i==0)

		{

			vec.pb(i);

			while(s%i==0)

				s/=i;	

		}	

	}

	if(s>1)

		vec.pb(s);

	return;	

}



ll k;

ll ss;

void dfs(int cnt,ll sum,int pick)

{

	if(cnt==vec.size())

	{

		if(pick>=1)

		{

			if(pick&1)

			{

				ss+=k/sum;

			}

			else

			{

				ss-=k/sum;

			}

		}

		return;

	}

	dfs(cnt+1,sum,pick);

	dfs(cnt+1,sum*vec[cnt],pick+1);

}



int main()

{

	ios::sync_with_stdio(false);

	cin.tie(0);

	cout.tie(0);

	cin>>t;

	while(t--)

	{

		cin>>n>>m;

		for(int i=1;i<=n;i++)

		{

			cin>>a[i];	

		}

		ll ans=1;

		bool f=1;

		for(int i=2;i<=n;i++)

		{

			if(a[i]==a[i-1])

			{

				ans=(ans*(m/a[i]))%mod;

				continue;	

			}

			if(a[i-1]%a[i]!=0)

			{

				f=0;

				break;	

			}

			prime(a[i-1]/a[i]);

			ss=0;

			k=m/a[i];

			dfs(0,1,0);

			ans=(ans*(k-ss))%mod;		

		} 

		if(!f)

		{

			cout<<0<<endl;

			continue;	

		}

		cout<<ans<<endl;		

	}

	return 0;

}