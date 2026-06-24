#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define rrep(i, n) for(ll i = n - 1; i > -1; i--)
#define all(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second
const ll INF = 999999999999999;
const ll MOD = 1000000007 /*988244353*/;
const ll MAX_N = 500010;
ll a, b, c, d, e, f, g, h, x, y, z, p, q, m, n, t, r, k, w, l, ans, i, j;
string S, T;
vl A, B;
void solve() {
    while(t--) {
        cin >> a >> b >> c >> d;
        if(a <= b) {
            cout << b << endl;
            continue;
        }
        if(c <= d) {
            cout << -1 << endl;
            continue;
        }
        cout << b + c * ((a - b - 1) / (c - d) + 1) << endl;
    }
}
int main() {
    // cout<<fixed<<setprecision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> t;
    solve();
}