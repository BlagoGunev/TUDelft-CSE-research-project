#include <bits/stdc++.h>



#define pb push_back

#define ll long long

#define ld long double



using namespace std;



typedef complex<double> base;



mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());



typedef pair <pair <int, int>, int> II;



const int N = 5e5 + 10;

const int mod = 998244353;

const double PI = acos(-1);



int t;

int n;



int mx = 300000;



int fact[N];

int fact2[N];



int cnt[N];



int bin(int x, int y) {

  int ans = 1;

  while (y) {

    if (y & 1)

      ans = ans * 1LL * x % mod;

    x = x * 1LL * x % mod;

    y >>= 1;

  }

  return ans;

}



int C(int n, int k) {

  return fact[n] * 1LL *

    bin(fact[k] * 1LL * fact[n - k] % mod, mod - 2) % mod;

}



int solve(int n) {

  int ans = 0;

  for (int i = 0; i <= n / 4; i++) {

    ans += C(n-2*i, 2*i) * 1LL * fact2[i] % mod * 1LL * bin(2, i) % mod * 1LL * cnt[n-i*4] % mod;

    ans %= mod;

  }

  return ans;

}



int main() {

  ios_base::sync_with_stdio(false);

  cin >> t;

  fact[0] = 1;

  fact2[0] = 1;

  for (int i = 1; i <= mx; i++) {

    fact[i] = fact[i - 1] * 1LL * i % mod;

    fact2[i] = fact2[i - 1] * 1LL * (i + i - 1) % mod;

  }

  cnt[0] = 1;

  cnt[1] = 1;

  for (int i = 2; i <= mx; i++) {

    cnt[i] = (cnt[i-2] * 1LL * (i - 1) % mod + cnt[i-1]) % mod; 

  } 

  while (t--) {

    cin >> n;

    cout << solve(n) << '\n';

  }

  return 0;

}