#include <bits/stdc++.h>

using namespace std;



const int MAXN = 5e3;

vector<int> g[MAXN];

int p[MAXN], sz[MAXN];



int get(int v) {

    if (v == p[v]) return p[v];

    return p[v] = get(p[v]);

}



void join(int u, int v) {

    u = get(u); v = get(v);

    if (u == v) return;

    if (sz[u] < sz[v]) swap(u, v);

    sz[u] += sz[v];

    p[v] = u;

}



vector<int> in[MAXN];



void solve(int n) {

    for (int i = 0; i < n; ++i) {

        in[i].clear();

        for (auto u : g[i]) {

            join(i, u);

        }

    }

    for (int i = 0; i < n; ++i) {

        in[get(i)].push_back(i);

    }

    vector<int> comp;

    for (int i = 0; i < n; ++i) {

        if (in[i].empty()) continue;

        if (sz[i] == n) {

            cout << "0\n";

            return;

        }

        if (sz[i] == 1) {

            cout << "1\n";

            cout << i + 1 << "\n";

            return;

        }

        comp.push_back(i);

        int k = sz[i];

        int cnt = 0;

        for (int v : in[i]) {

            if ((int)g[v].size() == k - 1) {

                cnt++;

            }

        }

        if (cnt == k) continue;

        if (cnt >= 1) {

            for (int v : in[i]) {

                if ((int)g[v].size() != k - 1) {

                    cout << "1\n";

                    cout << v + 1 << "\n";

                    return;

                }

            }

        }

        vector<int> used(n, 0);

        int v = i;

        while (true) {

            used[v] = 1;

            bool f = false;

            for (auto u : g[v]) {

                if (!used[u]) {

                    v = u;

                    f = true;

                    break;

                }

            }

            if (!f) {

                cout << "1\n";

                cout << v + 1 << "\n";

                return;

            }

        }

    }

    if ((int)comp.size() >= 3) {

        cout << "2\n";

        cout << comp[0] + 1 << " " << comp[1] + 1 << "\n";

        return;

    }

    if (sz[comp[0]] > sz[comp[1]]) {

        swap(comp[0], comp[1]);

    }

    cout << sz[comp[0]] << "\n";

    for (auto elem : in[comp[0]]) {

        cout << elem + 1 << " ";

    }

    cout << "\n";

}



main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0); cout.tie(0);

    int tst;

    cin >> tst;

    while (tst--) {

        int n;

        cin >> n;

        for (int i = 0; i < n; ++i) {

            g[i].clear();

            p[i] = i; sz[i] = 1;

            string s;

            cin >> s;

            for (int j = 0; j < n; ++j) {

                if (s[j] == '1') {

                    g[i].push_back(j);

                }

            }

        }

        solve(n);

    }

    return 0;

}