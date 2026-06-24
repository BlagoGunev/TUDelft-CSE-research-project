#include <bits/stdc++.h>

using namespace std;

#define si(a) scanf("%d",&a)
#define f first
#define s second
#define mp(a,b) make_pair(a,b)

#define MAX 1000005
long long mod = 1000000007;
int N, cnt[MAX];
int dp[MAX], pow2[MAX];

int main()
{
   pow2[0] = 1;
   for(int i = 1; i < MAX; i++){
      pow2[i] = (pow2[i-1] << 1);
      if(pow2[i] >= mod) pow2[i] -= mod;
   }

   si(N);
   for(int i = 0; i < N; i++) {
      int a;
      si(a);
      cnt[a]++;
   }

   long long ans = 0;
   for(int i = MAX-1; i > 1; i--) {
      int c = 0;
      for(int j = i; j < MAX; j += i) c += cnt[j];
      if(c) dp[i] = (long long)(c) * pow2[c-1] % mod;
      for(int j = i+i; j < MAX; j += i) {
         dp[i] -= dp[j];
         if(dp[i] < 0) dp[i] += mod;
      }
      ans = (ans + (long long)(i) * dp[i]) % mod;
   }
   cout << ans << endl;
}