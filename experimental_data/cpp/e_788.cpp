#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1.0);

const int mod = (int) 1e9 + 7;

void add(int &x, int y) {
  if ((x += y) >= mod) {
    x -= mod;
  }
}

int mult(int x, int y) {
  return (long long) x * y % mod;
}

int power(int x, int pw) {
  int res = 1;
  for (; pw; pw >>= 1) {
    if (pw & 1) {
      res = mult(res, x);
    }
    x = mult(x, x);
  }
  return res;
}

int sum(int x, int y) {
  add(x, y);
  return x;
}

void precalc() {
}

struct V {
  int cnt;
  int suma, sumb;
  int dsuma, dsumb;

  V() : cnt(0), suma(0), sumb(0), dsuma(0), dsumb(0) {}
  V(int a, int b) : cnt(1), suma(a), sumb(b), dsuma(0), dsumb(0) {}

  V(const V &l, const V &r) {
    cnt = l.cnt + r.cnt;
    suma = sum(l.suma, r.suma);
    sumb = sum(l.sumb, r.sumb);
    dsuma = sum(l.dsuma, r.dsuma);
    dsumb = sum(l.dsumb, r.dsumb);
    add(dsuma, mult(l.suma, r.cnt));
    add(dsumb, mult(r.sumb, l.cnt));
  }
};

struct T {
  int n;

  int *ca, *cb;
  V *a;
  bool *ison;

  T(vector<int> &a_, vector<int> &b_, int &res) {
    assert(sz(a_) == sz(b_));
    if (0) {
      eprintf("sz = %d\n", sz(a_));
      for (int i = 0; i < sz(a_); ++i) {
        eprintf("%d,%d\n", a_[i], b_[i]);
      }
    }
    for (n = 1; n < sz(a_); n <<= 1) ;
    a = new V[2 * n - 1];
    --a;

    ca = new int[n];
    cb = new int[n];
    ison = new bool[n];

    for (int i = 0; i < n; ++i) {
      if (i < sz(a_)) {
        ca[i] = a_[i];
        cb[i] = b_[i];
      } else {
        ca[i] = cb[i] = 0;
      }
      ison[i] = 0;
    }

    for (int i = 1; i < 2 * n; ++i) {
      a[i] = V();
    }

    for (int i = 0; i < sz(a_); ++i) {
      int toadd = get(i);
      //eprintf("add %d\n", toadd);
      add(res, toadd);
      change(i, 1);
    }
  }

  V get(int v, int l, int r, int l0, int r0) {
    if (l >= r0 || l0 >= r) {
      return V();
    }

    if (l0 <= l && r <= r0) {
      return a[v];
    }

    int m = (l + r) / 2;
    return V(get(2 * v, l, m, l0, r0), get(2 * v + 1, m, r, l0, r0));
  }

  V get(int l, int r) {
    return get(1, 0, n, l, r);
  }

  int get(int x) {
    auto left = get(0, x);
    auto right = get(x + 1, n);
    int res = 0;
    add(res, mult(ca[x], right.dsumb));
    add(res, mult(cb[x], left.dsuma));
    add(res, mult(left.suma, right.sumb));
    return res;
  }

  void change(int x, int nval) {
    assert(ison[x] != nval);
    ison[x] = nval;
    if (nval) {
      a[x + n] = V(ca[x], cb[x]);
    } else {
      a[x + n] = V();
    }
    x += n;

    for (x /= 2; x; x /= 2) {
      a[x] = V(a[2 * x], a[2 * x + 1]);
    }
  }
};


const int maxn = (int) 1e5 + 10;
int a[maxn];
int n, m;

int read() {
  if (scanf("%d", &n) < 1) {
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  scanf("%d", &m);
  return 1;
}

struct FTree {
  int n;
  int a[maxn];

  void build(int n_) {
    n = n_;
    for (int i = 0; i < n; ++i) {
      a[i] = 0;
    }
  }

  void add(int x, int toadd) {
    for (; x < n; x |= (x + 1)) {
      a[x] += toadd;
    }
  }

  int get(int x) {
    int res = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1) {
      res += a[x];
    }
    return res;
  }
} ftree;

pair<int, int> tosort[maxn];

int b[maxn];

int cnts[2][maxn];

int ids[maxn];

void solve() {
  for (int i = 0; i < n; ++i) {
    tosort[i] = mp(a[i], i);
  }
  sort(tosort, tosort + n);

  int cnt = 0;
  for (int i = 0; i < n;) {
    int i0 = i;

    while (i < n && tosort[i].first == tosort[i0].first) {
      b[tosort[i].second] = cnt;
      ++i;
    }
    ++cnt;
  }


  for (int iter = 0; iter < 2; ++iter) {
    ftree.build(cnt);
    for (int ri = 0; ri < n; ++ri) {
      int i = ri;
      if (iter) {
        i = n - 1 - i;
      }

      int y = b[i];
      cnts[iter][i] = ftree.get(y);
      ftree.add(y, 1);
    }
  }

  int res = 0;

  map<int, T*> tree;
  for (int i = 0; i < n;) {
    int i0 = i;

    while (i < n && tosort[i].first == tosort[i0].first) {
      ++i;
    }

    vector<int> as(i - i0);
    vector<int> bs(i - i0);
    for (int j = i0; j < i; ++j) {
      int pos = tosort[j].second;
      ids[pos] = j - i0;
      as[j - i0] = cnts[0][pos];
      bs[j - i0] = cnts[1][pos];
    }
    tree[tosort[i0].first] = new T(as, bs, res);
  }

  for (int iter = 0; iter < m; ++iter) {
    int type, x;
    scanf("%d%d", &type, &x);
    --type;
    --x;

    auto &t = *(tree[a[x]]);

    if (!type) {
      t.change(ids[x], 0);
    }

    int delta = t.get(ids[x]);
    if (!type) {
      add(res, mod - delta);
    } else {
      add(res, delta);
    }

    if (type) {
      t.change(ids[x], 1);
    }

    printf("%d\n", res);
  }
}

int main() {
  precalc();
#ifdef LOCAL
  freopen(TASK ".out", "w", stdout);
  assert(freopen(TASK ".in", "r", stdin));
#endif

  while (1) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}