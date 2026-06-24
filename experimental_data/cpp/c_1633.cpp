#include <bits/stdc++.h>

#define f first
#define s second
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define pb push_back
#define ins insert
#define lb lower_bound
#define ub upper_bound

using namespace std;

using ll = long long;
using ld = long double;

using vi = vector<int>;
using vl = vector<ll>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

ll hc, dc;
ll hm, dm;
ll k, w, a;

void solve() {
    cin >> hc >> dc >> hm >> dm >> k >> w >> a;
    for (ll i = 0; i <= k; i++) {
        // i - number of coins spent to w
        ll j = k - i;
        ll cur_hc = hc + j * a, cur_dc = dc + i * w;
        ll opsM = (cur_hc + dm - 1) / dm;
        ll opsH = (hm + cur_dc - 1) / cur_dc;
        if (opsH <= opsM) {
            cout << "YES\n";
            return;
        }
        // meh...
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}