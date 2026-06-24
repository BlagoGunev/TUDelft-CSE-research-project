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
const ld eps = 1e-13;
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

int myPower(int x, int pw) {
  int res = 1;
  for (; pw; pw >>= 1) {
    if (pw & 1) {
      res = mult(res, x);
    }
    x = mult(x, x);
  }
  return res;
}

void precalc() {
}

struct point {
  ld x, y;

  int read() {
    double x_, y_;
    if (scanf("%lf%lf", &x_, &y_) < 2) {
      return 0;
    }
    x = x_, y = y_;
    return 1;
  }

  point(): x(), y() {}
  point(ld x, ld y): x(x), y(y) {}

  point operator -(const point & p) const {
    return point(x - p.x, y - p.y);
  }

  point operator +(const point & p) const {
    return point(x + p.x, y + p.y);
  }

  ld operator *(const point & p) const {
    return x * p.x + y * p.y;
  }

  ld operator ^(const point & p) const {
    return x * p.y - y * p.x;
  }

  point operator *(const ld & m) const {
    return point(x * m, y * m);
  }
  
  ld slen() const {
    return x * x + y * y;
  }

  ld len() const {
    return sqrt(slen());
  }

  point norm() const {
    ld l = len();
    assert(l > eps);
    return point(x / l, y / l);
  }

  point rot() const {
    return point(-y, x);
  }

  bool operator <(const point & p) const {
    if (abs(x - p.x) > eps) {
      return x < p.x;
    }
    if (abs(y - p.y) > eps) {
      return y < p.y;
    }
    return false;
  }

  bool operator ==(const point & p) const {
    return abs(x - p.x) < eps && abs(y - p.y) < eps;
  }

  int type() const {
    return y > eps || (y >= -eps && x > eps);
  }
};

struct pointComp {
  bool operator ()(const point & a, const point & b) {
    int at = a.type(), bt = b.type();
    if (at != bt) {
      return at < bt;
    }
    ld prod = a ^ b;
    if (abs(prod) > eps) {
      return prod > eps;
    }
    return a.slen() < b.slen() - eps;
  }
};

struct line {
  point o, v;

  line(): o(), v() {}
  line(const point & a, const point & b) {
    o = a;
    v = (b - a).norm();
  }

  ld dist(const point & p) const {
    return v ^ (p - o);
  }

  bool operator <(const line & l) const {
    if (!(v == l.v)) {
      return pointComp()(v, l.v);
    }
    ld d = dist(l.o);
    return d < -eps;
  }
};

//intersect two lines, assume they do not coincide
bool intersect(const line & a, const line & b, point & res) { 
  ld coeff = (a.v ^ b.v);
  if (abs(coeff) < eps) {
    return false;
  }
  ld ka = (b.o ^ b.v) / coeff;
  ld kb = (a.v ^ a.o) / coeff;
  res = a.v * ka + b.v * kb;

#ifdef DEBUG
  assert(abs(a.dist(res)) < eps && abs(b.dist(res)) < eps);
#endif
  return true;
}


//a, b, c are on the same line, check if c is in [a,b]
bool inside(point a, point b, point c) {
  if (b < a) {
    swap(a, b);
  }
  return !(c < a || b < c);
}

//intersect [a,b] and [c,d]
//assume they are not on the same line and have positive length
bool intersect(point a, point b, point c, point d, point & res) {
  if (!intersect(line(a, b), line(c, d), res)) {
    return false;
  }
  return inside(a, b, res) && inside(c, d, res);
}

//intersect line and circle
bool intersect(line l, point o, ld r, point res[2]) {
  point n = l.v.rot();
  ld d = (l.o - o) * n;
  if (abs(d) > r + eps) {
    return false;
  }

  ld x = sqrt(max((ld) 0, r * r - d * d));

  for (int it = 0; it < 2; ++it) {
    res[it] = o + n * d + l.v * (it ? -x : x);
  }
  return true;
}

//intersect two circles
bool intersect(point o1, ld r1, point o2, ld r2, point res[2]) {
  if (r1 < r2 - eps) {
    swap(o1, o2);
    swap(r1, r2);
  }
  ld d = (o2 - o1).len();
  if (r1 + r2 < d - eps || r1 - r2 > d + eps) {
    return false;
  }

  ld cosa = (r1 * r1 + d * d - r2 * r2) / ((ld) 2 * r1 * d);
  ld sina = sqrt(max((ld) 0, (ld) 1 - cosa * cosa));
  point v1 = (o2 - o1).norm() * r1;
  point v2 = v1.rot();

  for (int it = 0; it < 2; ++it) {
    res[it] = o1 + v1 * cosa + v2 * (it ? -sina : sina); 
  }
  return true;
}

int commonTangents(point o1, ld r1, point o2, ld r2, point *res) {
  ld d = (o1 - o2).len();
  if (d < eps) {
    return 0;
  }
  int cnt = 0;
  for (int i = 0; i < 2; ++i) {
    ld cosa = (r1 + (i ? -r2 : r2)) / d;
    if (abs(cosa) < (ld) 1 + eps) {
      ld sina = sqrt(max((ld) 0, (ld) 1 - cosa * cosa));
      point v1 = (o2 - o1).norm() * r1;
      point v2 = v1.rot();
      for (int it = 0; it < 2; ++it) {
        res[cnt++] = o1 + v1 * cosa + v2 * (it ? -sina : sina);
      }
    }
  }
  return cnt;
}

namespace Halfplane {
  const static int maxn = (int) 8e5 + 10;
  line h[maxn];
  point p[maxn];

  int intersect(int n, line *_h, point *res) {
    for (int i = 0; i < n; ++i) {
      h[i] = _h[i];
    }
    static point box[4] = {
      point(1e6, -1e6),
      point(1e6, 1e6),
      point(-1e6, 1e6),
      point(-1e6, -1e6)
    };
    for (int i = 0; i < 4; ++i) {
      h[n++] = line(box[i], box[(i + 1) % 4]);
    }
    sort(h, h + n);

    {
      int m = 0;
      for (int i = 0; i < n; ++i) {
        if (i == 0 || !(h[i].v == h[i - 1].v)) {
          h[m++] = h[i];
        }
      }
      n = m;
    }

    int m = 0;
    int del = 0;
    for (int i = 1; i < n; ++i) {
      while (m > del && h[i].dist(p[m - 1]) <= eps) {
        --m;
      }
      while (m > del && h[i].dist(p[del]) <= eps) {
        ++del;
      }
      if (del == m && (h[m].v ^ h[i].v) < eps) {
        return 0;
      }
      point np;
      assert(intersect(h[i], h[m], np));
      if (h[del].dist(np) >= -eps) {
        p[m++] = np;
        h[m] = h[i];
      }
    }
    rotate(p, p + del, p + m);
    rotate(h, h + del, h + m + 1);
    m -= del;
    if (m == 0) {
      return 0;
    }

    point np;
    assert(intersect(h[0], h[m], np));
    p[m++] = np;
    for (int i = 0; i < m; ++i) {
      res[i] = p[i];
    }
    return m;
  }
};
//END ALGO


const int maxn = (int) 2e5 + 10;
point ps[maxn];

int n;

int read() {
  if (scanf("%d", &n) < 1) {
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    assert(ps[i].read());
  }
  return 1;
}

line ls[maxn * 4];

point ans[4 * maxn];

point qs[maxn];

void solve() {
  point p0 = ps[0];
  for (int i = 0; i < n; ++i) {
    qs[i] = ps[i] - p0;
    if (qs[i].type() == 1) {
      qs[i] = qs[i] * -1;
    }
  }

  sort(qs + 1, qs + n, pointComp());

  for (int i = 1; i < n - 1; ++i) {
    if (qs[i].type() == qs[i + 1].type() && abs(qs[i] ^ qs[i + 1]) <= eps) {
      printf("0\n");
      return;
    }
  }
  for (int i = 1; i < n; ++i) {
    qs[i - 1] = ps[i] - p0;
  }
  --n;
  sort(qs, qs + n, pointComp());


  int cntl = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    point p = qs[i];

    if (j == i) {
      j = (j + 1) % n;
    }

    while (i != j) {
      if ((p ^ qs[j]) < 0) {
        break;
      }
      j = (j + 1) % n;
    }

    for (int it = 0; it < 2; ++it) {
      int cj = (j + n - it) % n;
      if (cj == i) {
        continue;
      }

      ls[cntl] = line(qs[i] + p0, qs[cj] + p0);
      if (ls[cntl].dist(p0) < 0) {
        ls[cntl].v = ls[cntl].v * -1;
      }
      ++cntl;
    }
  }

  for (int i = 0; i < n; ++i) {
    ls[cntl] = line(qs[i] + p0, qs[(i + 1) % n] + p0);
    if (ls[cntl].dist(p0) < 0) {
      ls[cntl].v = ls[cntl].v * -1;
    }
    ++cntl;
  }

  int got = Halfplane::intersect(cntl, ls, ans);
  ans[got] = ans[0];

  ld S = 0;
  for (int i = 0; i < got; ++i) {
    S += (ans[i] ^ ans[i + 1]);
  }
  S /= 2;
  printf("%.18f\n", (double) S);
}

int main() {
  precalc();
#ifdef LOCAL
  freopen(TASK ".out", "w", stdout);
  assert(freopen(TASK ".in", "r", stdin));
#endif

  int t;
  scanf("%d", &t);
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