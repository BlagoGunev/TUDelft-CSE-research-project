# include <iostream>
# include <cstdio>
# include <cmath>
# include <algorithm>
# include <cstring>
# include <vector>
# include <map>
# include <random>
# include <ctime>
# include <unordered_map>
# include <queue>
# define int long long
using namespace std;
const int MAXN = 2e5 + 10;
int n, k;
struct node {
	int a, b;
}a[MAXN];
bool operator < (node A, node B) {
	return A.a < B.a;
}
bool check(int mid) {
	int cnt = 0, tmp = k;
	for (int i = 1; i < n; i++) {
		cnt += a[i].a < mid;
	}
	for (int i = n - 1; i >= 1; i--) {
		if (a[i].b && a[i].a < mid && tmp >= (mid - a[i].a)) {
			tmp -= (mid - a[i].a);
			cnt--;
		} 
	}
	return cnt <= (n / 2) - 1;
}
void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i].a;
	for (int i = 1; i <= n; i++) cin >> a[i].b;
	sort(a + 1, a + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
			int tmp = n / 2;
			if (tmp >= i) tmp++;
		if (a[i].b == 1) {
			ans = max(ans, a[i].a + k + a[tmp].a);
		}
	}
	if (a[n].b == 0) {
		int l = 0, r = 2e9, ret = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid)) ret = mid, l = mid + 1;
			else r = mid - 1;
		}
		ans = max(ans, ret + a[n].a);
	}
	cout << ans << endl ;
}
signed main() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}