#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
	using namespace std;
	int s[1 << 19];
	pair<int, int> c[105], tmp[105];
	char a[1 << 19];
int main() {
	int T = 0;
	scanf("%d", &T);
	for (int G = 1; G <= T; G++) {
		int n = 0, m = 0, k = 0;
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= n; i++) {
			a[i] = getchar();
			while (a[i] < 'A' || a[i] > 'Z')
				a[i] = getchar();
		}
		for (int i = 0; i < (1 << m); i++)
			s[i] = 0;
		int cnt = 0;
		for (int i = 2; i <= n; i++) {
			int cnt0 = 0;
			for (int j = 1; j <= cnt; j++)
				tmp[++cnt0] = make_pair(c[j].first | (1 << (a[i - 1] - 'A')), c[j].second + 1);
			tmp[++cnt0] = make_pair(1 << (a[i - 1] - 'A'), 2);
			sort(tmp + 1, tmp + cnt0 + 1);
			for (int j = 2; j <= cnt0; j++)
				if (tmp[j].first == tmp[j - 1].first)
					tmp[j].second = max(tmp[j].second, tmp[j - 1].second);
			tmp[cnt0 + 1].first = -1;
			cnt = 0;
			for (int j = 1; j <= cnt0; j++)
				if (tmp[j].first != tmp[j + 1].first) {
					c[++cnt] = tmp[j];	
					s[tmp[j].first] = max(s[tmp[j].first], tmp[j].second);
				}
		}
		int ans = 1e9;
		for (int i = 0; i < (1 << m); i++) {
			int w = 0;
			for (int j = 0; j < m; j++) {
				if ((i >> j) & 1) {
					s[i] = max(s[i], s[i ^ (1 << j)]), w++;
				}
			}
			if (!((i >> (a[n] - 'A')) & 1) && s[i] <= k) {
				ans = min(ans, m - w);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}