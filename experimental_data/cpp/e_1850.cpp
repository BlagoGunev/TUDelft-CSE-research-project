#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()

void solve() {
    ll n, c;
    cin >> n >> c;

    vector<ll> a(n);
    for (ll &i : a)
        cin >> i;

    ll lo = 0, hi = INT_MAX;
    while (lo < hi) {
        ll mid = (lo + hi + 1) / 2;

        ll sum = 0;
        for (int i = 0; i < n; i++) {
            ll cur = (a[i] + mid * 2) * (a[i] + mid * 2);
            if (c - sum >= cur)
                sum += cur;
            else {
                sum = c + 1;
                break;
            }
        }

        if (sum <= c)
            lo = mid;
        else
            hi = mid - 1;
    }

    cout << lo << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    
    while (t--)
        solve();

    return 0;
}