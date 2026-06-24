#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define pb push_back
void solve(){
	int n, q; cin >> n >> q;
	int a[n + 1];
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ps[n + 1]; ps[0] = 0;
	for (int i = 1; i <= n; i++) ps[i] = ps[i - 1] + (a[i] == 1 ? 1 : -(a[i] - 1));
	while (q--) {
		int l, r; cin >> l >> r;
		cout << (l < r && ps[r] - ps[l - 1] <= 0 ? "YES\n" : "NO\n");
	}
}
signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	while (t--) solve();
}