#include <iostream>

#include <stack>

#include <vector>

#include <algorithm>

#include <utility>



constexpr int N = 500005;



int n;

std::vector<std::pair<int, int>> v[N], e[N];

std::vector<int> v2[N];

int fa[N], sz[N], up[N];

int cnt, dfn[N];

long long ans;



void dfs1(int x, int f) {

    fa[x] = f;

    sz[x] = 1;

    dfn[x] = ++cnt;

    for (auto [i, c] : v[x])

        if (i != f) {

            up[i] = c;

            dfs1(i, x);

            sz[x] += sz[i];

        }

}



bool anc(int x, int y) {

    return dfn[y] >= dfn[x] && dfn[y] < dfn[x] + sz[x];

}



int f[N], g[N];



void dfs2(int x, int col) {

    f[x] = sz[x];

    for (int i : v2[x]) {

        dfs2(i, col);

        f[x] -= sz[i];

        if (!(fa[i] == x && up[i] == col)) f[x] += f[i];

    }

}



void dfs3(int x, int col) {

    for (int i : v2[x]) {

        if (fa[i] == x && up[i] == col) {

            g[i] = 1;

            ans += static_cast<long long>(g[x] + f[x] - 1) * f[i];

        } else g[i] = g[x] + f[x] - f[i];

        dfs3(i, col);

    }

}



int main() {

    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    std::cin >> n;

    for (int i = 1, x, y, z; i < n; ++i) {

        std::cin >> x >> y >> z;

        v[x].emplace_back(y, z);

        v[y].emplace_back(x, z);

        e[z].emplace_back(x, y);

    }

    dfs1(1, 0);

    g[1] = 1;

    for (int i = 1; i <= n; ++i) {

        std::vector<int> a;

        a.push_back(1);

        for (auto [x, y] : e[i]) a.push_back(x), a.push_back(y);

        std::sort(a.begin(), a.end(), [](int x, int y) { return dfn[x] < dfn[y]; });

        a.resize(std::unique(a.begin(), a.end()) - a.begin());

        std::stack<int> stk;

        for (int j : a) {

            while (!stk.empty() && !anc(stk.top(), j)) stk.pop();

            if (!stk.empty()) v2[stk.top()].push_back(j);

            stk.push(j);

        }

        dfs2(1, i);

        dfs3(1, i);

        for (int j : a) v2[j].clear();

    }

    std::cout << ans << '\n';

    return 0;

}