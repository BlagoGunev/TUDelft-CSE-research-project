/**

 *    author:  longvu

 *    created: 07/15/22 13:39:18

**/

#include<bits/stdc++.h>



using namespace std;



#define int long long

#define sz(x) ((int)x.size())

#define all(x) (x).begin(), (x).end()

const int INF = 1e13;

const int naxn = (int)(100001);

const int naxw = (int)(51);

const int mod = 1e9 + 7;



template<class X, class Y>

bool maximize(X& x, const Y y) {

    if (y > x) {x = y; return true;}

    return false;

}

template<class X, class Y>

bool minimize(X& x, const Y y) {

    if (y < x) {x = y; return true;}

    return false;

}



#define Fi first

#define Se second



vector<pair<int, int>> adj[naxn];

int dp[naxn][naxw];

int32_t main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {

        int u, v, c;

        cin >> u >> v >> c;

        adj[u].push_back({v, c});

        adj[v].push_back({u, c});

    }

    priority_queue<tuple<int, int, int>> dq;

    memset(dp, 0x3f, sizeof dp);

    dp[1][0] = 0;

    dq.push({0, 1, 0});

    while (!dq.empty()) {

        tuple<int, int, int> u = dq.top();

        dq.pop();

        get<0>(u) *= -1;

        if (dp[get<1>(u)][get<2>(u)] != get<0>(u)) {

            continue;

        }

        for (auto v : adj[get<1>(u)]) {

            if (get<2>(u)) {

                if (minimize(dp[v.Fi][0], (v.Se + get<2>(u)) * (v.Se + get<2>(u)) + dp[get<1>(u)][get<2>(u)])) {

                    dq.push({-dp[v.Fi][0], v.Fi, 0});

                }

            } else if (minimize(dp[v.Fi][v.Se], dp[get<1>(u)][0])) {

                dq.push({-dp[v.Fi][v.Se], v.Fi, v.Se});

            }

        }

    }

    for (int i = 1; i <= n; ++i) {

        cout << (dp[i][0] < INF ? dp[i][0] : -1) << " ";

    }

    cout << '\n';

    return 0;

}