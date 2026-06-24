#include <bits/stdc++.h>
using namespace std;

const int N = 200;

int n;
long long x;
pair<long long, long long> a[N];

int main(){


    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while (q--){
        cin >> n >> x;
        long long mx = 0;
        for (int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second, mx = max (mx, a[i].first);
        long long ans = 1e18;
        for (int i = 1; i <= n; ++i){
            if (a[i].second > a[i].first){
                if (x - a[i].first <= 0) ans = min (ans, 1ll);
                continue;
            }
            long long z = x - mx;
            long long l = 0, r = 1e9;
            while (l < r - 1){
                long long mid = (l + r) >> 1;
                if (z - mid * a[i].first + mid * a[i].second <= 0) r = mid;
                else l = mid;
            }
            if (z - l * a[i].first + l * a[i].second <= 0) ans = min (ans, 1 + l);
            if (z - r * a[i].first + r * a[i].second <= 0) ans = min (ans, 1 + r);
        }
        if (ans == 1e18) cout << -1 << '\n'; else
        cout << ans << '\n';
    }

}