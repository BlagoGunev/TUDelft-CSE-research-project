#include <bits/stdc++.h>

using namespace std;

const int N = 20005, M = 15;
int a[N][M];
bool b[N][M];
int t[M];

void Solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> b[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        t[v]++;
        a[u][v]++;
    }
    for (int i = 1; i <= n; i++) {
        int res = 0;
        for (int j = 1; j <= m; j++) {
            if (b[i][j]) {
                res += t[j] - a[i][j];
            }
        }
        cout << res << " ";
    }
    cout << "\n";
}

int main() {
#ifdef NOVACO
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cout.setf(cout.fixed);
    cout.precision(20);
    Solve();
}