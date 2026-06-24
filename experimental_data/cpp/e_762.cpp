// CONTEST SOURCE
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <sstream>
#include <set>
#include <unordered_map>
//#include <priority_queue>
using namespace std;
#define ll long long
#define x first
#define y second
#define pii pair<int, int>
#define pdd pair<double, double>
#define L(s) (int)(s).size()
#define VI vector<int>
#define all(s) (s).begin(), (s).end()
#define pb push_back
#define mp make_pair
#define inf 1000000000
int n, k;
pair<int, pair<int, int> > a[111111];
vector<int> f[11111], vals[11111];
set<pair<pair<int, int> , pair<int, int> > > ord_xr;
map<int, int> cnt;
void put(vector<int> &f, int v, int l, int r, int pos, int val) {
  if (l + 1 == r) {
    f[v] = val;
    return;
  }
  int mid = (l + r + 1) / 2;
  if (pos < mid) put(f, 2 * v + 1, l, mid, pos, val);
  else put(f, 2 * v + 2, mid, r, pos, val);
  f[v] = f[2 * v + 1] + f[2 * v + 2];
}
int get(vector<int> &f, int v, int l, int r, int st, int fn) {
  if (l == st && r == fn) return f[v];
  int mid = (r + l + 1) / 2, ans = 0;
  if (st < mid) ans += get(f, 2 * v + 1, l, mid, st, min(mid, fn));
  if (fn > mid) ans += get(f, 2 * v + 2, mid, r, max(st, mid), fn);
  return ans;
}
int main() {
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; ++i) {
    scanf("%d%d%d", &a[i].x, &a[i].y.x, &a[i].y.y);
    vals[a[i].y.y].pb(a[i].x);
  }

  for(int i = 0; i < 11111; ++i) {
    sort(all(vals[i]));
    f[i].resize(L(vals[i]) << 2);
  }

  sort(a, a + n);
  ll ans = 0;
  for(int i = 0; i < n; ++i) {
    while(L(ord_xr)) {
      set<pair<pair<int, int> , pair<int, int> > >::iterator it = ord_xr.begin();
      if (it->x.x < a[i].x) {
        int pos = lower_bound(all(vals[it->y.y]), it->x.y) - vals[it->y.y].begin();
        put(f[it->y.y], 0, 0, L(vals[it->y.y]), pos, 0);
        ord_xr.erase(it);
        //cerr << "remove " << it->y.x << endl;
      } else {
        break;
      }
    }

    ord_xr.insert(mp(mp(a[i].x + a[i].y.x, a[i].x), mp(a[i].y.x, a[i].y.y)));
    for(int fval = a[i].y.y - k; fval <= a[i].y.y + k; ++fval) {
      if (fval < 0 || fval >= 11111) continue;
      if (!L(vals[fval])) continue;
      int pos = lower_bound(all(vals[fval]), a[i].x - a[i].y.x) - vals[fval].begin();
      if (pos == L(vals[fval])) continue;

      int cur = get(f[fval], 0, 0, L(vals[fval]), pos, L(vals[fval]));
      //cerr << i << " " << fval << " " << cur << endl;
      ans += cur;
    }
    int mypos = lower_bound(all(vals[a[i].y.y]), a[i].x) - vals[a[i].y.y].begin();
    put(f[a[i].y.y], 0, 0, L(vals[a[i].y.y]), mypos, 1);
  }
  cout << ans << endl;
}