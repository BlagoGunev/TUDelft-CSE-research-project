#include <bits/stdc++.h>

#define pb push_back

#define fi first

#define se second

using namespace std;

typedef vector<int> vi;

typedef vector<vi> vvi;

typedef pair<int, int> ii;

typedef vector<ii> vii;

typedef long long ll;

typedef vector<ll> vll;

typedef vector<vll> vvll;

typedef double ld;

void sol()

{

	int n;

	cin>>n;

	string s;

	cin>>s;

	vi a(n+1);

	for(int i=1; i<n+1; i++)

	{

		cin>>a[i];

	}

	ll ans =1;

	vi vis(n+1, 0);

	for(int i=1; i<=n; i++)

	{

		if(vis[a[i]]==1)continue;

		int x = a[i];

		string t;

		ll count = 0;

		while(vis[x]!=1)

		{

			vis[x]=1;

			t.pb(s[x-1]);

			x = a[x];

			count++;

		}

		string g;

		for(int j=0; j<t.size()/2; j++)

		{

			g.pb(t[j]);

			int l = g.size();

			if(t.size()%l!=0) continue;

			int r = 0;

			bool flag =0;

			for(int k=j+1; k<t.size(); k++)

			{

				r= r%l;

				if(t[k]!=g[r])

				{

					flag =1;

					break;

				}

				r++;

			}

			if(!flag)

			{

				count = l;

				break;

			}

		}

		ans = (ans*count)/__gcd(ans, count);

	}

	cout<<ans<<"\n";

}

int main()

{

    ios::sync_with_stdio(false);

    cin.tie(0);

    int t;

    cin>>t;

    while(t--)

    {

    	sol();

	}

    return 0;

}