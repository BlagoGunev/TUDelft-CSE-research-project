#include <bits/stdc++.h>
 
using namespace std;

const int INF = 1'000'000'007;
const int MOD = 998244353;

void solve(){
    int n, x, m;
    cin >> n >> x >> m;

    vector<int> fib(44);
    fib[1] = 1;
    fib[2] = 1;
    for (int i = 3; i <= 43; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    int sz = fib[10] * n + 1;
    vector<int> dp(sz, INF);
    dp[0] = 0;

    for (int i = 0; i < sz; i++){
        for (int j = 1; j <= 43; j++){
            if (i + fib[j] < sz){
                dp[i + fib[j]] = min(dp[i + fib[j]], dp[i] + 1);
            }
        }
    }

    vector<vector<int>> dp2(n + 1, vector<int> (sz));
    dp2[0][0] = 1;

    for (int k = 1; k <= x; k++){
        for (int i = 0; i < n; i++){
            for (int j = sz - 1; j >= 0; j--){
                if (j + fib[k] < sz){
                    dp2[i + 1][j + fib[k]] = (dp2[i + 1][j + fib[k]] * 1ll + dp2[i][j]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < sz; j++){
        if (dp[j] == m){
            ans = (ans * 1ll + dp2[n][j]) % MOD;
        }
    }

    cout << ans << '\n';
}
 
signed main()
{
#ifdef FELIX
	auto _clock_start = chrono::high_resolution_clock::now();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tests = 1;
	//cin >> tests;
	for (int test = 0; test < tests; test++){
		solve();
	}
#ifdef FELIX
	cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
		chrono::high_resolution_clock::now()
			- _clock_start).count() << "ms." << endl;
#endif
	return 0;
}