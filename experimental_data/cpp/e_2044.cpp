#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main(){
   int T;
   cin >> T;
   while(T--){
      LL k , l1 , r1 , l2 , r2;
      cin >> k >> l1 >> r1 >> l2 >> r2;
      LL v = 1 , ans = 0;
      while(v < 1E10){
         LL L = l1 * v;
         LL R = r1 * v;
         if(L > r2 || R < l2){
            v *= k;
            continue;
         }
         if(L < l2){
            L = l2 + (v - l2 % v) % v;
         }
         if(R > r2){
            R = r2 - r2 % v;
         }
         if(L <= R){
            ans += (R - L) / v + 1;
         }
         v *= k;
      }
      cout << ans << '\n';
   }
}