#include <bits/stdc++.h>
using namespace std;

const int BITS = 60;
const int INF = 1e9;

// capacity is an adjacency matrix storing the capacity of each directed edge, 
// network is the undirected version of the directed graph 
int bfs(int s, int t, vector<vector<int>> &network, vector<vector<int>> &capacity, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});
 
    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();
 
        for (int next : network[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t) {
                    return new_flow;
                }
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}
 
int maxflow(int n, int s, int t, vector<vector<int>> &network, vector<vector<int>> &capacity) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;
 
    while ((new_flow = bfs(s, t, network, capacity, parent))) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

void solve() {
    int n;
    cin >> n;
    
    vector<vector<int>> network(n + BITS + 2);
    vector<vector<int>> capacity(n + BITS + 2, vector<int>(n + BITS + 2));
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        for (int j = 0; j < BITS; j++) {
            if (a & 1) {
                network[j + 1].push_back(BITS + 1 + i);
                network[BITS + 1 + i].push_back(j + 1);
                capacity[j + 1][BITS + 1 + i] = 300;
            }
            a >>= 1;
        }
    }
    for (int i = 0; i < BITS; i++) {
        network[0].push_back(i + 1);
        capacity[0][i + 1] = 1;
    }
    for (int i = 0; i < n; i++) {
        network[BITS + 1 + i].push_back(BITS + 1 + n);
        capacity[BITS + 1 + i][BITS + 1 + n] = 1;
    }

    int min_cut = maxflow(n + BITS + 2, 0, n + BITS + 1, network, capacity);
    cout << n - min_cut << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}