#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define mp make_pair
#define F first
#define S second

constexpr int mod = 998244353;

void compute() {
  int l, r;
  cin >> l >> r;
  int k = 0;
  while (l * (1 << k) <= r) k++;

  cout << k << " ";  // this is maximal length

  ll a = (r / (1 << (k - 1))) - l + 1;                        // number of x, 2x, 4x, ..., 2^{k-1} x
  ll b = (k - 1) * max(0, r / ((1 << (k - 2)) * 3) - l + 1);  // number of x, ... 2^{k-2} * 3 x

  //   cout << a << "+" << b << "\n";
  cout << (a + b) % mod << "\n";
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int t;
  cin >> t;
  while (t-- > 0) compute();

  return 0;
}