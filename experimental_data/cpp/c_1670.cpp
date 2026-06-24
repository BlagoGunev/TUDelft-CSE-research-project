#include "bits/stdc++.h"

using namespace std;

#define int long long

#define endl "\n"

int mod = 1e9 + 7;



void solv() {

	int n, ans = 1;

	cin >> n;

	vector<int> a(n), b(n), c(n), pa(n);

	for (int &x : a) {

		cin >> x;

		--x;

	}

	for (int &x : b) {

		cin >> x;

		--x;

	}

	for (int &x : c) {

		cin >> x;

		--x;

	}

	for (int i = 0; i < n; ++i) {

		pa[a[i]] = i;

	}

	vector<bool> vis(n);

	for (int i = 0; i < n; ++i) {

		if (vis[i] == false) {

			if (c[i] != -1) {

				for (int j = i; !vis[j]; j = pa[b[j]]) {

					vis[j] = true;

				}

			}

		}

	}

	for (int i = 0; i < n; ++i) {

		if (vis[i] == false) {

			if (c[i] == -1) {

				if (a[i] != b[i]) {

					ans *= 2;

					ans %= mod;

				}

			}

		}

		for (int j = i; !vis[j]; j = pa[b[j]]) {

			vis[j] = true;

		}

	}

	cout << ans << endl;

}



int32_t main() {

	cin.tie(nullptr)->sync_with_stdio(false);

	int t;

	cin >> t;

	while (t--) {

		solv();

	}



	return 0;

}