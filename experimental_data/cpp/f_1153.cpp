#include <cstdio>
const long long MOD = 998244353;
long long POWER(long long a, long long b)
{
	long long r = 1;
	for (; b; b >>= 1)
	{
		if (b & 1)
			r = r * a % MOD;
		a = a * a % MOD;
	}
	return r;
}
int N, K, L;
long long fc[100001], fi[100001], inv[100001];
long long f[4001][4001], g[4001][4001]; // f[i][j] : 长度为i，当前深度为j的合法括号前缀数量
int main()
{
	inv[1] = 1;
	for (int i = 2; i <= 100000; i++)
		inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
	fc[0] = fi[0] = 1;
	for (int i = 1; i <= 100000; i++)
	{
		fc[i] = fc[i - 1] * i % MOD;
		fi[i] = fi[i - 1] * inv[i] % MOD;
	}
	scanf("%d%d%d", &N, &K, &L);
	f[0][0] = 1;
	for (int i = 0; i <= N + N; i++)
	{
		for (int j = i & 1; j <= i; j += 2)
			if (j >= K)
				g[i][j] = (g[i][j] + f[i][j]) % MOD;
		if (i < N + N)
			for (int j = i & 1; j <= i; j += 2)
			{
				f[i + 1][j + 1] = (f[i + 1][j + 1] + f[i][j] * (N - (i + j) / 2)) % MOD;
				if (j)
					f[i + 1][j - 1] = (f[i + 1][j - 1] + f[i][j] * j) % MOD;
				g[i + 1][j + 1] = (g[i + 1][j + 1] + g[i][j] * (N - (i + j) / 2)) % MOD;
				g[i + 1][j - 1] = (g[i + 1][j - 1] + g[i][j] * j) % MOD;
			}
	}
	printf("%lld\n", g[N + N][0] * POWER(f[N + N][0], MOD - 2) % MOD * L % MOD * POWER(N + N + 1, MOD - 2) % MOD);
	return 0;
}