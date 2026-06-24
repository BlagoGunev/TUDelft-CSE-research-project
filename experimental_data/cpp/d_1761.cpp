#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e6 + 5;

constexpr int mod = 1e9 + 7;

void add(int &x, int y) {x += y, x >= mod && (x -= mod);}

int ksm(int a, int b) {

  int s = 1;

  while(b) {

    if(b & 1) s = 1ll * s * a % mod;

    a = 1ll * a * a % mod, b >>= 1;

  }

  return s;

}

int n, k, ans, fc[N], ifc[N];

int bin(int n, int m) {

  if(n < 0 || m > n) return 0;

  return 1ll * fc[n] * ifc[m] % mod * ifc[n - m] % mod;

}

int main() {

  cin >> n >> k;

  for(int i = fc[0] = 1; i < N; i++) fc[i] = 1ll * fc[i - 1] * i % mod;

  ifc[N - 1] = ksm(fc[N - 1], mod - 2);

  for(int i = N - 2; ~i; i--) ifc[i] = 1ll * ifc[i + 1] * (i + 1) % mod;

  if(k == 0) cout << ksm(3, n) << "\n", exit(0);

  for(int i = 1; i <= k; i++) {

    int r = n - (k + i - 1);

    if(r < 0) break;

    int coef = bin(k - 1, i - 1);

    if(r >= 1) add(ans, 1ll * coef * bin((r - 1) + i, i) % mod * ksm(3, n - i * 2) % mod);

    add(ans, 1ll * coef * bin(r + i - 1, i - 1) % mod * ksm(3, n - i * 2 + 1) % mod);

  }

  cout << ans << "\n";

  return 0;

}