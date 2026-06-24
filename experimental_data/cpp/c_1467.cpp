#include <bits/stdc++.h>

#include <unordered_set>

#include <unordered_map>

#include <array>

using namespace std;

#define pb push_back

#define all(x) (x).begin(), (x).end()

#define allr(x) (x).rbegin(), (x).rend()

#define fi first

#define se second

#define mp make_pair

#define ll long long

#define ui unsigned

#define ull unsigned long long

#define ld long double

#define puu pair<unsigned, unsigned>

#define pld pair<ld, ld>

#define pll pair<ll, ll>

#define pii pair<int, int>

#define pli pair<ll,int>

#define __builtin_popcount __popcnt

#define forn(i, n) for (int i = 0; i < int(n); i++)

const int MOD = 1e9 + 7;



void solve() {

	int n1, n2, n3; cin >> n1 >> n2 >> n3;

	ll sum1 = 0, sum2 = 0, sum3 = 0;

	int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX;

	forn(i, n1 + n2 + n3) {

		int x; cin >> x;

		if (i < n1) {

			sum1 += x;

			min1 = min(min1, x);

		}

		else if (i < n1 + n2) {

			sum2 += x;

			min2 = min(min2, x);

		}

		else {

			sum3 += x;

			min3 = min(min3, x);

		}

	}



	ll ans = sum1 + sum2 + sum3 - min(2LL * (min1 + min2 + min3 - max({ min1,min2,min3 })), 2 * min({ sum1, sum2, sum3 }));

	cout << ans << endl;

}



int main() {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



	/*FILE* s;

	freopen_s(&s, "ts1_input.txt", "r", stdin);*/

	//int t; cin >> t;

	//for (int i = 1; i <= t; ++i) {

	//    //cout << "Case #" << i << ": ";

	//    solve();

	//}

	solve();

	/*fclose(stdin);*/

}