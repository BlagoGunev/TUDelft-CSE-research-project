// In the name of God.
// We're nothing and you're everything.
// Ya Ali!
 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 14, mod = 998244353, maxv = 1e5 + 14;
 
int n, k, a[maxn], dp[maxn][maxn], sum[maxn][maxn];
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		sum[1][i] = i;
	int ans = 0, last = 0;
	for(int b = maxv / (k - 1) + 1; b > 0; b--){
		//cerr << b << "====9=========\n";
		for(int j = 2; j <= k; j++){
			int ptr = j - 1;
			for(int i = j; i <= n; i++){
				while(a[i] - a[ptr + 1] >= b)
					ptr++;
				if(a[i] - a[ptr] >= b)
					dp[j][i] = sum[j - 1][ptr];
				else
					dp[j][i] = 0;
				sum[j][i] = sum[j][i - 1] + dp[j][i];
				if(sum[j][i] >= mod)
					sum[j][i] -= mod;
				//cerr << j << ' ' << i << ' ' << dp[j][i] << '\n';
			}
		}
		//cerr << b << ' ' << sum[k][n] << '\n';
		ans = (ans + (ll) (sum[k][n] - last + mod) * b) % mod;
		last = sum[k][n];
	}
	cout << ans << '\n';
}