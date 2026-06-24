#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define ld long double

#define boost ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)

#define all(x) x.begin(),x.end()

#define pb push_back

#define endl '\n'

#define fi first

#define se second

#define sz size()

#define mp make_pair

const ll MOD = 1e9 + 7;

ll n, a[200010], k;

int main()

{

	boost;

	ll t;

	cin >> t;

	while (t--) {

		cin >> n >> k;

		map<ll, ll> m;

		for (ll i = 0; i < n; i++) {

			cin >> a[i];

			m[a[i]]++;

		}

		vector<ll> v;

		for (auto x : m) {

			if (x.se >= k) {

				v.pb(x.fi);

			}

		}

		if (v.sz == 0) {

			cout << -1 << endl;

			continue;

		}

		sort(all(v));

		ll la = v[0], ra = v[0], mx = -1, l = v[0];

		bool ok = false;

		for (ll i = 0; i < v.sz-1; i++) {

			if (v[i + 1] - v[i] == 1) {

				if (v[i + 1] - l > mx) {

					la = l;

					ra = v[i + 1];

					mx = ra - la;

				}

			}

			else {

				l = v[i + 1];

			}

		}

		cout << la << ' ' << ra << endl;

	}

	return 0;

}