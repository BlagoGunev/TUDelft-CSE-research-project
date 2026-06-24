#include "bits/stdc++.h"
using namespace std;
#define int 		long long
using vi 	= 		vector<int>;
using vv 	= 		vector<vi>;
using pi 	= 		pair<int, int>;
using vp 	= 		vector<pi>;

#define nl 			"\n"
#define F 			first
#define S 			second
#define pb 			push_back
#define sz(x) 		(int)x.size()
#define read(x) 	int x; cin >> x
#define all(s) 		s.begin(), s.end()
#define rep(i,a,b) 	for(int i=a;i<=b;i++)
#define rev(i,a,b) 	for(int i=a;i>=b;i--)
#define rdvr(x)    	for(auto &it :x) cin >> it

#ifdef TSUKI
#include "bits/bug.hpp"
#else
#define dbg(...)
#endif

constexpr int MOD = 998244353;
constexpr int INF = 1e18;
constexpr int MXN = 2e5 + 10;

int n;
vi a(MXN);

void サンローラン_ドン() {
	cin >> n;
	a.assign(n, 0);
	rep(i, 0, n - 1) cin >> a[i];
	sort(all(a));
	int ans = 0;
	rev(k , (n + 1) / 2, 1) {
		int t = k, ok  = 1;
		int r = n - 1;
		while (t  && r >= k - 1) {
			if (a[r] > t ) r--;
			else {
				t--;
				r--;
			}
		}
		if (!t)  ans = max(ans, k);

	}
	cout << ans << nl;
}



int32_t main() {
	cin.tie(0); cout.tie(0) -> sync_with_stdio(0);
	int t = 1;
	cin >> t;
	while (t--) {
		サンローラン_ドン();
	}
}