#include <bits/stdc++.h>

#define sz(v) (ll) v.size()



using namespace std;

typedef long long ll;

const ll N = 2e5 + 10;

const ll inf = 1e8;



ll n,s,a[N],x[N],dp[N][2];



void solve(){

	cin >> n >> s;

	for(ll i = 1; i <= n; ++i) cin >> a[i];

	x[1] = a[1], x[n] = a[n];

	for(ll i = 2; i <= n-1; ++i){

		x[i] = (a[i] <= s ? a[i] : max(s,s-a[i]));

	}

	dp[2][1] = x[1]*x[2], dp[2][0] = (a[2]-x[2])*x[1];

	for(ll i = 3; i <= n-1; ++i){

		dp[i][1] = min(dp[i-1][1]+(a[i-1]-x[i-1])*x[i],dp[i-1][0]+x[i-1]*x[i]);

		dp[i][0] = min(dp[i-1][1]+(a[i-1]-x[i-1])*(a[i]-x[i]),dp[i-1][0]+x[i-1]*(a[i]-x[i]));

		// cout << dp[i][1] << " " << dp[i][0] << endl;

	}

	cout << min(dp[n-1][0]+x[n-1]*x[n],dp[n-1][1]+(a[n-1]-x[n-1])*x[n]) << endl;

}



int main(){

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t; cin >> t;

	while(t--) solve();

	return 0;

}