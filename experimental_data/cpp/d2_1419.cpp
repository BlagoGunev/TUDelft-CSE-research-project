#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vc vector
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()
#define pb push_back

const int maxn = 1e5, inf = 1e9 + 7;


void solve () {
    int n;
    cin >> n;
    vc <int> a(n);
    for (int &i: a) cin >> i;
    sort(a.begin(), a.end());
    int l = 0, r = n - 1;
    vc <int> b;
    int mx = n / 2;
    reverse(a.begin() + mx, a.end());
    while (l <= r) {
        b.pb(a[r--]);
        if (l <= r)
            b.pb(a[l++]);
    }
    int cnt = 0;
    for (int i = 1; i < n - 1; ++i) if (b[i] < b[i - 1] && b[i] < b[i + 1]) ++cnt;
    cout << cnt << '\n';
    for (int i : b)
        cout << i << ' ';
    cout << '\n';
}

signed main () {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
}
/*
1
3
1 2
2 1 1
152 152
151 151
150 150
 */