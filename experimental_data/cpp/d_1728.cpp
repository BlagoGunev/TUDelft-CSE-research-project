#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {

   int t;cin>>t;

   while(t--){

       string s;cin>>s;

       int n=s.size();

       vector<vector<int>> dp(n,vector<int> (n));

       for(int i=0;i<n-1;i++){

           if(s[i]==s[i+1]) dp[i][i+1]=1;

       }

      int k=4;

      while(k<=n){

          for(int i=0;i<=n-k;i++){

              if(((s[i]==s[i+1]&&dp[i+2][i+k-1])||(s[i]==s[i+k-1]&&dp[i+1][i+k-2]))&&( (s[i+k-1]==s[i+k-2]&&dp[i][i+k-3])||(s[i]==s[i+k-1]&&dp[i+1][i+k-2]) )) dp[i][i+k-1]=1;

          }

          k+=2;

      }

    if(dp[0][n-1]) cout<<"Draw\n";

    else cout<<"Alice\n";   

   }

}