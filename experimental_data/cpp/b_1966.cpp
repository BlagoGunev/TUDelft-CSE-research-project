#include <bits/stdc++.h>

using namespace std;

using ld = long double;
using ll = long long;
#define int long long
const ll N = 301;
const ld EPS = 1e-9;
const int MOD = 1e9 + 9;

void solve1();

void solve2();

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll qwerty = 1;
    cin >> qwerty;
    while (qwerty--) {
        solve1();
    }
}

void solve1() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char q;
            cin >> q;
            if (q == 'W') {
                v[i][j] = 1;
            }
        }
    }
    bool flag = false;
    if (v[0][0] == v[n - 1][m - 1] || v[n - 1][0] == v[0][m - 1]) {
        flag = true;
    }
    int kol1 = 0, kol2 = 0;
    for (int i = 0; i < m; i++) {
        kol1 += (v[0][i] == v[n - 1][m - 1]);
    }
    for (int i = 0; i < n; i++) {
        kol2 += (v[i][0] == v[n - 1][m - 1]);
    }
    if (kol1 > 0 && kol2 > 0) {
        flag = true;
    }
    kol1 = 0, kol2 = 0;
    for (int i = 0; i < m; i++) {
        kol1 += (v[n - 1][i] == v[0][0]);
    }
    for (int i = 0; i < n; i++) {
        kol2 += (v[i][m - 1] == v[0][0]);
    }
    if (kol1 > 0 && kol2 > 0) {
        flag = true;
    }
    kol1 = 0, kol2 = 0;
    for (int i = 0; i < m; i++) {
        kol1 += (v[0][i] == v[n - 1][0]);
    }
    for (int i = 0; i < n; i++) {
        kol2 += (v[i][m - 1] == v[n - 1][0]);
    }
    if (kol1 > 0 && kol2 > 0) {
        flag = true;
    }
    kol1 = 0, kol2 = 0;
    for (int i = 0; i < m; i++) {
        kol1 += (v[n - 1][i] == v[0][m - 1]);
    }
    for (int i = 0; i < n; i++) {
        kol2 += (v[i][0] == v[0][m - 1]);
    }
    if (kol1 > 0 && kol2 > 0) {
        flag = true;
    }
    if (flag) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}