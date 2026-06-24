// Problem: F. Traveling Salescat
// Author: XZC(L_Wave)
// Language: Cpp/G++20
// Contest: Codeforces - Ethflow Round 1 (Codeforces Round 1001, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2062/problem/F
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Create Time: not 2025-01-26 23:36:04, but 1926-08-17 11:45:14
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast","inline","fast-math","unroll-loops")
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a), i##ABRACADABRA = (b); i <= i##ABRACADABRA; i++)
#define drep(i, a, b) for (int i = (a), i##ABRACADABRA = (b); i >= i##ABRACADABRA; i--)
using namespace std;
using ll = long long;

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

struct node{
  ll a,b;
  void read(){cin>>a>>b;}
  // void read(){a=rng(),b=rng();}
}w[3010];
ll dp[2][3010][17],res[3010];
int n;

// dp[i][j][S] 表示前 i 个点，选了 j 个点，线头、尾，链头、尾各自的数量
// 内存太大，压掉 i 这一位
// 转移：不选、选为四个关键节点中的一个、选为线中间的一个
// 特判掉 k=2,3（可以直接暴力枚举）
// 线头：1,a[i]
// 线尾：2,b[i]
// 链头：4,2b[i]（没线头时是 b[i]）
// 链尾：8,2a[i]（没线尾时是 a[i]）
// 中间：(0),a[i]+b[i]

void solve(){
  cin>>n;
  rep(i,1,n)w[i].read();
  sort(w+1,w+n+1,[&](node p,node q){return p.a-p.b<q.a-q.b;});
  rep(i,0,n+1)res[i]=1e18;
  {
    // 情况一：线头线尾都有
    rep(i,0,1)rep(j,0,n+1)rep(k,0,15)dp[i][j][k]=1e18;
    dp[0][0][0]=0;
    rep(i,1,n){
      dp[i&1][0][0]=0;
      rep(j,0,n)for (auto S:{0,4,5,7,15})if (ll&dpw=dp[(i-1)&1][j][S];dpw<1e17){
        dp[i&1][j][S]=min(dp[i&1][j][S],dpw);
        if (!(S&1)&&(S>>2&1))dp[i&1][j+1][S|1]=min(dp[i&1][j+1][S|1],dpw+w[i].a);
        if (!(S>>3&1)){
          if (!(S>>1&1))dp[i&1][j+1][S|2]=min(dp[i&1][j+1][S|2],dpw+w[i].b);
          if (!(S>>2&1))dp[i&1][j+1][S|4]=min(dp[i&1][j+1][S|4],dpw+w[i].b*2);
          else{
            dp[i&1][j+1][S|8]=min(dp[i&1][j+1][S|8],dpw+w[i].a*2);
            dp[i&1][j+1][S]=min(dp[i&1][j+1][S],dpw+w[i].a+w[i].b);
          }
        }
        dpw=1e18;
      }
      rep(j,4,n)res[j]=min(res[j],dp[i&1][j][15]);
      if (i<n)rep(j,4,n)res[j]=min(res[j],dp[i&1][j-1][5]+w[i+1].a); // 这是没有线尾的情况
    }
  }
  // {
    // // 情况二：只有线头
    // rep(i,0,1)rep(j,0,n+1)rep(k,0,7)dp[i][j][k]=1e18;
    // dp[0][0][0]=0;
    // rep(i,1,n){
      // dp[i&1][0][0]=0;
      // rep(j,0,n)rep(S,0,7)if (ll&dpw=dp[(i-1)&1][j][S];dpw<1e17){ // 13 压成 7
        // dp[i&1][j][S]=min(dp[i&1][j][S],dpw);
        // if (!(S>>0&1)&&(S>>1&1))dp[i&1][j+1][S+1]=min(dp[i&1][j+1][S+1],dpw+w[i].a);
        // if (!(S>>2&1)){
          // if (!(S>>1&1))dp[i&1][j+1][S+2]=min(dp[i&1][j+1][S+2],dpw+w[i].b*2);
          // else{
            // dp[i&1][j+1][S+4]=min(dp[i&1][j+1][S+4],dpw+w[i].a);
            // dp[i&1][j+1][S]=min(dp[i&1][j+1][S],dpw+w[i].a+w[i].b);
          // }
        // }
        // dpw=1e18;
      // }
      // rep(j,4,n)res[j]=min(res[j],dp[i&1][j][7]);
      // // rep(j,0,n)rep(S,0,15)if (dp[i&1][j][S]<1e17)
        // // cout<<i<<' '<<j<<' '<<S<<' '<<dp[i&1][j][S]<<'\n';
      // // cout<<res[4]<<'\n';
    // }
  // }
  {
    // 情况三：只有线尾
    rep(i,0,1)rep(j,0,n+1)rep(k,0,7)dp[i][j][k]=1e18;
    dp[0][0][0]=0;
    rep(i,1,n){
      dp[i&1][0][0]=0;
      rep(j,0,n)rep(S,0,7)if (ll&dpw=dp[(i-1)&1][j][S];dpw<1e17){ // 14 压成 7
        dp[i&1][j][S]=min(dp[i&1][j][S],dpw);
        if (!(S>>0&1)&&!(S>>2&1))dp[i&1][j+1][S+1]=min(dp[i&1][j+1][S+1],dpw+w[i].b);
        if (!(S>>2&1)){
          if (!(S>>1&1))dp[i&1][j+1][S+2]=min(dp[i&1][j+1][S+2],dpw+w[i].b);
          else{
            dp[i&1][j+1][S+4]=min(dp[i&1][j+1][S+4],dpw+w[i].a*2);
            dp[i&1][j+1][S]=min(dp[i&1][j+1][S],dpw+w[i].a+w[i].b);
          }
        }
        dpw=1e18;
      }
      rep(j,4,n)res[j]=min(res[j],dp[i&1][j][7]);
      if (i<n)rep(j,4,n)res[j]=min(res[j],dp[i&1][j-1][2]+w[i+1].a); // 这是没有线尾的情况
    }
  }
  // {
    // // 情况四：无线头无线尾
    // rep(i,0,1)rep(j,0,n+1)rep(k,0,3)dp[i][j][k]=1e18;
    // dp[0][0][0]=0;
    // rep(i,1,n){
      // dp[i&1][0][0]=0;
      // rep(j,0,n)rep(S,0,3)if (ll&dpw=dp[(i-1)&1][j][S];dpw<1e17){ // 12 压成 3
        // dp[i&1][j][S]=min(dp[i&1][j][S],dpw);
        // if (!(S>>0&1)&&!(S>>1&1))dp[i&1][j+1][S+1]=min(dp[i&1][j+1][S+1],dpw+w[i].b);
        // if (!(S>>1&1)&&(S>>0&1))dp[i&1][j+1][S+2]=min(dp[i&1][j+1][S+2],dpw+w[i].a);
        // if ((S>>0&1)&&!(S>>1&1))dp[i&1][j+1][S]=min(dp[i&1][j+1][S],dpw+w[i].a+w[i].b);
        // dpw=1e18;
      // }
      // rep(j,4,n)res[j]=min(res[j],dp[i&1][j][3]);
    // }
  // }
  rep(i,1,n)rep(j,i+1,n)res[2]=min(res[2],w[j].a+w[i].b);
  if (n>2)rep(i,1,n){
    vector<ll>V;
    rep(j,1,i-1)V.push_back(w[j].b+w[i].a);
    rep(j,i+1,n)V.push_back(w[j].a+w[i].b);
    sort(V.begin(),V.end());
    res[3]=min(res[3],V[0]+V[1]);
  }
  rep(i,2,n)cout<<res[i]<<" \n"[i==n];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin>>tt;
  while (tt--)solve();
  return 0;
}