#include <bits/stdc++.h>

// Pennyroyal -> herbal for all the bugs
#ifdef Pennyroyal
#include <debug.h>
#else
#define debug(...)
#define sdebug(...)
#endif

using namespace std;
using ll = long long;
using my_fake_pastic_love = void;

const int nmax = 2e5 + 1;
vector<int> g[nmax];
int n, op;

int l[nmax], r[nmax];

ll dfs(int u) {
    ll res = 0;
    for (auto v : g[u]) {
        res += dfs(v);
    }
    if (res < l[u]) op++;
    return (res >= l[u] and res <= r[u]) ? res : r[u];
}

void refresh(int n) {
    op = 0;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
}

void radiohead(my_fake_pastic_love) {
    cin >> n;
    refresh(n);
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        g[p].emplace_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }

    dfs(1);
    
    cout << op << '\n';
}

int32_t main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testcase;
    cin >> testcase;
    for (int tc = 1; tc <= testcase; tc++) {
        radiohead();
    }

    return 0;
}