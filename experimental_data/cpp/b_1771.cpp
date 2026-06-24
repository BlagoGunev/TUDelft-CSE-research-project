#include <iostream>

#include <algorithm>

#include <vector>

#include <string>

#include <queue>

#include <set>

#include <map>

#include <numeric>

using namespace std;

typedef long long ll;



void sol() {

	ll n, m;

	cin >> n >> m;

	vector<ll> MIN(n + 2, n + 1);

	ll ans = 0;

	while (m--) {

		ll a, b;

		cin >> a >> b;

		if (a > b) swap(a, b);

		MIN[a] = min(MIN[a], b);

	}

	for (ll i = n; i > 0; i--) {

		MIN[i] = min(MIN[i], MIN[i + 1]);

		ans += MIN[i] - i;

	}

	cout << ans << '\n';

}

int main() {

	cin.tie(0)->ios::sync_with_stdio(0);

	int T;

	cin >> T;

	while (T--) sol();

}