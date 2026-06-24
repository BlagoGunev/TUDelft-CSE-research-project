#include<bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin >> T;
   while(T--){
      string s , t;
      cin >> s >> t;
      int ans = (int)s.size() + (int)t.size() , p = 0;
      while(p < min((int)s.size() , (int)t.size()) && s[p] == t[p]){
         ++p , --ans;
      }
      if(p > 0){
         ++ans;
      }
      cout << ans << '\n';
   }
}