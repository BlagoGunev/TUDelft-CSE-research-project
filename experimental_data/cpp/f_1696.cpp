#include <bits/stdc++.h>
#define X first
#define Y second

#define _ << " " <<
#define debug(x) #x << " = " << x

#define ll long long
#define ull unsigned long long
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v).size())

using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

const ll maxn = 128;

char eq[maxn][maxn][maxn];

void find_tree(std::vector<std::vector<ll>>& adj,
    std::vector<ll> active)
{
    if (active.size() == 2) {
        std::set<ll> in_sub {all(active)};

        adj[active.front()].push_back(active.back());
        adj[active.back()].push_back(active.front());

        std::queue<ll> q;
        q.push(active.front());
        q.push(active.back());

        ll n = sz(adj) - 1;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            auto x = adj[cur].front();

            for (ll y = 1; y <= n; y++) {
                if (eq[x][y][cur] && !in_sub.count(y)) {
                    in_sub.insert(y);
                    adj[y].push_back(cur);
                    adj[cur].push_back(y);
                    q.push(y);
                }
            }
        }

        return;
    }

    for (auto x : active) {
        for (auto y : active) {
            if (x == y) continue;

            std::vector<ll> split;
            for (auto z : active) {
                if (z == x || z == y) continue;

                if (eq[x][y][z]) {
                    split.push_back(z);
                }
            }

            if (split.size() >= 2) {
                // We can split the tree here
                return find_tree(adj, split);
            }
        }
    }

    // Everything has degree <= 2
    // Find node where no 1 are possible with it => degree 1, remove it and recurse
    for (auto& x : active) {
        ll cnt = 0;

        for (auto& y : active) {
            for (auto& z : active) {
                if (y != x && z != x && y != z) {
                    cnt += eq[y][z][x];
                }
            }
        }

        if (cnt == 0) {
            active.erase(std::remove(all(active), x), active.end());
            return find_tree(adj, active);
        }
    }
}

void solve()
{
    ll n;
    std::cin >> n;

    for (ll i = 1; i < n; i++) {
        for (ll j = 1; j <= n - i; j++) {
            std::string s;
            std::cin >> s;

            for (ll k = 1; k <= n; k++) {
              //  std::cout << debug(i) _ debug(i+j) _ debug(k) _ debug((s[k] == '1')) << std::endl;
                eq[i][i + j][k] = (s[k-1] == '1');
                eq[i + j][i][k] = (s[k-1] == '1');
            }
        }
    }

    std::vector<std::vector<ll>> adj(n+1);
    std::vector<ll> active(n);
    std::iota(all(active), 1);

    find_tree(adj, active);

    const auto& bfs = [&] (ll s) {
        std::vector<ll> dist(n+1, -1);
        dist[s] = 0;
        std::queue<ll> q;
        q.push(s);
        while (!q.empty()) {
            auto x = q.front();
            q.pop();

            for (auto& y : adj[x]) {
                if (dist[y] == -1) {
                    dist[y] = dist[x] + 1;
                    q.push(y);
                }
            }
        }

        return dist;
    };

    std::vector<std::vector<ll>> distances;
    distances.push_back({}); // 0

    for (ll i = 1; i <= n; i++) {
        distances.push_back(bfs(i));

        if (std::count(all(distances.back()), -1) > 1) {
            std::cout << "No" << std::endl;
            return;
        }
    }

    for (ll i = 1; i <= n; i++) {
        for (ll j = i+1; j <= n; j++) {
            for (ll k = 1; k <= n; k++) {
               // std::cout << debug(i) _ debug(j) _ debug(k) _ debug((int)eq[i][j][k]) << std::endl;
                bool v = distances[i][k] == distances[j][k];
                if (v != eq[i][j][k]) {
                    std::cout << "No" << std::endl;
                    return;
                }
            }
        }
    }

    std::cout << "Yes" << std::endl;
    for (ll i = 1; i <= n; i++) {
        for (ll j : adj[i]) {
            if (i < j) {
                std::cout << i _ j << std::endl;
            }
        }
    }


}

int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    std::cin >> t;
    while(t--) solve();
    return 0;
}