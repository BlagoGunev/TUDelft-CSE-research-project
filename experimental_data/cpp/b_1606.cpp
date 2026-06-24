#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {

	ll n,k; cin >> n >> k;

	if (k == 1) {

		cout << n-k << '\n';

		return;

	}

	ll res = 1;

	ll d = 0;

	while(res < k) {

		res += res;

		d++;		

	}

	cout << d + (n - res+k-1)/k << '\n';

}

int main() {

	ios_base::sync_with_stdio(0);

	cin.tie(0); cout.tie(0);

	ll t; cin >> t;

	while(t--) {

		solve();

	}

}