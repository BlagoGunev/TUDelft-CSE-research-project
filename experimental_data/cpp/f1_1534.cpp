//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("unroll-loops,Ofast")
#include <bits/stdc++.h>

/*{{{*/
using namespace std;
#ifdef LOCAL // https://github.com/p-ranav/pprint
pprint::PrettyPrinter P(cerr);
#define de(...) P.compact(true);P.print('[', #__VA_ARGS__,"] =", __VA_ARGS__)
#define de_nc(...) P.compact(false);P.print('[', #__VA_ARGS__,"] =", __VA_ARGS__)
#else
#define de(...)
#define de_nc(...)
#endif
#define all(x) (x).begin(),(x).end()
using ll = long long;
using pii = pair<int, int>;

inline namespace Traits {
    // is iterable
    template<typename T, typename = void> struct is_iterable : false_type {};
    template<typename T>
    struct is_iterable<T, void_t<decltype(begin(declval<T>())), decltype(end(declval<T>()))>> : true_type {};
    template<typename T> constexpr bool is_iterable_v = is_iterable<T>::value;
    // is readable
    template<typename T, typename = void> struct is_readable : false_type {};
    template<typename T>
    struct is_readable<T, enable_if_t<is_same_v<decltype(cin >> declval<T&>()), istream&>>> : true_type {};
    template<typename T> constexpr bool is_readable_v = is_readable<T>::value;
    // is printable
    template<typename T, typename = void> struct is_printable : false_type {};
    template<typename T>
    struct is_printable<T, enable_if_t<is_same_v<decltype(cout << declval<T>()), ostream&>>> : true_type {};
    template<typename T> constexpr bool is_printable_v = is_printable<T>::value;
}
inline namespace Input {
    template<typename T> constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;
    template<typename T, typename U> void re(pair<T, U>& p);
    template<typename T> enable_if_t<is_readable_v<T>> re(T& x) { cin>>x; }
    template<typename T> enable_if_t<needs_input_v<T>> re(T& v) { for (auto& x : v) re(x); }
    template<typename... T> void re(T&... args) {(re(args), ...);}
    template<typename T, typename U> void re(pair<T, U>& p) { re(p.first, p.second); };
}
inline namespace Output {
    template<typename T> constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;
    template<int offset=0, typename... T> void wr(T... args);
    template<int offset=0,typename T> enable_if_t<is_printable_v<T> && is_integral_v<T>> _W(const T& x) { cout<<x+offset; }
    template<int offset=0,typename T> enable_if_t<is_printable_v<T> && !is_integral_v<T>> _W(const T& x) { cout<<x; }
    template<int offset=0,typename T, typename U> void _W(const pair<T, U>& p) { wr<offset>(p.first, p.second); }
    template<int offset=0,typename It> void _W(It f, const It& l) { for (;f!=l; ++f) { _W<offset>(*f); if (f!=l) cout<<' '; }}
    template<int offset=0,typename T> enable_if_t<needs_output_v<T>> _W(const T& x) { _W<offset>(begin(x), end(x)); }
    template<int offset, typename... T> void wr(T... args) { 
        int i=0; ((_W<offset>(args), ++i, cout<<(i==sizeof...(args) ? '\n' : ' ')), ...);
#ifdef LOCAL
        cout.flush();
#endif
    }
}
template<typename T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; } // set a = min(a,b)
template<typename T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }/*}}}*/

struct SCC {
    int n, pos=0;
    vector<vector<int>> g;
    vector<bool> vis;
    vector<int> low, ord, stk, color;
    vector<vector<int>> comp;
    vector<pair<int, int>> edges;
    SCC(int _n) : n(_n), g(n), vis(n), low(n), ord(n, -1), color(n) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
        edges.emplace_back(u, v);
    }

    void dfs(int u) {
        low[u]=ord[u]=pos++;
        stk.push_back(u);
        vis[u]=true;
        for (auto v : g[u]) {
            if (ord[v]==-1) {
                dfs(v);
                low[u]=min(low[u], low[v]);
            } else if (vis[v]) {
                low[u]=min(low[u], ord[v]);
            }
        }

        if (low[u]==ord[u]) {
            comp.emplace_back();
            while (true) {
                int v=stk.back();
                stk.pop_back();
                vis[v]=false;
                comp.back().push_back(v);
                if (u==v) break;
            }
        }
    }

    int solve() {
        for (int i=0; i<n; i++) {
            if (ord[i]==-1) dfs(i);
        }
        // reverse(comp.begin(), comp.end()); to sort components in topological order
        for (int i=0; i<(int)comp.size(); i++) {
            for (const auto& x : comp[i])
                color[x]=i;
        }
        vector<int> in(comp.size());
        for (auto [u, v] : edges) {
            if (color[u]!=color[v]) in[color[v]]++;
        }
        int ans=0;
        for (auto x : in) ans+=x==0;
        return ans;
    }
};
void test_case() {
    int n, m;
    re(n, m);
    vector<string> a(n);
    re(a);
    vector<int> need(n);
    re(need);
    // vector<pair<int, int>> mn(m);
    // for (int i=0; i<m; i++) {
    //     for (int j=0; j<n; j++) {
    //         if (a[j][i]=='#') 
    //         {
    //             mn[i]={j, i};
    //             break;
    //         }
    //     }
    // }
    // sort(all(mn));
    vector vis(n, vector(m, -1));
    const vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    auto dfs=[&](auto& dfs, int x, int y, const int col) -> void {
        vis[x][y]=col;
        for (auto [dx, dy] : dir) {
            unsigned nx=x+dx, ny=y+dy;
            if (nx<n && ny<m && a[nx][ny]=='#' && vis[nx][ny]==-1) dfs(dfs, nx, ny, col);
        }
    };
    int ans=0;
    int col=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j]=='#' && vis[i][j]==-1) {
                dfs(dfs, i, j, col++);
            }
        }
    }
    // vector<vector<int>> g(col);
    de_nc(vis);
    // Flow g(2*col+2);
    vector<int> in(col);
    SCC g(col);
    for (int j=0; j<m; j++) {
        int last=-1, llast=-1, rlast=-1;
        for (int i=0; i<n; i++) {
            if (a[i][j]=='#' && vis[i][j]!=last) {
                if (last!=-1) {
                    g.add_edge(last, vis[i][j]);
                }
                last=vis[i][j];
                llast=rlast=-1;
            }
            if (j && a[i][j-1]=='#' && vis[i][j-1]!=llast) {
                if (last!=-1) {
                    g.add_edge(last, vis[i][j-1]);
                    de(last, vis[i][j-1], 1);
                }
                llast=vis[i][j-1];
            }
            if (j+1<m && a[i][j+1]=='#' && vis[i][j+1]!=rlast) {
                if (last!=-1) {
                    g.add_edge(last, vis[i][j+1]);
                    de(last, vis[i][j+1], 1);
                }
                rlast=vis[i][j+1];
            }
        }
    }
    wr(g.solve());
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt=1;
    while (tt--) {
        test_case();
    }
    return 0;
}