#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, n, k;

	scanf("%d", &t);

	while (t--) {
		scanf("%d %d", &n, &k);

		int mod = n%k;
		int div = n/k;
		int lim = k/2;

		printf("%d\n", div*k + min(lim, mod));
	}

	return 0;
}