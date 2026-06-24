#include <bits/stdc++.h>
#define LL unsigned long long
using namespace std;
const int N = 1e5 + 10;
const LL MOD = 998244353;
LL Qpow(LL x, LL k, LL P) {
	LL ret = 1, tmp = (x + P) % P;
	while (k) {
		if (k & 1) ret = ret * tmp % P;
		tmp = tmp * tmp % P; k >>= 1;
	} return ret;
}
int n, m, Q, A[N], tot; map<int, int> idx;
struct Qry { int l, r, id; } qq[N]; 
vector<Qry> qry[101]; LL fact[N * 2], inv[N * 2], F[N], Ans[N];
int cnt[N], cc[N]; LL cur = 0;
void add(int x, int k) {
	cur = cur * inv[cnt[x] + k] % MOD * fact[cnt[x] + k - cc[x]] % MOD;
	cur = cur * fact[cnt[x] + k] % MOD * inv[cnt[x] + k - (++ cc[x])] % MOD;
}
void del(int x, int k) {
	cur = cur * inv[cnt[x] + k] % MOD * fact[cnt[x] + k - cc[x]] % MOD;
	cur = cur * fact[cnt[x] + k] % MOD * inv[cnt[x] + k - (-- cc[x])] % MOD;
}
int main() {
	ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> Q; tot = 0;
	for (int i = 1; i <= n; i ++) cin >> A[i], cnt[A[i]] ++;
	for (int i = 1, l, r, k; i <= Q; i ++) {
		cin >> l >> r >> k;
		if (idx.find(k) == idx.end()) idx[k] = ++ tot;
		qry[idx[k]].push_back({l, r, i});
	}
	fact[0] = 1; for (int i = 1; i <= n + 100000; i ++) fact[i] = fact[i - 1] * i % MOD;
	inv[n + 100000] = Qpow(fact[n + 100000], MOD - 2, MOD);
	for (int i = n + 99999; i >= 0; i --) inv[i] = inv[i + 1] * (i + 1) % MOD;
	for (auto [k, id] : idx) {
		F[0] = 1;
		for (int i = 1; i <= n; i ++) F[i] = F[i - 1] * (1ll * m * k % MOD + i) % MOD;
		int qtot = qry[id].size(); int T = sqrt(n) * 12 + 1;
		for (int i = 0; i < qtot; i ++) qq[i + 1] = qry[id][i];
		sort(qq + 1, qq + 1 + qtot, [T](Qry a, Qry b) {
			return (a.l / T != b.l / T ? a.l < b.l : ((a.l / T) & 1 ? a.r > b.r : a.r < b.r));
		});
		cur = 1; for (int i = 1; i <= m; i ++) cc[i] = 0;
		for (int i = 1, l = 1, r = 0; i <= qtot; i ++) {
			while (l > qq[i].l) add(A[-- l], k);
			while (l < qq[i].l) del(A[l ++], k);
			while (r > qq[i].r) del(A[r --], k);
			while (r < qq[i].r) add(A[++ r], k);
			Ans[qq[i].id] = cur * F[n - (r - l + 1)] % MOD;
		}
	}
	for (int i = 1; i <= Q; i ++) cout << Ans[i] << "\n";
	return 0;
}