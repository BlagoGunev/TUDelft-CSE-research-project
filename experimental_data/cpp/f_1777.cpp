// author: erray

#include <bits/stdc++.h>



#ifdef DEBUG

  #include "debug.h"

#else

  #define debug(...) void(37)

#endif



using namespace std;



template<typename T, typename F = function<T(const T&, const T&)>> 

struct SparseTable {

  vector<vector<T>> a;

  int n;

  F op;

  SparseTable() { }

  SparseTable(vector<T> _a, F _op) : op(_op) {

    n = int(_a.size());

    int lg = 32 - __builtin_clz(n);

    a.resize(lg); 

    a[0] = _a;

    for (int j = 1; j < lg; ++j) {

      int size = n - (1 << j) + 1;

      a[j].resize(size);

      for (int i = 0; i < size; ++i) {

        a[j][i] = op(a[j - 1][i], a[j - 1][i + ((1 << (j - 1)))]);

      }

    }

  }

  T get(int l, int r) {

    assert(l >= 0 && r < n && l <= r);

    int lg = __lg(r - l + 1);

    return op(a[lg][l], a[lg][r + 1 - (1 << lg)]);

  }

};





struct Trie {

  array<int, 2> emp = {-1, -1};

  vector<array<int, 2>> t = {emp};

  bool empty = true;

  void add(int x) {

    empty = false;

    int v = 0;

    for (int b = 30; b >= 0; --b) {

      int to = ((x >> b) & 1);

      if (t[v][to] == -1) {

        t[v][to] = int(t.size());

        t.push_back(emp);

      }

      v = t[v][to];

    }

  }

  int ask(int x) {

    if (empty) {

      return 0;

    }

    int v = 0;

    for (int b = 30; b >= 0; --b) {

      int to = ((x >> b) & 1);

      if (t[v][to ^ 1] == -1) {

        x = x & (~0 ^ (1 << b));

        assert(t[v][to] != -1);

        v = t[v][to];

      } else {

        x |= (1 << b);

        v = t[v][to ^ 1];

      }

    }

    return x;

  }

};



int main() {

  ios_base::sync_with_stdio(false);

  cin.tie(0);

  int TT;

  cin >> TT;

  while (TT--) {

    int N;

    cin >> N;

    vector<int> A(N + 1);

    for (int i = 0; i < N; ++i) {

      cin >> A[i + 1];

    }

    N += 1;

    debug(A);

    vector<int> pref(N + 1);

    for (int i = 0; i < N; ++i) {

      pref[i + 1] = pref[i] ^ A[i];

    }

    debug(pref);

    vector<int> foo(N);

    iota(foo.begin(), foo.end(), 0);

    SparseTable st(foo, [&](int x, int y) {

      return A[y] > A[x] ? y : x;

    });

    int ans = 0;

    function<Trie(int, int)> Dfs = [&](int l, int r) {

      int id = st.get(l, r);

      if (l == r) {

        Trie res;

        res.add(pref[id]);

        return move(res);

      }

      int ll = l, lr = id - 1;

      int rl = id + 1, rr = r;

      Trie left = (ll <= lr ? Dfs(ll, lr) : Trie{});

      Trie right = (rl <= rr ? Dfs(rl, rr) : Trie{});

      ans = max(ans, pref[r + 1] ^ pref[id] ^ A[id]);

      ans = max(ans, left.ask(pref[r + 1] ^ A[id]));

      ans = max(ans, right.ask(pref[id] ^ A[id]));

      if (lr - ll > rr - rl) {

        ll = rl, lr = rr;

        swap(left, right);

      }

      for (int i = ll; i <= lr; ++i) {

        ans = max(ans, right.ask(pref[i] ^ A[id])); 

      }

      for (int i = ll; i <= lr; ++i) {

        right.add(pref[i]);  

      }       

      right.add(pref[id]);

      return right;

    };

    Dfs(0, N - 1);

    cout << ans << '\n';

  }

}