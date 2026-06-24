#include <bits/stdc++.h>



using namespace std;



#define MX 300

typedef long long LL;



#define inf 100000000000000000LL



LL dp[MX][MX], dp_[MX][MX];

LL sum[MX];

LL MIN[MX][MX];



int main () {

#ifndef ONLINE_JUDGE

	freopen("in.txt", "r", stdin);

#endif

	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i ++) {

		int a;

		cin >> a;

		sum[i] = sum[i - 1] + a;

	}

	for (int i = 0; i < MX; i ++)

		for (int j = 0; j < MX; j ++) dp_[i][j] = MIN[i][j] = inf;

	for (int d = 0; d <= m; d ++) dp_[d][d] = abs(sum[1] - d);

	for (int j = 0; j <= m; j ++) {

		for (int i = m; i >= 0; i --) MIN[i][j] = min(MIN[i + 1][j], dp_[i][j]);

	}

	for (int i = 2; i <= n; i ++) {

		for (int j = 0; j < MX; j ++)

			for (int k = 0; k < MX; k ++) dp[j][k] = dp_[j][k], dp_[j][k] = inf;

		for (int j = 0; j <= m; j ++)

			for (int k = j; k <= m; k ++) dp_[j][k] = min(dp_[j][k], MIN[j][k - j] + abs(k - sum[i]));

		for (int j = 0; j < MX; j ++) MIN[i][j] = inf;

		for (int j = 0; j <= m; j ++) {

			for (int k = m; k >= 0; k --) MIN[k][j] = min(MIN[k + 1][j], dp_[k][j]);

		}

	}

	LL tot = inf;

	for (int i = 0; i <= m; i ++) tot = min(tot, dp_[i][m]);

	cout << tot << endl;

	return 0;

}