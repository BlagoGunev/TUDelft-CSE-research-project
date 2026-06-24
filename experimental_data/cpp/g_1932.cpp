#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL exgcd(LL a, LL b, LL &x, LL &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    } else {
        LL d = exgcd(b, a % b, y, x);
        y -= (a / b) * x;
        return d;
    }
}

void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<vector<int>> e(n);
    vector<int> l(n), s(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<bool> vis(n);
    priority_queue<array<LL, 2>> q;
    const LL INF = 1e18;
    vector<LL> dis(n, INF);
    dis[0] = 0;

    auto get = [&](LL h1, LL h2, LL s1, LL s2) -> LL {
        if (h1 == h2) {
            return 0;
        }
        if (s1 == s2) {
            return -1;
        }
        if (s1 < s2) {
            swap(s1, s2);
            swap(h1, h2);
        }
        LL a = s1 - s2;
        LL b = h;
        LL c = h2 - h1;
        LL x, y;
        LL d = exgcd(a, b, x, y);
        if (c % d) {
            return -1;
        }
        x *= c / d, y *= c / d;
        LL k1 = b / d, k2 = a / d;
        LL tmp;
        if (x < 0) {
            tmp = (-x + k1 - 1) / k1;
        } else {
            tmp = (-x) / k1;
        }
        x += tmp * k1;
        return x;
    };

    q.push({0, 0});
    while (q.size()) {
        int u = q.top()[1];
        q.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] =1;
        for (int v : e[u]) {
            LL t = get((l[u] + dis[u] % h * s[u]) % h, (l[v] + dis[u] % h * s[v]) % h, s[u], s[v]);
            if (t == -1) {
                continue;
            }
            t += 1;
            if (dis[v] > dis[u] + t) {
                dis[v] = dis[u] + t;
                q.push({-dis[v], v});
            }
        }
    }

    if (dis[n - 1] == INF) {
        cout << -1 << '\n';
    } else {
        cout << dis[n - 1] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}