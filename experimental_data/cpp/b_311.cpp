#include <bits/stdc++.h>
using namespace std;

int n, m, p;
int d[100055];
long long arr[100055], S[100055];
long long dp[2][100055];
int deq[100055];

inline long long f(int i, int j) {
	return dp[0][j] - arr[i] * j + S[j];
}
inline bool check(int i, int j, int k) {
	long long a1 = -i, b1 = dp[0][i] + S[i];
	long long a2 = -j, b2 = dp[0][j] + S[j];
	long long a3 = -k, b3 = dp[0][k] + S[k];

	return (a2 - a1) * (b3 - b2) >= (b2 - b1) * (a3 - a2);
}
int main() {
	scanf("%d %d %d", &n, &m, &p);

	for (int i = 0; i < n - 1; i++) scanf("%d", &d[i]);
	for (int i = n - 2; i >= 0; i--) d[i] += d[i + 1];

	int x, y;

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		x--;

		y += d[x];
		arr[i + 1] = y;
	}

	sort(arr + 1, arr + m + 1);

	for (int i = 1; i <= m; i++) {
		S[i] = S[i - 1] + arr[i];
	}

	memset(dp, 63, sizeof(dp));

	// dp[i] = dp[j] + arr[i] * (i - j) - (S[i] - S[j])
	// dp[i] = dp[j] + (arr[i] * i - arr[i] * j) - S[i] + S[j])
	// dp[i] = -S[i] + dp[j] + arr[i] * i - arr[i] * j + S[j]
	// dp[i] = arr[i] * i - S[i] + dp[j] - arr[i] * j + S[j]
	

	dp[0][0] = 0;
	
	while (p--) {
		int s = 0, t = 1;
		
		deq[0] = 0;
		dp[1][0] = 0;

		for (int i = 1; i <= m; i++) {
			while (s + 1 < t && f(i, deq[s]) >= f(i, deq[s + 1])) s++;

			dp[1][i] = arr[i] * i - S[i] + f(i, deq[s]);

			while (s + 1 < t && check(deq[t - 2], deq[t - 1], i)) t--;

			deq[t++] = i;
		}

		swap(dp[0], dp[1]);
	}

	printf("%lld\n", dp[0][m]);

	return 0;
}