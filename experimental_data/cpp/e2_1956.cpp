#include<bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;

#pragma region acl_internal
#pragma region internal_type_traits
#ifndef ATCODER_INTERNAL_TYPE_TRAITS_HPP
#define ATCODER_INTERNAL_TYPE_TRAITS_HPP 1
namespace atcoder {
namespace in {
template <class T> using is_integral = typename std::is_integral<T>;
template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;
template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;
template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;
template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;
template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;
template <class T> using to_unsigned_t = typename to_unsigned<T>::type;
}
}
#endif
#pragma endregion internal_type_traits

#pragma region internal_bit
#ifndef ATCODER_INTERNAL_BITOP_HPP
#define ATCODER_INTERNAL_BITOP_HPP 1
#if __cplusplus >= 202002L
#include <bit>
#endif
namespace atcoder {
namespace in {
#if __cplusplus >= 202002L
using std::bit_ceil;
#else
unsigned int bit_ceil(unsigned int n) {
    unsigned int x = 1;
    while (x < (unsigned int)(n)) x *= 2;
    return x;
}
#endif
int countr_zero(unsigned int n) {
    return __builtin_ctz(n);
}
constexpr int countr_zero_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}
}
}
#endif
#pragma endregion internal_bit

#pragma region internal_csr
#ifndef ATCODER_INTERNAL_CSR_HPP
#define ATCODER_INTERNAL_CSR_HPP 1
namespace atcoder {
namespace in {
template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    explicit csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};
}
}
#endif
#pragma endregion internal_csr

#pragma region internal_math
#ifndef ATCODER_INTERNAL_MATH_HPP
#define ATCODER_INTERNAL_MATH_HPP 1
namespace atcoder {
namespace in {
constexpr ll safe_mod(ll x, ll m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}
struct barrett {
    unsigned int _m;
    ull im;
    explicit barrett(unsigned int m) : _m(m), im((ull)(-1) / m + 1) {}
    unsigned int umod() const { return _m; }
    unsigned int mul(unsigned int a, unsigned int b) const {
        ull z = a;
        z *= b;
        ull x =
            (ull)(((unsigned __int128)(z)*im) >> 64);
        ull y = x * _m;
        return (unsigned int)(z - y + (z < y ? _m : 0));
    }
};
constexpr ll pow_mod_constexpr(ll x, ll n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    ull r = 1;
    ull y = safe_mod(x, m);
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}
constexpr bool is_prime_constexpr(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    ll d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr ll bases[3] = {2, 7, 61};
    for (ll a : bases) {
        ll t = d;
        ll y = pow_mod_constexpr(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}
template <int n> constexpr bool is_prime = is_prime_constexpr(n);
constexpr std::pair<ll, ll> inv_gcd(ll a, ll b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};
    ll s = b, t = a;
    ll m0 = 0, m1 = 1;
    while (t) {
        ll u = s / t;
        s -= t * u;
        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b
        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}
constexpr int primitive_root_constexpr(int m) {
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    int divs[20] = {};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while (x % 2 == 0) x /= 2;
    for (int i = 3; (ll)(i)*i <= x; i += 2) {
        if (x % i == 0) {
            divs[cnt++] = i;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        divs[cnt++] = x;
    }
    for (int g = 2;; g++) {
        bool ok = true;
        for (int i = 0; i < cnt; i++) {
            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = primitive_root_constexpr(m);
ull floor_sum_unsigned(ull n,
                                      ull m,
                                      ull a,
                                      ull b) {
    ull ans = 0;
    while (true) {
        if (a >= m) {
            ans += n * (n - 1) / 2 * (a / m);
            a %= m;
        }
        if (b >= m) {
            ans += n * (b / m);
            b %= m;
        }

        ull y_max = a * n + b;
        if (y_max < m) break;
        n = (ull)(y_max / m);
        b = (ull)(y_max % m);
        std::swap(m, a);
    }
    return ans;
}
}
}
#endif
#pragma endregion internal_math

#pragma region internal_queue
#ifndef ATCODER_INTERNAL_QUEUE_HPP
#define ATCODER_INTERNAL_QUEUE_HPP 1
namespace atcoder {
namespace in {
template <class T> struct simple_queue {
    std::vector<T> payload;
    int pos = 0;
    void reserve(int n) { payload.reserve(n); }
    int size() const { return int(payload.size()) - pos; }
    bool empty() const { return pos == int(payload.size()); }
    void push(const T& t) { payload.push_back(t); }
    T& front() { return payload[pos]; }
    void clear() {
        payload.clear();
        pos = 0;
    }
    void pop() { pos++; }
};
}
}
#endif
#pragma endregion internal_queue

#pragma region internal_scc
#ifndef ATCODER_INTERNAL_SCC_HPP
#define ATCODER_INTERNAL_SCC_HPP 1
namespace atcoder {
namespace in {
struct scc_graph {
  public:
    explicit scc_graph(int n) : _n(n) {}
    int num_vertices() { return _n; }
    void add_edge(int from, int to) { edges.push_back({from, {to}}); }
    std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }
    std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }
  private:
    int _n;
    struct edge {
        int to;
    };
    std::vector<std::pair<int, edge>> edges;
};
}
}
#endif
#pragma endregion internal_scc
#pragma endregion acl_internal

#pragma region modint
#ifndef ATCODER_MODINT_HPP
#define ATCODER_MODINT_HPP 1
namespace atcoder {
namespace in {
struct modint_base {};
struct static_modint_base : modint_base {};
template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;
}
template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
struct static_modint : in::static_modint_base {
    using mint = static_modint;
  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }
    static_modint() : _v(0) {}
    template <class T, in::is_signed_int_t<T>* = nullptr>
    static_modint(T v) {
        ll x = (ll)(v % (ll)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, in::is_unsigned_int_t<T>* = nullptr>
    static_modint(T v) {
        _v = (unsigned int)(v % umod());
    }
    unsigned int val() const { return _v; }
    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }
    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v -= rhs._v;
        if (_v >= umod()) _v += umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        ull z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }
    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }
    mint pow(ll n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        if (prime) {
            assert(_v);
            return pow(umod() - 2);
        } else {
            auto eg = in::inv_gcd(_v, m);
            assert(eg.first == 1);
            return eg.second;
        }
    }
    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }
  private:
    unsigned int _v;
    static constexpr unsigned int umod() { return m; }
    static constexpr bool prime = in::is_prime<m>;
};
template <int id> struct dynamic_modint : in::modint_base {
    using mint = dynamic_modint;
  public:
    static int mod() { return (int)(bt.umod()); }
    static void set_mod(int m) {
        assert(1 <= m);
        bt = in::barrett(m);
    }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }
    dynamic_modint() : _v(0) {}
    template <class T, in::is_signed_int_t<T>* = nullptr>
    dynamic_modint(T v) {
        ll x = (ll)(v % (ll)(mod()));
        if (x < 0) x += mod();
        _v = (unsigned int)(x);
    }
    template <class T, in::is_unsigned_int_t<T>* = nullptr>
    dynamic_modint(T v) {
        _v = (unsigned int)(v % mod());
    }
    unsigned int val() const { return _v; }
    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }
    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v += mod() - rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        _v = bt.mul(_v, rhs._v);
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }
    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }
    mint pow(ll n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        auto eg = in::inv_gcd(_v, mod());
        assert(eg.first == 1);
        return eg.second;
    }
    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }
  private:
    unsigned int _v;
    static in::barrett bt;
    static unsigned int umod() { return bt.umod(); }
};
template <int id> in::barrett dynamic_modint<id>::bt(998244353);
using modint998244353 = static_modint<998244353>;
using modint1000000007 = static_modint<1000000007>;
using modint = dynamic_modint<-1>;
namespace in {
template <class T>
using is_static_modint = std::is_base_of<in::static_modint_base, T>;
template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;
template <class> struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<dynamic_modint<id>> : public std::true_type {};
template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;
}
}
#endif
#pragma endregion modint

#define rep(i,b) for(int i=0;i<b;i++)
#define rrep(i,b) for(int i=b-1;i>=0;i--)
#define rep1(i,b) for(int i=1;i<b;i++)
#define repx(i,x,b) for(int i=x;i<b;i++)
#define rrepx(i,x,b) for(int i=b-1;i>=x;i--)
#define fore(i,a) for(auto& i:a)
#define rng(x) (x).begin(), (x).end()
#define rrng(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define pb push_back
#define fi first
#define se second
#define pcnt __builtin_popcountll

using namespace std;
using namespace atcoder;

using ld = long double;
template<typename T> using mpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<typename T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename T> ll sumv(const vector<T>&a){ll res(0);for(auto&&x:a)res+=x;return res;}
bool yn(bool a) { if(a) {cout << "Yes" << endl; return true;} else {cout << "No" << endl; return false;}}
#define retval(x) {cout << #x << endl; return;}
#define cout2(x,y) cout << x << " " << y << endl;
#define coutp(p) cout << p.fi << " " << p.se << endl;
#define out cout << ans << endl;
#define outd cout << fixed << setprecision(20) << ans << endl;
#define outm cout << ans.val() << endl;
#define outv fore(yans , ans) cout << yans << "\n";
#define outdv fore(yans , ans) cout << yans.val() << "\n";
#define assertmle(x) if (!(x)) {vi v(3e8);}
#define asserttle(x) if (!(x)) {while(1){}}
#define coutv(v) {fore(vy , v) {cout << vy << " ";} cout << endl;}
#define coutv2(v) fore(vy , v) cout << vy << "\n";
#define coutvm(v) {fore(vy , v) {cout << vy.val() << " ";} cout << endl;}
#define coutvm2(v) fore(vy , v) cout << vy.val() << "\n";
using pll = pair<ll,ll>;using pil = pair<int,ll>;using pli = pair<ll,int>;using pii = pair<int,int>;using pdd = pair<ld,ld>;
using vi = vector<int>;using vd = vector<ld>;using vl = vector<ll>;using vs = vector<string>;using vb = vector<bool>;
using vpii = vector<pii>;using vpli = vector<pli>;using vpll = vector<pll>;using vpil = vector<pil>;
using vvi = vector<vector<int>>;using vvl = vector<vector<ll>>;using vvs = vector<vector<string>>;using vvb = vector<vector<bool>>;
using vvpii = vector<vector<pii>>;using vvpli = vector<vector<pli>>;using vvpll = vector<vpll>;using vvpil = vector<vpil>;
using mint = modint998244353;
//using mint = modint1000000007;
//using mint = dynamic_modint<0>;
using vm = vector<mint>;
using vvm = vector<vector<mint>>;
vector<int> dx={1,0,-1,0,1,1,-1,-1},dy={0,1,0,-1,1,-1,1,-1};
ll gcd(ll a, ll b) { return a?gcd(b%a,a):b;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
#define yes {cout <<"Yes"<<endl;}
#define no {cout <<"No"<<endl;}
const double eps = 1e-10;
const ll LINF = 2001002003004005006ll;
const int INF = 1001001001;
#ifdef MY_LOCAL_DEBUG
#define showp(p) cerr<<#p<<" = "<<p.fi<<" : "<<p.se<<endl
#define show1(a) cerr<<#a<<" = "<<a<<endl
#define show2(a,b) cerr<<#a<<" = "<<a<<" : "<<#b<<" = "<<b<<endl
#define show3(a,b,c) cerr<<#a<<" = "<<a<<" : "<<#b<<" = "<<b<<" : "<<#c<<" = "<<c<<endl
#define show4(a,b,c,d) cerr<<#a<<" = "<<a<<" : "<<#b<<" = "<<b<<" : "<<#c<<" = "<<c<<" : "<<#d<<" = "<<d<<endl
#define show5(a,b,c,d,e) cerr<<#a<<" = "<<a<<" : "<<#b<<" = "<<b<<" : "<<#c<<" = "<<c<<" : "<<#d<<" = "<<d<<" : "<<#e<<" = "<<e<<endl
#define DEBUG_LINE cout << "DEBUG_LINE : " << __LINE__ << endl
#define showv(v) {cout<<#v<<" : "; fore(vy , v) {cout << vy << " ";} cout << endl;}
#define showv2(v) {cout<<#v<<endl; fore(vy , v) cout << vy << "\n";}
#define showvm(v) {cout<<#v<<" : "; fore(vy , v) {cout << vy.val() << " ";} cout << endl;}
#define showvm2(v) {cout<<#v<<endl; fore(vy , v) cout << vy.val() << "\n";}
#define showmat(v) {cout<<#v<<endl; fore(row , v) { fore(seg , row) cout << seg << " "; cout << endl;}}
#define showmatm(v) {cout<<#v<<endl; fore(row , v) { fore(seg , row) cout << seg.val() << " "; cout << endl;}}
#else
#define showp(p)
#define show1(a)
#define show2(a,b)
#define show3(a,b,c)
#define show4(a,b,c,d)
#define show5(a,b,c,d,e)
#define DEBUG_LINE
#define showv(v)
#define showv2(v)
#define showvm(v)
#define showvm2(v)
#define showmat(v)
#define showmatm(v)
#endif
#define overload5(a,b,c,d,e,f, ...) f
#define show(...) overload5(__VA_ARGS__, show5, show4, show3, show2, show1)(__VA_ARGS__)

void solve(){
    int n; cin>>n;
    vi a(n);
    rep(i,n) cin>>a[i];
    while(1){
        bool ok = false;
        rep(i,n-1){
            a[i+1] = max(0, a[i+1]-a[i]);
            if (a[i+1]==0) ok = true;
        }
        a[0] = max(0, a[0]-a[n-1]);
        if (a[0]==0) ok = true;
        if (ok) break;
    }
    int id = -1;
    rep(i,n) if (a[i]==0){
        id = i;
        break;
    }
    assert(id!=-1);
    rep(i,id){
        a[i+1] = max(0, a[i+1]-a[i]);
    }
    while(1){
        int mx = 0;
        int now = 0;
        rep(i,n-1){
            int j = (id+i); if (j>=n) j -= n;
            int nj = (j+1); if (nj>=n) nj -= n;
            a[nj] = max(0, a[nj]-a[j]);
            if (a[nj]!=0){
                now++;
            }else{
                if (mx<now) mx = now;
                now = 0;
            }
        }
        chmax(mx, now);
        if (mx<=3) break;
    }

    int pre = n;
    rep(i,n){
        int j = (id+i)%n;
        if (a[j]==0){
            if (pre!=n){
                int pj = (id+pre)%n;
                int nj = (j+(n-1))%n;
                if (nj-pj==0){
                }else if(nj-pj==1 || (nj<pj && (n-pj)+nj==1)){
                    a[nj] = 0;
                }else if((nj)-pj==2 || (nj<pj && (n-pj)+nj==2)){
                    ll k = a[(pj+1)%n]/a[pj];
                    ll val = k*a[(pj+1)%n] - k*(k+1)/2*a[pj];
                    if (val>=a[(pj+2)%n]) a[(pj+2)%n] = 0;
                    a[(pj+1)%n] = 0;
                }else{
                    assert(0);
                }
                pre = n;
            }
        }else{
            if (pre == n) pre = i;
        }
    }
    if (pre!=n){
        int pj = (id+pre)%n;
        int j = (id+n-1)%n;
        if (j-pj==0){
        }else if(j-pj==1 || (j<pj && (n-pj)+j==1)){
            a[j] = 0;
        }else if(j-pj==2 || (j < pj && (n-pj)+j==2)){
            ll k = a[(pj+1)%n]/a[pj];
            ll val = k*a[(pj+1)%n] - k*(k+1)/2*a[pj];
            if (val>=a[(pj+2)%n]) a[(pj+2)%n] = 0;
            a[(pj+1)%n] = 0;
        }else{
            assert(0);
        }
        pre = n;
    }
    int m = 0;
    rep(i,n) if (a[i]!=0) m++;
    cout << m << endl;
    rep(i,n) if (a[i]!=0) cout << i+1 << " ";
    cout << endl;


    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin>>t;

    rep(i,t){
        solve();
    }

    return 0;
}