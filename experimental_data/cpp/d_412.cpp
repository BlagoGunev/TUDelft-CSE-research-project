#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int maxn = 200000;

vector <int> ans;
vector <int> cur;

vector <int> G[maxn];

int used[maxn];

void dfs(int i){
    used[i] = 1;
    for (int j = 0; j < (int)G[i].size(); ++j) {
        int v = G[i][j];
        if (used[v] == 0) {
            dfs(v);
        }
    }
    ans.push_back(i);
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u; --v;
        G[u].push_back(v);
    }
    for (int i = 0; i < n; ++i) {
        if (used[i] == 0) {
            dfs(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", ans[i] + 1);
    }
    return 0;
}