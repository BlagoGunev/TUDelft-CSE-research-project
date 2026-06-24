bool TEST = false;

using namespace std;
#include<bits/stdc++.h>
#include<fstream>

#define rep(i,n) for(ll (i)=0;(i)<(ll)(n);i++)
#define rrep(i,n) for(ll (i)=(ll)(n)-1;(i)>=0;i--)
#define range(i,start,end,step) for(ll (i)=start;(i)<(ll)(end);(i)+=(step))
#define rrange(i,start,end,step) for(ll (i)=start;(i)>(ll)(end);(i)+=(step))

#define dump(x)  cerr << "Line " << __LINE__ << ": " <<  #x << " = " << (x) << "\n";
#define spa << " " <<
#define fi first
#define se second
#define all(a)  (a).begin(),(a).end()
#define allr(a)  (a).rbegin(),(a).rend()

using ld = long double;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
 
template<typename T> using V = vector<T>;
template<typename T> using VV = V<V<T>>;
template<typename T, typename T2> using P = pair<T, T2>;
template<typename T, typename T2> using M = map<T, T2>;
template<typename T> using S = set<T>;
template<typename T, typename T2> using UM = unordered_map<T, T2>;
template<typename T> using PQ = priority_queue<T, V<T>, greater<T>>;
template<typename T> using rPQ = priority_queue<T, V<T>, less<T>>;
template<class T>vector<T> make_vec(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vec(size_t a, Ts... ts){return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));}
template<class SS, class T> ostream& operator << (ostream& os, const pair<SS, T> v){os << "(" << v.first << ", " << v.second << ")"; return os;}
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { for (auto &e : v) os << e << ' '; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<vector<T>> &v){ for(auto &e : v){os << e << "\n";} return os;}
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
 
template <class T> void UNIQUE(vector<T> &x) {sort(all(x));x.erase(unique(all(x)), x.end());}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
void fail() { cout << -1 << '\n'; exit(0); }
inline int popcount(const int x) { return __builtin_popcount(x); }
inline int popcount(const ll x) { return __builtin_popcountll(x); }
template<typename T> void debug(vector<vector<T>>&v){for(ll i=0;i<v.size();i++)
{cerr<<v[i][0];for(ll j=1;j<v[i].size();j++)cerr spa v[i][j];cerr<<"\n";}};
template<typename T> void debug(vector<T>&v){if(v.size()!=0)cerr<<v[0];
for(ll i=1;i<v.size();i++)cerr spa v[i];
cerr<<"\n";};
template<typename T> void debug(priority_queue<T>&v){V<T> vals; while(!v.empty()) {cerr << v.top() << " "; vals.push_back(v.top()); v.pop();} cerr<<"\n"; for(auto val: vals) v.push(val);}
template<typename T, typename T2> void debug(map<T,T2>&v){for(auto [k,v]: v) cerr << k spa v << "\n"; cerr<<"\n";}
template<typename T, typename T2> void debug(unordered_map<T,T2>&v){for(auto [k,v]: v) cerr << k spa v << "\n";cerr<<"\n";}
V<int> listrange(int n) {V<int> res(n); rep(i,n) res[i]=i; return res;}

template<typename T> P<T,T> divmod(T a, T b) {return make_pair(a/b, a%b);}

const ll INF = (1ll<<62);
// const ld EPS   = 1e-10;
// const ld PI    = acos(-1.0);

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

template <class S, S (*op)(S, S), S (*e)()> struct SG {
  public:
    SG() : SG(0) {}
    explicit SG(int n) : SG(std::vector<S>(n, e())) {}
    explicit SG(const std::vector<S>& v) : _n(int(v.size())) {
        log = ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void update(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S query(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S query_all() const { return d[1]; }
    
    void check () {
        rep(i,_n) cerr << get(i) << " ";
        cerr << endl;
    }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

// class S, S (*op)(S, S), S (*e)()
using T = int;
T op (T l, T r) {
    return max(l,r);
}
T e () {
    return (T)-INF;
}
// SG<T, op, e> sg(n);

struct UF {
  public:
    UF() : _n(0) {}
    explicit UF(int n) : _n(2*n-1), parent_or_size(2*n-1, -1), ns(2*n-1), _num(n) {}

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return root(a) == root(b);
    }

    int root(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = root(parent_or_size[a]);
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> root_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            root_buf[i] = root(i);
            group_size[root_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[root_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }
    
    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int ri = root(a), rj = root(b);
        if (ri == rj) return 0;
        // if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        // x: parent
        parent_or_size[ri] = parent_or_size[rj] = _num;
        ns[_num].emplace_back(ri);
        ns[_num].emplace_back(rj);
        ns[ri].emplace_back(_num);
        ns[rj].emplace_back(_num);
        _num += 1;
        
        return 1;
    }

  public:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
    VV<int> ns;
    int _num;
};

void Main(){
    ll n,m,q;
    cin >> n >> m >> q;
    V<ll> p(n);
    V<int> invp(n+1);
    UF uf(n);
    rep(i,n) {
        cin >> p[i];
        invp[p[i]] = i;
    }
    V<int> used(m);
    V<P<int,int>> es(m);
    rep(i,m) {
        int u,v;
        cin >> u >> v;
        u--;v--;
        es[i] = {u,v};
    }
    V<P<int,int>> qs(q);
    rep(i,q) {
        int t,v;
        cin >> t >> v;
        v--;
        qs[i] = {t,v};
        if (t==2) {
            used[v] = 1;
        }
    }
    rep(i,m) {
        if (!used[i]) uf.merge(es[i].first, es[i].second);
    }
    V<int> index;
    reverse(all(qs));
    for (auto [t,v] : qs) {
        if (t==1) index.emplace_back(uf.root(v));
        else uf.merge(es[v].first, es[v].second);
    }
    int N = uf._num;
    // cout << N spa "hoge" << endl;
    V<int> ls(N, -1);
    V<int> rs(N, -1);
    V<int> ts(2*N);
    V<int> par(N, -1);
    auto ns = uf.ns;
    // debug(ns);
    int t = 0;
    rep(start,N) {
        if (~ls[start] || uf.root(start)!=start) continue;
        // cout << start << endl;
        stack<int> q;
        q.push(start);
        par[start] = start;
        while (!q.empty()) {
            int u = q.top();
            q.pop();
            if (u<0) {
                u = ~u;
                rs[u] = t;
                t++;
            } else {
                ls[u] = t;
                q.push(~u);
                int leaf = 1;
                for (auto v : ns[u]) {
                    if (~par[v]) continue;
                    q.push(v);
                    par[v] = u;
                    leaf = 0;
                    //process
                }
                if (leaf) ts[t] = p[u];
                t++;
            }
        }
    }
    // debug(ls);
    // debug(rs);
    SG<T, op, e> sg(ts);
    reverse(all(index));
    for (auto ind : index) {
        auto vv = sg.query(ls[ind], rs[ind]);
        auto u = invp[vv];
        if (vv>0) sg.update(ls[u], 0);
        cout << vv << "\n";
    }
}

int main(void){
    std::ifstream in("tmp_in");
    if (TEST) {
        std::cin.rdbuf(in.rdbuf());
        std::cout << std::fixed << std::setprecision(15);
    } else {
        std::cin.tie(nullptr);
        std::ios_base::sync_with_stdio(false);
        std::cout << std::fixed << std::setprecision(15);
    }
    Main();
}