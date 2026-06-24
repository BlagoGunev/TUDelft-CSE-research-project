//I wrote this code 4 u today

#include <bits/stdc++.h>



template<class t> using vc = std::vector<t>;



typedef long long ll;



int who[100005], sz[100005];

vc<int> g[100005];



vc<int> mef;

void calc(int u, int p = -1) {

    mef.push_back(u);

    sz[u] = 1;

    for (auto v : g[u]) if (p != v) calc(v, u), sz[u] += sz[v];

}



int n;

int find_c(int u) {

    for (auto v : g[u]) if (2 * sz[v] > n && sz[v] < sz[u]) return find_c(v);

    return u;

}



int main() {

    std::cin.tie(nullptr)->ios_base::sync_with_stdio(false);

    std::iota(std::begin(who), std::end(who), 0);

    std::cin >> n;

    for (int i = 0, a, b; i + 1 < n && std::cin >> a >> b; ++i) g[a].push_back(b), g[b].push_back(a);

    calc(1), mef.clear(), calc(find_c(1));

    ll ans = 0;

    for (int i = n / 2; i - n / 2 < n; ++i) who[mef[i - n / 2]] = mef[i - (i >= n) * n], ans += std::min(sz[mef[i - n / 2]], n - sz[mef[i - n / 2]]);

    std::cout << 2 * ans << '\n';

    for (int v = 1; v <= n; ++v) std::cout << who[v] << ' ';

    std::cout << '\n';

}