#include <bits/stdc++.h>

using namespace std;

using ll = long long;
vector<vector<ll>> g;
vector<bool> vis;
vector<ll> siz;
ll N;

ll sum(ll x) {
    vis[x] = true;

    ll s = 1;
    ll best = 1e18;
    for (auto child : g[x]) {
        if (vis[child]) continue;
        best = min(best, sum(child));
        s += siz[child];
    }
    best = min(best, s * s + ( N - s) * ( N - s));

    siz[x] = s;
    return best;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll t; cin >> t;
    for (ll i = 0; i < t; ++i) {
        ll n, m, c; cin >> n >> m >> c;

        N = n;
        g.clear();
        vis.clear();
        vis.resize(n + 1);
        g.resize(n + 1);
        siz.clear();
        siz.resize(n + 1);
        for (ll j = 0; j < m; ++j) {
            ll a, b; cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        cout << sum(2) << "\n";
    }

    return 0;
}