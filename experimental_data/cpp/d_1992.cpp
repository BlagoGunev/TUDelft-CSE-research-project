#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(i=a;i<=b;i++)
#define FOR(i,a,b) for(i=a;i>=b;i--)
#define o1 cout<<"YES\n"
#define o0 cout<<"NO\n"
using namespace std;
const int N = 5e5 + 10;
void solve() {
	int i;
	int n, m, k;
	cin >> n >> m >> k;
	vector<char> a(n + 1);
	For(i, 1, n) {
		cin >> a[i];
	}
	a[0] = 'L';
	vector<bool> vis(n + 1);
	vector<int> mem(n + 1);
	auto calc = [&](auto && calc, int x)->int {
		if (x > n) return 0;
		if (vis[x]) return mem[x];
		if (a[x] == 'L') {
			int i, res = 1e9;
			For(i, 1, m) {
				res = min(res, calc(calc, x + i));
			}
			vis[x] = 1;
			return mem[x] = res;
		}
		if (a[x] == 'W') {
			vis[x] = 1;
			return mem[x] = calc(calc, x + 1) + 1;
		}
		vis[x] = 1;
		return mem[x] = 1e9;
	};
	if (calc(calc, 0) <= k) o1;
	else o0;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}