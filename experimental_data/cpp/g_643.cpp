#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define x first
#define y second
#define pii pair<int, int>
#define pdd pair<double, double>
#define INF 1000000000
#define FOR(i, a, b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i, n) FOR(i, 1, (n))
#define rept(i, n) FOR(i, 0, (n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a), 0, sizeof(a))
#define VI vector<int>
#define ll long long

uint32_t x, y, z, w;

inline uint32_t rnd() {
  uint32_t t = x;
  t ^= t << 11;
  t ^= t >> 8;
  x = y;
  y = z;
  z = w;
  w ^= w >> 19;
  w ^= t;
  return w;
}

int a, b, c, d, n, m, k, p, s;
int mas[150002];
const int S = 400;
const int N = 150000;
const int K = (N + S - 1) / S;
int bl2[150002][K + 1], full[K + 1];
inline void build() {
  memset(full, -1, sizeof(full));
  rept(i, n) {
    int nbl = i / s;
    ++bl2[mas[i]][nbl];
  }
}

inline void updPart(int v, int l, int r, int id) {
  if (full[v] != -1) {
    FOR(i, v * s, v * s + s - 1) {
      --bl2[mas[i]][v];
      mas[i] = full[v];
      ++bl2[full[v]][v];
    }
    full[v] = -1;
  }
  FOR(i, l, r) {
    --bl2[mas[i]][v];
    mas[i] = id;
    ++bl2[id][v];
  }
}

inline void upd(int l, int r, int id) {
  int nl = l / s, nr = r / s;
  FOR(i, nl + 1, nr - 1) { full[i] = id; }
  if (nl != nr) {
    updPart(nl, l, nl * s + s - 1, id);
    updPart(nr, nr * s, r, id);
  } else {
    updPart(nl, l, r, id);
  }
}

inline int getVal(int pos) {
  int nbl = pos / s;
  if (full[nbl] != -1) return full[nbl];
  return mas[pos];
}

int TT = -1;
int cnt[150002], last[150002], lpos[150002];
int ls[502], ans[11], ls2[502];
int pcnt[502];

inline int getCntPart(int v, int l, int r, int id) {
  if (full[v] != -1) {
    if (id == full[v])
      return r - l + 1;
    else
      return 0;
  }
  int ans = 0;
  FOR(i, l, r) {
    if (mas[i] == id) ++ans;
  }
  return ans;
}

inline int getCnt(int l, int r, int id) {
  int nl = l / s, nr = r / s;
  int ans = 0;
  FOR(i, nl + 1, nr - 1) {
    if (full[i] != -1) {
      if (id == full[i]) ans += s;
    } else {
      ans += bl2[id][i];
    }
  }
  if (nl != nr) {
    ans += getCntPart(nl, l, nl * s + s - 1, id);
    ans += getCntPart(nr, nr * s, r, id);
  } else {
    ans += getCntPart(nl, l, r, id);
  }
  return ans;
}

inline void solve(int l, int r) {
  const int K = 500;
  ++TT;
  int k = 0;
  rept(it, K) {
    int t = rnd() % (r - l + 1) + l;
    if (lpos[t] == TT) continue;
    lpos[t] = TT;
    int val = getVal(t);
    if (last[val] == TT) {
      ++cnt[val];
    } else {
      last[val] = TT;
      cnt[val] = 1;
      ls2[k++] = val;
    }
  }
  memset(pcnt, 0, (K + 1) * sizeof(int));
  rept(i, k) { ++pcnt[cnt[ls2[i]]]; }
  rept(i, K + 1) {
    if (i) pcnt[i] += pcnt[i - 1];
  }
  FORD(i, k - 1, 0) { ls[k - (--pcnt[cnt[ls2[i]]]) - 1] = ls2[i]; }

  int sum = r - l + 1;
  int sa = 0;
  int small = 0;
  int it = 0;
  while (sum * 100 >= p * (r - l + 1) && it < k && sa < 100 / p) {
    int v = ls[it++];
    int cc = getCnt(l, r, v);
    sum -= cc;
    if (cc * 100 >= p * (r - l + 1)) {
      ans[sa++] = v;
      small = 0;
    } else if (cc * 100 <= 10 * (r - l + 1)) {
      ++small;
    }

    if (small >= 11) break;
  }
  printf("%d", sa);
  rept(i, sa) { printf(" %d", ans[i]); }
  printf("\n");
}
int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  srand(std::chrono::duration_cast<std::chrono::nanoseconds>(
            (std::chrono::high_resolution_clock::now().time_since_epoch()))
            .count() +
        time(0));
  auto init = [](uint32_t &a) {
    a = 0;
    while (!a) a = (rand() << 15) + rand();
  };
  init(x);
  init(y);
  init(z);
  init(w);
  scanf("%d%d%d", &n, &m, &p);
  s = S;
  rept(i, n) { scanf("%d", &mas[i]); }
  memset(full, -1, sizeof(full));
  memset(last, -1, sizeof(last));
  memset(lpos, -1, sizeof(lpos));
  build();

  rept(it, m) {
    scanf("%d", &a);
    if (a == 1) {
      scanf("%d%d%d", &a, &b, &c);
      --a;
      --b;
      upd(a, b, c);
    } else {
      scanf("%d%d", &a, &b);
      --a;
      --b;
      solve(a, b);
    }
  }
}