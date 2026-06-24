#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define V vector
#define VA valarray
#define pb push_back
#define SZ(a) ((int)a.size())
#define all(a) (a).begin(), (a).end()
#define TP template <class o>
#define TPP template <typename t1, typename t2>
#define rep(i, a, b) for (int i = a, i##_ = b; i <= i##_; i++)
#define REP(i, a, b) for (int i = b, i##_ = a; i >= i##_; i--)
#define FOR(i, n) rep(i, 1, n)
#define debug(x) cerr << #x << ' ' << '=' << ' ' << x << endl
using namespace std;
typedef double db;
typedef unsigned ui;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

TPP istream &operator>>(istream &cin, pair<t1, t2> &a) {return cin >> a.first >> a.second; }
TP istream &operator>>(istream &cin, V<o> &a) {for(o &i: a) cin >> i; return cin; }
TP istream &operator>>(istream &cin, VA<o> &a) {for(o &i: a) cin >> i; return cin;}
TP istream &operator>>(istream &cin, o &x) {qr(x); return cin;}
TP void qr(o& x) {cin >> x;}
template <class o, class... O> void qr(o& x, O&... y) { qr(x), qr(y...); }
TP void pr1(o x) { cout << x << ' ';}
template <class o, class... O> void pr1(o x, O... y) { pr1(x), pr1(y...); }
TP void pr2(o x) { cout << x << endl;}
template <class o, class... O> void pr2(o x, O... y) { pr2(x), pr2(y...); }
TPP ostream& operator <<(ostream &cout, pair<t1, t2> &a) {
    return cout << a.first << ' ' << a.second;
}
TP ostream& operator <<(ostream &cout, VA<o> &a) {
    int n = SZ(a);  if(!n) return cout;
    cout << a[0];
    for(int i = 1; i < n; i++) cout << ' ' << a[i];
    return cout << '\n';
}
TP ostream& operator <<(ostream &cout, V<o> &a) {
    int n = SZ(a);  if(!n) return cout;
    cout << a[0];
    for(int i = 1; i < n; i++) cout << ' ' << a[i];
    return cout << '\n';
}
TPP ostream& operator <<(ostream &cout, V<pair<t1, t2>> &a) {
    for(auto i: a) cout << i << '\n';
    return cout;
}
TP bool cmax(o& x, o y) { return (x < y ? x = y, 1 : 0); }
TP bool cmin(o& x, o y) { return (x > y ? x = y, 1 : 0); }

const int mod = 998244353;
TPP void ad(t1& x, t2 y) { (x += y) >= mod && (x -= mod); }
TPP void dl(t1& x, t2 y) { (x -= y) < 0 && (x += mod); }
ll power(ll a, ll b, ll mod) {ll c=1;for(;b;b/=2,a=a*a%mod)if(b&1)c=c*a%mod;return c;}

const int N = 510, inf = 0x3f3f3f3f;
int n, a[N][N], b[N][N], t[N];
pii pos[N * N];
ll jc[N];

bool check() {
    FOR(i, n) FOR(j, n) if(a[i][j] ^ b[i][j]) return 1;
    return 0;
}

void solve() {
    qr(n);
    jc[0] = 1; FOR(i, n) jc[i] = jc[i - 1] * i % mod;
    FOR(i, n) FOR(j, n) qr(a[i][j]);
    FOR(i, n) FOR(j, n) qr(b[i][j]), pos[b[i][j]] = {i, j};
    map<pii, bool> v;
    FOR(i, n) FOR(j, n) {
        int x = a[i][j];
        if(pos[x].fi != i && pos[x].se != j) {
            pii now = {(pos[x].fi - i + n) % n, (pos[x].se - j + n) % n};
            if(v[now]) return pr2(0);
            v[now] = 1;
        }
    }
    int ans = 1;
    while(check()) {
        V<int> row, col;
        FOR(i, n) {
            int d = pos[a[i][n]].se, f = 1;
            FOR(j, n - 1) if((j + d - 1) % n + 1 != pos[a[i][j]].se) {f = 0; break;}
            if(f && d < n) row.pb(i);
        }
        FOR(i, n) {
            int d = pos[a[n][i]].fi, f = 1;
            FOR(j, n - 1) if((j + d - 1) % n + 1 != pos[a[j][i]].fi) {f = 0; break;}
            if(f && d < n) col.pb(i);
        }
        if(row.empty() == col.empty()) return pr2(0);
        ans = ans * jc[SZ(row) + SZ(col)] % mod;
        if(SZ(row)) {
            for(int i: row) {
                int d = pos[a[i][n]].se - 1;
                FOR(j, n) t[(j + d) % n + 1] = a[i][j];
                FOR(j, n) a[i][j] = t[j];
            }
        }
        else {
            for(int j: col) {
                int d = pos[a[n][j]].fi - 1;
                FOR(i, n) t[(i + d) % n + 1] = a[i][j];
                FOR(i, n) a[i][j] = t[i];
            }
        }
    }
    pr2(ans);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(15);
    int T = 1;
    qr(T);// #f45587
    while (T--) solve();
    return 0;
}