#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <array>
#include <list>
#include <stack>
#include <valarray>
#include <fstream>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef vector<vpi> vvpi;
typedef long long ll;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;
typedef vector<pl> vpl;
typedef vector<vl> vvl;
typedef vector<vpl> vvpl;

const int INF = 1001001001;
const ll INFL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }
int in() { int x; cin >> x; return x; }
double fin() { double x; cin >> x; return x; }
string sin() { string x; cin >> x; return x; }
ll lin() { ll x; cin >> x; return x; }

ll mod = 1000000007;

ll solve(ll n, ll x1, ll y1, ll x2, ll y2, ll k, ll plus) {
    if (0 > x2 || 0 > y2 || n - 1 < x1 || n - 1 < y1 || plus >= k) return 0;

    if (x1 <= 0 && n - 1 <= x2 && y1 <= 0 && n - 1 <= y2) {
        ll a = min(plus + n, k);
        ll b = plus + 1;
        ll sol = (a + b) * (a - b + 1) / 2 % mod * n % mod;
        return sol;
    } else if (x1 <= 0 && n - 1 <= x2) {
        ll a = min(plus + n, k);
        ll b = plus + 1;
        ll my1 = max(0LL, y1);
        ll my2 = min(n - 1, y2);
        ll sol = (a + b) * (a - b + 1) / 2 % mod * (my2 - my1 + 1) % mod;
        return sol;
    } else if (y1 <= 0 && n - 1 <= y2) {
        ll a = min(plus + n, k);
        ll b = plus + 1;
        ll mx1 = max(0LL, x1);
        ll mx2 = min(n - 1, x2);
        ll sol = (a + b) * (a - b + 1) / 2 % mod * (mx2 - mx1 + 1) % mod;
        return sol;
    } else {
        ll m = n / 2;
        ll sol1 = solve(m, x1, y1, x2, y2, k, plus);
        ll sol2 = solve(m, x1 - m, y1, x2 - m, y2, k, plus + m);
        ll sol3 = solve(m, x1, y1 - m, x2, y2 - m, k, plus + m);
        ll sol4 = solve(m, x1 - m, y1 - m, x2 - m, y2 - m, k, plus);

        return (sol1 + sol2 + sol3 + sol4) % mod;
    }
}

int main() {
#ifdef LOCAL_ENV
    freopen("sol.in", "r", stdin);
    freopen("sol.out", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    int q = in();
    forn (cs, q) {
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;

        x1--; y1--; x2--; y2--;

        ll cur = 1;
        while (cur <= x2 || cur <= y2) cur <<= 1;
        cout << solve(cur, x1, y1, x2, y2, k, 0) << '\n';
    }
    return 0;
}