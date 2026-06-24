#include <vector> 

#include <iostream> 

#include <algorithm>



using namespace std;



template <typename T, typename F = std::function<T(const T&, const T&)>>

struct Segtree {

  T unit;

  int n, m; 

  F unite;

  std::vector<T> tree;

  Segtree(int n_ = 0, T u = T()) : unit(u), n(n_) {

    m = 1;

    while (m < n) m *= 2;

    tree = std::vector<T> (m * 2 - 1, unit);

  }

  void apply(int u, T w) {

    u += m - 1;

    tree[u] = w;

    while (u > 0) {

      --u >>= 1;

      int v = u << 1;

      tree[u] = unite(tree[v + 1], tree[v + 2]);

    }

  }

  T get(int l, int r) {

    T u = unit, v = unit;

    l += m - 1, r += m - 1;

    while (l < r) {

      if (~l & 1) u = unite(u, tree[l++]);

      if (~r & 1) v = unite(tree[--r], v);

      l >>= 1, r >>= 1;

    }

    return unite(u, v);

  }

  T get(int at) { return get(at, at + 1); }

};

 



int main() {

  ios::sync_with_stdio(false);

  cin.tie(0);

  int tt;

  cin >> tt;

  while (tt--) {

    int n;

    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {

      cin >> a[i];

    }                       

    Segtree<int> S(n, -1);

    S.unite = [&](const int& i, const int& j) {

      if (j == -1) return i;

      if (i == -1) return j;

      return a[i] < a[j] ? i : j;

    };

    for (int i = 0; i < n; i++) {

      S.apply(i, i);

    }

    int q;

    cin >> q;

    while (q--) {

      int l, r;

      cin >> l >> r;

      l--;

      vector<int> can;

      can.reserve(32);

      if (r - l < 32) {

        for (int i = l; i < r; i++) {

          can.push_back(i);

        }

      } else {

        for (int i = 0; i < 32; i++) {

          int u = S.get(l, r);

          can.push_back(u);

          S.apply(u, -1); 

        }

      }

      int ans = 1 << 30;

      int m = can.size();

      for (int i = 1; i < m; i++) {

        for (int j = 0; j < i; j++) {

          ans = min(ans, a[can[i]] | a[can[j]]);

        }

      }

      cout << ans << '\n';

      if (r - l >= 32) {

        for (int i = 0; i < 32; i++) {

          S.apply(can[i], can[i]);

        }

      }

    }

  }

  return 0;

}