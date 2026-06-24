#include<iostream>

#include<cstring>

#include<random>

using namespace std;

using LL = long long;



int main(){



#ifdef LOCAL

    freopen("data.in", "r", stdin);

    freopen("data.out", "w", stdout);

#endif



    cin.tie(0);

    cout.tie(0);

    ios::sync_with_stdio(0);



    const int maxn = 85;

    int g[maxn][maxn];

    int n, k;

    cin >> n >> k;

    for(int i = 1; i <= n; i++)

        for(int j = 1; j <= n; j++)

            cin >> g[i][j];

    mt19937 rnd(random_device{}());

    uniform_int_distribution<int> dist(0, 1);

    const int INF = 1e9 + 5;

    int ans = INF;

    for(int i = 0; i < 5000; i++){

        vector<int> p[2];

        for(int j = 1; j <= n; j++) p[dist(rnd)].push_back(j);

        vector<int> dp(n + 1, INF);

        dp[1] = 0;

        for(int j = 0; j < k; j++){

            vector<int> ndp(n + 1, INF);

            for(auto x0 : p[0])

                for(auto x1 : p[1]){

                    ndp[x0] = min(ndp[x0], dp[x1] + g[x1][x0]);

                    ndp[x1] = min(ndp[x1], dp[x0] + g[x0][x1]);

                }



            dp.swap(ndp);

        }

        ans = min(ans, dp[1]);

    }

    cout << ans << '\n';

}