#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

/***********/

int n, m, w[505], b[1005], s[505], sn, v[505], ans;

/***********/

int main() {

	//freopen("in.txt", "r", stdin);

	/***********/

	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++)

		scanf("%d", &w[i]);

	for (int i = 1; i <= m; i++) {

		scanf("%d", &b[i]);

		if (!v[b[i]]) {

			s[sn++] = b[i];

			v[b[i]] = 1;

		}

	}

	for (int i = 1; i <= m; i++) {

		int y, t, j;

		for (y = 0; s[y] != b[i]; ans += w[s[y]], y++);

		t = s[y];

		for (j = y; j > 0; j--) s[j] = s[j-1];

		s[0] = t;

	}

	printf("%d\n", ans);

	/***********/

	return 0;

}