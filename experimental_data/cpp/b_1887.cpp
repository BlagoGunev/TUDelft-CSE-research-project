# include <iostream>
# include <vector>
# include <algorithm>
# include <cmath>
# include <climits>
# include <set>
# include <map>
# include <queue>
# include <cassert>
# include <string>
# include <string.h>
# include <numeric>

# define ln "\n"

using ll = long long;
using ull = unsigned long long;
using namespace std;

ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

int main() {
    int N;
    int T;
    int K;
    int u;
    int v;
    int tmp;
    cin >> N >> T;
    vector <vector<int>> vi(T + 1);
    vector <vector<pair<int, int>>> in(N + 1);
    vector <int> dis(N + 1, INT_MAX);
    priority_queue<pair<int, int>> q;
    vector <bool> processed(N + 1, false);
    for (int i = 1; i <= T; i++) {
        cin >> tmp;
        for (int j = 0; j < tmp; j++) {
            cin >> u >> v;
            in[u].push_back({v, i});
            in[v].push_back({u, i});
        }
    }
    cin >> K;
    for (int i = 1; i <= K; i++) {
        cin >> tmp;
        vi[tmp].push_back(i);
    }
    dis[1] = 0;
    q.push({0,1});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : in[a]) {
            int b = u.first, w = u.second;
            auto it = upper_bound(vi[w].begin(), vi[w].end(), dis[a]);
            if (it != vi[w].end()) {
                if ((*it) < dis[b]) {
                    dis[b] = (*it);
                    q.push({-dis[b],b});
                }
            }
        }
    }
    if (dis[N] == INT_MAX) dis[N] = -1;
    cout << dis[N];
    return 0;
}