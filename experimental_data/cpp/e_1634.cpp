#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 10;
int e[maxn][2], visited[maxn], cnt[maxn];
vector <int> a[maxn], g[maxn];

void dfs(int u, int c) {
    while (g[u].size()) {
        int i = g[u].back();
        g[u].pop_back();
        if (visited[i]) continue;
        visited[i] = c;
        int v = e[i][0] + e[i][1] - u;
        dfs(v, (c == 1 ? 2 : 1));
    }
}

int main () {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int m;
    cin >> m;

    vector <int> v;

    for (int i = 0; i < m; i++) {
        int n;
        cin >> n;

        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            a[i].push_back(x);
            v.push_back(x);
        }
    }

    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());

    int ind = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < a[i].size(); j++) {
            a[i][j] = lower_bound(v.begin(), v.end(), a[i][j]) - v.begin() + 1;
            cnt[a[i][j]]++;
            e[ind][0] = m + a[i][j];
            e[ind][1] = i;
            g[e[ind][0]].push_back(ind);
            g[e[ind][1]].push_back(ind);
            ind++;
        }
    }

    for (int i = 1; i <= v.size(); i++) {
        if (cnt[i] % 2) {
            cout << "NO";
            return 0;
        }
    }

    for (int i = 0; i < m + int(v.size()); i++) {
        dfs(i, 1);
    }

    cout << "YES" << "\n";

    ind = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < a[i].size(); j++) {
            cout << (visited[ind] == 1 ? 'L' : 'R');
            ind++;
        }
        cout << "\n";
    }

    return 0;
}