#include <bits/stdc++.h>

#define int long long
using namespace std;
const int N = 5e5 + 5;
const int LOG = 20;
int n, type, res, a[N], b[N], lg[N], mn[LOG][N], mx[LOG][N];

pair<int, int> get(int l, int r) {
    int LG = lg[r - l];
    return {min(mn[LG][l], mn[LG][r - (1 << LG)]), max(mx[LG][l], mx[LG][r - (1 << LG)])};
}

void precalc() {
    for (int i = 2; i < N; i++) {
        lg[i] = lg[i / 2] + 1;
    }
    for (int i = 0; i <= n; i++) {
        mn[0][i] = max(a[i], a[i + 1]);
        mx[0][i] = min(a[i], a[i + 1]);
    }
    for (int i = 0; i < LOG - 1; i++) {
        for (int j = 0; j <= n - (1 << i); j++) {
            mn[i + 1][j] = min(mn[i][j], mn[i][j + (1 << i)]);
            mx[i + 1][j] = max(mx[i][j], mx[i][j + (1 << i)]);
        }
    }
}

signed main() {
    cin >> n;
    type = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = a[1], a[n + 1] = a[n];
    precalc();
    for (int i = 1; i <= n; i++) {
        int l = 1, r = min(n + 1 - i, i), cnt = 0;
        int pff = 400;
        while (l <= r && pff--) {
            int m = (l + r) / 2;
            auto t = get(i - m, i + m);
            if (t.first <= t.second) {
                r = m - 1;
                cnt = m;
            }
            else {
                l = m + 1;
            }
        }
        if (!type)
            continue;
        if (cnt == 1) {
            b[i] = a[i];
        } else {
            auto got = get(i - cnt, i + cnt);
            if (a[i] > a[i - 1]) {
                if (cnt % 2 == 0) {
                    b[i] = got.second;
                } else {
                    b[i] = got.first;
                }
            } else {
                if (cnt % 2 == 1) {
                    b[i] = got.second;
                } else {
                    b[i] = got.first;
                }
            }
        }
        res = max(res, cnt - 1);
    }
    cout << res << '\n';
    if (type == 1) {
        for (int i = 1; i <= n; i++) {
            cout << b[i] << ' ';
        }
    }
    return 0;
}