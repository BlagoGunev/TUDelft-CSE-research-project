#include <bits/stdc++.h>

using namespace std;

#define pb push_back

#define ub upper_bound

#define lb lower_bound

#define ll long long

#define ld long double

#define pii pair<ll, ll>

typedef __int128 lll;

typedef vector<ll> vi;

typedef vector<vi> vvi;

typedef vector<pii> vpi;

typedef set<ll> si;

typedef map<ll, ll> mii;

#define all(value) value.begin(), value.end()

const int M = 1e9 + 7;



//..................................................................



void solve()

{

	ll n;

	cin >> n;

	vi v(n);

	for (int i = 0; i < n; i++)

	{

		cin >> v[i];

	}

	if(n==1)

	{

		cout<<"0"<<endl;

		return;

	}

	si s;

	ll ind = -1;

	for (int i = n - 2; i >= 0; i--)

	{

		if (v[i] > v[i + 1])

		{

			ind = i;

			break;

		}

	}

	for (int i = 0; i <= ind; i++)

	{

		s.insert(v[i]);

	}

	// cout<<"ss"<<" "<<s.size()<<endl;

	bool check=false;

	for (int i = n-1; i >ind; i--)

	{

		ll curr=v[i];

		if(check)

		{

			s.insert(v[i]);

		}

		if (s.count(curr) && check==false)

		{

			check =true;

		}

	}

	cout<<s.size()<<endl;

}



int main()

{

	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif



	ll t = 1;

	cin >> t;

	while (t--)

	{

		solve();

	}

}