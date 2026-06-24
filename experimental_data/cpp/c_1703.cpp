#include <bits/stdc++.h>

using namespace std;



#define sz(x) (int)(x).size()

#define all(x) (x).begin(), (x).end()

#define cnt(x, y) count(all(x), y)

#define sq(x) ((x) * (x))

#define F first

#define S second



#define YES cout << "Yes\n"

#define NO cout << "No\n"

#define BAD cout << "-1\n"

#define ENDL cout << '\n'

#define EXIT(x) return (cout << (x) << '\n', 0)



using ll = long long;

using pi = pair<int, int>;

using pl = pair<ll, ll>;

using ti = tuple<int, int, int>;

using tl = tuple<ll, ll, ll>;



const int MAX = 2e5 + 5;

const int INF = 2e9;

const ll LINF = 9e18;

const ll MOD = 998244353;

const int dy[9] = { -1, 0, 1, 0, -1, 1, 1, -1, 0 };

const int dx[9] = { 0, 1, 0, -1, 1, 1, -1, -1, 0 };



int solve() {

	int n; cin >> n;

	vector<int> v(n);

	for (auto& i : v) cin >> i;

	for (int i = 0; i < n; i++) {

		int b; string s;

		cin >> b >> s;

		reverse(all(s));

		for (auto& j : s) {

			if (j == 'U') v[i] = (v[i] - 1 + 10) % 10;

			else v[i] = (v[i] + 1) % 10;

		}

	}

	for (auto& i : v) cout << i << ' ';

	cout << '\n'; return 0;

}



int main() {

	cin.tie(0);

	ios_base::sync_with_stdio(0);



	int t = 1; cin >> t;

	while (t--) solve();

	return 0;

}