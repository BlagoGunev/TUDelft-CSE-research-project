#include <bits/stdc++.h>
 
using ld = long double;
using ll = long long;
using ull = unsigned long long;
 
// #define endl '\n'
#define int ll
#define double long double
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define fir first
#define sec second
#define pb push_back
#define mp make_pair
#define ALL(v) begin(v), end(v)
#define current_time chrono::steady_clock::now().time_since_epoch().count()
 
ll TL = 1e9;
ll INF = 1e18;
ll MOD = 1e9 + 7;
ll MOD2 = 1e9 + 1000 - 7;
ll p2 = 101;
ll p = 10;
ld eps = 1e-9;
 
const double PI = acosl(-1);
const ll pw = 1e12;
 
using namespace std;

ll powmod(ll a, ll b, ll mod) {ll res = 1;a %= mod; assert(b >= 0); for(; b; b >>= 1){if(b & 1) res = res * a % mod;a = a * a % mod;}return res;}
ll gcd(ll a, ll b) {return b ? gcd(b,a % b):a;}
mt19937_64 rnd(current_time);
mt19937 rndd(rnd());
uniform_real_distribution <ld> rnddbl(0, 1);

void solve() {
    int n, k; cin >> n >> k;
    vector <int> a(n);
    rep(i, n) cin >> a[i];
    sort(ALL(a));
    int cnt = 0;
    while (!a.empty() && a.back() + cnt <= k) {
        cnt += a.back();
        a.pop_back();
    }
    cout << k - cnt << endl;
}

signed main() {
    cout << setprecision(20) << fixed;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}