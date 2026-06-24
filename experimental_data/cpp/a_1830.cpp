// #pragma GCC optimize("O3")
// 293206GT
//#include <bits/extc++.h>
//using namespace __gnu_pbds;
//template<class T>
//using OrderedSet = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


#ifdef LOCAL
    #include "includes.h"
    using namespace std;
    #include "debug.h"
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

using ll = long long;
#define int ll

#define put(a) cout << (a) << '\n'
#define sqr(x) ((x) * (x))
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

#ifdef LOCAL
#define dbg(...) cerr << "line #" << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbgPrint(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define sz(a) (int) (a).size()
#define len(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define eb emplace_back
#define rep(x, y, a) for (int x = (y); x < (int)(a); ++x)
#define asd(n) rep(i, 0, n)
#define jkl(n) rep(j, 0, n)
#define UB upper_bound
#define LB lower_bound
#define mp make_pair
namespace IO {

    template<class A, class B>
    ostream& operator<<(ostream& out, vector<pair<A, B>> a);

    template<class A>
    ostream& operator<<(ostream& out, vector<A> a);

    template<class A, class B>
    ostream& operator<<(ostream& out, pair<A, B> a) {
        out << a.first << " " << a.second;
        return out;
    }

    template<class A, class B>
    ostream& operator<<(ostream& out, vector<pair<A, B>> a) {
        for (pair<A, B> x: a)
            out << x.first << " " << x.second << '\n';
        return out;
    }

    template<class A>
    ostream& operator<<(ostream& out, vector<A> a) {
        for (A x: a) out << x << ' ';
        return out;
    }

    template<class A, class B>
    istream& operator>>(istream& in, pair<A, B>& a) {
        in >> a.first >> a.second;
        return in;
    }

    template<class A>
    istream& operator>>(istream& in, vector<A>& a) {
        for (A& x: a) in >> x;
        return in;
    }
}  // namespace IO

template<class A, class B>
inline int chkmax(A& a, B b) {
    if (a < (A) b) {
        a = (A) b;
        return 1;
    }
    return 0;
}

template<class A, class B>
inline int chkmin(A& a, B b) {
    if (a > (A) b) {
        a = (A) b;
        return 1;
    }
    return 0;
}

using namespace IO;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve();

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(41);
    int q = 1;
    cin >> q;
    while (q--) solve();
}

using namespace std;
const int N = 1e6;
vpii g[N];
int par_ed[N];
int ans[N];
void dfs(int v, int p) {
    for (auto [x, y] : g[v]) if (x != p) {
        ans[x] = ans[v];
        if (y < par_ed[v]) ++ans[x];
        par_ed[x] = y;
        dfs(x, v);
    }
}
void solve() {
    int n;
    cin >> n;
    asd(n) g[i].clear();
    asd(n - 1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].eb(v, i);
        g[v].eb(u, i);
    }
    par_ed[0] = -1;
    dfs(0, -1);
    int anss = 0;
    asd(n) chkmax(anss, ans[i]);
    put(anss + 1);
}