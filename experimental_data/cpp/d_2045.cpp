#if not LOCAL
#define NDEBUG 1
#endif
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (auto i = a; i < (b); ++i)
#define down(x, a) for (auto x = a; x--;)
#define all(x) begin(x), end(x)
#define sz(x) int(size(x))
#define let auto const
using ll = long long;
using lint = ll;
using pii = pair<int, int>;
using vi = vector<int>;

inline char gc() {  // like getchar()
  static char buf[1 << 16];
  static size_t bc, be;
  if (bc >= be) {
    buf[0] = 0, bc = 0;
    be = fread(buf, 1, sizeof(buf), stdin);
  }
  return buf[bc++];  // returns 0 on EOF
}
int readInt() {
  int a, c;
  while ((a = gc()) < 40);
  if (a == '-') return -readInt();
  while ((c = gc()) >= 48) a = a * 10 + c - 480;
  return a - 48;
}

struct FT {
  vector<lint> xs;
  vector<ll> s;
  vector<lint> updates;
  void clear() {
    for (auto pos : updates) {
      for (; pos < sz(s); pos |= pos + 1) s[pos] = 0;
    }
    updates.clear();
  }
  void update(lint pos, ll dif) {  // a[pos] += dif
    pos = (lower_bound(all(xs), pos) - begin(xs));
    updates.emplace_back(pos);
    for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
  }
  ll query(lint pos) {  // sum of values in [0, pos)
    pos = (lower_bound(all(xs), pos) - begin(xs));
    ll re = 0;
    for (; pos; pos &= pos - 1) re += s[pos - 1];
    return re;
  }
  void fakeUpdate(lint x) { xs.push_back(x); }
  void init() {
    sort(all(xs));
    xs.erase(unique(all(xs)), xs.end());
    s.assign(sz(xs), 0);
  }
};

template <class T, class L, auto op, auto mapping, auto compose>
struct Tree {
  int n;
  vector<T> val;
  vector<L> lazy;
  Tree(int n) : n(n), val(2 * n), lazy(2 * n) {}
  void apply(int i, L upd) {
    val[i] = mapping(upd, val[i]);
    lazy[i] = compose(upd, lazy[i]);
  }
  void push(int x) {  // x ∈ [n..2n)
    down(i, 31 ^ __builtin_clz(x)) {
      let y = x >> (i + 1);
      rep(c, y * 2, y * 2 + 2) apply(c, lazy[y]);
      lazy[y] = {};
    }
  }
  void merge(int x) {
    while (x >>= 1) {
      assert(lazy[x] == L{});
      val[x] = op(val[x * 2], val[x * 2 + 1]);
    }
  }  // x ∈ [n..2n)
  void build() {
    down(x, n) {
      val[x] = op(val[x * 2], val[x * 2 + 1]);
      lazy[x] = {};
    }
  }
  void update(int x, T v) {
    if (x < 0 || x >= n) return;
    x += n;
    push(x);
    val[x] = v;
    merge(x);
  }
  T query(int l, int r) {  // query [l, r)
    if (l >= r) return T{};
    assert(0 <= l && l < r && r <= n);
    l += n;
    r += n;
    push(l);
    push(r - 1);
    if (l + 1 == r) return val[l];
    T x = val[l++], y = val[--r];
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1) x = op(x, val[l++]);
      if (r & 1) y = op(val[--r], y);
    }
    return op(x, y);
  }
  void update(int l, int r, L upd) {  // update [l, r)
    if (l >= r) return;
    assert(0 <= l && l < r && r <= n);
    l += n;
    r += n;
    let u = l, v = r - 1;
    push(u);
    push(v);
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1) apply(l++, upd);
      if (r & 1) apply(--r, upd);
    }
    push(u);
    push(v);
    merge(u);
    merge(v);
  }
};

const lint INF = 1e18;

struct T {
  lint val = INF;
};
using L = lint;
T op(T lft, T rgt) {  // Combine data
  return {min(lft.val, rgt.val)};
}
T mapping(L upd, T cur) {  // Apply lazy to data
  return {cur.val + upd};
}
L compose(L upd, L cur) {  // Compose lazy
  return cur + upd;
}

using SegTree = Tree<T, L, op, mapping, compose>;

const int MAXN = 2e5 + 5;

int A[MAXN];
lint prefA_[MAXN];

lint dp[MAXN][2];
lint baseCost[MAXN][2];

void Main() {
  int N = readInt(), D = readInt(), Ts = readInt(), Tf = readInt(),
      Tw = readInt();
  rep(i, 0, N) A[i] = readInt();

  if (Ts >= Tf) {
    cout << 1ll * (N - 1) * Tf << '\n';
    return;
  }

  Tf -= Ts;
  Tw *= 2;
  lint baseAns = 1ll * (N - 1) * Ts;

  rep(i, 0, N) A[i] -= D;
  rep(i, 0, N) prefA_[i] = A[i] + (i ? prefA_[i - 1] : 0);
  rep(i, N, MAXN) prefA_[i] = prefA_[N - 1];
  auto prefA = [&](int i) {
    if (i < 0) return 0ll;
    return prefA_[i];
  };

  FT os;
  rep(i, 0, N) os.fakeUpdate(prefA(i));
  os.init();

  down(i, N) {
    if (i < N - 1) {
      os.update(prefA(i), 1);
    }
    if (prefA(N - 1) + D >= prefA(i - 1)) {
      auto cnt = os.query(prefA(i - 1));
      dp[i][0] = 1ll * cnt * Tw;
    } else {
      dp[i][0] = INF;
    }
    if (prefA(N - 1) >= prefA(i)) {
      auto cnt = os.query(prefA(i) + D);
      dp[i][1] = 1ll * cnt * Tw;
    } else {
      dp[i][1] = INF;
    }
  }

  vector<tuple<lint, lint, int>> lft;
  vector<pair<lint, lint>> rgt, rgt2;
  lft.reserve(N + 5);
  rgt.reserve(N + 5);
  rgt2.reserve(N + 5);
  auto Solve = [&](auto self, int L, int R) {
    if (L >= R) return;
    int M = (L + R) / 2;
    self(self, M + 1, R);

    os.clear();
    down(i, M + 1) {
      if (i < L) break;
      if (i < M) {
        os.update(prefA(i), 1);
      }
      rep(ib, 0, 2) {
        auto bound = ib == 0 ? prefA(i - 1) : (prefA(i) + D);
        auto cnt = os.query(bound);
        baseCost[i][ib] = 1ll * cnt * Tw + Tf;
      }
    }

    lft.clear();
    rep(ib, 0, 2) {
      down(i, M + 1) {
        if (i < L) break;
        auto bound = ib == 0 ? prefA(i - 1) : (prefA(i) + D);
        lft.push_back({bound, i, ib});
      }
    }
    sort(all(lft));

    rgt.clear();
    rep(i, M + 1, R + 1) { rgt.push_back({prefA(i - 1), i}); }
    sort(all(rgt));

    SegTree seg(R - M);
    rep(jb, 0, 2) {
      rgt2.clear();
      rep(i, M, R + 1) {
        if (i > M) {
          seg.val[seg.n + i - (M + 1)] = {dp[i][jb] + jb * Tw};
        }
        if (jb == 0) {
          rgt2.push_back({prefA(i) + D - 1, i});
        } else {
          if (i + 1 < N) {
            rgt2.push_back({prefA(i + 1) + D + D - 1, i});
          }
        }
      }
      seg.build();
      sort(all(rgt2));

      int ptr_rgt = 0, ptr_rgt2 = 0;
      lint last_query = -INF;
      for (auto [val, i, ib] : lft) {
        while (ptr_rgt < sz(rgt) && rgt[ptr_rgt].first < val) {
          int j = rgt[ptr_rgt++].second;
          seg.update((int)j + 1 - (M + 1), R + 1 - (M + 1), Tw);
        }
        while (ptr_rgt2 < sz(rgt2) && rgt2[ptr_rgt2].first < val) {
          int j = rgt2[ptr_rgt2++].second;
          seg.update((int)j + 1 - (M + 1), T{INF});
        }
        if (dp[i][ib] > baseCost[i][ib] + last_query) {
          last_query = seg.query(M + 1 - (M + 1), R + 1 - (M + 1)).val;
          dp[i][ib] = min(dp[i][ib], baseCost[i][ib] + last_query);
        }
      }
    }

    self(self, L, M);
  };
  Solve(Solve, 0, N - 1);
  cout << dp[0][0] + baseAns << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int t = 1;
  // cin >> t;
  while (t--) Main();
}