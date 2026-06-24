#include <bits/stdc++.h>

#include <string>

using namespace std;

#define ll long long

#define endl '\n'

#define f(x) for(auto &x:x)

#define w(x) while (x--)

#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL)

#define TT int t;cin>>t;while(t--)

#define soort(x) sort(x.begin(),x.end())

int main()

{

	fast;

	TT{

		ll n,m;

	cin >> n >> m;

	if (m > n)swap(n, m);

	ll sum = (n / 3) * m + (n % 3 * (m / 3));

	sum += min(m % 3, n % 3);

	cout << sum << endl;



	}

}

/*

*







*/