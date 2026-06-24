#include <bits/stdc++.h>

using namespace std;

int32_t main() {

	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int TC; cin >> TC; while (TC--) {

		int N, X; cin >> N >> X;

		map<int, int> cnt;

		for (int i = 0; i < N-1; ++i) {

			int u, v; cin >> u >> v;

			cnt[u]++, cnt[v]++;

		}

		if (cnt[X] == 0 || cnt[X] == 1) cout << "Ayush" << endl;

		else {

			if (N % 2 == 0) cout << "Ayush" << endl; else cout << "Ashish" << endl;

		}

	}

	return 0;

}