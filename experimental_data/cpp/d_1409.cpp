#include <bits/stdc++.h>

using namespace std;



typedef long long ll;

typedef pair<ll, ll> pll;

typedef pair<int, int> pii;



const int N = 5e5 + 100, mod = 1e9 + 7;

const int inf = 1e9;

const ll lnf = 1e18;



#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout)

#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define SP cout << setprecision(10);

#define all(x) (x).begin(), (x).end()

#define sz(x) int((x).size())

#define mp make_pair

#define pb push_back

#define fndl '\n'

#define S second

#define F first



ll t, n, s;



int dsum(ll num) {

	int ans = 0;

	while (num > 0) ans += num % 10, num /= 10;

	return ans;

}



int main () {

	fast_io;

	cin >> t;

	while (t --) {

		cin >> n >> s;

		if (dsum(n) <= s) {

			cout << 0 << fndl;

			continue;

		}

		ll cn = n, a = 1, ans = lnf;

		while (cn > 0) {

			if (dsum(1ll * (cn + 1) * a) <= s) {

				ans = 1ll * (cn + 1) * a - n;

				break;

			}

			a *= 10;

			cn /= 10;

		}

		if (dsum(1ll * (cn + 1) * a) <= s) ans = min(ans, 1ll * (cn + 1) * a - n);

		cout << ans << fndl;

	}

	cout << endl;

	return 0;

}