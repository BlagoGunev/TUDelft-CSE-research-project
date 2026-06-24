#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

// constants
const bool HAVE_CASE = true;
const ll MOD = 998244353;

void test_case_run() {
    ll x, m;
    cin >> x >> m;

    ll cnt = 0;
    for (ll y = 1; y <= min(m, 4*x); y++) {
        if (y == x) continue;
        ll val = x^y;
        if (x%val == 0 || y%val == 0) cnt++;
    }

    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    if (HAVE_CASE) cin >> t;
    while (t--) test_case_run();

    cout.flush();
    
    return 0;
}