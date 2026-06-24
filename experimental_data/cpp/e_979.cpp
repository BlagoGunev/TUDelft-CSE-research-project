#include "bits/stdc++.h"
using namespace std;
int n;
int c[55];
const int mod = 1000000000 + 7;
long long bin[111];
int p;

long long mem[55][55][55][55];

long long dp(int cur, int white_odd, int black_odd, int white) {
	if(cur == n + 1) {
		if(((white_odd + black_odd) & 1) == p) return 1;
		return 0;
	}
	if(mem[cur][white_odd][black_odd][white] != -1) return mem[cur][white_odd][black_odd][white];
	int black = cur - 1 - white;
	int white_even = white - white_odd;
	int black_even = black - black_odd;
	
	long long ans = 0;
	if(c[cur] == 1 || c[cur] == -1) {
		long long odd = black_odd ? (bin[black_even] * bin[black_odd - 1]) : 0;
		odd %= mod;
		long long even = black_odd ? (bin[black_even] * bin[black_odd - 1]) : bin[black_even];
		even %= mod;
		ans += ((bin[white] * odd) % mod) * dp(cur + 1, white_odd, black_odd, white + 1);
		ans += ((bin[white] * even) % mod) * dp(cur + 1, white_odd + 1, black_odd, white + 1);
		ans %= mod;
	}
	if(c[cur] == 0 || c[cur] == -1) {
		long long odd = white_odd ? (bin[white_even] * bin[white_odd - 1]) : 0;
		odd %= mod;
		long long even = white_odd ? (bin[white_even] * bin[white_odd - 1]) : bin[white_even];
		even %= mod;
		ans += ((bin[black] * odd) % mod) * dp(cur + 1, white_odd, black_odd, white);
		ans += ((bin[black] * even) % mod) * dp(cur + 1, white_odd, black_odd + 1, white);
		ans %= mod;
	}
	return mem[cur][white_odd][black_odd][white] = ans;
}

int main(int argc, char const *argv[])
{
	bin[0] = 1;
	for(int i = 1; i <= 100; i++) {
		bin[i] = bin[i - 1] + bin[i - 1];
		bin[i] %= mod;
	}
	scanf("%d %d", &n, &p);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	memset(mem, -1, sizeof mem);
	printf("%lld\n", dp(1, 0, 0, 0));
	return 0;
}