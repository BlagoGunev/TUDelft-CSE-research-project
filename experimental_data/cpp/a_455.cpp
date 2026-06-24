#include <algorithm>
#include <iostream>
#include <iomanip>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
using namespace std;
//#pragma comment(linker,"/STACK:102400000,102400000")

int n;
long long sum[100011];
long long dp[100011];

int MAIN()
{
	memset(sum, 0, sizeof(sum));
	memset(dp, 0, sizeof(dp));
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		sum[x] += x;
	}
	dp[0] = 0;
	dp[1] = sum[1];
	dp[2] = sum[2];

	for(int i = 3; i <= 100000; i++)
	{
		dp[i] = sum[i] + max(dp[i-2], dp[i-3]);
	}
	long long ans = 0;

	for(int i = 1; i <= 100000; i++)
		ans = max(ans, dp[i]);
	cout << ans << endl;
	return 0;
}

int main()
{
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	return MAIN();
}