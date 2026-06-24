#include <iostream>
#include <vector>
#include <numeric>
#include <queue>
#include <deque>
#include <iomanip>
#include <map>
#include <set>
#include <random>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <functional>
#define slow() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define all(array) array.begin(), array.end()
#define pb push_back
#define eb emplace_back
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2")
// using ll = int;
using ll = long long;
using ld = long double;
using namespace std;
const ll INF = 1e18 + 52;
const ll inf = 1e9 + 52;
const ll mod = 1e9 + 9;
const ll P = 71;


void solve() {
    ll n; cin >> n;
    vector<ll> a(n); for (ll i = 0; i < n; ++i) cin >> a[i];
    ll mx1 = 0;
    ll cnt1 = 0;
    for (ll i = 0; i < n; i += 2) {
        ++cnt1;
        mx1 = max(mx1, a[i]);
    }
    ll mx2 = 0, cnt2 = 0;
    for (ll i = 1; i < n; i += 2) {
        ++cnt2;
        mx2 = max(mx2, a[i]);
    }
    cout << max(mx2 + cnt2, mx1 + cnt1);
}


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    clock_t timer = clock();
#endif
    slow();
    int tc = 1;
    int cfmode = 1;
    if (cfmode) cin >> tc;
    while (tc--) {
        solve();
        if (tc) cout << "\n";
    }
#ifdef LOCAL
    cout << fixed << setprecision(10);
    cout << "\n\nExecution time: " << (long double) (clock() - timer) / CLOCKS_PER_SEC;
#endif
    return 0;
}