#include <bits/stdc++.h>

using namespace std;



int T,N,dp[200005][2];

vector<int> lst;



int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> T;

    while (T--) {

        cin >> N;

        lst.clear();

        for (int i = 0; i < N; ++i) {

            int x; cin >> x;

            if (lst.size() < 2 || x != lst[lst.size()-2])

                lst.push_back(x);

        }

        int ans = 0;

        N = lst.size();

        for (int i = 0; i < N; ++i) {

            dp[i][0] = dp[i][1] = 1;

            for (int j = 1; j <= 2; ++j) if (i-j >= 0) {

                if (lst[i-j]+1 == lst[i]) dp[i][0] = max(dp[i][0],dp[i-j][0]+1);

                if (lst[i-j]+2 == lst[i]) dp[i][0] = max(dp[i][0],dp[i-j][1]+1);

                if (lst[i-j] == lst[i]) dp[i][1] = max(dp[i][1],dp[i-j][0]+1);

                if (lst[i-j]+1 == lst[i]) dp[i][1] = max(dp[i][1],dp[i-j][1]+1);

            }

            ans = max({ans,dp[i][0],dp[i][1]});

        }

        cout << ans << '\n';

    }



    return 0;

}