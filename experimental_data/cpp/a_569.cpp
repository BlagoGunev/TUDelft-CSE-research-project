#include <bits/stdc++.h>



#define sz(s) s.size()

#define sr(s) sort(s.begin(), s.end())

#define rs(s) reverse(s.begin(), s.end())

#define ar(a, n) sort(a + 1, a + n + 1)

#define ra(a, n) reverse(a + 1, a + n + 1)

#define solved exit(0);

#define S second

#define F first



typedef long long ll;



using namespace std;



const int N = 1e5 + 15;

const int LL = 1e9 + 15;

const int SSS = 1e6 + 15;



int t, s, q, ct;



main()

{

	cin >> t >> s >> q;

	while (s < t)

	{

		++ct;

		s *= q;

	}

	cout << ct;

    return 0;

}