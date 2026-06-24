#include<bits/stdc++.h>

#define forin(i, a, b) for(int i = a; i <= b; i++)

#define forde(i, a, b) for(int i = a; i >= b; i--)

#define forv(a, b) for(auto & a : b)

#define fi first

#define se second

#define ii pair<int, int>

using namespace std;

const int N = 2e5 + 10;

int a[3][N], mx[3][N], ma[3][N];

void solve() {

    int m; cin >> m;

    forin(i, 1, 2) {

        forin(j, 1, m) cin >> a[i][j];

    }

    a[1][1] = -1;

    forin(i, 1, 2) {

        forde(j, m, 1) {

            mx[i][j] = max(mx[i][j + 1], a[i][j] + m - j + 1);

            ma[i][j] = max(ma[i][j + 1] + 1, a[i][j] + 1);

        }

    }

    int tmp = -1;

    int res = max(mx[1][2] + m, ma[2][1]);

    forin(j, 1, m) {

        if (j % 2) {

            tmp = max(tmp, a[1][j]) + 1;

            tmp = max(tmp, a[2][j]) + 1;

        }

        else {

            tmp = max(tmp, a[2][j]) + 1;

            tmp = max(tmp, a[1][j]) + 1;

        }

        if (j % 2) {

            int dep = max(tmp + m - j, mx[2][j + 1]);

            int c = max(dep + m - j, ma[1][j + 1]);

            res = min(res, c);

        }

        else {

            int dep = max(tmp + m - j, mx[1][j + 1]);

            int c = max(dep + m - j, ma[2][j + 1]);

            res = min(res, c);

        }

    }

    forin(i, 1, m) ma[1][i] = mx[2][i] = ma[2][i] = mx[1][i] = 0;

    cout << res;

}

int main() {

    cin.tie(0) -> sync_with_stdio(0);

    if (fopen ("task.inp", "r")) {

        freopen ("task.inp", "r", stdin);

        freopen ("task.out", "w", stdout);

    }

    int t; cin >> t;

    while (t--) {

        solve();

        cout << "\n";

    }

}