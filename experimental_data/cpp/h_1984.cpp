#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


// Modular template copied from tourist

template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}

template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;

  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }

  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }

  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }

  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }

  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
#ifdef _WIN32
    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
    asm(
      "divl %4; \n\t"
      : "=a" (d), "=d" (m)
      : "d" (xh), "a" (xl), "r" (mod())
    );
    value = m;
#else
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
    int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }

  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

  template <typename U>
  friend const Modular<U>& abs(const Modular<U>& v) { return v; }

  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename U>
  friend std::istream& operator>>(std::istream& stream, Modular<U>& number);

 private:
  Type value;
};

template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }

template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}

template <typename T>
bool IsZero(const Modular<T>& number) {
  return number() == 0;
}

template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
  return stream << number();
}

template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, int64_t>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}

/*
using ModType = int;

struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/

constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

struct point {
  ll x, y;
};
point operator+(point a, point b) {
  return {a.x+b.x,a.y+b.y};
}
point operator*(point a, ll f) {
  return {a.x*f,a.y*f};
}
point operator-(point a, point b) {
  return {a.x-b.x,a.y-b.y};
}
ll operator*(point a, point b) {
  return a.x*b.x+a.y*b.y;
}
ll operator%(point a, point b) {
  return a.x*b.y-a.y*b.x;
}
typedef const point& point_;

ostream& operator<<(ostream&out, point_ p) {
  out << '(' << p.x << ", " << p.y << ')';
  return out;
}

bool incircle(point a, point b, point c, point d) {
  a = a-d;
  b = b-d;
  c = c-d;
  return ((a*a) * (b%c) + (b*b) * (c%a) + (c*c) * (a%b))*((b-a)%(c-a) > 0 ? 1 : -1) >= 0;
}

bool intriangle(point a, point b, point c, point d) {
  a = a-d;
  b = b-d;
  c = c-d;
  return (a%b) * (b%c) > 0 && (a%b) * (c%a) > 0;
}

int main() {
  //cout << incircle({3,3}, {2,5}, {1,1}, {4,2}) << endl;
  //return 0;
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<point> p(n);
    for (point&x : p) cin >> x.x >> x.y;
    map<array<int,3>, vector<int>> tri;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        for (int k = 0; k < j; k++) {
          int ins = 0;
          for (int l = 0; l < n; l++) {
            if (!incircle(p[i],p[j],p[k], p[l])) break;
            //cout << p[i] << ' ' << p[j] << ' ' << p[k] << ' ' << p[l]<< endl;
            ins++;
          }
          if (ins < n) continue;
          vector<int> tris;
          for (int l = 0; l < n; l++) {
            if (intriangle(p[i],p[j],p[k], p[l]))
              tris.push_back(l);
          }
          tri[{k,j,i}] = tris;
          //cout << i << ' ' << j << ' ' << k << endl;
        }
      }
    }
    auto lookup = [&](int i, int j, int k) {
      if (i > j) swap(i,j);
      if (j > k) swap(j,k);
      if (i > j) swap(i,j);
      assert(i <= j && j <= k);
      return tri.find({i,j,k});
    };
    vector<int> has = {0,1}, ind(n, -1), par = {-1,-1}, ok(n);
    vector<vector<int>> child(n);
    ind[0] = 0;
    ind[1] = 1;
    ok[0] = ok[1] = 1;
    int found = 1;
    while (found) {
      found = 0;
      for (int i : vector<int>(has)) {
        for (int j : vector<int>(has)) {
          if (i >= j) continue;
          for (int k = 0; k < n; k++) {
            if (ind[k] != -1) continue;
            auto it = lookup(i,j,k);
            if (it == tri.end()) continue;
            auto P = it->second;
            ind[k] = has.size();
            has.push_back(k);
            par.push_back(has[max(ind[i],ind[j])]);
            child[par.back()].push_back(k);
            for (int v : P) ok[v] = 1;
            ok[k] = 1;
            found = 1;
            //cout << 'a' << par.back() << ' ' << k << endl;
          }
        }
      }
    }
    int oks = 0;
    for (int v : ok) oks += v;
    //cout << oks << ' ' << n << endl;
    if (oks != n) {
      cout << 0 << endl;
      continue;
    }

    Mint ans = 1;
    for (int i = 1; i <= (int)has.size()-1; i++) ans *= i;
    function<int(int)> dfs = [&](int cur) {
      int sz = 1;
      for (int i : child[cur]) {
        sz += dfs(i);
      }
      ans /= sz;
      return sz;
    };
    assert(dfs(1) == (int)has.size()-1);
    cout << ans << endl;
  }
}