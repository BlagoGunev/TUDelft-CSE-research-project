#include <bits/stdc++.h>

#include <ext/pb_ds/detail/standard_policies.hpp>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>



#define FIO                     ios::sync_with_stdio(false); cin.tie(nullptr)

#define TC(t)                   int t; cin >> t; for(int i = 1; i <= t; i++)

#define ll                      long long int

#define ull                     unsigned long long int

#define lll                     __int128

#define lld                     long double

#define loop(i, a, b)           for(ll i = a; i <= b; i++)

#define loop2(i, b, a)          for(ll i = b; i >= a; i--)

#define ini(x, y)               memset(x, y, sizeof(x))

#define all(x)                  x.begin(), x.end()

#define all2(x)                 x.rbegin(), x.rend()

#define sz(x)                   (ll)x.size()

#define pb                      push_back

#define ppb                     pop_back

#define mp                      make_pair

#define ff                      first

#define ss                      second

#define M                       998244353

#define endl                    '\n'

#define bits(x)                 __builtin_popcountll(x)

#define zrbits(x)               __builtin_ctzll(x)

#define vl                      vector<ll>

#define pll                     pair<ll,ll>

#define vpll                    vector<pll>

#define uni(x)                  x.erase(unique(all(x)), x.end())

#define ordered_set             tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

#define multi_ordered_set       tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>

#define mxheap                  priority_queue<ll>

#define mnheap                  priority_queue<ll, vector<ll>, greater<ll>>

#define mxheap2                 priority_queue<pair<ll,ll>>

#define mnheap2                 priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>



const int N = 2e5 + 5;

const int L = 20;

const int MX = 1e9 + 10;

const ll INF = 1e18;



const int dx[] = {0, -1, 0, 1, -1, -1, 1, 1};

const int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};



using namespace std;

using namespace __gnu_pbds;



inline ll uceil(ll a,ll b) {return (a % b ? a / b + 1 : a / b);}

inline ll mod(ll x) {return ( (x % M + M) % M );}

ll ulog(ll val, ll base) {ll cnt = 0; val /= base; while(val) {cnt++; val /= base;} return cnt;}

ll power(ll a, ll b) {ll res = 1; while (b) {if (b & 1) res = res * a; a = a * a; b >>= 1;} return res;}

ll modpow(ll a, ll b) {ll res = 1; while (b) {if (b & 1) res = res * a % M; a = a * a % M; b >>= 1;} return res;}



#ifdef FARHAN

#define deb(x)                  cerr << #x << " = " << x << endl;

#define deb2(x, y)              cerr << #x << " = " << x << ", " << #y << " = " << y << endl;

#define deb3(x, y, z)           cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;

#define deb4()                  cerr << endl;

#define done                    cerr << "Line " << __LINE__ << " is done" << endl;

#else

#define deb(x)

#define deb2(x, y)

#define deb3(x, y, z)

#define deb4()

#define done

#endif



template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {for(auto& x : v) os << x << " "; return os;}

template<typename T> ostream& operator<<(ostream& os, const set<T>& v) {for(auto& x : v) os << x << " "; return os;}

template<typename T, typename S> ostream& operator<<(ostream& os, const pair<T, S>& p) {os << p.first << ' ' << p.second; return os;}

template<typename... T> void in(T&... args) {((cin >> args), ...);}

template<typename... T> void out(T&&... args) {((cout << args << endl), ...);}

template<typename... T> void out2(T&&... args) {((cout << args << " "), ...);}

template<typename... T> void out3(T&&... args) {((cout << args << " "), ...); cout << endl;}



void solve() {

        ll n;

        cin >> n;

        vector<ll> a(n);

        ll zero = 0;

        for(int i = 0; i < n; i++) {

                cin >> a[i];

                if(a[i] == 0) zero++;

        }

        ll badOne = 0;

        for(int i = 0; i < zero; i++) {

                badOne += a[i];

        }



        ll fix = n * (n - 1) / 2;

        fix %= M;

        ll ans = 0;

        for(ll i = 1; i <= badOne; i++) {

                ll mul = i * i % M;

                ans = (ans + fix * modpow(mul, M - 2) % M) % M;

        }

        cout << ans << endl;

}



signed main () {

        #ifdef FARHAN

                freopen("input.txt", "r", stdin);

                freopen("output.txt", "w", stdout);

        #endif

        FIO;

        TC(t)

        solve();

        return 0;

}