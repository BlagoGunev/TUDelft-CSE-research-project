#include <bits/stdc++.h>



using namespace std;

typedef long long ll;

typedef pair<int, int> PII;

const int inf = 1 << 30;



void solve() {

    int n, m;

    cin >> n >> m;

    vector g(n, multiset<int>());

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            int x;

            cin >> x;

            g[i].insert(x);

        }

    }

    vector<vector<int>> ans(n, vector<int>(m));

    int j = 0;

    while (true) {

        int mn = inf;

        for (int i = 0; i < n; i++) {

            mn = min(mn, g[i].empty() ? inf : *g[i].begin());

        }

        if (mn == inf) break;

        int now = -1;

        for (int i = 0; i < n; i++) {

            if (*g[i].begin() == mn) {

                now = i;

                break;

            }

        }

        for (int i = 0; i < n; i++) {

            if (i != now) {

                ans[i][j] = *g[i].rbegin();

                auto it = prev(g[i].end());

                g[i].erase(it);

            } else {

                ans[i][j] = *g[i].begin();

                g[i].erase(g[i].begin());

            }

        }

        j++;

    }

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            cout << ans[i][j] << " \n"[j == m - 1];

        }

    }

}



int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);



    int T = 1;

    cin >> T;

    while (T--) {

        solve();

    }

    return 0;

}