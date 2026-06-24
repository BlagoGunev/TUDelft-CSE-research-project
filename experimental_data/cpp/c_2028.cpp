#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#define ff first
#define ss second
typedef long long ll;
using namespace std;
const int N = 3e5 + 10;
ll a[N];
ll pref[N];
ll dp1[N], dp2[N];
void solve() {
	int n, m, v;
	cin >> n >> m >> v;
	for (int i = 0; i <= n + 2; i++) {
		dp1[i] = 0;
		dp2[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i, ans = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if ((pref[i] - pref[mid - 1]) >= v) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		if (ans == -1) dp1[i] = 0;
		else dp1[i] = dp1[ans - 1] + 1;
	}
	for (int i = n; i >= 1; i--) {
		int l = i, r = n, ans = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if ((pref[mid] - pref[i - 1]) >= v) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		if (ans == -1) dp2[i] = 0;
		else dp2[i] = dp2[ans + 1] + 1;
	}
	ll answ = -1;
	for (int i = 1; i <= n; i++) {
		if (dp2[i] == m) {
			answ = max(answ, pref[i - 1]);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dp1[i] == m) {
			answ = max(answ, pref[n] - pref[i]);
			continue;
		}
		int l = i + 1, r = n, ans = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (dp2[mid] >= (m - dp1[i])) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		if (ans == -1) continue;
		answ = max(answ, pref[ans - 1] - pref[i]);
	}
	cout << answ << "\n";
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}