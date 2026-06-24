#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;

const ll MOD = 1000 * 1000 * 1000 + 7;
const int MAXN = 100001;
vector <pair <int, int> > e[MAXN];


ll pw(ll x, int y) {
	if (y == 0) return 1;
	ll v = pw(x, y / 2);
	v = (v * v) % MOD;
	if (y & 1) {
		v = (v * x) % MOD;
	}
	return v;
}

ll obr(int x) {
	return pw(x, MOD - 2);
}

struct Num {
	ll x;

	Num(ll y = 0) :x(y % MOD) {};

	friend Num operator * (Num a, Num b) {
		return Num((a.x * b.x) % MOD);
	}

	friend Num operator / (Num a, Num b) {
		return Num((a.x * obr(b.x)) % MOD);
	}

	friend Num operator + (Num a, Num b) {
		return Num((a.x + b.x) % MOD);
	}

	friend Num operator - (Num a, Num b) {
		return Num((a.x - b.x + MOD) % MOD);
	}

	Num operator ~() {
		return Num(obr(x));
	}

	operator ll() const {
		return x;
	}
};

//using Num = ld;

Num Obr(Num x) {
	return ~x;
}

Num a[MAXN];
Num b[MAXN];

void dfs(int v, int p, int paredge) {
	if (e[v].size() == 1) {
		a[v] = b[v] = 0;
		return;
	}
	Num sa(0);
	Num sb(0);
	Num sum(paredge);
	for (auto edge : e[v]) {
		if (edge.first == p) continue;
		dfs(edge.first, v, edge.second);
		sa = sa + Num(a[edge.first]);
		sb = sb + Num(b[edge.first]);
		sum = sum + Num(edge.second);
	}
	Num ml = Num(e[v].size()) - sa;
	a[v] = Obr(ml);
	b[v] = Num(a[v]) * (sb + sum);
}

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		e[a].emplace_back(b, c);
		e[b].emplace_back(a, c);
	}
	dfs(0, 0, 0);
	cout << b[0] << endl;
	return 0;
}