#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;

int main() {
      cin.tie(0); ios_base::sync_with_stdio(0);

      int N;
      cin >> N;
      
      vector<int> A(N);
      for(int i = 0; i < N; i++) cin >> A[i];

      ll ans = 0;
      for(int b = 0; b < 30; b++) {
            vector<int> B(N);
            for(int i = 0; i < N; i++) B[i] = A[i] >> b & 1;

            ll sumOdd = 0, sumEven = 0, cnt = 0, cntEven = 0, cntOdd = 0;
            for(int i = 0; i < N; i++) {
                  if(B[i]) cnt++;
                  if(cnt & 1) sumOdd += i, cntOdd++;
                  else sumEven += i, cntEven++;
            }

            cnt = 0;
            ll tot = 0;
            for(int i = 0; i < N; i++) {
                  if(cnt & 1) {
                        tot += sumEven - (i - 1) * cntEven;
                  } else {
                        tot += sumOdd - (i - 1) * cntOdd;
                  }

                  if(B[i]) cnt++;
                  if(cnt & 1) sumOdd -= i, cntOdd--;
                  else sumEven -= i, cntEven--;
            }

            for(int k = 0; k < b; k++) {
                  tot *= 2;
                  tot %= mod;
            }

            ans += tot;
            ans %= mod;
      }  

      cout << ans << '\n';
}