#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i = 1; i <= n; i++)
#define REP(i, n) for(int i = 0; i < n; i++)
#define MP make_pair
#define FI first
#define SE second
#define VI vector<int>
#define CLR(x) memset(x, 0, sizeof(x))
#define SZ(x) (x.size())
#ifdef QWERTIER
#define err(x) cerr<<x<<endl;
#else
#define err(x)
#endif
typedef long long LL;
typedef pair<int, int> pii;

#define N 3010
#define L 14
pii a[N];
int suc[N];
pii maxv[N][L];
pii get_max(int l, int r) {
  int ll = log2(r-l+1);
  return max(maxv[l][ll], maxv[r-(1<<ll)+1][ll]);
}
int b[N];
int main() {
#ifdef QWERTIER
  freopen("in.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  FOR (i, n) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a+1, a+n+1);
  reverse(a+1, a+n+1);
  FOR (i, n) {
    suc[i] = a[i].first - a[i+1].first;
  }
  FOR (i, n)
    maxv[i][0] = pii(suc[i], i);
  FOR (j, L-1) {
    for (int i = 1; i + (1<<j) -1 <= n; i++)
      maxv[i][j] = max(maxv[i][j-1], maxv[i+(1<<(j-1))][j-1]);
  }

  pair<pii, int> ans;
  pair<pii, int> opt;
  FOR (i, n) {
    for (int j = 1; j + i <= n; j++) {
      if (2 * j < i || 2 * i < j)
        continue;
      int kr = min(n-i-j, 2 * min(i, j));
      int kl = (max(i, j) + 1) / 2;
      if (kl > kr)
        continue;
      // printf("%d %d %d %d\n", i, j, kl, kr);
      auto tmp = get_max(i+j+kl, i+j+kr);
      pair<pii, int> res = make_pair(pii(suc[i], suc[i+j]), tmp.first);
      if (ans <= res) {
        opt = make_pair(pii(i, i+j), tmp.second);
        ans = res;
      }
    }
  }
  FOR (i, opt.first.first)
    b[a[i].second] = 1;
  for (int i = opt.first.first + 1; i <= opt.first.second; i++)
    b[a[i].second] = 2;
  for (int i = opt.first.second+1; i <= opt.second; i++)
    b[a[i].second] = 3;
  for (int i = opt.second+1; i <= n; i++)
    b[a[i].second] = -1;
  FOR (i, n)
    printf("%d ", b[i]);
  return 0;
}