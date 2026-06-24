#include <bits/stdc++.h>
#define intt long long
#define pb push_back
#define endl '\n'
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<intt,intt>
#define ld long double
using namespace std;
const int sz = 505;
const int inf = 1e9+7;
int a[sz], d[sz];
int dp[sz][sz];
int i,j;
int main(){
    int n, len, k;
    cin >> n >> len >> k;
    for ( i = 1; i <= n; i++ ){
        cin >> d[i];
    }
    d[i]=len;
    for ( i = 1; i <= n; i++ ){
        cin >> a[i];
    }
    for ( i = 1; i <= n; i++ ){
        dp[i][0] = dp[i-1][0]+(d[i+1]-d[i])*a[i];
        for ( j = 1; j <= min(i-1, k); j++ ){
            // cout << i << " " << j << " : " << endl;
            dp[i][j]=inf;
            if ( j != i-1 )
                dp[i][j] = dp[i-1][j] + (d[i+1]-d[i])*a[i];
            for ( int l = i-1; l >= 1 and j-(i-l) >= 0; l-- ){
                dp[i][j] = min(dp[i][j], dp[l][j-(i-l)]+a[l]*(d[i+1]-d[l+1]));
                // cout << l << " " << i+1 << " " << d[i+1]-d[l] << endl;
            }
            // cout << i << " " << j << " " << dp[i][j] << endl << endl;
        }
    }
    int res = inf;
    for ( i = 0; i <= k; i++ )  res = min(res, dp[n][i]);
    cerr << "Answer : ";
    cout << res << endl;
}