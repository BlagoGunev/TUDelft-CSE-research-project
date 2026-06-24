#include "bits/stdc++.h"



using namespace std;



template <class T> class flow_graph {

public:

    struct edge {

        int to;

        T c;

        T f;

        T w;

        int rev;

        int id;

    };

    vector<vector<edge>> g;

    vector<T> d;

    vector<int> pr, used;

    int n;

    int st, fin;

    bool modified;

    T flow, cost;

    flow_graph(int n, int st, int fin) : n(n), st(st), fin(fin) {

        modified = true;

        assert(0 <= st && st < n && 0 <= fin && fin < n && st != fin);

        g.resize(n);

        d.resize(n);

        pr.resize(n);

        used.resize(n);

    }

    void clear() {

        modified = true;

        for (int i = 0; i < n; i++) {

            for (edge& e : g[i]) {

                e.f = 0;

            }

        }

    }

    void add(int from, int to, T forward_cap, T backward_cap, T w, int id) {

        modified = true;

        assert(0 <= from && from < n && 0 <= to && to < n);

        int from_size = g[from].size();

        int to_size = g[to].size();

        g[from].push_back({to, forward_cap, 0, w, to_size, id});

        g[to].push_back({from, backward_cap, 0, -w, from_size, -1});

    }

    pair<T, T> bfs() {

        queue<int> q({st});

        fill(d.begin(), d.end(), INT_MAX);

        fill(pr.begin(), pr.end(), -1);

        fill(used.begin(), used.end(), 0);

        d[st] = 0;

        used[st] = true;

        int cnt = 0;

        while (!q.empty()) {

            int i = q.front();

            q.pop();

            for (edge& e : g[i]) {

                if (e.c > e.f && d[e.to] > d[i] + e.w) {

                    d[e.to] = d[i] + e.w;

                    pr[e.to] = e.rev;

                    if (!used[e.to]) {

                        q.push(e.to);

                        used[e.to] = true;

                    }

                }

            }

            used[i] = false;

        }

        if (pr[fin] == -1) {

            return {T(0), T(0)};

        }

        T d = INT_MAX, w = 0;

        int tmp = fin;

        while (pr[tmp] != -1) {

            edge& e = g[tmp][pr[tmp]];

            d = min(d, g[e.to][e.rev].c - g[e.to][e.rev].f);

            tmp = e.to;

        }

        tmp = fin;

        while (pr[tmp] != -1) {

            edge& e = g[tmp][pr[tmp]];

            e.f -= d;

            g[e.to][e.rev].f += d;

            w += g[e.to][e.rev].w * d;

            tmp = e.to;

        }

        return {d, w};

    }

    T min_cost_max_flow(int type) {

        if (!modified) {

            return (type == 0 ? flow : cost);

        }

        modified = false;

        T ans = 0, res = 0;

        while (true) {

            auto mem = g;

            pair<T, T> c = bfs();

            if (c.first == 0) break;

            if (c.second > 0) {

                g = mem;

                break;

            }

            ans = ans + c.first;

            res = res + c.second;

        }

        flow = ans, cost = res;

        return (type == 0 ? flow : cost);

    }

    vector<bool> min_cut() {

        min_cost_max_flow(0);

        vector<bool> ret(n);

        for (int i = 0; i < n; i++) {

            ret[i] = (pr[i] != -1 || i == st);

        }

        return ret;

    }

};



int main() {

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    int n, m;

    cin >> n >> m;

    flow_graph<long long> g(n + 2, n, n + 1);

    vector<int> ans(m);

    vector<int> in(n), out(n);

    for (int i = 0; i < m; i++) {

        int x, y, c, w;

        cin >> x >> y >> c >> w;

        x--, y--;

        if (c % 2 == 1) {

            in[y]++;

            out[x]++;

            ans[i]++;

            c--;

        }

        c /= 2;

        w *= 2;

        g.add(x, y, c, 0, w, i);

    }

    if (out[0] % 2 == 1) {

        out[0]++;

        in[n - 1]++;

    }

    for (int i = 1; i + 1 < n; i++) {

        if (in[i] % 2 != out[i] % 2 && (i > 0 && i + 1 < n)) {

            cout << "Impossible\n";

            return 0;

        }

        if (in[i] > out[i]) {

            g.add(n, i, (in[i] - out[i]) / 2, 0, -(int) 1e9, -1);

        } else if (in[i] < out[i]) {

            g.add(i, n + 1, (out[i] - in[i]) / 2, 0, -(int) 1e9, -1);

        }

    }

    g.add(n, 0, (int) 1e9, 0, 0, -1);

    g.add(n - 1, n + 1, (int) 1e9, 0, 0, -1);

    auto res = g.min_cost_max_flow(0);

    for (int i = 0; i < n + 2; i++) {

        for (auto e : g.g[i]) {

            if (e.w == -(int) 1e9) {

                if (e.f != e.c) {

                    cout << "Impossible\n";

                    return 0;

                }

            }

            if (e.id != -1) {

                ans[e.id] += 2 * e.f;

            }

        }

    }

    cout << "Possible\n";

    for (auto x : ans) {

        cout << x << " ";

    }

}