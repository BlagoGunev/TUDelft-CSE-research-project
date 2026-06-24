#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define replr(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define reprl(i, a, b) for (int i = int(a); i >= int(b); --i)
#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define mkp(a, b) make_pair(a, b)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef vector<VPI> VVPI;
typedef pair<ll, ll> PLL;
typedef vector<ll> VL;
typedef vector<PLL> VPL;
typedef vector<VL> VVL;
typedef vector<VVL> VVVL;
typedef vector<VPL> VVPL;
template<class T> T setmax(T& a, T b) {if (a < b) return a = b; return a;}
template<class T> T setmin(T& a, T b) {if (a < b) return a; return a = b;}
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class T>
using indset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll MOD = 1e9 + 7;

void solve() {
    ll n, k;
    cin >> n >> k;
    ll a = 1;
    ll b = 0;

    ll ans = +1;

    while (true) {
        ll c = (a + b) % k;
        a = b;
        b = c;
        // cout << b << " " << flush;
        if (b % k == 0) break;
        ans++;
    }
    cout << (ans*(n%MOD))%MOD << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    /*freopen("mincross.in", "r", stdin); */
    /*freopen("test.out", "w", stdout); */
    int t = 1;
    cin >> t;
    while (t--) solve();
}