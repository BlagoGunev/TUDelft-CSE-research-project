#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) begin(x), end(x)
#define dump(x) cerr << #x " = " << x << endl
using ll = long long;
using namespace std;
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;
template <class T, class U> inline void chmax(T & a, U const & b) { a = max<T>(a, b); }
template <class T, class U> inline void chmin(T & a, U const & b) { a = min<T>(a, b); }
template <typename X, typename T> auto vectors(X x, T a) { return vector<T>(x, a); }
template <typename X, typename Y, typename Z, typename... Zs> auto vectors(X x, Y y, Z z, Zs... zs) { auto cont = vectors(y, z, zs...); return vector<decltype(cont)>(x, cont); }
template <typename T> ostream & operator << (ostream & out, vector<T> const & xs) { REP (i, int(xs.size()) - 1) out << xs[i] << ' '; if (not xs.empty()) out << xs.back(); return out; }

constexpr ll INF = (ll)1e18 + 9;

// http://algoogle.hadrori.jp/algorithm/dinic.html
// dinic
struct max_flow {
    struct edge { int to; ll cap; int rev; };
    int V;
    vector<vector<edge>> G;
    vector<int> itr, level;

    max_flow(int V) : V(V) { G.assign(V,vector<edge>()); }

    void add_edge(int from, int to, ll cap) {
        G[from].push_back((edge) {to, cap, (int) G[to].size()});
        G[to].push_back((edge) {from, 0, (int) G[from].size()-1});
    }

    void bfs(int s) {
        level.assign(V,-1);
        queue<int> q;
        level[s] = 0; q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for(auto &e: G[v]){
                if (e.cap > 0 and level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    ll dfs(int v, int t, ll f) {
        if (v == t) return f;
        for (int& i = itr[v]; i < (int) G[v].size(); ++i) {
            edge& e = G[v][i];
            if (e.cap > 0 and level[v] < level[e.to]) {
                ll d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    ll run(int s, int t) {
        ll ret = 0, f;
        while (bfs(s), level[t] >= 0) {
            itr.assign(V,0);
            while ((f = dfs(s, t, INF)) > 0) ret += f;
        }
        return ret;
    }
};


struct restriction_t {
    int l, r, x; ll c;
};

ll solve(int n, int h, int m, vector<restriction_t> const & a) {
    // vector<vector<pair<int, ll> > g(2 + n * h + m);
    max_flow g(2 + n * h + m);
    auto at = [&](int x, int y) { return x * h + y; };
    auto rest = [&](int i) { return n * h + i; };
    int src = n * h + m;
    int dst = n * h + m + 1;

    REP (x, n) {
        REP (y, h) {
            // g[src].emplace_back(at(x, y), 2 * y + 1);
            g.add_edge(src, at(x, y), 2 * y + 1);
            if (y > 0) {
                // g[at(x, y)].emplace_back(at(x, y - 1), INF);
                g.add_edge(at(x, y), at(x, y - 1), INF);
            }
        }
    }
    REP (i, m) {
        if (a[i].x < h) {
            int y = a[i].x;
            REP3 (x, a[i].l, a[i].r) {
                // g[at(x, y)].emplace_back(rest(i), INF);
                g.add_edge(at(x, y), rest(i), INF);
            }
        }
        // g[rest(i)].emplace_back(dst, a[i].c);
        g.add_edge(rest(i), dst, a[i].c);
    }

    return n * h * h - g.run(src, dst);
}

int main() {
    int n, h, m; cin >> n >> h >> m;
    vector<restriction_t> a(m);
    REP (i, m) {
        cin >> a[i].l >> a[i].r >> a[i].x >> a[i].c;
        -- a[i].l;
    }
    cout << solve(n, h, m, a) << endl;
    return 0;
}