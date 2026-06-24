#include<bits/stdc++.h>

#include<unordered_map>

#define ll long long

#define ull unsigned long long

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;



const int inf = 0x3f3f3f3f;

const ll INF = 0x3f3f3f3f3f3f3f3f;

const double eps = 1e-8;

const ll mod = 1000000007;

const int N = 2e5 + 5;



int n, a[N];



int get(int x)

{

	for (int i = 0; i <= 31; i++)

		if ((1ll << i) >= x)

			return (1ll << i) - x;

}



int getdis(int x, int y)

{

	if (x == y)

		return 0;

	if (x < y)

		swap(x, y);

	return getdis(get(x), y) + 1;

}



void solve()

{

	cin >> n;

	for (int i = 1; i <= n; i++)

		cin >> a[i];

	int mx = -1, st1;

	for (int i = 2; i <= n; i++)

	{

		int d = getdis(a[1], a[i]);

		if (mx < d)

		{

			mx = d;

			st1 = i;

		}

	}



	mx = -1;

	ll st2;

	for (int i = 1; i <= n; i++)

	{

		if (i == st1)

			continue;

		int d = getdis(a[st1], a[i]);

		if (mx < d)

		{

			mx = d;

			st2 = i;

		}

	}

	cout << st1 << ' ' << st2 << ' ' << mx << '\n';

}



signed main()

{

	IOS;

	ll t = 1;

	//cin >> t;

	while (t--)

		solve();

	return 0;

}