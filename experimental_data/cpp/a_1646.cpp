#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
const lli inf = 1e18;
const int inf_int = 1e9;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    lli n,s;
    cin >> n >> s;
    if(s < n*n){
      cout << 0 << "\n";
    }else{
      cout << (s / (n*n)) << "\n";
    }
  }
}