#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 998244353LL

int n,t,a[100001],k,x,z,dp[2][100001],c;
ll ans;
vector<int> brick[2];

void solve(){
    for (int i:brick[0]) dp[0][i] = 0;
    for (int i:brick[1]) dp[1][i] = 0;
    brick[0].clear();
    brick[1].clear();
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    ans = 0LL;
    for (int i=n; i; i--){
        k = i%2;
        dp[k][a[i]] = 1;
        brick[k].clear();
        brick[k].push_back(a[i]);
        c = a[i];
        for (int y: brick[1-k]){
            x = (a[i]+y-1)/y;
            z = a[i]/x;
            dp[k][z] += dp[1-k][y];
            ans += (((ll)(x-1)*(ll)i)%MOD)*(ll)dp[1-k][y];
            ans %= MOD;
            if (z != c){
                brick[k].push_back(z);
                c = z;}
            dp[1-k][y] = 0;
        }
    }
    cout << ans << endl;
}

int main(){
    int t=1;
    cin >> t;
    while(t--) solve();
}