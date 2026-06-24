#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 998244353;
const int M = 200005;

int n, m;
int l, r;
vector<int> segs[M];
int sl[M], sr[M];
ll f[2 * M], inv_f[2 * M];

ll fast_expo(ll a, ll n) {
	ll b = 1;
	while (n) {
		if (n & 1) b = b * a % MOD;
		a = a * a % MOD;
		n >>= 1;
	} 
	return b;
}

void init() {
	for (int i = 0; i < 2 * M; i++) {
		if (i == 0) f[i] = 1;
		else f[i] = f[i - 1] * i % MOD;
		inv_f[i] = fast_expo(f[i], MOD - 2);
	}
}

ll C(int n, int k) {
	return f[n] * inv_f[k] % MOD * inv_f[n - k] % MOD;
}

ll catalan(int n) {
	return (C(2 * n, n) - C(2 * n, n + 1) + MOD) % MOD;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> l >> r;
		segs[i] = {l, r};
	}
	sort(segs, segs + m);
	for (int i = 0; i < m; i++) {
		if (segs[i][0] == segs[i][1]) continue;
		sl[segs[i][0]]++;
		sr[segs[i][1]]++;
	}
	vector<int> st;
	st.push_back(0);
	ll ans = 1;
	for (int i = 1; i <= n; i++) {
		while (sr[i]) st.back()++, ans = ans * catalan(st.back()) % MOD, st.pop_back(), sr[i]--, st.back()--;
		st.back()++;
		while (sl[i]) st.push_back(0), sl[i]--;
	}
	ans = ans * catalan(st.back() - 1) % MOD;
	cout << ans << endl;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	init();
	
	int yt = 1;
	cin >> yt;
	while (yt--) {
		solve();
	}
	
	return 0;
}