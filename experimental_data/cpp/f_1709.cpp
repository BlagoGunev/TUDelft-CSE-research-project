#include <bits/stdc++.h>

using namespace std;



const int mod = 998244353;

const int i3 = (mod + 1) / 3;



int getsize(int a, int b) {

  int ret = 2;

  while (ret <= a + b) ret <<= 1;

  return ret;

}



int qpow(int a, int p) {

  int ret = 1;

  while (p) {

    if (p & 1) ret = ret * (long long)a % mod;

    a = a * (long long)a % mod;

    p >>= 1;

  }

  return ret;

} 



void change(vector<int>& y, int len) {

  for (int i = 1, j = len >> 1; i < len - 1; i++) {

    if (i < j) swap(y[i], y[j]);

    int k = len >> 1;

    while (j >= k) {

      j -= k;

      k >>= 1;

    }

    if (j < k) j += k;

  }

  return ;

}



void fft(vector<int>& y, int len, int on) {

  change(y, len);

  for (int h = 2; h <= len; h <<= 1) {

    int wn = qpow(on == 1 ? 3 : i3, (mod - 1) / h);

    for (int j = 0; j < len; j += h) {

      int w = 1;

      for (int k = j; k < j + h / 2; k++) {

        int u = y[k], t = w * (long long)y[k + h / 2] % mod;

        y[k] = (u + t) % mod;

        y[k + h / 2] = (u - t + mod) % mod;

        w = w * (long long)wn % mod;

      }

    }

  }

  if (on == -1) {

    int ilen = qpow(len, mod - 2);

    for (int i = 0; i < len; i++) y[i] = y[i] * (long long)ilen % mod;

  }

  return ;

}



vector<int> mul(vector<int> u) {

  int su = u.size();

  int sz = getsize(su - 1, su - 1);

  u.resize(sz);

  for (int i = su; i < sz; i++) u[i] = 0;

  fft(u, sz, 1);

  for (int i = 0; i < sz; i++) u[i] = u[i] * (long long)u[i] % mod;

  fft(u, sz, -1);

  u.resize(su + su - 1);

  return u;

}



int n, k, f;



void solve() {

  cin >> n >> k >> f;

  vector<int> a(k + k + 1), s(k + 1);

  for (int i = 0; i <= k; i++) a[i] = i + 1;

  for (int i = k + 1; i <= k + k; i++) a[i] = k + k + 1 - i;

  s[0] = 0;

  for (int i = 1; i <= k; i++) s[i] = (s[i - 1] + a[i - 1]) % mod;

  for (int t = 2; t <= n; t++) {

    a.resize(k + 1);

    for (int i = 0; i <= k; i++) s[i] = (qpow(k + 1, (1 << t) - 2) + mod - s[i]) % mod;

    for (int i = 0; i <= k; i++) a[i] = a[i] * (long long)(k - i) % mod;

    for (int i = 0; i <= k; i++) a[i] = (a[i] + s[i]) % mod;

    a = mul(a);

    s[0] = 0;

    for (int i = 1; i <= k; i++) s[i] = (s[i - 1] + a[i - 1]) % mod;

  }

  if (f <= a.size()) cout << a[f] << endl;

  else cout << 0 << endl;

  return ;

}



signed main() {

  #ifdef Sakuyalove

    freopen("in.in", "r", stdin);

    freopen("out.out", "w", stdout);

  #endif

  ios::sync_with_stdio(false);

  cin.tie(0);

  cout.tie(0);

  int T = 1;

  // cin >> T;

  while (T--) solve();

}