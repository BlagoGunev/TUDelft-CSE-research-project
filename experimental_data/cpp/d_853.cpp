#include <bits/stdc++.h>

using namespace std;

int n, x[300005], nx[300005], cnt[3], s[300005], ans, hv, cur, ta, tb;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", x + i);
		ans += x[i];
		s[i + 1] = s[i] + x[i];
		x[i] /= 1000;
		cnt[x[i]]++;
	}
	nx[n] = n;
	for (int i = n - 1; i >= 0; i--)
		if (x[i] == 1)
			nx[i] = i;
		else
			nx[i] = nx[i + 1];
	for (int i = 0; i < n; i++) {
		ans = min(ans, cur + max(0, s[n] - s[i] - hv));
		if (x[i] == 2) {
			if (nx[i] != n) {
				ta = min(hv, s[nx[i]] - s[i]);
				ans = min(ans, cur + s[nx[i]] - s[i] - ta + 1000 + max(0, s[n] - s[nx[i] + 1] - (hv - ta + 100)));
			}
		} else {
			ta = i + 1;
			tb = min(hv, 1000);
			while (ta < n && x[ta] == 2) {
				ans = min(ans, cur + 1000 - tb + 2000 * (ta - i) + max(0, s[n] - s[ta + 1] - (hv - tb + 200 * (ta - i))));
				ta++;
			}
		}
		cur += x[i] * 1000;
		hv += x[i] * 100;
	}
	printf("%d\n", ans);
	return 0;
}