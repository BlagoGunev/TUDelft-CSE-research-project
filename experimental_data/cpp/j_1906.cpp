#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define sd second
#define fs first
#define pb push_back
#define eb emplace_back

const int N = 5005;
const ll MOD = 998244353;
const ll INF = 1e9;

ll dp[N][N][2], p[N];
int a[N];

ll add(ll x, ll y) {
    ll res = (x+y)%MOD;
    if (res < 0) res += MOD;
    return res;
}

void solve() {
    int n; cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    p[0] = (ll) 1;
    for (int i=1; i<=n; i++) p[i] = (p[i-1]*2)%MOD;
    for (int i=0; i<=n+1; i++) dp[n+1][i][0] = dp[n+1][i][1] = 1;
    for (int i=n; i>=2; i--) {
        for (int j=1; j<=i; j++) {
            for (int k=0; k<2; k++) {
                if (j == i-1 && k==0 && i!=2 || j==1 && k==1) continue;
                dp[i][j][k] = add(dp[i][j][k], dp[i][j-1][0]);
                if (k==0 || a[i-1] > a[i-2]) {
                    dp[i][j][k] = add(dp[i][j][k], dp[i+1][j+1][1]*p[j-1]%MOD);
                }
            }
        }
    }
    cout << dp[2][1][0];

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}