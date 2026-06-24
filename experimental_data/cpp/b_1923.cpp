//
// Created by never_island on 2024/2/2.
//
#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N = 300005, mod = 998244353;

int qpow(int x, int ind) {
    int ans(1), now(x);
    while (ind) {
        if (ind & 1) {
            ans *= now;
            ans %= mod;
        }
        now *= now;
        now %= mod;
        ind >>= 1;
    }
    return ans;
}

struct graph {
    int N, M, cnt;
    vector<int> nx, to, ls, val_of_edge, val_of_point;

    graph(int n, int m) {
        N = n;
        M = m;
        nx.resize(M + 2);
        to.resize(M + 2);
        ls.resize(M + 2);
        val_of_edge.resize(M + 2);
        val_of_point.resize(N + 2);
        cnt = 0;
    }

    void add(int u, int v, int w)//加一条从u到v，权值为w的单向边
    {
        nx[++cnt] = ls[u];
        to[cnt] = v;
        val_of_edge[cnt] = w;
        ls[u] = cnt;
    }
};

int read() {
    char ch = getchar();
    int x(0);
    while (ch > '9' || ch < '0')ch = getchar();
    while (ch <= '9' && ch >= '0') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}

int T, n, a[N], K, x[N], b[N];

signed main() {
    cin >> T;
    while (T--) {
        cin >> n >> K;
        for (int i = 0; i <= n; i++)b[i] = 0;
        int sum(0), flag(1);
        for (int i = 1; i <= n; i++)cin >> a[i];
        for (int i = 1; i <= n; i++)cin >> x[i];
        for (int i = 1; i <= n; i++)b[abs(x[i])] += a[i];
        for (int i = 1; i <= n; i++)b[i] += b[i - 1];
        for (int i = 1; i <= n; i++) {
            if (b[i] > K * i)flag = 0;
        }
        if (flag)cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}