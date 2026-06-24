#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4000, INF = 1e9;
vector<int> G[MAXN];
pair<int, int> edges[MAXN];
int ans = INF;

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
        edges[i] = { a, b };
    }
    for(int i = 0; i < N; i++) {
        sort(G[i].begin(), G[i].end());
    }
    for(int i = 0; i < M; i++) {
        int l = 0, r = 0;
        int a = edges[i].first, b = edges[i].second;
        while(l < (int)G[a].size() && r < (int)G[b].size()) {
            if(G[a][l] == G[b][r])
                ans = min(ans, (int)G[a].size() + (int)G[b].size() + (int)G[G[b][r]].size() - 6);
            if(G[a][l] < G[b][r])
                l++;
            else
                r++;
        }
    }
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}