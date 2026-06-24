#include <bits/stdc++.h>

using namespace std;

#define ll long long int



void solve() {

    ll n, ans = -1;

    cin >> n;

    vector<ll> vc(n);

    for (int i = 0; i < n; i++) cin >> vc[i], ans = min(ans, vc[i]);

    for (int i = 0; i < n; i++) ans &= vc[i];

    cout << ans << endl;

}



void T() {

    ll t;

    cin >> t;

    while (t--) {

        solve();

    }

}



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    T();

    // solve();

    return 0;

}