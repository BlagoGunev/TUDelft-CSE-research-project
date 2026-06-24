#include <bits/extc++.h>

#define pb push_back
// #define int long long
typedef long long ll;
#define ld long double
#define pai pair<int, int>
#define fr first
#define sc second
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
using namespace std;
const int INF = (int) 1e18;

vector<int> kek(vector<int> a) {
  int n = (int) a.size();
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    b[i] = a[i] ^ a[(i + 1) % n];
  }
  return b;
}

int bit_solve(int n, vector<int> &b) {
  if (*max_element(all(b)) == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  bool ok = true;
  for (int i = 0; i < n / 2; i++) {
    ok &= (b[i] == b[i + n / 2]);
  }
  if (ok) {
    vector<int> h1;
    for (int i = 0; i < n / 2; i++)h1.pb(b[i]);
    return bit_solve(n / 2, h1);
  }
  vector<int> b2(n);
  for (int i = 0; i < n; i++) {
    b2[i] = b[i] ^ b[(i + n / 2) % n];
  }
  return n / 2 + bit_solve(n, b2);
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << bit_solve(n, a) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
}


// a1 a2 a3 a4 a5 a6 a7 a8
// a1^a2 a2^a3 a3^a4 a4^a5 a5a6
// a1^a3 a2^a4 a3^a5 a4a6
// a1a2a3a4 a2a3a4a5 a3a4a5a6
// a1a5 a2a6
// a1a2a5a6 a2a3a6a7
// a1a3a5a7 a2a4a6a8
// a1a2a3a4a5a6a7a8
// 0 0