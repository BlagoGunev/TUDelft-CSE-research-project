#include <bits/stdc++.h>

using namespace std;

int t, n, m;

bool F(){
  for(int i = 2; i <= m && i * i <= n; i++){
    if(n % i == 0){
      return 0;
    }
  }
  return 1;
}

int main(){
  cin >> t;
  while(t--){
    cin >> n >> m;
    cout << (m < n && F() || n == 1 ? "YES" : "NO") << '\n';
  }
  return 0;
}