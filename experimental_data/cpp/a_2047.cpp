#define GLIBCXX_DEBUG

#include <bits/stdc++.h>
// #include "optimization.h"
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define fs first
#define sc second
#define th third
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define vec vector
#define vsum(x) accumulate(x.begin(), x.end(), 0LL)
#define ins insert
#define rsz(x) resize(x)
#define sz(x) (int)(x.size())
#define ext extract
#define prq priority_queue
#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME
#define FORN_1(end) for (int iter_for_forn = 0; iter_for_forn < end; ++iter_for_forn)
#define FORN_2(iter, end) for (int iter = 0; iter < end; ++iter)
#define FORN_3(iter, begin, end) for (int iter = begin; iter < end; ++iter)
#define FORN_4(iter, begin, end, move) for (int iter = begin; iter < end; iter+=move)
#define RFORN_1(begin) for (int iter_for_rforn = (begin); iter_for_rforn >= 0; --iter_for_rforn)
#define RFORN_2(iter, end) for (int iter = end-1; iter >= 0; --iter)
#define RFORN_3(iter, begin, end) for (int iter = end-1; iter >= begin; --iter)
#define RFORN_4(iter, begin, end, move) for (int iter = end-1; iter >= begin; iter-=move)
#define forn(...) GET_MACRO(__VA_ARGS__, FORN_4,FORN_3, FORN_2, FORN_1)(__VA_ARGS__)
#define rforn(...) GET_MACRO(__VA_ARGS__, RFORN_4,RFORN_3, RFORN_2, RFORN_1)(__VA_ARGS__)
#define each(el, arr) for (auto &el : arr)
#ifdef LOCAL
#define dbg(...) [](auto...zxc){ ((cout << zxc << ' '), ...) << endl;}(#__VA_ARGS__, ":", __VA_ARGS__)
#define dbgv(v) cout<< #v <<" : { | "; for(auto &zxc: v) {cout << zxc << " | "; }cout <<"}"<< endl;
#else
#define dbg(...)
#define dbgv(v)
#endif
template<class T1, class T2, class T3>
struct triple {
    T1 first;
    T2 second;
    T3 third;

    triple() = default;

    triple(const T1 &f, const T2 &s, const T3 &t) : first(f), second(s), third(t) {}

    bool operator==(const triple &other) const {
        return tie(first, second, third) == tie(other.first, other.second, other.third);
    }

    bool operator!=(const triple &other) const { return !(*this == other); }

    bool operator<(const triple &other) const {
        return tie(first, second, third) < tie(other.first, other.second, other.third);
    }

    bool operator<=(const triple &other) const { return !(*this > other); }

    bool operator>(const triple &other) const {
        return tie(first, second, third) > tie(other.first, other.second, other.third);
    }

    bool operator>=(const triple &other) const { return !(*this < other); }
};

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vb = vector<bool>;
using vi = vector<int>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vvvvi = vector<vvvi>;
using vvvvvi = vector<vvvvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vvvvl = vector<vvvl>;
using vvvvvl = vector<vvvvl>;
using vd = vector<ld>;
using vvd = vector<vd>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;
using ti = triple<int, int, int>;
using tl = triple<ll, ll, ll>;
using td = triple<ld, ld, ld>;
using vpi = vector<pi>;
using vvpi = vector<vpi>;
using vti = vector<ti>;
using vpl = vector<pl>;
using vvpl = vector<vpl>;
using vtl = vector<tl>;
using vpd = vector<pd>;
using vtd = vector<td>;

template<class T1>
istream &operator>>(istream &in, vector<T1> &a) {
    for (T1 &i: a) in >> i;
    return in;
}

template<class T1, class T2>
istream &operator>>(istream &in, vector<pair<T1, T2>> &a) {
    for (auto &[i1, i2]: a) in >> i1 >> i2;
    return in;
}

template<class T1, class T2>
istream &operator>>(istream &in, pair<T1, T2> &a) {
    in >> a.first >> a.second;
    return in;
}

template<class T1, class T2, class T3>
istream &operator>>(istream &in, vector<triple<T1, T2, T3>> &a) {
    for (auto &[i1, i2, i3]: a) in >> i1 >> i2 >> i3;
    return in;
}

template<class T1, class T2, class T3>
istream &operator>>(istream &in, triple<T1, T2, T3> &a) {
    in >> a.first >> a.second >> a.third;
    return in;
}

template<class T1>
ostream &operator<<(ostream &out, vector<T1> &a) {
    for (T1 &i: a) out << i << ' ';
    return out;
}

template<class T1, class T2>
ostream &operator<<(ostream &out, vector<pair<T1, T2>> &a) {
    for (auto &[i1, i2]: a) out << i1 << ' ' << i2 << '\n';
    return out;
}

template<class T1, class T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &a) {
    out << a.first << ' ' << a.second;
    return out;
}

template<class T1, class T2, class T3>
ostream &operator<<(ostream &out, vector<triple<T1, T2, T3>> &a) {
    for (auto &[i1, i2, i3]: a) out << i1 << ' ' << i2 << ' ' << i3 << '\n';
    return out;
}

template<class T1, class T2, class T3>
ostream &operator<<(ostream &out, const triple<T1, T2, T3> &a) {
    out << a.first << ' ' << a.second << ' ' << a.third;
    return out;
}

int BitSize(int64_t number) {
    int BitSizeAns = 1;
    while (number > 1) number >>= 1, BitSizeAns++;
    return BitSizeAns;
}

int64_t Bit(int64_t number, int PosInNumber) { return (number >> PosInNumber) & 1; }

template <class T>
T gcd(T a, T b) {
    while (b) a = a % b, swap(a, b);
    return a;
}

template <class T>
T lcm(T a, T b){ return a / gcd(a,b) * b; }

template<class T>
bool ckmin(T &a, const T &b) { return b < a && (a = b); }

template<class T>
bool ckmax(T &a, const T &b) { return b > a && (a = b); }

void coutans(bool ans) { ans ? cout << "YES" << '\n' : cout << "NO" << '\n'; }

const ll mod = 998244353;

int64_t poww(int64_t val, int64_t d, int64_t modd = mod) {
    int64_t ans = 1, mn = val;
    while (d) {
        if (d & 1) ans = mn * ans % modd;
        mn = mn * mn % modd, d >>= 1;
    }
    return ans;
}

void solve(){
    int n; cin>> n;
    vi a(n) ;cin >> a;
    int sum =0;
    int ans = 0;
    forn(i,n){
        sum += a[i];
        int u = sqrt(sum);
        dbg(sum);
        if(u%2==1 && u*u==sum){
            ans++;
        }
    } 
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}