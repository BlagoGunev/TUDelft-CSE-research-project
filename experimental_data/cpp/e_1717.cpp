// LUOGU_RID: 100168025
#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5, mod = 1e9 + 7;

template <typename T>

void read(T &x)

{

	T sgn = 1;

	char ch = getchar();

	for (; !isdigit(ch); ch = getchar()) if (ch == '-') sgn = -1;

	for (x = 0; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';

	x *= sgn;

}

int ksm(int a, int b = mod - 2)

{

	int ret = 1;

	for (; b; b >>= 1, a = 1ll * a * a % mod) if (b & 1) ret = 1ll * ret * a % mod;

	return ret;

}

int qmod(int a)

{

	if (a >= mod) a -= mod;

	return a;

}

int n, prime[maxn], cnt, phi[maxn], ans;

bool vis[maxn];

void sieve(int mx)

{

	phi[1] = 1;

	for (int i = 2; i <= mx; i++)

	{

		if (!vis[i]) prime[++cnt] = i, phi[i] = i - 1;

		for (int j = 1; j <= cnt && prime[j] * i <= mx; j++)

		{

			vis[i * prime[j]] = 1;

			if (i % prime[j] == 0)

			{

				phi[i * prime[j]] = phi[i] * prime[j];

				break;

			}

			phi[i * prime[j]] = phi[i] * (prime[j] - 1);

		}

	}

}

int lcm(int a, int b)

{

	return 1ll * a * b / __gcd(a, b) % mod;

}

int main()

{

	read(n);

	sieve(n);

//	printf("phi[%d]=%d\n", 2, phi[2]);

	for (int c = 1; c <= n - 2; c++)

	{

		for (int d = 1; d * d <= n - c; d++)

		{

			if ((n - c) % d == 0)

			{

				ans = qmod(ans + 1ll * lcm(c, d) * phi[(n - c) / d] % mod);

				if (d * d != n - c && d != 1) ans = qmod(ans + 1ll * lcm(c, (n - c) / d) * phi[d] % mod);

			}

		}

	}

	printf("%d\n", ans);

	return 0;

}