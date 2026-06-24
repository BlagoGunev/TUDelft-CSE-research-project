#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define all(x) (x).begin(), (x).end()

#define rall(x) (x).rbegin(), (x).rend()



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);



    ll tc = 1;

    // cin >> tc;

    while (tc--) {

        ll n, m, k;

        cin >> n >> m >> k;

        vector<ll> v(k);

        for (auto &x : v) {

            cin >> x;

        }

        vector<vector<ll>> g(n + 1);

        for (ll a, b, x = 0; x < m; x++) {

            cin >> a >> b;

            g[a].push_back(b);

            g[b].push_back(a);

        }

        vector<ll> dist_source(n + 1, 0), dist_terminal(n + 1, 0);

        auto bfs = [&](vector<ll> &dist, ll node) -> void {

            vector<bool> visit(n + 1, 0);

            queue<ll> q;

            q.push(node);

            visit[node] = 1;

            while (!q.empty()) {

                auto frnt = q.front();

                q.pop();

                for (auto nbr : g[frnt]) {

                    if (!visit[nbr]) {

                        visit[nbr] = 1;

                        dist[nbr] = dist[frnt] + 1;

                        q.push(nbr);

                    }

                }

            }

        };

        bfs(dist_source, 1);

        bfs(dist_terminal, n);

        vector<pair<ll, ll>> elem;

        for (auto x : v) {

            elem.push_back({dist_source[x], dist_terminal[x]});

        }

        sort(all(elem));

        ll res = -1e18;

        for (ll x = 0; x < elem.size() - 1; x++) {

            ll dsx = elem[x].first, dtx = elem[x].second;

            ll dsx1 = elem[x + 1].first, dtx1 = elem[x + 1].second;

            if (dsx < dsx1) {

                res = max(res, min(dist_source[n], dtx1 + dsx + 1));

            } else {

                res = max(res, min(dist_source[n], dtx + dsx1 + 1));

            }

        }

        cout << res << '\n';

    }

    return 0;

}