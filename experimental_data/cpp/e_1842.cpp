#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
// #define ll long long int
int INF = 2e18;
struct segtree{
	int n; vector<int> t; vector<int> lazy;
	void push(int v) {
		t[v*2] += lazy[v];
		lazy[v*2] += lazy[v];
		t[v*2+1] += lazy[v];
		lazy[v*2+1] += lazy[v];
		lazy[v] = 0;
	}

	void update(int v, int tl, int tr, int l, int r, int addend) {
		if (l > r) 
			return;
		if (l == tl && tr == r) {
			t[v] += addend;
			lazy[v] += addend;
		} else {
			push(v);
			int tm = (tl + tr) / 2;
			update(v*2, tl, tm, l, min(r, tm), addend);
			update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
			t[v] = min(t[v*2], t[v*2+1]);
		}
	}

	int query(int v, int tl, int tr, int l, int r) {
		if (l > r)
			return INF;
		if (l == tl && tr == r)
			return t[v];
		push(v);
		int tm = (tl + tr) / 2;
		return min(query(v*2, tl, tm, l, min(r, tm)), 
				query(v*2+1, tm+1, tr, max(l, tm+1), r));
	}
	void build(int N){
		n = N;
		t.assign(4*n, 0);
		lazy.assign(4*n, 0);
		// cout << 4*n << "\n";
	}
};
void solve(){
	int n, k, A; cin >> n >> k >> A;
	segtree seg;
	seg.build(k+1);
	vector<vector<array<int, 2>>> p(k+1);
	for (int i=0; i<n; i++){
		int x, y, c; cin >> x >> y >> c;
		p[k-y].pb({x, c});
	}
	vector<int> dp(k+1, INF); dp[0] = 0;
	for (int i=1; i<=k; i++){
		
		for (auto [x, cx]: p[i]){
			// cout << i << ' ' << x << ' ' << cx << "\n";
			seg.update(1, 0, k, x, i-1, cx);
		}
		// if (i==2){
		// 	cout << seg.query(1, 0, k, 0, i-1) << "\n";
		// }
		dp[i] = A*i + seg.query(1, 0, k, 0, i-1) - A;
		dp[i] = min(dp[i], A*i);
		seg.update(1, 0, k, i, i, -A*i);
		seg.update(1, 0, k, i, i, dp[i]);
	}
	cout << dp[k] << "\n";
	// for (int i=0; i<=k; i++){
	// 	cout << i << ' ' << dp[i] << "\n";
	// }



}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t; t=1;
    // cin >> t;
    for (int i=0; i<t; i++) solve();
}