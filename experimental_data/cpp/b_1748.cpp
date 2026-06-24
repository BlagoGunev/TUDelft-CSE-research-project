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
string s;

void サンローラン_ドン() {
	cin >> n >> s;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		vi cnt(10, 0);
		int mx = 0, dis = 0;
		for (int j = i; j <= i + 99  && j < n ; j++) {
			int x = s[j] - '0';
			cnt[x]++;
			mx = max(mx, cnt[x]);
			if (cnt[s[j] - '0'] == 1) {
				dis++;
			}
			if (mx <= dis) ans++;
			// if (dis > 10) break;
		}
		// dbg(mp);
	}
	cout << ans << nl;
}



int32_t main() {
	cin.tie(0); cout.tie(0) -> sync_with_stdio(0);
	int t = 1;
	cin >> t;
	while (t--) {
		// cout << "TEST : --->" << nl;
		サンローラン_ドン();
	}
}