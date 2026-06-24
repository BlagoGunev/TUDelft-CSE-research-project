#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
#define str string

#define all(v)  v.begin(), v.end()
#define fi      first
#define se      second
#define pb      push_back
#define ent cout << "\n";

using namespace std;

const long long MOD = 1e9+7, ininff = 1e18;

void run() {
    ll n;
    cin >> n;

    ll q;
    cin >> q;

    str s;
    cin >> s;

    s = '?' + s;

    ll a[n+17] = {}, b[n+17] = {};

    for (ll i=1; i<=n; i++) {
        b[i] = b[i-1];
        if (s[i] == '0') {
            b[i] = i;
        }
    }
    a[n+1] = n+1;
    for (ll i=n; i>=1; i--) {
        a[i] = a[i+1];
        if (s[i] == '1') {
            a[i] = i;
        }
    }

    set <pair <ll, ll>> st;

    // for (ll i=1; i<=n; i++) {
    //     cout << a[i] << ' ';
    // }
    // ent;
    // for (ll i=1; i<=n; i++) {
    //     cout << b[i] << ' ';
    // }
    // ent;

    while (q--) {
        ll l, r;
        cin >> l >> r;

        if (a[l] <= b[r]) {
            st.insert({a[l], b[r]});
        }
        else {
            st.insert({-1, -1});
        }
    }

    cout << st.size() << '\n';
}

int main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    ll ttest=1;
    cin >> ttest;

    for (ll test_number=1; test_number<=ttest; test_number++) {
        run();
    }

    return 0;
}