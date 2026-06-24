/*

	JAI JAGANNATH!

*/

//@Author : zanj0



#include<bits/stdc++.h>

using namespace std;



#define int 			long long int



#define ff              first

#define ss              second

#define pb              push_back

#define MOD             1000000007

#define inf             1e18

#define ps(x,y)         fixed<<setprecision(y)<<x

#define w(x)            int x; cin>>x; while(x--)

#define endl       		"\n"

#define timetaken cerr<<"Time : "<<1000*(long double)clock()/(long double)CLOCKS_PER_SEC<<"ms\n"



void zanj0()

{

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifdef LOCAL

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif

}

void Solve() {

	int n, k;

	cin >> n >> k;

	map<int, int> start, last;

	for (int i = 0, x; i < n; i++) {

		cin >> x;

		if (!start.count(x)) {

			start[x] = i;

		}

		last[x] = i;

	}

	for (int i = 0, a, b; i < k; i++) {

		cin >> a >> b;

		cout << (start.count(a) && last.count(b) && start[a] < last[b] ? "YES" : "NO") << endl;

	}

}

int32_t main()

{

	zanj0();

	w(t) Solve();

	timetaken;

	return 0;

}