#include <bits/stdc++.h>

using namespace std;



const int MAXN = 2e5;

int used[MAXN], p[MAXN], indl[MAXN], indr[MAXN];

int id = 0;

vector<array<int, 2>> g[MAXN];



bool dfs(int v) {

    used[v] = id;

    for (auto ed : g[v]) {

        int u = ed[0], i = ed[1];

        if (p[u] == -1 || (used[p[u]] != id && dfs(p[u]))) {

            p[u] = v;

            indr[u] = indl[v] = i;

            return true;

        }

    }

    return false;

}



int usedr[MAXN];



void visit(int v) {

    used[v] = id;

    for (auto ed : g[v]) {

        int u = ed[0];

        if (used[p[u]] != id) {

            usedr[u] = id;

            visit(p[u]);

        }

    }

}



int main() {

    int nl, nr, m, q;

    cin >> nl >> nr >> m >> q;

    for (int i = 0; i < m; ++i) {

        int u, v;

        cin >> u >> v;

        u--; v--;

        g[u].push_back({v, i + 1});

    }

    fill(p, p + nr, -1);

    fill(indl, indl + nl, -1);

    fill(indr, indr + nr, -1);

    bool found = true;

    while (found) {

        found = false;

        id++;

        for (int v = 0; v < nl; ++v) {

            if (used[v] != id && indl[v] == -1) {

                found |= dfs(v);

            }

        }

    }

    id++;

    for (int v = 0; v < nl; ++v) {

        if (used[v] != id && indl[v] == -1) {

            visit(v);

        }

    }

    vector<array<int, 2>> del;

    for (int v = 0; v < nl; ++v) {

        if (used[v] != id) {

            /// cout << v + 1 << " " << indl[v] << endl;

            del.push_back({v + 1, indl[v]});

        }

    }

    for (int v = 0; v < nr; ++v) {

        if (usedr[v] == id) {

            /// cout << -v - 1 << " " << indr[v] << endl;

            del.push_back({-v - 1, indr[v]});

        }

    }

    int start = 0;

    int64_t sum = 0;

    for (auto elem : del) {

        sum += elem[1];

    }

    while (q--) {

        int tp;

        cin >> tp;

        if (tp == 1) {

            cout << "1\n" << del[start][0] << "\n" << (sum -= del[start][1]) << endl;

            start++;

        } else {

            cout << del.size() - start << "\n";

            for (int i = start; i < del.size(); ++i) {

                cout << del[i][1] << " ";

            }

            cout << endl;

        }

        /// cerr << "===" << endl;

    }

    return 0;

}