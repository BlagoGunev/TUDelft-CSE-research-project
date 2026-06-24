#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}
int fac[200100];
int mfac[200100];
#define MOD 998244353
int modinv(int n, int m = MOD - 2)
{
	if (m == 0)
		return 1;
	if (m % 2)
		return n * modinv(n, m - 1) % MOD;
	int v = modinv(n, m / 2);
	return v * v % MOD;
}
int ncr(int n, int r)
{
	if (n < r)
		return 0;
	int v = fac[n];
	v *= mfac[r];
	v %= MOD;
	v *= mfac[n - r];
	v %= MOD;
	return v;
}
int npr(int n, int r)
{
	if (n < r)
		return 0;
	int v = fac[n];
	v *= mfac[n - r];
	v %= MOD;
	return v;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fac[0] = 1;
	mfac[0] = 1;
	int i;
	for (i = 1; i <= 200000; i++)
	{
		fac[i] = fac[i - 1] * i % MOD;
		mfac[i] = modinv(fac[i]);
	}
	int T;
	cin >> T;
	while (T--)
	{
		int N, K;
		cin >> N;
		int i;
		int befa = 0;
		int befi = 0;
		int ans = 1;
		for (i = 1; i <= N; i++)
		{
			int a;
			cin >> a;
			if (i == N && a == -1)
			{
				a = N;
			}
			if (a != -1)
			{
				if (a > i)
					ans = 0;
				if (i == N && a < N)
					ans = 0;
				if (ans == 0)
					continue;
				int difa = a - befa;
				int difi1 = i - befa;
				int dif2i = befi - befa;
				int j;
				int curcnt = 0;
				for (j = 0; j <= min(dif2i, difa); j++)
				{
					int pick = ncr(dif2i, j) * ncr(difi1 - dif2i, difa - j) % MOD;
					pick *= npr(difi1-dif2i, j) * npr(difi1 - j, difa - j) % MOD;
					curcnt += pick;
					curcnt %= MOD;
				}
				ans *= curcnt;
				ans %= MOD;
				befa = a;
				befi = i;
			}
		}
		if (befa != N)
			ans = 0;
		cout << ans << '\n';
	}
}