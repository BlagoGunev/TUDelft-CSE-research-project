/**

 *  - Meet Brahmbhatt

 *  - Hard work always pays off

**/

#include<bits/stdc++.h>

using namespace std;

#define endl "\n"

#define ff first

#define ss second

#define int long long

#define sz(x) (int)(x).size()



const long long INF = 4e18;

const int32_t M = 1e9 + 7;

const int32_t MM = 998244353;



void solve() {

	int n; cin >> n;

	if (n <= 6) {

		cout << 15 << endl;

		return;

	}

	n = (n + 1) / 2;

	if (n % 3 == 0) {

		cout << (n / 3) * 15 << endl;

	} else if (n % 3 == 1) {

		cout << (n / 3 - 1) * 15 + 20 << endl;

	} else {

		cout << (n / 3 - 1) * 15 + 25 << endl;

	}

}



signed main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cout << fixed << setprecision(9);

	int tt = 1;

	cin >> tt;

	while (tt--) solve();

	return 0;

}