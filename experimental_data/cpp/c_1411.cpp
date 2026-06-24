#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>

using namespace std;

#ifdef imtiyazrasool92
#include "algos/debug.h"
#else
#define dbg(...) 92
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

struct dsu {
    vector<int> parent;
    vector<int> size;
    void init(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        fill(size.begin(), size.end(), 1);
    }
    int find_parent(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find_parent(parent[i]);
    }
    void uni(int u, int v) {
        u = find_parent(u);
        v = find_parent(v);
        if (u != v) {
            if (size[u] < size[v])
                swap(u, v);
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

void run_case() {
    int N, M;
    cin >> N >> M;

    dsu D;
    D.init(N + 1);

    int answer = 0;
    for (int i = 0 ; i < M; i++) {
        int L, R;
        cin >> L >> R;
        if (L != R)
            answer += (D.find_parent(L) == D.find_parent(R)) + 1;
        D.uni(L, R);
    }

    cout << answer;
}

int32_t main() {
    ios::sync_with_stdio(false);
#ifndef imtiyazrasool92
    cin.tie(nullptr);
#endif

    int tests = 1;
    cin >> tests;

    while (tests--) {
        run_case();
        cout << '\n';
    }

    return 0;
}