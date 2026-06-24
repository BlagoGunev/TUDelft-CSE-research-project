///Mn kotr el labawy mb2t4 nawy

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
using ll = long long;
int dp[55][55][55][4];
int solve(int x, int y, int z, int lst){
  if(x+y+z==0)return 1;
  int &ret = dp[x][y][z][lst];
  if(~ret)return ret;
  ret = 0;
  if(lst!=0&&x)
    ret += 1ll * x * solve(x-1,y,z,0) % MOD;
  if(lst!=1&&y)
    ret += 1ll * y * solve(x,y-1,z,1) % MOD;
  if(ret>=MOD)ret-=MOD;
  if(lst!=2&&z)
    ret += 1ll * z * solve(x,y,z-1,2) % MOD;
  if(ret>=MOD)ret-=MOD;
  return ret;
}
vector<pair<int,int>> go[3][55];
int dp2[55][2505];
vector<int> v[3];
vector<pair<pair<int,int>,int>> sE(vector<int> v){
  memset(dp2,0,sizeof dp2);
  dp2[0][0] = 1;
  for(int k = 0; k < v.size(); k++){
    for(int j = k + 1; j >= 1; --j){
      for(int val = (k + 1) * 50; val >= v[k]; --val){
        dp2[j][val] += dp2[j-1][val - v[k]];
        if(dp2[j][val]>= MOD)dp2[j][val]-=MOD;
      }
    }
  }

  vector<pair<pair<int,int>,int>>ret;
  for(int k = 0; k <= v.size(); k++){
    for(int val = 0; val <= 2500; val++)
      if(dp2[k][val])
      ret.push_back(make_pair(make_pair(k,val),dp2[k][val]));

  }

  return ret;

}
int main(){
//  ios_base::sync_with_stdio(0);cin.tie(0);
  int n, T;
  cin >> n >>T;

  for(int k = 0; k <n; k++){
    int x, y; cin >> x >> y;
    v[y-1].push_back(x);
  }

  for(int k = 0; k < 3; k++){
    auto x = sE(v[k]);
    for(auto y : x){
      go[k][y.first.first].push_back(make_pair(y.first.second,y.second));
    }
  }
  memset(dp,-1,sizeof dp);
  int ans = 0;
  for(int sz1 = 0; sz1 <= v[0].size(); sz1++)
    for(int sz2=0; sz2 <= v[1].size(); sz2++)
      for(int sz3= 0; sz3 <= v[2].size(); sz3++)
        if(solve(sz1,sz2,sz3,3)){
//            cout <<sz1 << ' ' << sz2 <<" " << sz3 << '\n';
          for(auto x : go[0][sz1])
          for(auto y : go[1][sz2]){
            if(x.first+y.first>T)break;
            ans += 1ll * solve(sz1,sz2,sz3,3) * x.second %MOD * y.second % MOD * dp2[sz3][T-x.first-y.first] % MOD;
            if(ans>=MOD)ans-=MOD;
          }
        }

    cout << ans << "\n";

  return 0;
}