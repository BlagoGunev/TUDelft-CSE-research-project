#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
  #define pr_debug(...) do { printf("DEBUG: line %d: %s: ", __LINE__, __PRETTY_FUNCTION__); printf(__VA_ARGS__); } while(0)
  #define pr_vars(...) do { pr_debug(" "); pr_var(split(#__VA_ARGS__, ',').begin(), __VA_ARGS__); } while(0)
#else
  __attribute__ ((constructor)) static void fast_cin() { ios_base::sync_with_stdio(false); cin.tie(0); }
  #define pr_debug(...) do { } while(0)
  #define pr_vars(...) do { } while(0)
#endif /* ONLINE_JUDGE */

using ll = int64_t;
using ull = uint64_t;
#define X first
#define Y second

template<typename T> ostream &operator<< (ostream &fout, const vector<T> &vec)
{ for (const auto &el : vec) fout << el << ' '; return fout; }

template<typename T> istream &operator>> (istream &fin, vector<T> &vec)
{ for (size_t i = 0; i < vec.size(); i++) fin >> vec[i]; return fin; }

vector<string> split(const string &s, char c) { vector<string> v; ull st = 0, fn = 0, lvl = 0;
for ( ; fn < s.size(); fn++ ) { if (s[fn] == c && lvl == 0) { v.push_back(s.substr(st, fn - st)); st = fn + 1; }
if (s[fn] == '(') { lvl++; } if (s[fn] == ')') { lvl--; } } v.push_back(s.substr(st, fn - st)); return v; }

void pr_var(vector<string>::iterator it) { (void) it; cout << endl; }
template<typename T, typename... Args> void pr_var(vector<string>::iterator it, T a, Args... args)
{ cout << *it << "=" << a << "  "; pr_var(++it, args...); }

ll div_ceil(ll n, ll d) { ll res = n / d; if (res >= 0) res += n % d ? 1 : 0; return res; }
ll gcd(ll a, ll b) { a = llabs(a); b = llabs(b); while (a && b) a > b ? a %= b : b %= a; return a + b; }
ll lcm(ll a, ll b) { ll c = gcd(a, b); return c == 0 ? 0 : llabs(a / c * b); }

#define setp(a) fixed << setprecision(a)
const double PI = acos(-1.0);
constexpr double EPS = 1e-9;
constexpr double INF = 2e18;

using mp = pair<ll, ll>;
using mt = tuple<ll, ll, ll>;    // unpack: tie(ll, ll, ll) = mt;

constexpr ll MAX = 1e5 + 5;

int main()
{
    ll n, k; cin >> n >> k;
    vector<ll> a(k); cin >> a;
    sort(a.begin(), a.end(), greater<ll>());

    ll t4 = n;
    ll t2 = 2 * n;

    for (ll i = 0; i < k; i++) {
        if (t4 && a[i] >= 4) { ll m = a[i] / 4; if (m > t4) m = t4; a[i] -= 4 * m; t4 -= m; }
    }
    for (ll i = 0; i < k; i++) {
        if (t2 && a[i] >= 2) { ll m = a[i] / 2; if (m > t2) m = t2; a[i] -= 2 * m; t2 -= m; }
    }

    t2 += t4;
    ll t1 = t4;

    for (ll i = 0; i < k; i++) {
        if (t2 && a[i] >= 2) { ll m = a[i] / 2; if (m > t2) m = t2; a[i] -= 2 * m; t2 -= m; }
    }

    for (ll i = 0; i < k; i++) {
        if (t1 && a[i] >= 1) { ll m = a[i] / 1; if (m > t1) m = t1; a[i] -= 1 * m; t1 -= m; }
        if (a[i] > 0 && t2) { ll m = div_ceil(a[i], 2); if (m > t2) m = t2; a[i] -= 2 * m; t2 -= m; }
    }

    for (ll i = 0; i < k; i++) {
        if (a[i] > 0) { cout << "NO" << endl; return 0; }
    }

    cout << "YES" << endl;
    return 0;
}