#include <bits/stdc++.h>
#define ar array
//#define int long long

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;

void solve() {
    ll n, x, y, sum = 0; cin >> n >> x >> y;
    vector<ll> a(n+1);
    for(int i=1; i<=n; i++) cin >> a[i], sum += a[i];
    ll ans = 0;

    sort(a.begin()+1, a.end());

    for(int i=1; i<=n; i++) {
        int l=1, r=i-1, pos=-1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(sum - a[i] - a[mid] >= x) pos = mid, l = mid + 1;
            else r = mid - 1;
        }
        if(pos == -1) continue;
        l=1, r=i-1;
        int pos2=-1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(sum - a[i] - a[mid] <= y) pos2 = mid, r = mid - 1;
            else l = mid + 1;
        }

        if(pos2 == -1) continue;
        ans += abs(pos-pos2+1);
    }

    cout << ans << '\n';
}

signed main() {
    int t = 1; cin >> t;
    while(t--) solve();

    return 0;
}