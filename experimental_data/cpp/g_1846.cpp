#pragma GCC optimize("O3,unroll-loops,inline,no-stack-protector,fast-math")
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <random>
#include <bitset>

using namespace std;

random_device rd;
mt19937 rnd(rd());

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

const ll inf = 1e8, max_n = 1e5 + 10, lg = 20;
const ld eps = 1e-6, pi = 3.14159265358979;

void no() {
    cout << "NO\n";
}

void yes() {
    cout << "YES\n";
}

ll gen(ll l, ll r) {
    return rnd() % (r - l + 1) + l;
}

int conv(string s) {
    int res = 0;
    for (auto i : s) {
        res *= 2;
        res += i - '0';
    }
    return res;
}

int bit(int a, int id) {
    return (a >> id) & 1;
}

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    int st = conv(s);
    vector<int> d(m), del(m), add(m);
    int sz = (1 << n);
    for (int i = 0; i < m; i++) {
        cin >> d[i];
        cin >> s;
        del[i] = conv(s);
        cin >> s;
        add[i] = conv(s);
    }
    vector<pii> g[sz];
    vector<int> dist(sz, inf);
    dist[st] = 0;
    vector<bool> used(sz, false);
    used[st] = true;
    for (int i = 0; i < m; i++) {
        for (int mask = 0; mask < sz; mask++) {
            int x = 0;
            for (int j = 0; j < n; j++) {
                x += (bit(mask, j) & !bit(del[i], j)) << j;
            }
            x |= add[i];
            g[mask].emplace_back(x, d[i]);
        }
    }
    for (auto [i, j] : g[st]) {
        dist[i] = min(dist[i], j);
    }
    for (int op = 0; op < sz - 1; op++) {
        int id = -1;
        for (int i = 0; i < sz; i++) {
            if (!used[i] && dist[i] != inf) {
                id = i;
            }
        }
        if (id == -1) {
            break;
        }
        for (int i = 0; i < sz; i++) {
            if (!used[i] && dist[i] != inf && dist[id] > dist[i]) {
                id = i;
            }
        }
        used[id] = true;
        for (auto [i, j] : g[id]) {
            dist[i] = min(dist[i], dist[id] + j);
        }
    }
    if (dist[0] == inf) {
        cout << -1 << '\n';
    } else {
        cout << dist[0] << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin >> t;
    while (t--) {
        solve();
    }
}