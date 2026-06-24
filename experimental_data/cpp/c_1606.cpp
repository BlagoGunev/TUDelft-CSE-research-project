#include <stdio.h>
#define ll long long

ll n, k, a[11], d[11];
ll pow[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 1000000000};

int main() {
	int T, w, n, k;
	scanf("%d", &T);
	while(T --) {
		scanf("%d%d", &n, &k); w = 1; ll ans = 0; ++ k; 
		for(int i = 1; i <= n; ++ i) scanf("%d", &a[i]);
		for(int i = 1; i < n; ++ i) d[i] = a[i + 1] - a[i], d[i] = pow[d[i]] - 1;
		while(k && w < n) {
			if(d[w] <= k) ans += d[w] * pow[a[w]], k -= d[w];
			else ans += k * pow[a[w]], k = 0;
			w ++; 
		} if(k) ans += k * pow[a[n]];
		printf("%lld\n", ans);
	}
}