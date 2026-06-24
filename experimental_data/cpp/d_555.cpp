#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
int a[200010];
pair<int, int> p[200010];
int id[200010];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		p[i] = make_pair(a[i], i);
	}
	sort(p, p + n);
	for (int i = 0; i < n; i++) {
		a[i] = p[i].first;
		id[p[i].second] = i;
	}
	for (int i = 0; i < m; i++) {
		int x, len, ans;
		scanf("%d%d", &x, &len);
		x = id[x-1];
		while (1) {
			int pr = lower_bound(a + x, a + n, a[x] + len) - a;
			if (a[pr] == a[x] + len) {
				ans = pr;
				break;
			}
			--pr;
			len -= a[pr] - a[x];
			x = pr;
			int pl = lower_bound(a, a + x, a[x] - len) - a;
			if (pl == x) {
				ans = x;
				break;
			}
			if (a[pl] == a[x] - len) {
				ans = pl;
				break;
			}
			len -= a[x] - a[pl];
			len %= 2ll * (a[x] - a[pl]);
			x = pl;
		}
		printf("%d\n", p[ans].second + 1);
	}
	return 0;
}