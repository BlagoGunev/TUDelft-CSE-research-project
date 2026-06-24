#include <cstdio>

typedef long long int ll;

ll q, k, n, a, b;

int main() {
	//freopen("test.in", "r", stdin);
	scanf("%d", &q);
	while(q--) {
		scanf("%d%d%d%d", &k, &n, &a, &b);
		if (k <= n * b) {
			printf("-1\n");
		}
		else if (k > n * a) {
			printf("%lld\n", n);
		}
		else {
			k -= n*b;
			k = (k - 1) / (a - b);
			printf("%lld\n", k);
		}
	}
	return 0;
}