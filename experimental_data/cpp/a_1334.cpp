#include<bits/stdc++.h>

using namespace std;



const int maxn = 2e5 + 20;



#define TLE std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

#define endl "\n"

#define int long long

#define P pair<int, int>



int n;

struct Node {

	int x, y;

} t[maxn];



void solve() {

	cin >> n;



	for (int i = 1; i <= n; i ++) {

		int l, r;

		cin >> l >> r;

		t[i] = {l, r};

	}

	int r1 = t[1].x, r2 = t[1].y;

	if (r1 < r2) {

		cout << "NO\n";

		return ;

	}

	for (int i = 2; i <= n; i ++) {

		int x = t[i].x, y = t[i].y;

		int res1 = x - r1, res2 = y - r2;

		if (res1 < res2 || res1 < 0 || res2 < 0) {

			cout << "NO\n";

			return ;

		}

		if (y > x) {

			cout << "NO\n";

			return ;

		}

		r1 = x, r2 = y;

	}

	cout << "YES\n";

}



signed main() {

	TLE;

	int T = 1;

	cin >> T;



	while (T --) {

		solve();

	}



	return 0;

}