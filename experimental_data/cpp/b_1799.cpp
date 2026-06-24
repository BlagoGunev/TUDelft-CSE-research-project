// In the name of God
//        : )
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
const int N = 2e5 + 5;
int n, a[N];
void solve() {
    cin >> n;
    int mn = 1e9 + 10, mx = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], mn = min(mn, a[i]), mx = max(mx, a[i]);
    if (mn == mx) {
        cout << 0 << '\n';
        return;
    }
    if (mn == 1) {
        cout << -1 << '\n';
        return;
    }
    vector<pair<int, int> > ans;
    while (true) {
        mn = *min_element(a, a + n);
        mx = *max_element(a, a + n);
        if (mn == mx)
            break;
        int imx = 0, imn = 0;
        for (int i = 0; i < n; i ++) {
            if (a[i] == mn)
                imn = i;
            if (a[i] == mx)
                imx = i;
        }
        ans.pb(mp(imx, imn));
        a[imx] = (a[imx] + a[imn] - 1) / a[imn];
    }
    cout << ans.size() << '\n';
    for (auto x : ans)
        cout << ++x.fi << ' ' << ++x.se << '\n';

}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}