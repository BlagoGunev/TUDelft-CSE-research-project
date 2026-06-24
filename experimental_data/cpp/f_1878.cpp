#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second 
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) (int)x.size()
#define len(x) (int)strlen(x)
#define all(x) x.begin(), x.end()
#define debug cerr << "OK\n";
#define ub upper_bound
#define lb lower_bound 
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

mt19937 bruh(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rofl(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef set<int> si;
typedef set<ll> sll;
typedef set<pii> spii;
typedef set<pll> spll;
typedef multiset <int> msi;
typedef multiset <ll> msll;
typedef map <int, int> mi;
typedef map <ll, ll> mll;

const int N = 1e6 + 2;
const int M = 1e6;
const int mod = 0;
const int inf = 2e9 + 3;
const ll INF = 1e18;
const ld pi2 = 2.0 * 3.141592653589793;
const ld pi = 3.141592653589793;
const ld eps = 1e-12;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

#ifndef PC
    #define gcd __gcd
#endif

void files(string s = "main") {
    #ifndef PC
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    #endif
}

int add(int a, int b) {
    if (a + b < 0) return a + b + mod;
    if (a + b >= mod) return a + b - mod;
    return a + b;		
}

int mul(int a, int b) {
    return a * 1LL * b % mod;
}

int binpow(int a, int n) {
    int ret = 1;
    while (n) {
        if (n & 1) ret = mul(ret, a);
        a = mul(a, a);
        n >>= 1;
    }
    return ret;
}

int T;
int n, q;
vector<pair<int, int>> d[N];

void solve() {
    cin >> n >> q;
    int init_n = n;
    map<int, int> init, init_dcol;
    long long init_col = 1;
    for (auto [x, y] : d[n]) {
        init[x] = y;
        init_col *= y + 1;
        for (auto [z, w] : d[y + 1]) {
            init_dcol[z] += w;
        }
    }
    map<int, int> now = init;
    map<int, int> dcol = init_dcol;
    long long col = init_col;

    for (int i = 1, t, X; i <= q; ++i) {
        cin >> t;
        if (t == 1) {
            cin >> X;
            n *= X;
            for (auto [x, y] : d[X]) {
                col /= now[x] + 1;
                for (auto [z, w] : d[now[x] + 1]) {
                    dcol[z] -= w;
                }
                now[x] += y;
                col *= now[x] + 1;
                for (auto [z, w] : d[now[x] + 1]) {
                    dcol[z] += w;
                }
            }
            bool F = 1;
            for (auto [x, y] : dcol) {
                if (now[x] < y) {
                    F = 0;
                }
            }
            if (F) cout << "YES\n";
            else cout << "NO\n";
        }
        else {
            n = init_n;
            now = init;
            col = init_col;
            dcol = init_dcol;
        }
    }
    cout << '\n';
}

int main() {
    speed;
    for (int i = 2; i <= M; ++i) {
        if (sz(d[i])) continue;
        for (int j = i; j <= M; j += i) {
            int x = j, cnt = 0;
            while (x % i == 0) {
                cnt++;
                x /= i;
            }
            d[j].push_back({i, cnt});
        }
    }
    cin >> T;
    while (T--) solve();
}