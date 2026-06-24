#include <bits/stdc++.h>

using namespace std;



using i64 = long long;



template<class Info, class Tag>

struct LazySegmentTree {

    int n;

    vector<Info> info;

    vector<Tag> tag;

    LazySegmentTree(int n) : n(n), info(4 * n), tag(4 * n) {}

template <typename T>

    LazySegmentTree(vector<T> init) : LazySegmentTree(init.size()) {

        auto build = [&](auto build, int id, int l, int r) -> void {

            if (r == l) {

                info[id] = init[l];

                return;

            }

            int m = l + r >> 1;

            build(build, 2 * id, l, m);

            build(build, 2 * id + 1, m + 1, r);

            pull(id);

        };

        build(build, 1, 0, n - 1);

    }

    void pull(int id) {

        info[id] = info[2 * id] + info[2 * id + 1];

    }

    void apply(int id, const Tag &v) {

        info[id] += v;

        tag[id] += v;

    }

    void push(int id) {

        apply(2 * id, tag[id]);

        apply(2 * id + 1, tag[id]);

        tag[id] = Tag();

    }

    void modify(int id, int l, int r, int p, const Info &v) {

        if (r == l) {

            info[id] = v;

            return;

        }

        int m = l + r >> 1;

        push(id);

        if (p <= m) {

            modify(2 * id, l, m, p, v);

        } else {

            modify(2 * id + 1, m + 1, r, p, v);

        }

        pull(id);

    }

    void modify(int p, const Info &v) {

        modify(1, 0, n - 1, p, v);

    }

    Info rangeQuery(int id, int l, int r, int ql, int qr) {

        if (qr < l || r < ql) {

            return Info();

        }

        if (ql <= l && r <= qr) {

            return info[id];

        }

        int m = l + r >> 1;

        push(id);

        return rangeQuery(2 * id, l, m, ql, qr) + rangeQuery(2 * id + 1, m + 1, r, ql, qr);

    }

    Info rangeQuery(int ql, int qr) {

        return rangeQuery(1, 0, n - 1, ql, qr);

    }

    void rangeApply(int id, int l, int r, int ql, int qr, const Tag &v) {

        if (qr < l || r < ql) {

            return;

        }

        if (ql <= l && r <= qr) {

            apply(id, v);

            return;

        }

        int m = l + r >> 1;

        push(id);

        rangeApply(2 * id, l, m, ql, qr, v);

        rangeApply(2 * id + 1, m + 1, r, ql, qr, v);

        pull(id);

    }

    void rangeApply(int ql, int qr, const Tag &v) {

        return rangeApply(1, 0, n - 1, ql, qr, v);

    }

};



struct Tag {

    int x = 0;

    Tag() {}

    Tag(int x) : x(x) {}

    Tag& operator+=(const Tag &t) {

        x ^= t.x;

        return *this;

    }

};



struct Info {

    array<int, 2> cnt{};

    array<i64, 2> sum{};

    Info() {}

    Info(int x, int i) {

        cnt[x] = 1;

        sum[x] = i;

    }

    friend Info operator+(const Info &a, const Info &b) {

        Info res;

        for (int i = 0; i < 2; i++) {

            res.cnt[i] = a.cnt[i] + b.cnt[i];

            res.sum[i] = a.sum[i] + b.sum[i];

        }

        return res;

    }

    Info& operator+=(const Tag &t) {

        if (t.x) {

            swap(cnt[0], cnt[1]);

            swap(sum[0], sum[1]);

        }

        return *this;

    }

};



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);



#ifdef LOCAL

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif



    auto solve = [&]() {

        int n;

        cin >> n;



        vector<vector<pair<int, int>>> g(n);

        for (int i = 0; i < n - 1; i++) {

            int u, v;

            cin >> u >> v;

            u--, v--;

            g[u].emplace_back(v, i + 1);

            g[v].emplace_back(u, i + 1);

        }



        // hld

        vector<int> tin(n), tout(n), sz(n, 1), dep(n), top(n), par(n, -1), pe(n, -1);

        auto dfs1 = [&](auto dfs1, int u, int p) -> void {

            if (p != -1) {

                g[u].erase(find(g[u].begin(), g[u].end(), pair(p, pe[u])));

            }

            for (auto &e : g[u]) {

                auto [v, i] = e;

                par[v] = u;

                pe[v] = i;

                dep[v] = dep[u] + 1;

                dfs1(dfs1, v, u);

                sz[u] += sz[v];

                if (sz[v] > sz[g[u][0].first]) {

                    swap(e, g[u][0]);

                }

            }

        };

        dfs1(dfs1, 0, -1);

        auto dfs2 = [&](auto dfs2, int u, int p) -> void {

            static int T = 0;

            tin[u] = T++;

            for (auto e : g[u]) {

                auto [v, i] = e;

                top[v] = v == g[u][0].first ? top[u] : v;

                dfs2(dfs2, v, u);

            }

            tout[u] = T - 1;

        };

        dfs2(dfs2, 0, -1);



        LazySegmentTree<Info, Tag> st(n);

        st.modify(0, Info(1, 0));



        int op;



        while (cin >> op && op != 3) {

            if (op == 1) {

                int u;

                cin >> u;

                u--;

                

                st.modify(tin[u], Info(1, pe[u]));



                u = par[u];



                while (u != -1) {

                    st.rangeApply(tin[top[u]], tin[u], 1);

                    u = par[top[u]];

                }

            }



            auto info = st.info[1];



            if (info.cnt[0] != info.cnt[1]) {

                cout << "0\n";

            } else if (op == 1) {

                cout << info.sum[1] << '\n';

            } else {

                vector<int> ans;



                for (int i = 0; i < n; i++) {

                    auto info = st.rangeQuery(tin[i], tin[i]);

                    if (info.cnt[1]) {

                        ans.push_back(pe[i]);

                    }

                }



                sort(ans.begin(), ans.end());

                cout << ans.size();

                for (auto i : ans) {

                    cout << ' ' << i;

                }

                cout << '\n';

            }



            cout << flush;

        }

    };

    

    solve();

    

    return 0;

}