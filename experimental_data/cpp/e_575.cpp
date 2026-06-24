#undef NDEBUG
#ifdef SU1
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 100100;

int n;
int x[N], y[N], v[N];

inline bool read() {
 if (!(cin >> n)) return false;
 forn(i, n) assert(scanf("%d%d%d", &x[i], &y[i], &v[i]) == 3);
 return true;
}

const int nmax = 100000;
inline int good(int x, int y) { return 0 <= min(x, y) && max(x, y) <= nmax; }

int ci;
vector<pt> pts;

inline void add(int x, int y) {
 if (!good(x, y)) return;
 if (abs(x - ::x[ci]) + abs(y - ::y[ci]) > v[ci]) return;
 pts.pb(mp(x, y));
}

inline pt operator- (const pt& a, const pt& b) { return mp(a.x - b.x, a.y - b.y); }
inline li cross(const pt& v1, const pt& v2) { return v1.x * 1ll * v2.y - v1.y * 1ll * v2.x; }

vector<pt> convexHull(vector<pt> a) {
 sort(all(a));
 a.erase(unique(all(a)), a.end());
 vector<pt> up, dw;
 forn(i, sz(a)) {
  while (sz(up) > 1 && cross(a[i] - up.back(), up.back() - up[sz(up) - 2]) <= 0)
   up.pop_back();
  up.pb(a[i]);
 }
 forn(i, sz(a)) {
  while (sz(dw) > 1 && cross(a[i] - dw.back(), dw.back() - dw[sz(dw) - 2]) >= 0)
   dw.pop_back();
  dw.pb(a[i]);
 }
 reverse(all(up));
 if (sz(up) > 1) dw.insert(dw.end(), up.begin() + 1, up.end() - 1);
 return dw;
}

typedef pair<ld, ld> ptd;

template<typename X> inline ostream& operator<< (ostream& out, const pair<X, X>& p) { return out << "(" << p.x << ", " << p.y << ")"; }

inline ptd operator+ (const ptd& a, const ptd& b) { return mp(a.x + b.x, a.y + b.y); }
inline ptd operator/ (const ptd& a, const ld& b) { return mp(a.x / b, a.y / b); }
inline ld dist(const ptd& a, const ptd& b) { return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y)); }
inline ld det(const ld& a, const ld& b, const ld& c, const ld& d) { return a * d - b * c; }

inline bool intersect(const ptd& a, const ptd& b, const ptd& c, const ptd& d, ptd& ans) {
 //cerr << a << ' ' << b << ' ' << c << ' ' << d << endl;
 ld A1 = b.y - a.y, B1 = a.x - b.x, C1 = -(A1 * a.x + B1 * a.y);
 ld A2 = d.y - c.y, B2 = c.x - d.x, C2 = -(A2 * c.x + B2 * c.y);
 ld dd = det(A1, B1, A2, B2);
 if (abs(dd) < EPS) return false;
 ans.x = det(-C1, B1, -C2, B2) / dd;
 ans.y = det(A1, -C1, A2, -C2) / dd;
 return true;
}

inline ld getCircumCircle(const pt& a, const pt& b, const pt& c) {
 if (!cross(b - a, c - a)) return -2;
 //cerr << a << ' ' << b << ' ' << c << endl;
 ptd ans;
 ptd c1 = (a + b) / 2, c2 = (a + c) / 2, v1 = b - a, v2 = c - a;
 assert(intersect(c1, c1 + pt(-v1.y, v1.x), c2, c2 + pt(-v2.y, v2.x), ans));
 return dist(ans, a);
}

inline void solve() {
 pts.clear();
 forn(i, n) {
  ci = i;
  for (int x = 0; x <= nmax; x += nmax)
   for (int y = 0; y  <= nmax; y += nmax)
    add(x, y);
  for (int x = 0; x <= nmax; x += nmax) {
   add(x, ::y[i] + ::x[i] + v[i] - x);
   add(x, ::y[i] + ::x[i] - v[i] - x);
   add(x, ::y[i] - ::x[i] + v[i] + x);
   add(x, ::y[i] - ::x[i] - v[i] + x);
  }
  for (int y = 0; y <= nmax; y += nmax) {
   add(::x[i] + ::y[i] + v[i] - y, y);
   add(::x[i] + ::y[i] - v[i] - y, y);
   add(::x[i] - ::y[i] + v[i] + y, y);
   add(::x[i] - ::y[i] - v[i] + y, y);
  }
  add(x[i], y[i] + v[i]);
  add(x[i], y[i] - v[i]);
  add(x[i] + v[i], y[i]);
  add(x[i] - v[i], y[i]);
 }
 //forn(i, sz(pts)) cerr << pts[i] << ' '; cerr << endl;
 pts = convexHull(pts);
 //forn(i, sz(pts)) cerr << pts[i] << ' '; cerr << endl;

 ld ansv = -1;
 int ansp = -1;
 forn(i, sz(pts)) {
  ld curv = getCircumCircle(pts[i], pts[(i + 1) % sz(pts)], pts[(i + 2) % sz(pts)]);
  if (ansv < curv) ansv = curv, ansp = i;
 }
 assert(ansp != -1);

 cerr << ansv << endl;
 forn(i, 3) {
  int p = (ansp + i) % sz(pts);
  cout << pts[p].x << ' ' << pts[p].y << endl;
 }
}

int main() {
#ifdef SU1
    assert(freopen("input.txt", "rt", stdin));
    assert(freopen("output.txt", "wt", stdout));
#endif
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;

    while (read()) {
  solve();
  break;
 }
 
    return 0;
}