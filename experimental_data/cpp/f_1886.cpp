#include <bits/stdc++.h>
#define ALL(x) begin(x), end(x)
#define All(x, l, r) &x[l], &x[r] + 1
using namespace std;
void file() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
}
template <typename T> using vec = vector<T>;

const int kLim = 3005, sLim = 1.2e4 + 5, inf = 1e9;
int n, N;
array<int, kLim> dif;
vec<int> s1, s2, s3;

#define ls (o << 1)
#define rs (o << 1 | 1)
struct SGT {
  array<int, sLim> mn, t;
  void clr() { mn.fill(0); t.fill(0); }
  void pu(int o) { mn[o] = min(mn[ls], mn[rs]); }
  void ad(int o, int v) { mn[o] += v; t[o] += v; }
  void pd(int o) {
    if(int& x = t[o]) {
      ad(ls, x); ad(rs, x); x = 0;
    }
  }
  void bu(int o, int l, int r) {
    t[o] = 0;
    if(l == r) return void(mn[o] = dif[l]);
    int mi = (l + r) >> 1;
    bu(ls, l, mi); bu(rs, mi + 1, r);
    pu(o);
  }
  void upd(int o, int l, int r, int x, int y, int v) {
    if((l > y) || (r < x)) return ;
    if((l >= x) && (r <= y)) return ad(o, v);
    pd(o); int mi = (l + r) >> 1;
    upd(ls, l, mi, x, y, v); upd(rs, mi + 1, r, x, y, v);
    pu(o);
  }
  void upd(int o, int l, int r, int x, int v) {
    if(l == r) return void(mn[o] = v);
    pd(o); int mi = (l + r) >> 1;
    (mi < x) ? upd(rs, mi + 1, r, x, v) : upd(ls, l, mi, x, v);
    pu(o);
  }
  int qry(int o, int l, int r, int x) {
    if(l == r) return mn[o];
    pd(o); int mi = (l + r) >> 1;
    return (mi < x) ? qry(rs, mi + 1, r, x) : qry(ls, l, mi, x);
  }
  int qry() { return mn[1]; }
}sgt;

struct DSU {
  array<int, kLim> fa;
  void clr() { iota(ALL(fa), 0); }
  int fd(int x) { return (fa[x] == x) ? x : (fa[x] = fd(fa[x])); }
  void del(int x) { fa[x] = fd(x + 1); }
};

DSU pos;
bool chk(int t1, int t2) {
  pos.clr(); pos.del(t1); pos.del(t2);
  for(int k : s1) {
    int p = pos.fd(max(t1 - k, 1));
    if(p >= t1) return 0;
    pos.del(p);
  }
  for(int k : s3) {
    if(k >= t2 - t1 + 1) continue;
    int p = pos.fd(max(t1 - k, 1));
    if(p >= t1) return 0;
    pos.del(p);
  }
  dif.fill(0);
  for(int i = 1; i <= t1; i++)
    if(pos.fd(i) != i) {
      dif[i] += inf; dif[i + 1] -= inf;
    }else { dif[1]++; dif[i + 1]--; }
  for(int k : s3)
    if(k >= t2 - t1 + 1) {
      dif[1]--; dif[max(t1 - k + 1, 1)]++;
    }else break;
  for(int i = 1; i <= N; i++) dif[i] += dif[i - 1];
  sgt.bu(1, 1, N);
  vec<int> rem = s2;
  reverse(ALL(s3));
  for(int k : s3) {
    if(k < t2 - t1 + 1) {
      rem.push_back(k); continue;
    }
    int p = pos.fd(max(t2 - k, 1));
    if(p <= t1) {
      sgt.upd(1, 1, N, max(t1 - k + 1, 1), p, -1);
      if(sgt.qry() >= 0) {
        sgt.upd(1, 1, N, p, inf);
        pos.del(p); continue;
      }else sgt.upd(1, 1, N, max(t1 - k + 1, 1), p, 1);
    }
    p = pos.fd(max(t1 - k, 1));
    if(p >= t1) {
      reverse(ALL(s3));
      return 0;
    }
    pos.del(p);
    sgt.upd(1, 1, N, max(t1 - k + 1, 1), p, -1);
    sgt.upd(1, 1, N, p, inf);
    rem.push_back(k);
  }
  reverse(ALL(s3));
  sort(ALL(rem), greater<> ());
  for(int k : rem) {
    int p = pos.fd(max(t2 - k, 1));
    if(p >= t2) return 0;
    pos.del(p);
  }
  return 1;
}

bool check(int r) {
  for(int l = 1; l < r; l++)
    if(chk(l, r)) return 1;
  return 0;
}

int32_t main() {
  // file();
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n; N = 2 * n + 2;
  for(int i = 1, t, s; i <= n; i++) {
    cin >> t >> s;
    if(t == 1) s1.push_back(s);
    else if(t == 2) s2.push_back(s);
    else s3.push_back(s);
  }
  sort(ALL(s1), greater<> ());
  sort(ALL(s2), greater<> ());
  sort(ALL(s3), greater<> ());
  int l = 1, r = 2 * n + 3;
  while(l + 1 < r) {
    int mi = (l + r) >> 1;
    check(mi) ? (r = mi) : (l = mi);
  }
  cout << ((r == 2 * n + 3) ? -1 : r) << "\n";
  return 0;
}