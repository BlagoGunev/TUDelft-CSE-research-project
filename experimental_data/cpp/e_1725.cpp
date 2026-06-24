// LUOGU_RID: 97172271
#include <bits/stdc++.h>



constexpr int maxa = 2e5;



template<unsigned P>

class modint {

  static_assert(1 <= P, "P must be a positive integer");



  using mint = modint<P>;



protected:

  unsigned v;



public:

  constexpr modint() : v() {}



  template<typename T,

           typename std::enable_if<std::is_integral<T>::value &&

                                       std::is_signed<T>::value,

                                   bool>::type = true>

  constexpr modint(T t_v) : v() {

    long long tmp = t_v % static_cast<long long>(P);

    if (tmp < 0) {

      tmp += P;

    }

    v = tmp;

  }



  template<typename T,

           typename std::enable_if<std::is_integral<T>::value &&

                                       std::is_unsigned<T>::value,

                                   bool>::type = true>

  constexpr modint(T t_v) : v() {

    v = t_v % P;

  }



  constexpr unsigned val() const {

    return v;

  }



  static constexpr unsigned mod() {

    return P;

  }



  static constexpr mint raw(unsigned v) {

    mint res;

    res.v = v;

    return res;

  }



  constexpr mint &operator+=(const mint &rhs) {

    v < P - rhs.v ? v += rhs.v : v -= P - rhs.v;

    return *this;

  }



  constexpr mint &operator++() {

    v + 1 < P ? ++v : v = 0;

    return *this;

  }



  constexpr mint operator++(int) {

    mint tmp = *this;

    v + 1 < P ? ++v : v = 0;

    return tmp;

  }



  constexpr mint &operator-=(const mint &rhs) {

    v < rhs.v ? v += P - rhs.v : v -= rhs.v;

    return *this;

  }



  constexpr mint &operator--() {

    v ? --v : v = P - 1;

    return *this;

  }

  

  constexpr mint operator--(int) {

    mint tmp = *this;

    v ? --v : v = P - 1;

    return tmp;

  }



  constexpr mint operator-() const {

    mint res;

    res.v = v ? P - v : 0;

    return res;

  }



  constexpr mint &operator*=(const mint &rhs) {

    v = static_cast<unsigned long long>(v) * rhs.v % P;

    return *this;

  }



  constexpr mint pow(unsigned long long b) const {

    mint a(*this), s(1);

    for (; b; b >>= 1) {

      if (b & 1) {

        s *= a;

      }

      a *= a;

    }

    return s;

  }



  constexpr mint inv() const {

    return pow(P - 2);

  }



  constexpr friend mint operator+(const mint &lhs, const mint &rhs) {

    return mint(lhs) += rhs;

  }                                                                              

                                                                                 

  constexpr friend mint operator-(const mint &lhs, const mint &rhs) {            

    return mint(lhs) -= rhs;                                                     

  }



  constexpr friend mint operator*(const mint &lhs, const mint &rhs) {

    return mint(lhs) *= rhs;

  }



  constexpr friend bool operator==(const mint &lhs, const mint &rhs) {

    return lhs.v == rhs.v;

  }



  constexpr friend bool operator!=(const mint &lhs, const mint &rhs) {

    return lhs.v != rhs.v;

  }



  friend std::istream &operator>>(std::istream &in, mint &x) {

    return in >> x.v;

  }



  friend std::ostream &operator<<(std::ostream &out, const mint &x) {

    return out << x.v;

  }

};



using mint = modint<998244353>;



class Tree {

  private:

    std::vector<std::vector<int>> adj;

    std::vector<int> dep, siz, hson, top, par, dfn;

    int DFN = 0;

    void dfs (int u, int fa) {

      dfn[u] = ++DFN;

      siz[u] = 1;

      dep[u] = dep[fa] + 1;

      par[u] = fa;

      for (auto v : adj[u]) {

        if (v ^ fa) {

          dfs(v, u);

          if (siz[v] > siz[hson[u]]) {

            hson[u] = v;

          }

          siz[u] += siz[v];

        }

      }

    }

    void dfs1 (int u, int fa, int Top) {

      top[u] = Top;

      if (hson[u]) {

        dfs1(hson[u], u, Top);

      }

      for (auto v : adj[u]) {

        if ((v ^ fa) && (v ^ hson[u])) {

          dfs1(v, u, v);

        }

      }

    }

    int LCA (int x, int y) {

      while (top[x] != top[y]) {

        if (dep[top[x]] < dep[top[y]]) {

          std::swap(x, y);

        }

        x = par[top[x]];

      }

      return dep[x] < dep[y] ? x : y;

    }

  public:

    Tree (int n) : adj(n + 1), dep(n + 1), siz(n + 1), hson(n + 1), top(n + 1), par(n + 1), dfn(n + 1) {}

    void add (int x, int y) {

      adj[x].emplace_back(y);

      adj[y].emplace_back(x);

    }

    void init () {

      dfs(1, 0);

      dfs1(1, 0, 1);

    }

    int lca (int x, int y) {

      return LCA(x, y);

    }

    int dfnn (int x) {

      return dfn[x];

    }

    int dis (int x, int y) {

      return dep[y] - dep[x];

    }

};



class VTree {

  private:

    std::vector<std::vector<std::pair<int, int>>> adj;

    std::vector<int> siz, f1, f2;

    int rt, k;

    mint sum = 0;

    void dfs (int u) {

      for (auto [v, w] : adj[u]) {

        dfs(v);

        sum += mint(w) * siz[v] * (k - siz[v]);

        siz[u] += siz[v];

      }

    }

  public:

    VTree (int n, int rt, int k) : k(k), rt(rt), adj(n + 1), siz(n + 1), f1(n + 1), f2(n + 1) {};

    void add (int x, int y, int z) {

      adj[x].emplace_back(y, z);

    }

    void set (int x) {

      siz[x] = 1;

    }

    mint solve () {

      dfs(rt);

      return sum;

    }

};



signed main() {

  std::ios::sync_with_stdio(false);

  std::cin.tie(nullptr);



  int n;

  std::cin >> n;



  std::vector<std::vector<int>> pos(maxa + 5);

  for (int i = 1; i <= n; ++i) {

    int x;

    std::cin >> x;

    pos[x].emplace_back(i);

  }



  Tree T(n);

  for (int i = 1; i < n; ++i) {

    int x, y;

    std::cin >> x >> y;

    T.add(x, y);

  }



  T.init();



  std::bitset<maxa + 5> vis;

  std::vector<int> id(n + 1);

  mint res = 0, inv2 = mint(2).inv();

  for (int i = 2; i <= maxa; ++i) {

    if (!vis[i]) {

      std::vector<int> a, b;

      for (int j = i; j <= maxa; j += i) {

        vis[j] = 1;

        for (auto x : pos[j]) {

          a.emplace_back(x);

          b.emplace_back(x);

        }

      }

      if (a.empty()) {

        continue;

      }

      int k = a.size();



      sort(a.begin(), a.end(), [&](int x, int y) {

        return T.dfnn(x) < T.dfnn(y);

      });

      for (int i = 0; i < k - 1; ++i) {

        a.emplace_back(T.lca(a[i], a[i + 1]));

      }

      sort(a.begin(), a.end(), [&](int x, int y) {

        return T.dfnn(x) < T.dfnn(y);

      });

      a.erase(std::unique(a.begin(), a.end()), a.end());

      for (int i = 0; i < (int)a.size(); ++i) {

        id[a[i]] = i + 1;

      }

      VTree T1(a.size(), id[a[0]], k);

      for (int i = 0; i < (int)a.size() - 1; ++i) {

        int fa = T.lca(a[i], a[i + 1]), son = a[i + 1];

        T1.add(id[fa], id[son], T.dis(fa, son));

      }

      for (auto x : b) {

        T1.set(id[x]);

      }



      auto sum = T1.solve();

      res += sum * (k - 2) * inv2;

    }

  }



  std::cout << res << '\n';

}