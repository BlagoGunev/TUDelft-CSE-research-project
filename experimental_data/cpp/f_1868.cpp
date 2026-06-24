#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__);

struct point {
  long long x, y;
  point(): x(0), y(0) {}
  point(long long _x, long long _y): x(_x), y(_y) {}
  point operator - (const point &p) const {
    return point(x - p.x, y - p.y);
  }
  __int128  operator * (const point &p) const {
    return (__int128) x * p.y - (__int128) y * p.x;
  }
};

void debug_out(point a) {
  cerr << " " << a.x << " " << a.y << endl;
}


const long long inf = 1e18;

bool is_upper(point from, point pt, point to) {
  point vt = from - to;
  point p = pt - to;
  if ((p * vt) == 0) return false;
  return ((point(0, inf) - to) * vt > 0) == ((p * vt) > 0);
}

bool is_lower(point from, point pt, point to) {
  point vt = from - to;
  point p = pt - to;
  if ((p * vt) == 0) return false;
  return ((point(0, -inf) - to) * vt > 0) == ((p * vt) > 0);
}

bool go_to(point pt, point cur, point nxt, int dir) {
  if ((nxt - pt) * (cur - pt) == 0) {
    return nxt.x <= max(pt.x, cur.x) && nxt.x >= min(pt.x, cur.x);
  }
  if (dir == 1) return is_lower(pt, nxt, cur);
  if (dir == -1) return is_upper(pt, nxt, cur);
  assert(false);
}

point tangent(point pt, const vector<point> &poly, int dir) {
  int sz = poly.size();
  if (sz == 1) return poly[0];
  if (!go_to(pt, poly[0], poly[sz - 1], dir) && !go_to(pt, poly[0], poly[1], dir)) return poly[0];
  if (!go_to(pt, poly[sz - 1], poly[sz - 2], dir) && !go_to(pt, poly[sz - 1], poly[0], dir)) return poly[sz - 1];
  int lo = 0, hi = sz - 1;
  while (true) {
    int mid = (hi + lo) >> 1;
    int nxt = (mid + 1) % sz;
    int pr = (mid + sz - 1) % sz;
    int Nxt = go_to(pt, poly[mid], poly[nxt], dir);
    int Pr = go_to(pt, poly[mid], poly[pr], dir);
    if (!Nxt && !Pr) return poly[mid];
    if (Nxt) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  assert(false);
}

struct node {
  vector<point> Upper_convex;
  vector<point> Lower_convex;
  node(){};
};

node unite(node u, node v) {
  node res = u;
  for (point pt : v.Upper_convex) {
    int sz = res.Upper_convex.size();
    while (sz > 1 && is_lower(res.Upper_convex[sz - 2], res.Upper_convex[sz - 1], pt)) {
      res.Upper_convex.pop_back();
      sz--;
    }
    res.Upper_convex.push_back(pt);
  }
  for (point pt : v.Lower_convex) {
    int sz = res.Lower_convex.size();
    while (sz > 1 && is_upper(res.Lower_convex[sz - 2], res.Lower_convex[sz - 1], pt)) {
      res.Lower_convex.pop_back();
      sz--;
    }
    res.Lower_convex.push_back(pt);
  }
  return res;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<point> p(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> p[i + 1].y;
    p[i + 1].y += p[i].y;
    p[i + 1].x = i + 1;
  }
  vector<node> tree(4 * n + 4);
  function<void(int, int, int)> build = [&](int x, int l, int r) {
    if (l == r) {
      tree[x].Upper_convex = {p[l]};
      tree[x].Lower_convex = {p[r]};
      return;
    }
    int mid = (l + r) >> 1;
    build(2 * x, l, mid);
    build(2 * x + 1, mid + 1, r);
    tree[x] = unite(tree[2 * x], tree[2 * x + 1]);
  };
  build(1, 0, n);
  auto get_seg = [&](int ll, int rr) {
    vector<tuple<int, int, int>> res;
    vector<tuple<int, int, int, int>> que = {make_tuple(1, 0, n, 0)};
    while (que.size()) {
      auto [x, l, r, id] = que.back();
      que.pop_back();
      if (id == 2 || max(l, r) < min(ll, rr) || max(ll, rr) < min(l, r)) {
        continue;
      }
      if (ll <= l && r <= rr) {
        res.emplace_back(x, l, r);
        continue;
      }
      que.emplace_back(x, l, r, id + 1);
      int mid = (l + r) >> 1;
      if (id == 0) {
        que.emplace_back(2 * x, l, mid, 0);
      } else {
        que.emplace_back(2 * x + 1, mid + 1, r, 0);
      }
    }
    return res;
  };
  auto min_break = [&](int ll, int rr) {
    assert(ll > 0);
    point pt = p[ll - 1];
    point res = point(-inf, 0);
    vector<tuple<int, int, int>> seq = get_seg(ll, rr);
    for (auto [x, l, r] : seq) {
      point ret = tangent(pt, tree[x].Lower_convex, 1);
      if (res.x == -inf || go_to(pt, res, ret, 1)) {
        res = ret;
      }
    }
    return res;
  };
  auto max_break = [&](int ll, int rr) {
    assert(rr < n);
    point pt = p[rr + 1];
    point res = point(-inf, 0);
    vector<tuple<int, int, int>> seq = get_seg(ll, rr);
    for (auto [x, l, r] : seq) {
      point ret = tangent(pt, tree[x].Upper_convex, -1);
      if (res.x == -inf || go_to(pt, res, ret, -1)) {
        res = ret;
      }
    }
    return res;
  };

  auto min_break_time = [&](int l, int pos) {
    assert(pos > l);
    long long val = p[pos].y - p[l].y;
    int diff = pos - l;
    if (val < 0) return 0LL;
    else return (val + diff) / diff;
  };
  auto max_break_time = [&](int r, int pos) {
    assert(pos < r);
    long long val = p[r].y - p[pos].y;
    int diff = r - pos;
    if (val < 0) return 0LL;
    else return (val + diff) / diff;
  };

  long long ret = 0;
  function<void(int, int, int)> solve = [&](int l, int r, int dep) {
    if (l == r) {
      return;
    }
    if (l == r - 1) {
      int v = p[r].y - p[l].y;
      ret += max(v + 1 - dep, 0);
      return;
    }

    point nxt_min = min_break(l + 1, r);
    int x_min = nxt_min.x;
    long long min_time = max(1LL * dep, min_break_time(l, x_min));
    point nxt_max = max_break(l, r - 1);
    int x_max = nxt_max.x;
    long long max_time = max(1LL * dep, max_break_time(r, x_max));

    if (min_time < max_time) {
      ret += min_time - dep;
      solve(l, x_min - 1, min_time);
      solve(x_min, r, min_time);
    } else {
      ret += max_time - dep;
      solve(l, x_max, max_time);
      solve(x_max + 1, r, max_time);
    }
  };
  solve(0, n, 0);
  cout << ret;
  return 0;
}