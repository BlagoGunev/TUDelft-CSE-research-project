#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 

// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag, tree_order_statistics_node_update> 
// #define ordered_map tree<ll, ll, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long int
#define vi vector<ll>
#define vvi vector<vi>
#define pi pair<ll, ll>
#define vvpi vector<vector<pi>>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define abs std::abs
#define fi first
#define se second
#define nline "\n"
#define sq(a) ((a) * (a))
#define sz(a) (ll) a.size()
#define pb push_back
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
const ll N = 1e7 + 10;
const ll M = 1e9 + 7;

ll gcd(ll a,ll b){
    if (b==0) return a;
    return gcd(b, a%b); 
}

void solve() {

    ll a, b;
    cin >> a >> b;
    if(a == 1) {
        cout << b * b << endl;
        return;
    }
    if(a == gcd(a, b)) {
        cout << b * b / a << endl;
        return;
    }
    cout << a * b / (gcd(a, b)) << endl;

}

signed main() {
    fast
    #ifndef ONLINE_JUDGE
        freopen("io/input.txt", "r", stdin);
        freopen("io/output.txt", "w", stdout);
        freopen("io/error.txt", "w", stderr);
    #endif
    ll T;
    cin >> T;
    while(T--)
        solve();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}