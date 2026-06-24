#include <bits/stdc++.h>
using namespace std;
const int kMaxN = 5e5 + 1;
struct V {
    int d, f, w;
    vector<pair<int, int>> e;
} v[kMaxN];
int n, m, d[kMaxN], f[kMaxN], g[kMaxN];
pair<int, int> e[kMaxN];
void T(int x) {
    for (auto i : v[x].e) {
        int y = i.first, w = i.second;
        if (y != v[x].f) {
            if (!v[y].d) {
                v[y].d = v[x].d + 1, v[y].f = x, v[y].w = w, T(y);
            } else if (v[y].d < v[x].d) {
                int _f = v[y].f, _w = v[y].w, o = 1;
                int mxo = y, mxw = w, mno = y, mnw = w;
                for (int j = x; j != y; j = v[j].f) {
                    if (v[j].w > mxw) {
                        mxo = j, mxw = v[j].w;
                    } else if (v[j].w < mnw) {
                        mno = j, mnw = v[j].w;
                    }
                }
                v[y].f = x, v[y].w = w;
                for (int j = mxo; v[j].f != mno; j = v[j].f) {
                    o &= v[j].w > v[v[j].f].w;
                }
                for (int j = mno; v[j].f != mxo; j = v[j].f) {
                    o &= v[j].w < v[v[j].f].w;
                }
                if (o) {
                    d[v[mno].w] = v[mxo].w;
                }
                v[y].f = _f, v[y].w = _w;
            }
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y, e[i] = {x, y};
        v[x].e.push_back({y, i}), v[y].e.push_back({x, i});
    }
    v[1].d = 1, T(1);
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
    }
    for (int i = m; i >= 1; i--) {
        int x = e[i].first, y = e[i].second;
        f[x] += f[y], f[x] -= g[d[i]], f[y] = g[i] = f[x];
    }
    for (int i = 1; i <= n; i++) {
        cout << f[i] - 1 << " \n"[i == n];
    }
    return 0;
}