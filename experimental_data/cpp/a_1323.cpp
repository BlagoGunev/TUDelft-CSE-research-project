#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define MODY ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
signed main(){
  int t;
  cin >> t;
  while(t--){
    int n;
  cin >> n;
  int a[n];
  for (int i = 0; i<n ; i++) cin >> a[i];
  bool found = false;
  for (int i =0; i<n; i++){
    if (a[i]%2==0) {
      cout << 1 << '\n' << i+1; 
      found = true;
      break;
    }
  }
  if (!found) {
    if (n==1) cout << -1;
    else cout << 2 << '\n' << 1 << ' ' << 2;
  }
    cout << '\n';

}
}