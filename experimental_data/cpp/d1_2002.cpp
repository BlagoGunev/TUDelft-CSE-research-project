#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<vector<int>> child(n);
        vector<int> par(n);
        for (int i = 1; i < n; i++) {
            int p;
            cin >> p;
            p--;
            child[p].push_back(i);
            par[i] = p;
        }

        vector<int> pi(n);
        vector<vector<int>> ci(n);
        int i = 0;
        auto dfs = [&](auto self, int v, int p) -> void {
            pi[i] = p;
            int cur = i;
            i++;
            for (auto u : child[v]) {
                ci[cur].push_back(i);
                self(self, u, cur);
            }
        };

        dfs(dfs, 0, -1);

        vector<int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        for (int i = 0; i < n; i++) p[i]--;

        auto bad = [&](int i) {
            if (i == 0) return p[i] != 0;
            return p[pi[i]] != par[p[i]];
        };

        int num = 0;
        for (int i = 0; i < n; i++) {
            num += (i == 0 ? 2 : 1) * bad(i);
            for (auto c : ci[i]) num += bad(c);
        }

        for (int i = 0; i < q; i++) {
            int x, y;
            cin >> x >> y;
            x--; y--;

            if (x > y) swap(x, y);

            if (pi[y] == x) {
                num -= 2 * bad(x);
                for (auto c : ci[x]) num -= 2 * bad(c);
                for (auto c : ci[y]) num -= 2 * bad(c);
            } else {
                num -= 2 * bad(x);
                num -= 2 * bad(y);
                for (auto c : ci[x]) num -= 2 * bad(c);
                for (auto c : ci[y]) num -= 2 * bad(c);
            }

            swap(p[x], p[y]);

            if (pi[y] == x) {
                num += 2 * bad(x);
                for (auto c : ci[x]) num += 2 * bad(c);
                for (auto c : ci[y]) num += 2 * bad(c);
            } else {
                num += 2 * bad(x);
                num += 2 * bad(y);
                for (auto c : ci[x]) num += 2 * bad(c);
                for (auto c : ci[y]) num += 2 * bad(c);
            }

            if (num == 0) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}