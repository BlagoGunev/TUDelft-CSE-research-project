#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>

using namespace std;

using ll = long long;

const int maxn = 2e5 + 10;
const int maxm = 5;
const int mod = 1000000007;
const int inf = 2e9 + 7;
const ll llinf = 1e18 + 5;

int n, k;
int a[maxn];

bool get(ll x) {
    for (int i = 0; i < k; ++i) {
        int j = upper_bound(a, a + n, x) - a;
        x -= j;
    }
    return x == 0;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll lf = 0, rg = n * 1LL * k + 1;
    while (rg - lf > 1) {
        ll md = (lf + rg) / 2;
        if (get(md)) {
            lf = md;
        } else {
            rg = md;
        }
    }
    cout << rg << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);

//    freopen("/Users/kefaa/ClionProjects/untitled/input.txt", "r", stdin);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}