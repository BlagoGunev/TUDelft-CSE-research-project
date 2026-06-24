#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long
#define mp(x, y) make_pair(x, y)
#define eb(...) emplace_back(__VA_ARGS__)
#define fro(i, x, y) for(int i = (x); i <= (y); i++)
#define pre(i, x, y) for(int i = (x); i >= (y); i--)
inline void JYFILE19();

typedef int64_t i64;
typedef pair<int, int> PII;

bool ST;
const int N = 1e6 + 10;

int n, m, k, d, a[N], dp[N], sum[N];

inline void solve() {
  cin >> n >> m >> k >> d;
  fro(i, 1, n) {
    fro(j, 1, m) cin >> a[j];
    dp[1] = 1;
    multiset<int> q;
    q.insert(1);
    fro(j, 2, m) {
      dp[j] = *q.begin() + a[j] + 1;
      if (j - d - 1 >= 1) {
        q.erase(q.find(dp[j - d - 1]));
      }
      q.insert(dp[j]);
    }
    sum[i] = dp[m];
  }
  fro(i, 1, n) sum[i] += sum[i - 1];
  int ans = 1e18;
  fro(i, k, n)
    ans = min(ans, sum[i] - sum[i - k]);
  cout << ans << "\n";
  fro(i, 1, n) sum[i] = 0;
}

signed main() {
  JYFILE19();
  int t; cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
bool ED;
inline void JYFILE19() {
  // freopen("", "r", stdin);
  // freopen("", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  double MIB = fabs((&ED-&ST)/1048576.), LIM = 125;
  cerr << "MEMORY: " << MIB << endl, assert(MIB<=LIM);
}