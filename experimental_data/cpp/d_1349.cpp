#include <bits/stdc++.h>

using namespace std; 

using pii = pair<int,int>; using vi = vector<int>; using vp = vector<pii>; using ll = long long; 

using ull = unsigned long long; using db = double; using ld = long double; using lll = __int128_t;

template<typename T1, typename T2> T1 max(T1 a, T2 b) { return a > b ? a : b; }

template<typename T1, typename T2> T1 min(T1 a, T2 b) { return a < b ? a : b; }

#define multi int T; cin >> T; while ( T -- )

#define timer cerr << 1. * clock() / CLOCKS_PER_SEC << '\n';

#define iot ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

#define file(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)

#define rep(i,s,t) for (register int i = (s), i##_ = (t) + 1; i < i##_; ++ i)

#define pre(i,s,t) for (register int i = (s), i##_ = (t) - 1; i > i##_; -- i)

#define eb emplace_back

#define pb pop_back

const int N = 1e7 + 10, mod = 998244353;

const int inf = 0x3f3f3f3f;

const ll infll = 0x3f3f3f3f3f3f3f3fll;

int n, m, t, ans, a[N], b[N], f[N], inv[N];



signed main() {

    iot; cin >> n; rep(i,1,n) cin >> a[i], m += a[i];

    f[0] = n - 1; t = 1ll * m * (n - 1) % mod;

    inv[1] = 1; rep(i,2,max(m, n)) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;

    rep(i,1,m) f[i] = 1ll * (1ll * i * (n - 1) % mod * f[i - 1] + t) % mod * inv[m - i] % mod;

    pre(i,m - 1,0) f[i] += f[i + 1], ( f[i] >= mod && ((f[i] -= mod), 1) );

    rep(i,1,n) ans += f[a[i]], ( ans >= mod && ((ans -= mod), 1) );

    ans = (ans - 1ll * (n - 1) * f[0] % mod + mod) % mod;

    cout << 1ll * ans * inv[n] % mod << '\n';

}