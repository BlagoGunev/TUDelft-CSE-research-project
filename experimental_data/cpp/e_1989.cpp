#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)998244353;
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	vector<vector<int>>dp(n+1,vector<int>(k+1));
	vector<vector<int>>p(n+1,vector<int>(k+1));
	p[0][0] = 1;
	dp[0][0] = 1;
	for(int i = 0; i<=n; i++){
		p[i][0] = 1;
	}
	for(int t = 1; t<k; t++){
		for(int i = 1; i<=n; i++){
			dp[i][t] = p[i-1][t-1];
			if(i>=3 && i<n)dp[i][t]+=mod-dp[i-2][t-1];
			dp[i][t]%=mod;
			p[i][t] = p[i-1][t] + dp[i][t]; p[i][t]%=mod;
		}
	}
	for(int i = 1; i<=n; i++){
		dp[i][k] = p[i-1][k-1] + p[i-1][k]; dp[i][k]%=mod;
		if(i>=3 && i<n)dp[i][k]+=mod-dp[i-2][k-1];
		if(i>=3 && i<n)dp[i][k]+=mod-dp[i-2][k];
		dp[i][k]%=mod;
		p[i][k] = p[i-1][k]+dp[i][k]; p[i][k]%=mod;
	}
	cout << dp[n][k] << '\n';
	return 0;
}