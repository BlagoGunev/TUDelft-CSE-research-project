//InTheNameOfGOD

//PRS;)

#pragma GCC optimize("unroll-loops")

#pragma GCC target("avx2")

#include<bits/stdc++.h>

#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define rep(i, l, r) for(ii i = l; i < r; i++)

#define per(i, l, r) for(ii i = r - 1; i >= l; i--)

#define min(x, y) (x < y ? x : y)

#define max(x, y) (x > y ? x : y)

#define pb push_back

#define X first

#define Y second

typedef long long ll;

typedef int ii;

using namespace std;

constexpr ii xn = 45;

ll d[xn], l[xn], r[xn];

ii main()

{

	Fast;

	ii t;

	cin >> t;

	while(t--)

	{

		vector<ll> ps, pt;

		string s, t;

    	ii n;

		cin >> n >> s >> t;

    	if(s[0] != t[0] || s[n - 1] != t[n - 1])

		{

        	cout << "-1\n";

        	continue;

    	}

    	rep(i, 0, n - 1)

    	{

        	if(s[i] != s[i + 1]) ps.pb(i);

        	if(t[i] != t[i + 1]) pt.pb(i);

    	}

    	if(ps.size() != pt.size())

		{

        	cout << "-1\n";

        	continue;

    	}

        ii k = ps.size();

        ll ans = 0;

        rep(i, 0, k) ans += abs(ps[i] - pt[i]);

       	cout << ans << '\n';

    }

}