#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <vector>

#include <algorithm>

#include <cmath>

#include <bitset>

#include <set>

#include <map>

#include <unordered_set>

#include <unordered_map>

#include <queue>

#include <stack>

#include <iomanip>

#include <string>

#include <cstring>

#include <tuple>

#include <random>

#include <chrono>

#include <numeric>

#include <limits.h>



using namespace std;



typedef long long ll;

typedef double db;

typedef pair<int, int> pii;



mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



#define rand() rng()

#define All(x) x.begin(), x.end()

#define rAll(x) x.rbegin(), x.rend()

#define Sum(x) accumulate(All(x), 0)

#define X first

#define Y second



void solve() {

	int n;

	cin >> n;

	vector<int> a(n);

	for (int i = 0; i < n; i++)

		cin >> a[i];

	if (n > 60) {

		cout << 1 << '\n';

		return;

	}

	int ans = n;

	for (int i = 0; i < n-1; i++) {

		for (int l = 0; l <= i; l++) {

			for (int r = 0; r < n - 1 - i; r++) {

				int f = 0, g = 0;

				for (int j = i - l; j <= i; j++)

					f ^= a[j];

				for (int j = i + 1; j <= i + 1 + r; j++)

					g ^= a[j];

				if (f > g)

					ans = min(ans, l + r);

			}

		}

	}

	cout << (ans == n ? -1 : ans) << '\n';

}



signed main()

{

	ios::sync_with_stdio(0);

	cin.tie(0), cout.tie(0);



	solve();

}



/* stuff you should look for

	* int overflow, array bounds

	* special cases (n=1?)

	* do smth instead of nothing and stay organized

	* WRITE STUFF DOWN

	* DON'T GET STUCK ON ONE APPROACH

*/