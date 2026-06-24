# include <bits/stdc++.h>

using namespace std;

int n;
long long ans = 1;

int main(){
      cin >> n;

      if(n & 1)
            cout << 0 << endl;
      else {
            n /= 2;
            while(n --){
                  ans *= 2;
            }
            cout << ans << endl;
      }
}