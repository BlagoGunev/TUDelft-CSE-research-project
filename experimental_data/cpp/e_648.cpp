// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;

const ll INF = 1e9 + 1;
const ld EPS = 1e-13;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
    int dist, pred, ind;
    Node() : dist(INF), pred(-1), ind(-1) {}
    Node(int d, int p, int i) : dist(d), pred(p), ind(i) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector <int> sz(n), a(n), ten(n, 1);
    vector <vector <int>> is(k, vector <int> (11, -1));
    for (int i=0; i < n; ++i) {
        cin >> a[i];
        int b = a[i];
        if (b == 0) {
            sz[i] = 1;
            ten[i] = 10;
            is[0][1] = i;
        }
        while (b) {
            b /= 10;
            sz[i]++;
            ten[i] *= 10;
            ten[i] %= k;
        }
        is[a[i] % k][sz[i]] = i;
    }
    vector <vector <int>> m(k + 1, vector <int> (k + 1, -1));
    for (int i=0; i < k; ++i) {
        for (int j=0; j < k; ++j) {
            for (int s=1; s < 11; ++s) {
                if (is[j][s] != -1) {
                    int to = (i * ten[is[j][s]] % k + j) % k;
                    if (m[i][to] == -1 || sz[m[i][to]] > sz[is[j][s]]) {
                        m[i][to] = is[j][s];
                        if (i == 0) {
                            m[k][to] = is[j][s];
                        }
                        if (to == 0) {
                            m[i][k] = is[j][s];
                        }
                    }
                }
            }
        }
    }
    vector <Node> dist(k + 1);
    dist[0] = Node(0, -1, -1);
    vector <bool> used(k + 1, false);
    while (true) {
        int v = -1;
        for (int i=0; i <= k; ++i) {
            if (!used[i] && (v == -1 || dist[i].dist < dist[v].dist)) {
                v = i;
            }
        }
        if (v == -1 || dist[v].dist == INF) break;
        used[v] = true;
        for (int to=0; to <= k; ++to) {
            if (m[v][to] != -1 && dist[to].dist > dist[v].dist + sz[m[v][to]]) {
                dist[to] = Node(dist[v].dist + sz[m[v][to]], v, m[v][to]);
            }
        }
    }
    if (dist[k].dist == INF) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        vector <int> ans;
        int v = k;
        while (dist[v].pred != -1) {
            ans.push_back(a[dist[v].ind]);
            v = dist[v].pred;
        }
        for (int i=(int) ans.size() - 1; i >= 0; --i) {
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}