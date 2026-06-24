#include <bits/stdc++.h>
#ifdef ONPC
    #include "t_debug.cpp"
#else
    #define debug(...) 42
#endif
using namespace std;
//namespace pbds = __gnu_pbds;
using ll = long long;
const int inf = 1e9;
const ll infl = 1e18;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rng(RANDOM);
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p) { return is >> p.first >> p.second; }
template<typename Cont> int sz(const Cont& cont) { return int(cont.size()); }
template<typename Func> struct ycom { Func f; template<typename... T> auto operator()(T&&... args) { return f(*this, forward<T>(args)...); } }; template<typename Func> ycom(Func) -> ycom<Func>;
template<typename T> typename vector<T>::const_iterator operator+(const vector<T>& x, const int i) { return x.cbegin() + i ;};
template<typename T> typename vector<T>::iterator operator+(vector<T>& x, int i) { return x.begin() + i ;};
const string fileio = "";
constexpr int tests = 1, nmax = 2e5, nlog = __lg(nmax), mod = 1e9+7;

int solve() {
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n);
    for (auto& i : a) {cin >> i;}
    vector<int> c(k);
    for (auto& i : c) {cin >> i;}

    auto op = [&](int j){
        for (int i = c[j%k]-1; i >= 0;i--)
            a[i]++;
    };

    ll res = 0;
    for (int j = 0; j < d && j <= n*2; j++) {
        ll cur = 0;

        for (int i = 0; i < n; i++)
            cur += a[i] == i+1;

        res = max(res, cur + (d - j - 1) / 2);
        op(j);
    }
    cout << res << '\n';

    return 0;
}

signed main() {
    int t = 1;
    #ifdef ONPC
    t = 10000;
    #else
    if (fileio.size()) {freopen((fileio+".in").c_str(),"r",stdin);freopen((fileio+".out").c_str(),"w",stdout);}
    #endif
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit | cin.eofbit);
    cout << fixed << setprecision(12);
    if (tests) cin >> t;
    while (t-- && cin) {
        if (solve()) break;
        #ifdef ONPC
            cout << "____________________" << endl;
        #endif
    }
    return 0;
}

/*
     █████               █████  ███  ████                               
    ▒▒███               ▒▒███  ▒▒▒  ▒▒███                               
  ███████  ████████   ███████  ████  ▒███  █████ ████  ██████  ████████ 
 ███▒▒███ ▒▒███▒▒███ ███▒▒███ ▒▒███  ▒███ ▒▒███ ▒███  ███▒▒███▒▒███▒▒███
▒███ ▒███  ▒███ ▒▒▒ ▒███ ▒███  ▒███  ▒███  ▒███ ▒███ ▒███ ▒███ ▒███ ▒▒▒ 
▒███ ▒███  ▒███     ▒███ ▒███  ▒███  ▒███  ▒███ ▒███ ▒███ ▒███ ▒███     
▒▒████████ █████    ▒▒████████ █████ █████ ▒▒███████ ▒▒██████  █████    
 ▒▒▒▒▒▒▒▒ ▒▒▒▒▒      ▒▒▒▒▒▒▒▒ ▒▒▒▒▒ ▒▒▒▒▒   ▒▒▒▒▒███  ▒▒▒▒▒▒  ▒▒▒▒▒     
                                            ███ ▒███                    
                                           ▒▒██████                     
                                            ▒▒▒▒▒▒
*/