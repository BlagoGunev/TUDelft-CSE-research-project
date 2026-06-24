#include<bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) static_cast<int>((x).size())
#define int long long

set<array<int, 2>> good;
const int maxn = 2e5 + 1;
vector<int> adj[maxn];
int sz[maxn];

void dfs1 (int x, int p) {

        sz[x] = 1;
        vector<int> v;
        bool g = 1;
        for (auto u : adj[x]) {
                if (u == p) continue;
                dfs1(u, x);
                sz[x] += sz[u];
                v.push_back(sz[u]);
                if (good.find({u, x}) == good.end()) g = 0;
        }
        if (!g) return;
        sort(all(v));
        int cur = 1;
        for (auto u : v) {
                if (u > cur) g = 0;
                cur += u;
        }
        if (g) good.insert({x, p});

}
int pos[maxn];
int n;

void dfs2 (int x, int p) {

        vector<array<int, 2>> v;
        int cn = 0;
        for (auto u : adj[x]) {
                if (u == p) continue;
                v.push_back({sz[u], u});
                cn += (good.find({u, x}) != good.end());
        }
        if (p != -1) {
                v.push_back({n - sz[x], p});
                cn += (good.find({p, x}) != good.end());
        }
        sort(all(v));

        int cur = 1;
        for (auto &[c, u] : v) {
                int ex = c;
                c -= cur;
                cur += ex;
        }
        vector<int> mn(sz(v));
        int curmax = -1 * (int)1e9;

        for (int i = sz(v) - 1; i >= 0; i--) {
                auto [c, u] = v[i];
                curmax = max(curmax, c);
                mn[i] = curmax;
                pos[u] = i;
        }
        vector<int> mn2(sz(v));
        mn2[0] = v[0][0];
        for (int i = 1; i < sz(v); i++) mn2[i] = max(mn2[i - 1], v[i][0]);


        for (auto u : adj[x]) {
                if (u == p) continue;
                cn -= (good.find({u, x}) != good.end());
                if (cn == sz(v) - 1) {
                        bool ng = 1;
                        int j = pos[u];
                        if (j < sz(v) - 1) {
                                if (mn[j + 1] > -sz[u]) ng = 0;
                        }
                        if (j > 0) {
                                if (mn2[j - 1] > 0) ng = 0;
                        }
                        if (ng) good.insert({x, u});
                }
                cn += (good.find({u, x}) != good.end());
        }

        for (auto u : adj[x]) {
                if (u == p) continue;
                dfs2(u, x);
        }

}



signed main() {

        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n;
        for (int i = 1; i < n; i++) {
                int u, v;
                cin >> u >> v;
                u--; v--;
                adj[u].push_back(v);
                adj[v].push_back(u);
        }

        if (n == 1) {
                cout << "YES";
                return 0;
        }

        dfs1(0, -1);
        dfs2(0, -1);
        bool ps = 0;

        for (int x = 0; x < n; x++) {
                int cn = 0;
                vector<int> v;
                for (auto u : adj[x]) {
                        if (sz[u] < sz[x]) v.push_back(sz[u]);
                        else v.push_back(n - sz[x]);
                        cn += (good.find({u, x}) != good.end());
                }
                if (cn == sz(adj[x])) {
                        sort(all(v));
                        int cur = 1;
                        bool pss = 1;
                        for (auto u : v) {
                                if (u > cur) pss = 0;
                                cur += u;
                        }
                        if (pss) ps = 1;
                }
        }


        if (ps) cout << "YES";
        else cout << "NO";

        
}