#include <bits/stdc++.h>



using namespace std;

const int N = 1002;

int main() {

#ifndef ONLINE_JUDGE

	freopen("input.in", "r", stdin);

#endif

	int n, m, a[N];

	scanf("%d", &n);

	int root = 1, maxi = 0;

	for (int i = 1; i <= n; ++i) {

		scanf("%d", a + i);

		if (a[i] > maxi) {

			maxi = a[i];

			root = i;

		}

	}

	scanf("%d", &m);

	int mini[N];

	memset(mini, 1, sizeof mini);

	while (m--) {

		int u, v, c;

		scanf("%d%d%d", &u, &v, &c);

		if (a[u] > a[v])

			mini[v] = min(mini[v], c);

	}

	int result = 0;

	for (int i = 1; i <= n; ++i) {

		if (i != root && mini[i] == mini[0]) {

			printf("-1\n");

			return 0;

		}

		if (i != root)

			result += mini[i];

	}

	printf("%d\n", result);

	return 0;

}