#include <bits/stdc++.h>

#include <numeric>
using namespace std;
#define pb push_back
#define reset(a, b) memset(a, b, sizeof a);
#define ALL(x) x.begin(), x.end()

template <typename T>
void cetak(T t) {
  cout << t << ')' << endl;
}
template <typename T, typename... V>
void cetak(T t, V... v) {
  cout << t;
  if (sizeof...(v))
    cout << ", ";
  cetak(v...);
}

#define debug(x...)             \
  cout << '(' << #x << ") = ("; \
  cetak(x)
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())
typedef int (*func)(int, int);

const int mx = 100 + 10;
int n, a, b;

int awal_a, awal_b;

long long dp[mx][mx];

long long f(int x, int y) {
  if (x == n && y == n) {
    return gcd(x, a) + gcd(y, b);
  }
  long long &ret = dp[x - awal_a][y - awal_b];
  if (ret != -1) return ret;
  ret = 1e18;

  if (x + 1 <= n) {
    ret = min(ret, f(x + 1, y));
  }
  if (y + 1 <= n) {
    ret = min(ret, f(x, y + 1));
  }
  ret += gcd(x, a) + gcd(y, b);
  return ret;
}

void solve(int tc) {
  cin >> n >> a >> b;
  reset(dp, -1);

  for (int i = 1; i <= n; i++) {
    if (gcd(i, a) == 1) {
      awal_a = i;
    }
    if (gcd(i, b) == 1) {
      awal_b = i;
    }
  }

  int total = 0;
  for (int i = 1; i < awal_a; i++) {
    total += gcd(i, a);
    total++;
  }
  for (int i = 1; i < awal_b; i++) {
    total += gcd(i, b);
    total++;
  }

  // debug(awal_a, awal_b, total, f(awal_a, awal_b));

  cout << f(awal_a, awal_b) + total << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  // cin >> t;
  int tc = 0;
  while (t--) {
    solve(++tc);
  }
}