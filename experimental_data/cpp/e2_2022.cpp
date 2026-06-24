#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 210000;
const int T = 30;
const int MOD = (int)(1e9+7);

struct dsu {
	vector<int> p, t, s;
	int comp;
	bool can;
	dsu() {}
	dsu(int n) {
		p = vector<int>(n + 1);
		t = vector<int>(n + 1);
		s = vector<int>(n + 1);
		can = true;
		comp = n;
		for (int i = 1; i <= n; i++) {
			p[i] = i;
			t[i] = 0;
			s[i] = 1;
		}
	}
	pair<int, int> getp(int x) {
		if (p[x] == x) return {p[x], 0};
		auto [np, tt] = getp(p[x]);
		p[x] = np;
		t[x] ^= tt;
		return {p[x], t[x]};
	}
	void unite(int a, int b, bool tt) {
		if (!can) return;
		auto [na, ta] = getp(a);
		auto [nb, tb] = getp(b);
		a = na;
		b = nb;
		if (a == b) {
			if (ta ^ tb ^ tt)
				can = false;
			return;
		}
		comp--;
		if (s[a] < s[b]) swap(a, b);
		s[a] += s[b];
		p[b] = a;
		t[b] = (ta ^ tb ^ tt);
	}
};

int n, m, k, q, p2[N];
dsu cur[T];

int getans() {
	int res = 1;
	for (int i = 0; i < T; i++) {
		if (!cur[i].can) return 0;
		(res *= p2[max(cur[i].comp - 1, 0ll)]) %= MOD;
	}
	return res;
}

void upd(int r, int c, int v) {
	for (int j = 0; j < T; j++)
		cur[j].unite(r, n + c, (v >> j) & 1);
}

void test_case() {
	cin >> n >> m >> k >> q;
	for (int i = 0; i < T; i++)
		cur[i] = dsu(n + m);
	for (int i = 1; i <= k; i++) {
		int r, c, v; cin >> r >> c >> v;
		upd(r, c, v);
	}
	cout << getans() << '\n';
	while (q--) {
		int r, c, v; cin >> r >> c >> v;
		upd(r, c, v);
		cout << getans() << '\n';
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	p2[0] = 1;
	for (int i = 1; i < N; i++)
		p2[i] = p2[i - 1] * 2 % MOD;
	int t; cin >> t;
	while (t--) test_case();
}