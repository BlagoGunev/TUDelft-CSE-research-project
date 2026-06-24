#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#pragma comment(linker, "/STACK:16000000")

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 1e9;
const double EPS = 1e-8;
const double PI = 2 * acos(0.);
const int M = 1e9 + 7;

int dp[110][11010];
int C[110][110];

ll Qpow(int a, ll n) {
	if (n == 0) return 1;
	ll q = Qpow(a, n / 2);
	q = q * q % M;
	if (n & 1)
		q = q * a % M;
	return q;
}

int main() {
#ifdef _DBG1
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k;
	ll m;
	scanf("%d%lld%d", &n, &m, &k);
	for (int i = 0; i <= n; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % M;
		}
	}

	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		ll cnt = (m - i + n - 1) / n;
//		cerr << i << endl;
		for (int j = 0; (j << 1) <= n; ++j) {
			ll A = Qpow(C[n][j], cnt);
//			cerr << n << " " << j << " " << C[n][j] << endl;
//			cerr << A << endl;
			int st = k - (n - i) * n - 3;
			if (st < 0) st = 0;
//			cerr << st << endl;
			for (int y = st; y + j <= k; ++y) {
				if (dp[i][y] == 0) continue;
				int q = A * dp[i][y] % M;
				dp[i + 1][y + j] += q;
				if (dp[i + 1][y + j] >= M) dp[i + 1][y + j] -= M;
				if (j < n - j) {
					dp[i + 1][y + n - j] += q;
					if (dp[i + 1][y + n - j] >= M) dp[i + 1][y + n - j] -= M;
				}
//				cerr << i + 1 << " " << y + j << " " << j << " " << A << " " << A * dp[i][y] << endl;
			}
		}	
	}

//	for (int i = 0; i <= n; ++i) {
//		for (int j = 0; j <= k; ++j)
//			printf("%d ", dp[i][j]);
//		printf("\n");
//	}

	printf("%d\n", dp[n][k] % M);

	return 0;
}