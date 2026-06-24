#include <iostream>

using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
int si, lef, t0;
int a1, t1, p1;
int a2, t2, p2;

int main() {
	cin >> si >> lef >> t0;
	cin >> a1 >> t1 >> p1;
	cin >> a2 >> t2 >> p2;
	if (t1 > t2) {
		swap(a1, a2);
		swap(t1, t2);
		swap(p1, p2);
	}
	ll ans = 1LL * inf * inf;
	for (int i = 0; ; ++i) {
		if ((ll) a1 * t1 * (i - 1) > lef) {
			break;
		}
		ll t = 0;
		if (i && 1LL * a1 * i >= si && 1LL * a1 * (i - 1) < si) {
			t = 1LL * a1 * t1 * (i - 1) + 1LL * (si - 1LL * a1 * (i - 1)) * t1;
			if (t <= lef) {
				ans = min(ans, (ll)p1 * i);
			}
		} else if (1LL * a1 * i < si) {
			t += 1LL * a1 * t1 * i;
			ll ts = si -  a1 * i;
			if (t + 1LL * ts * t0 <= lef) {
				ans = min(ans, (ll)p1 * i);
			} else {
				if (t2 < t0) {
					ll byte = (t + 1LL * ts * t0 - lef + t0 - t2 - 1) / (t0 - t2);
					if (byte <= ts) {
						ll bug = (byte + a2 - 1) / a2;
						ans = min(ans, 1LL * i * p1 + 1LL * bug * p2);
					}
				}
			}
		}
	}
	if (ans == 1LL * inf * inf) {
		ans = -1;
	}
	cout << ans << endl;
	return 0;
}