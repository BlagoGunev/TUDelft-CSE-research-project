#ifdef ONPC
    #define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>

#define char unsigned char
#define rep(i, a, b) for(int i=a; i< (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back

#define LSOne(S) ((S) & -(S))

using namespace std;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long C;
typedef complex<C> P;
#define X real()
#define Y imag()

template<class T>
istream& operator>> (istream& is, complex<T>& p) {
    T value;
    is >> value;
    p.real(value);
    is >> value;
    p.imag(value);
    return is;
}

typedef long long ll;
typedef long double ld;

using pi = pair<ll, ll>;
using vi = vector<ll>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }

#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

template<typename S, typename T = S> void chmin(S &s, T t) {s = s < t ? s : t;}
template<typename S, typename T = S> void chmax(S &s, T t) {s = s > t ? s : t;}

const int INF = 1e9; // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-9;
const ll MOD = 1e9+7;

const int N=2e5+10;
pair<pair<ll,ll>,pair<ll,ll>> dp[N];

int solve() {
    int n; std::cin >> n;

    for (int i = 1; i <= n; i++) {
        dp[i]={{0,0},{0,0}};
    }

    dp[1]={{0,1}, {0,1}};

    int curr=1;
    for (int i = 1; i <= n; i++) {
        char type; std::cin >> type;
        if(type=='+') {
            int v,x; std::cin >> v >> x; 
            //std::cout << v << " " << x << ": " << endl;
            curr++;

            dp[curr].fi.fi=min(0ll, dp[v].fi.fi+x);
            dp[curr].fi.se=max(0ll, dp[v].fi.se+x);
            dp[curr].se.fi=min(dp[v].se.fi, dp[curr].fi.fi);
            dp[curr].se.se=max(dp[v].se.se, dp[curr].fi.se);
    

            //for (int i = 1; i <= curr; i++) {
            //    std::cout << i << ": ";
            //    std::cout << dp[i].fi.fi << " " << dp[i].fi.se << "; " << dp[i].se.fi << " " << dp[i].se.se << endl;
            //}
            //std::cout  << std::endl;
    

        } else {
            int u,v,k; std::cin >> u >> v >> k;
            if(dp[v].se.fi<=k && k<=dp[v].se.se) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }


    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    cin >> TET;
    for (int i = 1; i <= TET; i++) {
        #ifdef ONPC
            cout << "TEST CASE#" << i << endl;
        #endif
        
        if (solve()) {
            break;
        }

        #ifdef ONPC
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}