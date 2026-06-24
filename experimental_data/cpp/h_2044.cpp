#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

/*
pref1: sum of a[i] * (ni + j)
pref2: sum of a[i] * i
pref3: sum of a[i]
pref1 - ipref2 - jpref3?
*/

const int MAXN = 2005;
ll nums[MAXN][MAXN];
ll pref1[MAXN][MAXN];
ll pref2[MAXN][MAXN];
ll pref3[MAXN][MAXN];

void solve() {
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            cin >> nums[i][j];
        }
    }
    for (int i = 0; i <= n; i ++)
        for (int j = 0; j <= n; j ++)
            pref1[i][j] = pref2[i][j] = pref3[i][j] = 0;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            pref1[i + 1][j + 1] = nums[i][j] * (ll)(n * i + j + 1),
            pref2[i + 1][j + 1] = nums[i][j] * (ll)(i),
            pref3[i + 1][j + 1] = nums[i][j];
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= n; j ++)
            pref1[i][j] += pref1[i - 1][j],
            pref2[i][j] += pref2[i - 1][j],
            pref3[i][j] += pref3[i - 1][j];
    for (int i = 0; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            pref1[i][j] += pref1[i][j - 1],
            pref2[i][j] += pref2[i][j - 1],
            pref3[i][j] += pref3[i][j - 1];
    while (q --) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        ll ans = pref1[y2][x2] - pref1[y2][x1 - 1] - pref1[y1 - 1][x2] + pref1[y1 - 1][x1 - 1];
        ll sub1 = pref2[y2][x2] - pref2[y2][x1 - 1] - pref2[y1 - 1][x2] + pref2[y1 - 1][x1 - 1];
        ll sub2 = pref3[y2][x2] - pref3[y2][x1 - 1] - pref3[y1 - 1][x2] + pref3[y1 - 1][x1 - 1];
        ll i = y1 - 1;
        ll j = x1 - 1;
        // shift left
        ans -= j * sub2;
        // flatten upwards
        ans -= (n - (x2 - x1 + 1)) * sub1;
        // move upwards
        ans -= i * n * sub2;
        // adjust scale
        ans += i * (n - (x2 - x1 + 1)) * sub2;
        cout << ans << endl;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;

    cin >> tt;

    while (tt--) solve();
    return 0;
}