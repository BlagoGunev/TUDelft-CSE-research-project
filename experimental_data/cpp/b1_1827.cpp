#include<bits/stdc++.h>
using std::cin;
using std::cout;
using ll = long long;
using u64 = unsigned long long;
void IOinit() {
	std::ios::sync_with_stdio(false), cin.tie(0);
#ifdef zqj
	freopen("1.in", "r", stdin);
#endif
}
int main() {
	IOinit();
	int t;
	cin >> t;
	for(int i = 0;i < t;++i) {
		int n; cin >> n;
		std::vector<int> a(n);
		for(int & x : a) {
			cin >> x;
		}
		ll ans = 0;
		for(int i = 1;i < n;++i) {
			std::vector<int> min, max;
			int mx = a[i - 1];
			for(int j = i - 1;j >= 0;--j) {
				mx = std::max(mx, a[j]);
				max.push_back(mx);
			}
			int mn = a[i];
			for(int j = i;j < n;++j) {
				mn = std::min(mn, a[j]);
				min.push_back(mn);
			}
			for(int b : min) {
				ans += max.end() - lower_bound(max.begin(), max.end(), b);
			}
		}
		cout << ans << '\n';
	}
}