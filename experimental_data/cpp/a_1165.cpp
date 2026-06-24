#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define fast ios_base :: sync_with_stdio(false); cin.tie(0)
const int mod = 1e9+7;
const int inf = LLONG_MAX;
const int N = 1e6;

signed main(){
 fast;
 int n, x, y;
 cin >> n >> x >> y;
 string num;
 cin >> num;

 int pos = 0, ans = 0;
 for(int i = n-1; i >= n-x; i--){
  pos++;
  if(pos == y+1){
   if(num[i] == '1') continue;
   else ans++;
  }
  else{
   if(num[i] == '1') ans++;
  }
 }
 cout << ans << endl;
 return 0;
}