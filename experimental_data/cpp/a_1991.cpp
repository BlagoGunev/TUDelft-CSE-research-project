#include "bits/stdc++.h"
#define intt long long
// #define int intt
#define pb push_back
#define endl '\n'
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<intt,intt>
#define ld long double
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(), x.end()
using namespace std;
const int mod = 998244353;
const int inf = 1e9+7;
const intt infl = (intt)1e18+7;
const int sz = 5e5+5;
int a[sz];
int i,j;
void solve(){
    int n;
    cin >> n;
    int mx = 0;
    for ( i = 1; i <= n; i++ ){
        cin >> a[i];
        if ( i%2 )  mx = max(mx, a[i]);
    }
    cout << mx << endl;
}
signed main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
}