#include <bits/stdc++.h>
#define int long long

using namespace std;

const int NR = 20;

int T, n, a[NR], b[NR];
vector < pair < int, int > > res;

inline void mex(int l, int r) {
	if (a[r] == r - l && l != r) {
		mex(l, r - 1);
		return;
	}
	if (a[r]) res.push_back(make_pair(r, r)), a[r] = 0;
	if (l == r) return;
	mex(l, r - 1);
	res.push_back(make_pair(l, r));
	for (int i = l; i <= r; ++i) a[i] = r - l + 1;
	mex(l, r - 1);
}

inline void solve() {
    cin >> n; int ans = 0, msk;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 0; i < (1 << n); ++i) {
		int tot = 0;
		for (int j = 1; j <= n; ++j) {
		    if (i & (1 << j - 1)) b[j] = 1;
			else b[j] = 0;
		}
 		for (int j = 1; j <= n; ) {
			if (!b[j]) {
				tot += a[j], j ++;
				continue;
			}
			int l = j, r;
            for (int k = j; k <= n; ++k) {
				if (!b[k]) break;
				else r = k;
			}
			tot += (r - l + 1) * (r - l + 1), j = r + 1;
		}
		if (tot > ans) ans = tot, msk = i;
	}
	cout << ans << ' ';
	for (int i = 1; i <= n; ++i) {
		if (msk & (1 << i - 1)) b[i] = 1;
		else b[i] = 0;
	}
	for (int i = 1; i <= n; ) {
		if (!b[i]) {
			i ++;
			continue;
		}
        int l = i, r;
        for (int j = i; j <= n; ++j) {
			if (!b[j]) break;
			else r = j;
		}
		mex(l, r), i = r + 1, res.push_back(make_pair(l, r));
	}
	cout << res.size() << '\n';
	for (auto i : res) cout << i.first << ' ' << i.second << '\n';
}

signed main() {
    ios :: sync_with_stdio(false), cin.tie(0);
	T = 1;
	while (T --) solve();
	return 0;
}