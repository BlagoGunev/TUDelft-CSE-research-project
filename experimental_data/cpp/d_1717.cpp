// LUOGU_RID: 100163115
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

int n, k, ans;

int fac[maxn], ifac[maxn];

int C(int a, int b)

{

	if (a < 0 || b < 0 || a < b) return 0;

	return 1ll * fac[a] * ifac[a - b] % mod * ifac[b] % mod;

}

int main()

{

	read(n); read(k);

	k = min(k, n);

	fac[0] = ifac[0] = 1;

	for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;

	ifac[n] = ksm(fac[n]);

	for (int i = n - 1; i; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;

//	for (int i = 0; i <= n; i++) printf("C(n,%d)=%d\n", i, C(n, i));

	for (int i = 0; i <= k; i++) ans = qmod(ans + C(n, i));

	printf("%d\n", ans);

	return 0;

}