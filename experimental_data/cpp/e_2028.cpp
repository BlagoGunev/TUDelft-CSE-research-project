#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#define ll long long

using namespace std;

const long long INF = INT_MAX;
const long long MOD = 998244353;

vector<vector<int>> edges;
vector<int> nearest;
vector<bool> vis;
vector<long long> chances;

ll power(ll x, ll y) {
    if (y == 0) return 1;
    ll d = power(x, y / 2);
    if (y % 2 == 0) return (d % MOD * d % MOD) % MOD;
    else return (((x % MOD) * (d % MOD)) % MOD * (d % MOD)) % MOD;
}

int dfs(int x) {
    bool leaf = true;
    int m = INF;
    for (int i : edges[x]) {
        if (!vis[i]) {
            vis[i] = true;
            leaf = false;
            m = min(m, dfs(i));
        }
    }
    if (leaf) {
        nearest[x] = 0;
        return 0;
    }
    nearest[x] = m + 1;
    return m + 1;
}

void dfs2(int x, int lg, long long base) {
    chances[x] = (((nearest[x] * power(lg, MOD - 2)) % MOD) % MOD * base) % MOD;
    for (int i : edges[x]) {
        if (!vis[i]) {
            vis[i] = true;
            if (nearest[i] == nearest[x] - 1) {
                dfs2(i, lg, base);
            }
            else {
                dfs2(i, nearest[i] + 1, chances[x]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        edges.assign(n, vector<int>());
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            edges[a - 1].push_back(b - 1);
            edges[b - 1].push_back(a - 1);
        }
        nearest.assign(n, INF);
        vis.assign(n, false);
        vis[0] = true;
        dfs(0);

        chances.assign(n, -1);
        vis.assign(n, false);
        vis[0] = true;
        dfs2(0, nearest[0], 1);
        for (long long i : chances) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}