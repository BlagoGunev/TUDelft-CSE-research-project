#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

#define endl '\n'
#define pb push_back
#define vi vector<int>
using pi = pair<int, int>;

const int MOD = 1e9 + 7;

int binpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}
int modinv(int n) {
  return binpow(n, MOD - 2);
}

int gauss(int n) {
  return (n * (n + 1) % MOD) * modinv(2) % MOD;
}
int gauss(int a, int b) {
  return (gauss(b) - gauss(a - 1) + MOD) % MOD;
}

const int N = 2e5 + 5;
int fac[N];

void init() {
  fac[0] = 1;
  for (int i = 1; i < N; ++i) fac[i] = fac[i - 1] * i % MOD;
}

int C(int n, int k) {
  return (fac[n] * modinv(fac[k]) % MOD) * modinv(fac[n - k]) % MOD;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  init();
  
  int t;
  cin >> t;
  
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    
    int possible_pairs = (n * (n - 1) % MOD) * modinv(2) % MOD;
    int prob_chosen = modinv(possible_pairs) % MOD, prob_not_chosen = (1 - prob_chosen + MOD) % MOD;
    
    vector<int> friends;
    for (int i = 0; i < m; ++i) {
      int a, b, f;
      cin >> a >> b >> f;
      friends.pb(f);
    }
    
    // the expected number of times something is chosen
    int exp = 0, exp_add = 0;
    for (int j = 1; j <= k; ++j) {
      int prob = (binpow(prob_chosen, j) * C(k, j) % MOD) * binpow(prob_not_chosen, k - j) % MOD;
      exp = (exp + j * prob % MOD) % MOD;
      exp_add = (exp_add + gauss(j - 1) * prob) % MOD;
    }
    
    int ans = 0;
    for (int f : friends) {
      int val = (exp_add) % MOD + f * exp % MOD;
      ans = (ans + val) % MOD;
      // the amount of times this is chosen
      /*for (int j = 1; j <= k; ++j) {
        int val = f + j - 1;
        int prob = binpow(prob_chosen * modinv(m) % MOD, j) * C(k, j) % MOD;
        ans = (ans + val * prob % MOD) % MOD;
      }*/
    }
    
    cout << ans << endl;
  }
}

/*
2 1 10
1 2 1
*/