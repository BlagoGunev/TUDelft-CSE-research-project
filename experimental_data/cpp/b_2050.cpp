#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#include "headers/debug.h"
#else
#define debug(...) 42
#endif

using namespace std;

#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define LLINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define uniq(x) sort(all(x)); x.resize(unique(all(x))-x.begin());
#define sz(x) (int)x.size()
#define pw(x) (1LL<<x)
#define pb push_back
#define int long long

using pii = pair<int, int>;
using ll = long long;
using ld = long double;
const ll MOD = 1e9 + 7;
const long double PI = acos(-1.0);

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n != 0) {
        cout << "NO\n";
        return;
    }
    int v = sum / n;
    int ns = 0;
    int cs = 0;
    for (int i=0; i<n; i+=2) {
        ns += a[i];
        cs++;
    }
    int ns2 = 0;
    int cs2 = 0;
    for (int i=1; i<n; i+=2) {
        ns2 += a[i];
        cs2 ++;
    }
    if (ns % cs != 0 || ns / cs != v) {
        cout << "NO\n";
        return;
    } 
    if (cs2 == 0 || (ns2 % cs2 == 0 && ns2 / cs2 == v)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 1; cin >> t;
    while(t--)
        solve();
}