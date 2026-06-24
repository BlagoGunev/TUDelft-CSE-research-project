#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
typedef long long ll;
const int mod = 1e9 + 7;
int add(int a, int b)
{
	a += b;
	return a >= mod ? a - mod : a;
}
int sub(int a, int b)
{
	a -= b;
	return a < 0 ? a + mod : a;
}
int mul(int a, int b) { return (ll)a * b % mod; }
int qpow(int a, int b)
{
	int ret = 1;
	for (; b; b >>= 1, a = mul(a, a))
		if (b & 1)
			ret = mul(ret, a);
	return ret;
}
/* math */
int fac[N], ifac[N];
inline void init(int n)
{
	ifac[0] = fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = mul(fac[i - 1], i);
	ifac[n] = qpow(fac[n], mod - 2);
	for (int i = n - 1; i; i--)
		ifac[i] = mul(ifac[i + 1], i + 1);
}

inline int binom(int a, int b)
{
	if (b > a)
		return 0;
	return mul(fac[a], mul(ifac[b], ifac[a - b]));
}

int f[N], g[N];
int n;

int main()
{
	init(2e6);
	cin >> n;
	for (int i = n; i; i--)
	{
		if (i * 2 > n)
		{
			f[i] = g[i] = 1;
		}
		for (int j = 2; j * i <= n; j++)
		{
			if (f[i * j] + 1 > f[i])
				f[i] = f[i * j] + 1, g[i] = 0;
			if (f[i * j] + 1 == f[i])
			{
				int t1 = n / (i * j), t2 = n / (i);
				g[i] = add(g[i], mul(g[i * j], mul(fac[t2 - t1], binom(n - t1 - 1, t2 - t1 - 1))));
			}
		}
	}
	cout << g[1] << endl;
}