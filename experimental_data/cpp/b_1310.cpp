#include<iostream>

#include<cstring>

#include<algorithm>

using namespace std;

using LL = long long;

const int maxn = 1e6 + 5;



bool v[maxn];



int main(){



#ifdef LOCAL

    freopen("data.in", "r", stdin);

    freopen("data.out", "w", stdout);

#endif



    cin.tie(0);

    cout.tie(0);

    ios::sync_with_stdio(0);



    const int INF = 1e9;

    int n, k;

    cin >> n >> k;

    if (k == 0){

        cout << 0 << '\n';

        return 0;

    }

    vector<array<int, 4> > dp(1 << n, {0, -INF, -INF, -INF});

    for(int i = 1; i <= k; i++){

        int x;

        cin >> x;

        int s = (1 << n - 1) + (x - 1) / 2;

        if (dp[s][1] != -INF) dp[s][3] = 1;

        else dp[s][1] = dp[s][2] = 1;

    }

    for(int i = (1 << n - 1) - 1; i >= 1; i--){

        for(int j = 0; j < 4; j++){

            for(int k = 0; k < 4; k++){

                dp[i][j | k] = max(dp[i][j | k], dp[2 * i][j] + dp[2 * i + 1][k] + (j | k));

            }

        }

    }

    cout << max({dp[1][1], dp[1][2], dp[1][3]}) + 1 << '\n';



}