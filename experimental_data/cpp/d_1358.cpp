#pragma GCC optimize("O3", "unroll-loops") // "Ofast" 	

#pragma GCC target("avx2", "bmi", "bmi2", "lzcnt", "popcnt") 



#include <bits/stdc++.h>



#define int long long

#define vt vector

#define pb push_back

#define all(x) (x).begin(), (x).end()

#define sz(x) (int)(x).size()

#define f first

#define s second

#define dbg(x) cerr << #x << " = " << x << '\n'

#define bit(x, i) ((x) >> (i) & 1)



using namespace std;

using ll = long long;

using ld = long double;

using pii = pair<int, int>;



const int N = 1e6 + 5, mod = 1e9 + 7;

const ll inf = 1e18 + 7;

const ld eps = 1e-6;



int n, k, a[N], p[N], kol[N];



int get (int x) {

	int l = 1, r = x, ans = 1;

	while (l <= r) {

		int mid = l + r >> 1;

		if (p[x] - p[mid - 1] >= k) ans = mid, l = mid + 1;

		else r = mid - 1;

	}

	return ans;

}



void solve () {

	cin >> n >> k;

	for (int i = 1; i <= n; i++) cin >> a[i], a[n + i] = a[i];

	for (int i = 1; i <= n * 2; i++) p[i] = p[i - 1] + a[i], kol[i] = kol[i - 1] + (a[i] * (a[i] + 1) / 2);

	int ans = 0;

	for (int i = 1; i <= n * 2; i++) {

		int pos = get(i), res = kol[i] - kol[pos - 1], x = a[pos] - (k - (p[i] - p[pos]));

		if (x > 0) res -= x * (x + 1) / 2;

		ans = max(ans, res);

	}

	cout << ans;

	cout << '\n';

}



bool testcases = 0;



signed main() {

#ifndef ONLINE_JUDGE

	freopen(".in", "r", stdin);

	freopen(".out", "w", stdout);

#endif

	cin.tie(0) -> sync_with_stdio(0);

	int test = 1;

	if (testcases) cin >> test;

	for (int cs = 1; cs <= test; cs++) {

		solve();

	}

}