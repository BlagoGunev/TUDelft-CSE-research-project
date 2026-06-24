#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;


#define int long long
#define ld long double
#define nl '\n'
#define pb push_back
#define all(v) v.begin(), v.end()
const int inf = 1e9;
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define db(x...)
#endif
// const int mod = 1e9 + 7;
const int N = 2e5 + 10;


typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

/*
pbds A -----------
*A.find_by_order(k)  -- finding Kth element
A.order_of_key(X)  -- number of elements less than X

useful builtin function on bits ---------
__builtin_popcountl(x) -> count number of set bits in x
__builtin_clzll(x) -> count number of leading zeros in x
__builtin_ctzll(x) -> count number of trailing zeros in x

vector storing unique elements in sorted order--------
sort(all(v));
v.resize(unique(all(v)) - v.begin());
n = v.size();

*/


void solve()
{
	int n, x; cin >> n >> x;
	vector<int>a(n);
	for (int &i : a)cin >> i;

	auto f = [&](int k) -> bool {
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] < k)ans += k - a[i];
		}
		return (ans <= x);
	};
	int l = 1; int r = 1e12;
	int ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (f(mid)) {
			l = mid + 1;
			ans = mid;
		}
		else r = mid - 1;
	}
	cout << ans << nl;
}
int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
}