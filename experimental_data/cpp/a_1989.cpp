#include <bits/stdc++.h>
#pragma GCC Optimize("O3")
#pragma GCC target( "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native" ) 
#pragma GCC optimize("unroll-loops") 
using namespace std;
#define int long long
#define endl "\n"
const int mod = 1e9 + 7;
const int B = 5e5 + 100;
const int INF = 1e18 + 100;
void solve() {
    int n;
    cin >> n;
    int x[n + 1],y[n + 1];
    for(int i = 1;i <= n;i++) {
        cin >> x[i] >> y[i];
        if(y[i] < -1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t--) {
        solve();
    }
}