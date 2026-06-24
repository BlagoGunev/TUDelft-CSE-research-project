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

	vector<int> v(n);

	for (int i = 0; i < n; i++) {

		cin >> v[i];

	}



	vector<int> H = {0};

	for (int i = 0; i < n; i++) {

		if (i & 1) H.push_back(H.back() - v[i]);

		else H.push_back(H.back() + v[i]);

	}



	int ans = 0;

	for (int i = 0; i < sz(H) - 1; i++) {

		if (H[i] < H[i + 1]) {

			int mn = H[i + 1];

			for (int j = i + 1; j < sz(H) - 1; j++) {

				mn = min(mn, H[j]);

				if (H[j] > H[j + 1]) {

					ans += max(0ll, mn - max(H[i], H[j + 1]) + 1);

					if (j == i + 1) ans--;

				}

			}

		}

	}

	cout << ans << endl;

}



signed main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cout << fixed << setprecision(9);

	int tt = 1;

	// cin >> tt;

	while (tt--) solve();

	return 0;

}