#include<bits/stdc++.h>
#include<fstream>
using namespace std;
#define sz(a) (int)a.size()
#define ALL(v) v.begin(), v.end()
#define ALLR(v) v.rbegin(), v.rend()
#define ll long long
#define pb push_back
#define forr(i, a, b) for(int i = a; i < b; i++)
#define dorr(i, a, b) for(int i = a; i >= b; i--)
#define ld long double
#define vt vector
#include<fstream>
#define fi first
#define se second
#define pll pair<ll, ll>
#define pii pair<int, int>
#define mpp make_pair
const ld PI = 3.14159265359, prec = 1e-9;;
//using u128 = __uint128_t;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
const ll mod = 1e9 + 7, pr = 31;
const int mxn = 2e5 + 5, mxd = 250 * 250, sq = 100, mxv = 5e4 + 1, mxq = 2e6 + 5;
//const int base = (1 <<18);
const ll inf = 1e9 + 5, neg = -69420, inf2 = 1e14;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//have fun!!!!!
ll n, x;
ll a[mxn + 1], dp[mxn + 1], rp[mxn + 1];
void solve(){
    cin >> n >> x;
    for(int i = 1; i <= n; i++)cin >> a[i];
    int r = 1;
    ll tot = 0;
    for(int i = 1; i <= n; i++){
        if(i > 1)tot -= a[i - 1];
        while(r <= n && tot <= x){
            tot += a[r]; r++;
        }
        if(tot <= x){
            rp[i] = -1;
        }else{
            rp[i] = r;
        }
    }
    dp[n + 1] = 0;
    ll ans = 0;
    for(int i = n; i >= 1; i--){
        if(rp[i] == -1){
            dp[i] = 0;
        }else{
            dp[i] = dp[rp[i]] + 1;
        }
        ans += 1LL * (n - i + 1) - dp[i];
    }
    cout << ans << "\n";
}
 
 
 
 
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("THREE.inp", "r", stdin);
    //freopen("THREE.out", "w", stdout);
    int tt; cin >> tt;
    while(tt--){
        solve();
 
    }
    return(0);
}