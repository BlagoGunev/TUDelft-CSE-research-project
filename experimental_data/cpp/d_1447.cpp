#include<bits/stdc++.h>

#define pb push_back

using namespace std;

typedef long long ll;

typedef pair<int, int> PII;

const int N = 3e5 + 10, P = 1e9 + 7, mod = 998244353;

string a, b;

int dp[5010][5010];

void solve(){

	int n, m;

	cin >> n >> m;

	cin >> a >> b;

	a = " " + a;

	b = " " + b;

	int ans = 0;

	for(int i = 1; i <= n; i++){

		for(int j = 1; j <= m; j++){

			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) - 1;

			if(a[i] == b[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);

			dp[i][j] = max(dp[i][j], 0);

			ans = max(dp[i][j], ans);

		}

	}

	cout << ans << endl;

}               



int main(){

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;

	//cin >>t;

	//while(t--){

		solve();

	//}

	return 0;

}