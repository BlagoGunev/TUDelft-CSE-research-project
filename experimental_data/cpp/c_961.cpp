#include <bits/stdc++.h>
using namespace std;


const int MAXn =2e2,INF=1e9+4;
int dp[5][5],n,ans=INF,aaa;
char a[MAXn][MAXn];

void sooo(int n,char ch[MAXn][MAXn],int*id) {
  for(int i = 0;i<n;i++)
    for(int j = 0;j<n;j++) {
      id[0] += (((i + j ) % 2 + '0') == ch[i][j]);
      id[1] += (('1' - ( i + j ) % 2) == ch[i][j]);
    }
}
void dooo(){
	ans = min(ans,dp[0][0]+dp[1][0] + dp[2][1] + dp[3][1] ) ;
  aaa++;
  ans = min(ans,dp[0][0]+dp[1][1] + dp[2][0] + dp[3][1] ) ;
  ans = min(ans,dp[0][1]+dp[1][0] + dp[2][0] + dp[3][1] ) ;
  ans = min(ans,dp[0][0]+dp[1][1] + dp[2][1] + dp[3][0] ) ;
  aaa++;
  ans = min(ans,dp[0][1]+dp[1][0] + dp[2][1] + dp[3][0] ) ;
  ans = min(ans,dp[0][1]+dp[1][1] + dp[2][0] + dp[3][0] ) ;
}
int main() {
std::ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
   aaa;
  cin >> n;
  aaa++;
  for(int K = 0;K<4;K++) {
    for(int i = 0;i<n;i++) {
      for(int j = 0;j<n;j++)
			 cin >> a[i][j];
    }
    sooo(n,a,dp[K]);
  }
  aaa++;
  dooo();
  return cout << ans << endl,0;
}