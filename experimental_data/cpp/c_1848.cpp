#include <bits/stdc++.h>
#ifdef SHARAELONG
#include "../../cpp-header/debug.hpp"
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll solve(ll f, ll s, ll q) {
    ll a = f, b = s;
    while (true) {
        if (q == 0) return a;
        if (b == 0) {
            return q % 3 == 1 ? 0 : a;
        } else if (a >= 2*b) {
            ll op_cnt = 3 * (a / 2 / b);
            if (q <= op_cnt) {
                return q % 3 == 1 ? b : a - (2ll * q / 3) * b;
            } else {
                q -= op_cnt;
                a %= (2ll * b);
            }
        } else {
            ll bb = b;
            b = abs(a - b);
            a = bb;
            q--;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int& x: a) cin >> x;
    for (int& x: b) cin >> x;
    
    set<int> s;
    for (int i=0; i<n; ++i) {
        ll INF = 1e17;
        if (a[i] == 0 && b[i] == 0) continue;
        ll ret1 = solve(a[i], b[i], INF);
        ll ret2 = solve(a[i], b[i], INF+1);
        ll ret3 = solve(a[i], b[i], INF+2);
        if (ret1 == 0) s.insert(1);
        else if (ret2 == 0) s.insert(2);
        else s.insert(3);
    }
    cout << (s.size() <= 1 ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    cin >> cases;
    while (cases--) solve();
}