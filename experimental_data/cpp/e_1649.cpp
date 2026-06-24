#include<bits/stdc++.h>

using namespace std;



int main() {

  cin.tie(0)->sync_with_stdio(0);

  

  const int MX = 2e5 + 5, M = 998244353;

  vector<long long> fact(MX), ifact(MX);





  auto modpow = [&](int a, int b) -> int {

    long long res = 1;



    for (; b > 0; b >>= 1, a = a * 1LL * a % M) {

      if (b & 1) res = res * a % M;

    }

    return res;

  };



  auto getinv = [&](int x) -> int {

    return modpow(x, M - 2);

  };



  fact[0] = ifact[0] = 1;

  for (int i = 1; i < MX; i++) {

    fact[i] = fact[i - 1] * i % M;

    ifact[i] = getinv(fact[i]);

  }



  vector<int> ft(MX);

  auto add = [&](int i, int v) -> void {

    for (; i < MX; i += i&-i) 

      ft[i] += v;

  };

  auto get = [&](int i) -> int {

    int res = 0;

    for (; i > 0; i -= i&-i)

      res += ft[i];

    return res;

  };







  int n, m;

  cin >> n >> m;

  vector<int> A(n), B(m), cnt(MX);

  for (int& x : A) cin >> x, ++cnt[x], add(x, +1);

  for (int& x : B) cin >> x;



  long long ans = 0, pref = 1;

  for (int i = 1; i < MX; i++) pref = pref * ifact[cnt[i]] % M;

    

  for (int i = 0; i < min(n, m); i++) {

    // [0...(i-1)] completely matches B

    // let's put something at A[i] such that A[i] < B[i]



    ans += (pref * get(B[i] - 1) % M) * fact[n - i - 1] % M;

    ans %= M;

    if (cnt[B[i]] == 0) break;



    pref = pref * cnt[B[i]] % M;

    cnt[B[i]]--;

    add(B[i], -1);

  }



  if (n < m) {

    // we we can match whole prefix of length n

    if (*max_element(cnt.begin(), cnt.end()) == 0) ans = (ans + 1) % M;

  }

  cout << ans % M;



  return 0;

}