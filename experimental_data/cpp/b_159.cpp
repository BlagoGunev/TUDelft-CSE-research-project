#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 200000;
const int MAXR = 2000;

pair <int, int> a[MAXN], b[MAXN];
int r[2][MAXR], coun[MAXR];

int main() {
	ios_base::sync_with_stdio(false);

	int n, m, x, y;
	cin >> n >> m;
	for (int i = 0; i < n; i ++) {
		cin >> x >> y;
		a[i] = make_pair(y, x);
		r[0][y] ++;
	}
	
	sort(a, a + n);

	for (int i = 0; i < m; i ++) {
		cin >> x >> y;
		b[i] = make_pair(y, x);
		r[1][y] ++;
	}

	sort(b, b + m);

	int ans = 0;
	for (int i = 0; i < MAXR; i ++)
		ans += min(r[0][i], r[1][i]);

	cout << ans << ' ';
	ans = 0;

	int pos1 = 0;
	int pos2 = 0;
	for (int i = 0; i < MAXR; i ++) {
		while (pos1 < m && b[pos1].first == i) {
			coun[b[pos1].second] ++;
			pos1 ++;
		}
		while (pos2 < n && a[pos2].first == i) {
			ans += coun[a[pos2].second] > 0;
			coun[a[pos2].second] --;
			if (coun[a[pos2].second] < 0) coun[a[pos2].second] = 0;
			pos2 ++;
		}

		for (int j = pos1 - 1; j >= 0 && b[j].first == i; j --)
			coun[b[j].second] = 0;

	}

	cout << ans << endl;
}