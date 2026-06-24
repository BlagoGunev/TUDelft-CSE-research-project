#include <iostream>
#include <utility>
#include <cassert>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <deque>
#include <functional>
using namespace std;
#define int long long

void solve()
{
    int N, M; cin >> N >> M;
    vector<pair<int, int>> vc(M);
    bool end_one = false;
    for (int i = 0; i < M; i++) {
        cin >> vc[i].first >> vc[i].second;
    }
    vector<vector<int>> ord(N+1);
    for (int i = 0; i < M; i++) {
        ord[vc[i].second].push_back(vc[i].first);
    }
    vector<int> dis(N+1, -1);
    dis[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i:ord[cur]) {
            if (dis[i] == -1) {
                dis[i] = dis[cur] + 1;
                q.push(i);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        if (dis[i] == -1) {
            cout << "INFINITE\n";
            return;
        }
    }
    vector<vector<int>> lst(N);
    for (int i = 1; i <= N; i++) {
        lst[dis[i]].push_back(i);
    }
    vector<int> ans;
    for (int i = N-1; i >= 0; i--) {
        for (int j = i; j <= N-1; j++) {
            for (int k:lst[j]) ans.push_back(k);
        }
    }
    cout << "FINITE\n";
    cout << ans.size() << '\n';
    for (int i:ans) cout << i << ' ';
    cout << '\n';
    return;
}

signed main()
{
    //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}