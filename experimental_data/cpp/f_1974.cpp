#include <bits/stdc++.h>

using namespace std;

#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for(int i = 0; i < (int)(n); ++i)
#define rep2(i, n) for(int i = 0; i < (int)(n); ++i)
#define rep3(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define rep4(i, a, b, c) for(int i = (a); i < (int)(b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()
#define Sort(a) sort(a.begin(), a.end())
#define RSort(a) sort(a.rbegin(), a.rend())

typedef long long int ll;
typedef unsigned long long ul;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<char> vc;
typedef vector<string> vst;
typedef vector<double> vd;
typedef vector<long double> vld;
typedef pair<long long, long long> P;

template<class T> long long sum(const T& a){ return accumulate(a.begin(), a.end(), 0LL); }
template<class T> auto min(const T& a){ return *min_element(a.begin(), a.end()); }
template<class T> auto max(const T& a){ return *max_element(a.begin(), a.end()); }

const long long MINF = 0x7fffffffffff;
const long long INF = 0x1fffffffffffffff;
const long long MOD = 998244353;
const long double EPS = 1e-9;
const long double PI = acos(-1);

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p){ is >> p.first >> p.second; return is; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p){ os << "(" << p.first << ", " << p.second << ")"; return os; }
template<typename T> istream &operator>>(istream &is, vector<T> &v){ for(T &in : v) is >> in; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &v){ for(int i = 0; i < (int) v.size(); ++i){ os << v[i] << (i + 1 != (int) v.size() ? " " : ""); } return os; }
template <typename T, typename S> ostream &operator<<(ostream &os, const map<T, S> &mp){ for(auto &[key, val] : mp){ os << key << ":" << val << " "; } return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &st){ auto itr = st.begin(); for(int i = 0; i < (int)st.size(); ++i){ os << *itr << (i + 1 != (int)st.size() ? " " : ""); itr++; } return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &st){ auto itr = st.begin(); for(int i = 0; i < (int)st.size(); ++i){ os << *itr << (i + 1 != (int)st.size() ? " " : ""); itr++; } return os; }
template <typename T> ostream &operator<<(ostream &os, queue<T> q){ while(q.size()){ os << q.front() << " "; q.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, deque<T> q){ while(q.size()){ os << q.front() << " "; q.pop_front(); } return os; }
template <typename T> ostream &operator<<(ostream &os, stack<T> st){ while(st.size()){ os << st.top() << " "; st.pop(); } return os; }
template <class T, class Container, class Compare> ostream &operator<<(ostream &os, priority_queue<T, Container, Compare> pq){ while(pq.size()){ os << pq.top() << " "; pq.pop(); } return os; }

template<class T, class U> inline T vin(T& vec, U n) { vec.resize(n); for(int i = 0; i < (int) n; ++i) cin >> vec[i]; return vec; }
template<class T> inline void vout(T vec, string s = "\n"){ for(auto x : vec) cout << x << s; }
template<class... T> void in(T&... a){ (cin >> ... >> a); }
void out(){ cout << '\n'; }
template<class T, class... Ts> void out(const T& a, const Ts&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
template<class T, class U> void inGraph(vector<vector<T>>& G, U n, U m, bool directed = false){ G.resize(n); for(int i = 0; i < m; ++i){ int a, b; cin >> a >> b; a--, b--; G[a].push_back(b); if(!directed) G[b].push_back(a); } }

template <typename S, typename T>
struct RangeTree{
    struct BinaryIndexedTree{
        int N;
        vector<T> BIT;
        BinaryIndexedTree() {}

        void init(int size){
            N = size;
            BIT.assign(N + 1, 0);
        }

        T get(int i){
            return sum(i + 1) - sum(i);
        }

        void add(int i, T x){
            ++i;
            while(i <= N){
                BIT[i] += x;
                i += i & -i;
            }
        }

        T sum(int i) const {
            T ans = 0;
            while(i > 0){
                ans += BIT[i];
                i -= i & -i;
            }
            return ans;
        }

        T sum(int L, int R) const {
            return sum(R) - sum(L);
        }
    };

    using P = pair<S, S>;
    S N, M;
    vector<BinaryIndexedTree> bit;
    vector<vector<S>> ys;
    vector<P> ps;

    RangeTree() {}

    void add_point(S x, S y){
        ps.push_back(make_pair(x, y));
    }

    void build(){
        sort(ps.begin(), ps.end());
        ps.erase(unique(ps.begin(), ps.end()), ps.end());

        N = ps.size();
        bit.resize(N + 1);
        ys.resize(N + 1);
        for(int i = 0; i <= N; ++i){
            int j = i + 1;
            while(j <= N){
                ys[j].push_back(ps[i].second);
                j += j & -j;
            }

            sort(ys[i].begin(), ys[i].end());
            ys[i].erase(unique(ys[i].begin(), ys[i].end()), ys[i].end());
            bit[i].init(ys[i].size());
        }
    }

    int id(S x) const {
        auto f = [](const P &a, const P &b){
            return a.first < b.first;
        };
        return lower_bound(ps.begin(), ps.end(), make_pair(x, S()), f) - ps.begin();
    }

    int id(int i, S y) const {
        return lower_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin();
    }

    void add(S x, S y, T a){
        int i = lower_bound(ps.begin(), ps.end(), make_pair(x, y)) - ps.begin();
        assert(ps[i] == make_pair(x, y));
        ++i;
        while(i <= N){
            bit[i].add(id(i, y), a);
            i += i & -i;
        }
    }

    T sum(S x, S y) const {
        T ret = T();
        int a = id(x);
        while(a > 0){
            ret += bit[a].sum(id(a, y));
            a -= a & -a;
        }
        return ret;
    }

    // [(xl, yl), (xr, yr))
    T sum(S xl, S yl, S xr, S yr) const {
        T ret = T();
        int a = id(xl), b = id(xr);
        while(a != b) {
            if(a < b){
                ret += bit[b].sum(id(b, yl), id(b, yr));
                b -= b & -b;
            } else{
                ret -= bit[a].sum(id(a, yl), id(a, yr));
                a -= a & -a;
            }
        }
        return ret;
    }
};

ll T;

void input(){
    in(T);
}

void solve(){
    ll a, b, n, m; in(a, b, n, m);
    vll x(n), y(n);
    rep(i, n) in(x[i], y[i]);
    RangeTree<ll, ll> rt;
    rep(i, n) rt.add_point(x[i], y[i]);
    rt.build();
    rep(i, n) rt.add(x[i], y[i], 1);
    ll lx = 1, rx = a + 1, ly = 1, ry = b + 1;
    ll ans1 = 0, ans2 = 0;
    rep(i, m){
        char c; ll k; in(c, k);
        ll s = 0;
        if(c == 'L'){
            s += rt.sum(lx, ly, rx, ly + k);
            ly += k;
        }else if(c == 'R'){
            s += rt.sum(lx, ry - k, rx, ry);
            ry -= k;
        }else if(c == 'D'){
            s += rt.sum(rx - k, ly, rx, ry);
            rx -= k;
        }else{
            s += rt.sum(lx, ly, lx + k, ry);
            lx += k;
        }
        if(i % 2 == 0){
            ans1 += s;
        }else{
            ans2 += s;
        }
    }
    out(ans1, ans2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    while(T--) solve();
}