#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// void dfs(int node, int p, vector<int> adj[], int dp[]) {
//     if(dp[node] != -1) {dp[p]+=dp[node];return;}
//     for(auto nb: adj[node]) {
//         if(nb!=p) {
//             dfs(nb,node,adj,dp);
//         }
//     }
    
// }
#define ll long long
void solve() {
   ll n;cin>>n;
   for(ll k = 2; k <=1000;k++) {
       for(ll p = 2; p<=100;p++) {
           if(((pow(k,p+1)-1)/(k-1)) == n){cout<<"YES"<<endl;return;}
           if(((pow(k,p+1)-1)/(k-1)) > n) break;
       }
   }
   cout<<"NO"<<endl;
}

int main()
{   ios_base::sync_with_stdio(false);;
    cin.tie(NULL);cout.tie(NULL);
    int t; cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}