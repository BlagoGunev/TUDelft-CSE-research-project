#include<bits/stdc++.h>

using namespace std;



#define endl '\n'



const int MOD = 998244353;

int a[114514 * 3], c[350];



long long binpow(long long x, long long y) {

	for (long long z = 1;; y /= 2, x = (x * x) % MOD) {

		if (y % 2) z = (z * x) % MOD;

		if (!y) return z;

	}

}



long long mul(long long x, long long y) {

	return (x * y) % MOD;

}



long long inv(long long a) {

	return binpow(a, MOD - 2);

}



void cmb(int k)

{

	c[0] = 1;



	for (int i = 1; i <= k; i++)

		c[i] = mul(mul(c[i - 1], (k - i + 1)), inv(i));

}



void solve()

{

	int n;

	cin >> n;



	for (int i = 1; i <= n; i++)

		cin >> a[i];



	long long p = 1;



	for (int i = 1; i <= n; i += 3)

	{

		if (a[i] == a[i + 1] && a[i] == a[i + 2])

			p = mul(p, 3);

		

		for (int j = 0; j < 3; j++)

			for (int k = j + 1; k < 3; k++)

				if (a[i + j] == a[i + k])

				{

					for (int l = 0; l < 3; l++)

						if (l != j && l != k && a[i + l] > a[i + j])

							p = mul(p, 2);

				}

	}



	cmb(n / 3);

	cout << mul(p, c[n / 6]);

}



signed main()

{

	ios::sync_with_stdio(0);

	cin.tie(0); cout.tie(0);

	solve();

}