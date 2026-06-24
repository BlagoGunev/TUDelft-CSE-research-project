#include <bits/stdc++.h>
// ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define FASTIO               \
    ios::sync_with_stdio(0); \
    cin.tie(0); \
    cout.tie(0);
#define PB push_back

#define SZ 1000005

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pil> vpil;
typedef vector<pli> vpli;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<bool> vbl;
typedef vector<string> vst;

template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

/* debugger begin */
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

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
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T, typename V, typename Z>
void __print(const tuple<T, V, Z> &x) {cerr << '{'; __print(get<0>(x)); cerr << ','; __print(get<1>(x)); cerr << ','; __print(get<2>(x)); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

void err(istream_iterator<string> it) {
    cerr << '\n';
}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << "=";
    __print(a);
    cerr << ' ';
    err(++it, args...);
}

/* debugger end */

//const ll MOD = 1000000007;

void solve(int tt) {
    int n;
    cin >> n;
    unordered_map<ll, int> m;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        m[a]++;
    }
    vll vals;
    for (auto [x,y]: m) {
        vals.PB(x);
    }
    sort(all(vals));
    const ll MAXN = 1000000;
    // handle b = 1 separately
    for (ll x : vals) {
        ll cnt = m[x];
        if (cnt >= 3) {
            ll pro = cnt * (cnt-1) * (cnt-2);
//            pro /= 6;
            ans += pro;
        }
    }
    for (ll b = 2; b <= 1000; b++) {
        ll sq = b*b;
        for (ll x : vals) {
            if (x * sq > MAXN) {
                break;
            }
            ll cnt1 = m[b*x];
            if (cnt1) {
                ll cnt2 = m[x*sq];
                if (cnt2) {
                    ll cnt0 = m[x];
                    ans += cnt0 * cnt1 * cnt2;
                }
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    FASTIO;
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; tt++)
    {
        solve(tt);
    }
    return 0;
}