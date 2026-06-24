#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n+1, 0);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<int> b(n+1, 0);
        for(int i=1;i<=n;i++) cin >> b[i];
        const int INF = 1e9;
        vector<vector<int>> dp(n+1, vector<int>(2, -INF));
        dp[0][0] = 0; 
        for(int i=1;i<=n;i++){
            for(int prev=0; prev<=1; prev++){
                if(dp[i-1][prev] == -INF) continue;
                int current_diff = dp[i-1][prev];
                if(prev ==1){
                    current_diff -= b[i];
                }
                dp[i][0] = max(dp[i][0], current_diff);
                int new_prev = (i < n) ? 1 : 0;
                int new_diff = current_diff + a[i];
                dp[i][new_prev] = max(dp[i][new_prev], new_diff);
            }
        }
        int answer = max(dp[n][0], dp[n][1]);
        cout << answer << "\n";
    }
}