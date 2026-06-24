#include "bits/stdc++.h"
#ifdef mlocal
#include "./Competitive-Code-Library/snippets/prettyprint.h"
#endif
using namespace std;
#define for_(i, s, e) for (int i = s; i < (int) e; i++)
#define for__(i, s, e) for (ll i = s; i < e; i++)
typedef long long ll;
typedef vector<int> vi;
typedef array<int, 2> ii;
#define endl '\n'

void solve() {
    int l, n, m; cin >> l >> n >> m;
    vi a(l);
    for_(i, 0, l) cin >> a[i];

    vector<vi> mat(n, vi(m));
    for_(i, 0, n) {
        for_(j, 0, m) cin >> mat[i][j];
    }

    bool dp[n][m][l];
    memset(dp, 0, sizeof dp);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            for (int p = l - 1; p >= 0; p--) {
                if (mat[i][j] == a[p] and (p == l - 1 or i + 1 == n or j + 1 == m or !dp[i + 1][j + 1][p + 1])) {
                    dp[i][j][p] = true;
                } else {
                    if (i + 1 < n) dp[i][j][p] |= dp[i + 1][j][p];
                    if (j + 1 < m) dp[i][j][p] |= dp[i][j + 1][p];
                }
            }
        }
    }

    cout << (dp[0][0][0] ? 'T' : 'N') << endl;
}

int main() {
#ifdef mlocal
    freopen("test.in", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}