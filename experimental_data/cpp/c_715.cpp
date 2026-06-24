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

void precalc() {
}

int n, mod;

void add(int &x, int y) {
  if ((x += y) >= mod) {
    x -= mod;
  }
}

int mult(int x, int y) {
  return (long long) x * y % mod;
}

const int maxn = (int) 1e5 + 10;
int tmp[maxn * 2 + 1];
int *ten = tmp + maxn;

int gcdExt(int a, int b, int &c, int &d) {
  if (!b) {
    c = 1, d = 0;
    return a;
  }
  int res = gcdExt(b, a % b, d, c);
  d -= (a / b) * c;
  return res;
}

void prec() {
  int x = 10 % mod;
  int c, d;
  assert(gcdExt(x, mod, c, d) == 1);
  int invx = c % mod;
  if (invx < 0) {
    invx += mod;
  }
  assert(mult(x, invx) == 1 % mod);
  //eprintf("%d * %d = 1\n", x, invx);

  ten[0] = 1 % mod;
  for (int i = 0; i < maxn; ++i) {
    ten[i + 1] = mult(ten[i], x);
    ten[-i - 1] = mult(ten[-i], invx);
  }
}

vector<vector<int> > es, cs;

int read() {
  if (scanf("%d%d", &n, &mod) < 2) {
    return 0;
  }
  prec();
  es = cs = vector<vector<int> >(n);
  for (int i = 0; i < n - 1; ++i) {
    int s, t, c;
    scanf("%d%d%d", &s, &t, &c);
    c %= mod;
    es[s].pb(t), es[t].pb(s);
    cs[s].pb(c), cs[t].pb(c);
  }
  return 1;
}

struct T {
  map<int, int> *tree;
  int k, b;

  T() : k(0), b(0) {
    tree = new map<int, int>();
  }

  void add(int x, int cnt = 1) {
    assert(0 <= b && b < mod);

    ::add(x, mod - b);
    x = mult(x, ten[-k]);
    (*tree)[x] += cnt;
  }
  
  int get(int x) const {
    assert(0 <= x && x < mod);
    assert(0 <= b && b < mod);

    ::add(x, mod - b);
    x = mult(x, ten[-k]);

    auto iter = tree->find(x);
    return iter == tree->end() ? 0 : iter->second;
  }
};

long long res;

pair<T, T> dfs(int v, int pr) {
  pair<T, T> res;
  res.first.add(0);
  res.second.add(0);

  //eprintf("?");
  for (int it = 0; it < sz(es[v]); ++it) {
    int u = es[v][it];
    if (u == pr) {
      continue;
    }
    //eprintf("%d %d\n", v, u);
    auto got = dfs(u, v);
    got.first.k += 1;
    got.first.b = mult(got.first.b, ten[1]);

    got.second.k -= 1;
    got.second.b = mult(got.second.b, ten[-1]);

    add(got.first.b, cs[v][it]);
    add(got.second.b, cs[v][it]);
    //eprintf("%d\n", got.first.b);


    //eprintf("%d %d\n", sz(*got.first.tree), sz(*res.first.tree));
    if (sz(*got.first.tree) > sz(*res.first.tree)) {
      swap(res, got);
      //eprintf("?");
    }

    for (int it = 0; it < 2; ++it) {
      T &big = !it ? res.first : res.second;
      T &small = it ? got.first : got.second;
      /*eprintf("it = %d\n", it);
  for (pair<int, int> cur : *(big.tree)) {
    int want = cur.first;
    want = mult(want, ten[big.k]);
    add(want, big.b);
    eprintf("%dx%d\n", want, cur.second);
  }
  eprintf("small:\n");
  for (pair<int, int> cur : *(small.tree)) {
    int want = cur.first;
    want = mult(want, ten[small.k]);
    add(want, small.b);
    eprintf("%dx%d\n", want, cur.second);
  }*/
      for (pair<int, int> cur : *(small.tree)) {
        int want = cur.first;
        want = mult(want, ten[small.k]);
        add(want, small.b);
        want = mult(want, ten[!it ? -1 : 1]);

        want = mod - want;
        add(want, 0);

        ::res += (long long) big.get(want) * cur.second;
        if (0 && ::res) {
          eprintf("it = %d\n", it);
          eprintf("%d %d\n", v, u);
        }
      }
    }

    for (int it = 0; it < 2; ++it) {
      T &big = !it ? res.first : res.second;
      T &small = !it ? got.first : got.second;
      for (pair<int, int> cur : *(small.tree)) {
        int want = cur.first;
        want = mult(want, ten[small.k]);
        add(want, small.b);

        big.add(want, cur.second);
      }
    }
  }
  /*eprintf("finish %d\n", v);
  for (pair<int, int> cur : *(res.first.tree)) {
    int want = cur.first;
    want = mult(want, ten[res.first.k]);
    add(want, res.first.b);
    eprintf("%dx%d\n", want, cur.second);
  }*/
  return res;
};

void solve() {
  res = 0;
  dfs(0, -1);
  printf("%lld\n", res);
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