#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <set>
#include <vector>

template<class F, class X>
struct LiChao {
  struct Node {
    F f;
    int lk = -1, rk = -1;
  };

  int root = -1;
  static std::vector<Node> nodes;

  ~LiChao() {
    nodes.clear();
  }

  auto query(const X &x) {
    return query_impl(root, x, X::lo(), X::hi());
  }

  void update(const F &f, const X &ux0, const X &uxf) {
    root = update_impl(root, f, X::lo(), X::hi(), ux0, uxf);
  }

  auto query_impl(int I, const X &x, const X &nx0, const X &nxf) {
    if (I == -1) return F{}(x);

    X mid {nx0, nxf};
    if (x < mid)
      return std::min(nodes[I].f(x), query_impl(nodes[I].lk, x, nx0, mid));
    else
      return std::min(nodes[I].f(x), query_impl(nodes[I].rk, x, mid, nxf));
  }

  int update_impl(int I, F f, const X &nx0, const X &nxf, const X &ux0, const X &uxf) {
    if (!(ux0 < nxf))
      return I;
    if (!(nx0 < uxf))
      return I;

    if (I == -1) {
      I = (int)nodes.size();
      nodes.emplace_back();
    }

    X mid {nx0, nxf};

    bool cover = !(nx0<ux0 || uxf<nxf);
    bool imp_lef = f(nx0) < nodes[I].f(nx0);
    bool imp_mid = f(mid) < nodes[I].f(mid);

    if (cover) {

      if (imp_mid)
        std::swap(f, nodes[I].f);

      if (!(nx0 < mid && mid < nxf))
        return I;

      if (imp_lef ^ imp_mid)
        nodes[I].lk = update_impl(nodes[I].lk, f, nx0, mid, ux0, uxf);
      else
        nodes[I].rk = update_impl(nodes[I].rk, f, mid, nxf, ux0, uxf);

    } else {

      if (!(nx0 < mid && mid < nxf))
        return I;

      nodes[I].lk = update_impl(nodes[I].lk, f, nx0, mid, ux0, uxf);
      nodes[I].rk = update_impl(nodes[I].rk, f, mid, nxf, ux0, uxf);
    }

    return I;
  }
};

using ll = long long;

struct V2 {
  ll x, y;

  constexpr friend V2 operator+(const V2 &a, const V2 &b) {
    return {a.x + b.x, a.y + b.y};
  }

  constexpr friend V2 operator-(const V2 &a, const V2 &b) {
    return {a.x - b.x, a.y - b.y};
  }

  constexpr V2 &operator+=(const V2 &o) {
    return *this = *this + o;
  }
  constexpr V2 &operator-=(const V2 &o) {
    return *this = *this - o;
  }

  constexpr V2 operator+() const {
    return {+x, +y};
  }
  constexpr V2 operator-() const {
    return {-x, -y};
  }

  constexpr V2 discrete_normalized() const {
    if (x == 0 && y == 0) return {0, 0};
    ll f = std::gcd(std::abs(x), std::abs(y));
    return {x/f, y/f};
  }

  constexpr friend ll cross(const V2 &a, const V2 &b) {
    return a.x * b.y - a.y * b.x;
  }

  constexpr friend ll dot(const V2 &a, const V2 &b) {
    return a.x * b.x + a.y * b.y;
  }
  
  constexpr ll mag2() const {
    return x*x + y*y;
  }

  constexpr int quadrant() const {
    //        ^ +y
    //      1 | 0
    // -x --- -1 ---> +x
    //      2 | 3
    //        | -y
    if (x > 0 && y >= 0) return 0;
    if (y > 0 && x <= 0) return 1;
    if (x < 0 && y <= 0) return 2;
    if (y < 0 && x >= 0) return 3;
    return -1;
  }

  constexpr friend V2 rot90(const V2 &v) {
    return {-v.y, v.x};
  }

  constexpr friend V2 rotate_to_quadrant_0(const V2 &v) {
    if (v.x == 0 && v.y == 0) return {0, 0};
    if (v.quadrant() == 0) return v;
    return rotate_to_quadrant_0(rot90(v));
  }

  constexpr friend bool operator<(V2 a, V2 b) {
    int aq = a.quadrant();
    int bq = b.quadrant();
    if (aq != bq) return aq < bq;
    a = rotate_to_quadrant_0(a);
    b = rotate_to_quadrant_0(b);
    return a.y * b.x < b.y * a.x;
  }

  constexpr friend bool operator==(const V2 &a, const V2 &b) {
    return a.x == b.x && a.y == b.y;
  }

  constexpr friend bool operator!=(const V2 &a, const V2 &b) {
    return a.x != b.x || a.y != b.y;
  }

  friend std::ostream &operator<<(std::ostream &os, const V2 &v) {
    return os << '(' << v.x << ',' << v.y << ')';
  }
};

constexpr bool within_eighth_turn(const V2 &a, const V2 &b) {
  // cos(angle) = dot(a, b) / (|a| * |b|)
  // cos(angle)^2 = dot(a, b)^2 / (|a|^2 * |b|^2)

  ll d = dot(a, b);

  if (d < 0)
    return false;

  return 2 * d * d > a.mag2() * b.mag2();
}

constexpr long long sign(long long x) {
  if (x < 0) return -1;
  if (x > 0) return 1;
  return 0;
}

struct L2 {
  V2 v0, v1;
};

constexpr bool check_intersection(const L2 &a, const L2 &b) {
  if (sign(cross(a.v1 - a.v0, b.v0 - a.v0)) *
      sign(cross(a.v1 - a.v0, b.v1 - a.v0)) > 0)
    return false;
  if (sign(cross(b.v1 - b.v0, a.v0 - b.v0)) *
      sign(cross(b.v1 - b.v0, a.v1 - b.v0)) > 0)
    return false;
  return true;
}

long double dist_to_segment(const V2 &dir, L2 l) {
  //std::cerr << "checking " << dir << " with [" << l.v0 << ',' << l.v1 << "]\n";
  long long dll = cross(dir, l.v1-l.v0);

  // check parallel
  if (!dll) {
    //std::cerr << "miss because parallel\n";
    return std::numeric_limits<long double>::infinity();
  }

  // check dir line miss l segment
  if (sign(cross(dir, l.v0)) * sign(cross(dir, l.v1)) > 0) {
    //std::cerr << "miss because outside of segment\n";
    return std::numeric_limits<long double>::infinity();
  }

  // check ray wrong way
  if ((sign(cross(l.v0, l.v1)) * sign(cross(l.v0 - dir, l.v1 - dir)) > 0) &&
      (std::abs(cross(l.v0, l.v1)) < std::abs(cross(l.v0 - dir, l.v1 - dir)))) {
    //std::cerr << "miss because wrong way\n";
    return std::numeric_limits<long double>::infinity();
  }

  long double d = dll;

  long double x_num =
    (long double)cross({0, 0}, dir)*(l.v0.x - l.v1.x) -
    (long double)cross(l.v0, l.v1)*(0 - dir.x);
  long double y_num =
    (long double)cross({0, 0}, dir)*(l.v0.y - l.v1.y) -
    (long double)cross(l.v0, l.v1)*(0 - dir.y);

  return (x_num * x_num + y_num * y_num) / (d*d);
}

std::vector<V2> relevant_directions;
std::vector<L2> asteroids;
std::vector<std::set<V2>> useful_directions;

struct X {
  static int sz;
  int i;
  X(int i_) : i(i_) {}
  X(X a, X b) : i((a.i + b.i)/2) {}

  static constexpr int lo() { return 0; }
  static int hi() { return sz; }

  friend bool operator<(X a, X b) { return a.i < b.i; }
};
int X::sz;

struct Func {
  L2 line;
  int source = -1;
  std::pair<long double, int> operator()(X x) {
    if (source == -1) return {std::numeric_limits<long double>::infinity(), -1};
    return {dist_to_segment(relevant_directions[x.i], line), source};
  }
};

template<>
std::vector<LiChao<Func, X>::Node> LiChao<Func, X>::nodes {};

std::set<V2> find_useful_directions(const V2 &origin) {
  //std::cerr << "\nchecking origin: " << origin << '\n';

  std::set<V2> useful;

  long long direct_d = origin.mag2();

  bool direct = true;
  for (const L2 &asteroid : asteroids) {
    auto [v0, v1] = asteroid;
    if (origin == v0 || origin == v1)
      continue;

    long double d = dist_to_segment(-origin, {asteroid.v0-origin, asteroid.v1-origin});

    //std::cerr << d << ' ' << direct_d << '\n';

    if (d <= direct_d) {
      direct = false;
      break;
    }
  }

  if (direct)
    useful.insert(-origin.discrete_normalized());

  LiChao<Func, X> lc;

  for (int i = 0; i < (int)useful_directions.size(); ++i) {
    auto [v0, v1] = asteroids[i];

    v0 -= origin;
    v1 -= origin;

    if (cross(v0, v1) < 0)
      std::swap(v0, v1);

    Func f{{v0, v1}, i};

    auto it0 = lower_bound(
      relevant_directions.begin(),
      relevant_directions.end(),
      v0.discrete_normalized()
    );

    auto it1 = upper_bound(
      relevant_directions.begin(),
      relevant_directions.end(),
      v1.discrete_normalized()
    );

    X x0{int(it0 - relevant_directions.begin())};
    X xf{int(it1 - relevant_directions.begin())};

    /*
    std::cerr << "range: ";
    std::cerr << v0 << ' ' << v1 << '\n';
    std::cerr << x0.i << ' ' << xf.i << '\n';
    // */

    if (v1 < v0) {
      lc.update(f, X::lo(), xf);
      lc.update(f, x0, X::hi());
    } else {
      lc.update(f, x0, xf);
    }
  }

  for (int i = 0; i < (int)relevant_directions.size(); ++i) {
    if (!within_eighth_turn(relevant_directions[i], -origin))
      continue;

    auto [d, src] = lc.query({i});

    /*
    if (src != -1) {
      std::cerr << "hit: ";
      std::cerr << relevant_directions[i] << ' ' << src << '\n';
    }
    // */

    if (src != -1 && useful_directions[src].count(relevant_directions[i]))
      useful.insert(relevant_directions[i]);
  }

  /*
  std::cerr << "direct? " << direct << '\n';
  std::cerr << "useful: ";
  for (V2 d : useful)
    std::cerr << d << ' ';
  std::cerr << '\n';
  // */

  return useful;
}

int main() {
  std::cin.tie(0)->sync_with_stdio(0);

  int n; std::cin >> n;
  asteroids.resize(n);

  for (auto &[v0, v1] : asteroids) {
    std::cin >> v0.x >> v0.y >> v1.x >> v1.y;

    if (v1.mag2() > v0.mag2())
      std::swap(v1, v0);

    V2 along = v1-v0;
    V2 dir = -v1;

    if (!within_eighth_turn(along, dir))
      continue;
    
    relevant_directions.push_back(dir.discrete_normalized());
  }

  std::sort(asteroids.begin(), asteroids.end(), [&](L2 a, L2 b) {
    return a.v1.mag2() < b.v1.mag2();
  });

  std::sort(relevant_directions.begin(), relevant_directions.end());
  relevant_directions.erase(
    std::unique(relevant_directions.begin(), relevant_directions.end()),
    relevant_directions.end()
  );

  /*
  std::cerr << "relevant directions: [";
  for (V2 d : relevant_directions)
    std::cerr << d << ',';
  std::cerr << "\b]\n";
  // */

  X::sz = (int)relevant_directions.size();

  for (auto [v0, v1] : asteroids) {
    auto possibly_high_friction = find_useful_directions(v1);

    useful_directions.emplace_back();
    V2 along = v1-v0;
    for (V2 d : possibly_high_friction)
      if (within_eighth_turn(d, along))
        useful_directions.back().insert(d);
    /*
    std::cerr << "useful (<45): ";
    for (V2 d : useful_directions.back())
      std::cerr << d << ' ';
    std::cerr << '\n';
    // */
  }

  int q;
  std::cin >> q;

  //std::cerr << "[";
  for (int qq = 0; qq < q; ++qq) {
    V2 start;
    std::cin >> start.x >> start.y;
    //std::cerr << start << ',';

    auto useful = find_useful_directions(start);

    std::cout << (useful.size() ? "YES" : "NO") << '\n';
  }
  //std::cerr << "\b]\n";
}