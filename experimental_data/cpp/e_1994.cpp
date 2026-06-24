#include <bits/stdc++.h>
using namespace std;

namespace std {

template <int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
    static_assert(D >= 1, "Dimension must be positive");
    template <typename... Args>
    Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};

template <typename T>
struct Vec<1, T> : public vector<T> {
    Vec(int n = 0, T val = T()) : std::vector<T>(n, val) {}
};

/* Example
    Vec<4, int64_t> f(n, k, 2, 2); // = f[n][k][2][2];
    Vec<2, int> adj(n); // graph
*/

template <class Fun>
class y_combinator_result {
    Fun fun_;

   public:
    template <class T>
    explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

    template <class... Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template <class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

/* Example
    auto fun = y_combinator([&](auto self, int x) -> void {
        self(x + 1);
    });
*/

}  // namespace std

class DSU {
   public:
    DSU(int n) {
        prt.resize(n + 1, -1);
    }

    int SZ(int u) {
        return -prt[root(u)];
    }

    int root(int u) {
        return (prt[u] < 0 ? u : (prt[u] = root(prt[u])));
    }

    bool connected(int u, int v) {
        return ((u = root(u)) == (v = root(v)));
    }

    bool unite(int u, int v) {
        if ((u = root(u)) == (v = root(v))) {
            return 0;
        }

        if (prt[u] > prt[v]) {
            u ^= v ^= u ^= v;
        }

        prt[u] += prt[v];
        prt[v] = u;
        return 1;
    }

   private:
    vector<int> prt;
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<int> a(k);
        for (int i = 0; i < k; i++) {
            cin >> a[i];
            for (int j = 0; j < a[i] - 1; j++) {
                int x;
                cin >> x;
            }
        }
        sort(a.rbegin(), a.rend());
        int64_t ans = 0;
        for (int i = 0; i < k; i++) {
            for (int j = 20; j >= 0; j--) {
                if (((ans >> j & 1) == 0) && (a[i] >> j & 1)) {
                    ans |= 1 << j;
                } else if ((ans >> j & 1) && (a[i] >> j & 1)) {
                    ans |= (1 << j) - 1;
                }
            }
        }
        cout << ans << '\n';
    }
}