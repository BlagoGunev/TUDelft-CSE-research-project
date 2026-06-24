#include <bits/stdc++.h>
using namespace std;

#define cll static_cast<long long>
constexpr int mod = 1e9 + 7;
constexpr int N = 100000;

int fac[N + 5];
int invfac[N + 5];
int cnt[N + 5];

int Pow(int a, int b) {
	int r = 1;
	while(b) {
		if(b & 1)
			r = cll(r) * a % mod;
		a = cll(a) * a % mod;
		b >>= 1;
	}
	return r;
}

int P(int x, int y) {
	return cll(fac[x]) * invfac[x - y] % mod;
}

int C(int x, int y) {
	return cll(fac[x]) * invfac[y] % mod * invfac[x - y] % mod;
}

int main() {
	fac[0] = 1;
	for(int i = 1; i <= N; ++i)
		fac[i] = cll(i) * fac[i - 1] % mod;
	invfac[N] = Pow(fac[N], mod - 2);
	for(int i = N; i >= 1; --i)
		invfac[i - 1] = cll(i) * invfac[i] % mod;
	int T;
	scanf("%d", &T);
	for(int _case = 0; _case < T; ++_case) {
		int n, k;
		scanf("%d%d", &n, &k);
		int upp = (n - 1) / k + 1;
		for(int i = 1; i <= upp; ++i)
			cnt[i] = P(n - (i - 1) * (k - 1), i);
		cnt[upp + 1] = 0;
		int ans = 0, tot = 0;
		for(int i = 1; i <= upp; ++i) {
			int count = (cnt[i] * cll(n - i) - cnt[i + 1] + mod) % mod;
			ans = (ans + cll(fac[n - i - 1]) * (i + 1LL) % mod * count) % mod;
			tot = (tot + cll(fac[n - i - 1]) * count) % mod;
		}
		ans = cll(ans) * Pow(tot, mod - 2) % mod;
		printf("%d\n", ans);
	}
	return 0;
}