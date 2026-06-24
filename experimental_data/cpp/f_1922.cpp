#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, x;
  cin >> n >> x;
  int a[n];
  for(int i = 0;i<n;i++)cin >> a[i];
  int dp[n+1][n][x+1];
  int dp2[n+1][n][x+1];
  memset(dp, 0, sizeof dp);
  memset(dp2, 0, sizeof dp2);
  for(int len = 0;len<n;len++) {
    for(int i = 0;i<n-len;i++) {
      int j = i+len;
      for(int k = 1;k<=x;k++) {
        int cnt[x+1];
        memset(cnt, 0, sizeof cnt);
        for(int c = i;c<=j;c++) {
          if(a[c] == k and (c>i and a[c-1]!=k))
            dp[i][j][k]++;
          if(a[c]==k and (c==i or a[c-1]!=k)) 
            dp2[i][j][k]++;
          cnt[a[c]]++;
        }
        if(a[j]!=k)dp[i][j][k]++;
        bool ch=0;
        for(int c=1;c<=x;c++) {
          if(cnt[c]==0 and c!=k)ch=1;
        }
        if(ch)dp[i][j][k]=min(dp[i][j][k], 2);
        if(ch)dp2[i][j][k]=min(dp2[i][j][k], 1);
        if(a[j]!=k)dp[i][j][k]++;
        for(int c = i;c<j;c++) {
          dp[i][j][k]=min(dp[i][j][k], dp[i][c][k]+dp[c+1][j][k]);
          dp[i][j][k]=min(dp[i][j][k], dp2[i][c][k]+dp2[c+1][j][k]+1);
          dp2[i][j][k]=min(dp2[i][j][k], dp2[i][c][k]+dp2[c+1][j][k]);
          dp2[i][j][k]=min(dp2[i][j][k], dp[i][c][k]+dp[c+1][j][k]+1);
        }
        dp2[i][j][k]=min(dp2[i][j][k], dp[i][j][k]+1);
        dp[i][j][k]=min(dp[i][j][k], dp2[i][j][k]+1);
      }
      for(int k = 1;k<=x;k++) {
        for(int kk=1;kk<=x;kk++) {
          if(k==kk)continue;
          dp[i][j][k]=min(dp[i][j][k], dp2[i][j][kk]+1);
          dp2[i][j][k]=min(dp2[i][j][k], dp[i][j][kk]);
        }
      }

    }
  }
  int ans=1e9;
  for(int k = 1;k<=x;k++)ans=min(ans, dp[0][n-1][k]);
  cout << ans << "\n";
}
int main () {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--)solve();
}