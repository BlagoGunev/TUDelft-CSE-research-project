/**
 *    author: andif
 *    created: 09.03.2024 17:06:42
**/
#include<bits/stdc++.h>
using namespace std;

#define de(x) cerr << #x << " = " << x << endl
#define dd(x) cerr << #x << " = " << x << " "
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define per(i, a, b) for(int i = a; i > b; --i)
#define mt(a, b) memset(a, b, sizeof(a))
#define sz(a) (int)a.size()
#define fi first
#define se second
#define qc ios_base::sync_with_stdio(0);cin.tie(0)
#define eb emplace_back
#define all(a) a.begin(), a.end()
using ll = long long;
using db = double;
using pii = pair<int, int>;
using pdd = pair<db, db>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
const db eps = 1e-9;

int main() {
    qc;
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<vector<pii>> e(n + 1);
        rep(i, 1, n) {
            int u, v; cin >> u >> v;
            e[u].push_back(pair(i, v));
            e[v].push_back(pair(i, u));
        }
        vector<vi> f(n + 1, vi(3, 0));
        auto dp = [&] (auto self, int u, int p) -> void {
            bool ok_u = true;
            for (auto [_, v]: e[u]) {
                if (v == p) continue;
                self(self, v, u);
                bool ok_v = false;
                rep(i, 0, 3) {
                    ok_v |= f[v][i];
                }
                ok_u &= ok_v;
            }
            if (!ok_u) return;
            int z = 0, o = 0, t = 0;
            int sv = 0;
            for (auto [_, v]: e[u]) {
                if (v == p) continue;
                sv++;
                if (f[v][0]) z++;
                if (f[v][1]) o++;
                if (f[v][2]) t++;
            }
            if (o == 1 && z == sv - o) {
                f[u][0] = 1;
            }
            if (t == 2 && z == sv - t) {
                f[u][0] = 1;
            }
            if (t == 1 && z == sv - t) {
                f[u][1] = 1;
            }
            if (z == sv) {
                f[u][2] = 1;
            }
            // rep(i, 0, 3) {
            //     dd(u), dd(i), de(f[u][i]);
            // }
        };
        dp(dp, 1, 0);
        auto dfs = [&] (auto self, int u, int p, vi& ans) -> void {
            for (auto [i, v]: e[u]) {
                if (v == p) continue;
                self(self, v, u, ans);
                if (f[v][0]) ans.eb(i);
            }
        };
        if (f[1][0]) {
            vi ans;
            dfs(dfs, 1, 0, ans);
            cout << sz(ans) << '\n';
            rep(i, 0, sz(ans)) {
                cout << ans[i];
                if (i != sz(ans) - 1) cout << ' ';
            }
            cout << '\n';
        } else {
            cout << "-1" << '\n';
        }
    }
    return 0;
}