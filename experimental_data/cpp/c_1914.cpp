#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
using ll = long long;
using ld = long double;
const ll INF = 1e18, MOD = 1e9 + 7;
#define fst first
#define snd second

void solve() {
    ll n, k;
    cin >> n >> k;
    vector <ll> a(n), b(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll ans = 0;
    for (ll i = 0, mx = 0, sum = 0; i < min(n, k); i++) {
        mx = max(mx, b[i]);
        sum += a[i];
        ans = max(ans, sum + mx * (k - i - 1));
    }
    cout << ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t12345 = 1;
    cin >> t12345;
    while (t12345--) {
        solve();
        cout << '\n';
    }
    return 0;
}