//Code by Varshil Kavathiya



#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using namespace __gnu_pbds;



/*

****************************************************************************************************

*/



#define ll          long long

#define ld          long double

#define vll         vector<long long>

#define mll         map<long long,long long>

#define umll        unordered_map<ll,ll,custom_hash>

#define ss          second

#define ff          first

#define bs          binary_search

#define lb          lower_bound

#define ub          upper_bound

#define all(x)      x.begin(), x.end()

#define rep(i,n)    for(ll i=0;i<n;++i)

#define rep1(i,n)   for(ll i=1;i<n;++i)

#define tt          for(ll TT = 1; TT <= tc ; TT++)

#define pb          push_back

#define ppb         pop_back

#define sqrt        sqrtl

#define cntSetBits  __builtin_popcountll

#define Tzeros      __builtin_ctzll

#define Lzeros      __builtin_clzll

#define endl        '\n'

#define iendl       '\n', cout<<flush

#define fast        ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

#define timetaken cerr<<fixed<<setprecision(10); cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl

const ll INF =      8e18;

const ll mod =      1000000007;

ll tc =             1;

const ll N =        200005;

const int dx[4] = { -1, 1, 0, 0}; const int dy[4] = {0, 0, -1, 1};

inline ll power(ll x, unsigned ll y, ll p = LLONG_MAX) {ll res = 1; x = x % p; if (x == 0) {return 0;} while (y > 0) { if (y & 1) {res = (res * x) % p;} y = y >> 1; x = (x * x) % p;} return res;} // CALCULATING POWER IN LOG(Y) TIME COMPLEXITY

inline ll inversePrimeModular(ll a, ll p) {return power(a, p - 2, p);}

ll mod_add(ll a, ll b, ll mod) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}

ll mod_mul(ll a, ll b, ll mod) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}

ll mod_sub(ll a, ll b, ll mod) {a = a % mod; b = b % mod; return (((a - b) % mod) + mod) % mod;}

struct custom_hash {static uint64_t splitmix64(uint64_t x) {x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31);} size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM);}};

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}

ll lcm(ll a, ll b) {return ((a / gcd(a, b)) * b);}

template<class T, class V>istream& operator>>(istream &in, pair<T, V> &a) {in >> a.ff >> a.ss; return in;}

template<class T>istream& operator>>(istream &in, vector<T> &a) {for (auto &i : a) {in >> i;} return in;}

template<class T, class V>ostream& operator<<(ostream &os, pair<T, V> &a) {os << a.ff << " " << a.ss; return os;}

template<class T>ostream& operator<<(ostream &os, vector<T> &a) {for (int i = 0 ; i < a.size() ; i++) {if (i != 0) {os << ' ';} os << a[i];} return os;}

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

// ifdef->hide & ifndef->show

#ifndef ONLINE_JUDGE

#include "debug.cpp"

#define dbg(x...) cerr << #x << ": "; __(x)

#else

#define dbg(x...)

#endif

/*

****************************************************************************************************

*/



void solve()

{

      ll n; cin >> n;

      vector<vector<ll>>v(n, vector<ll>(n));

      cin >> v;

      ll sum = 0;

      rep(i, n)

      {

            rep(j, n)

            {

                  sum += v[i][j];

            }

      }

      ll x = 0, y = n - 1;

      ll mn = v[0][n-1];

      dbg(mn);

      while (x != n && y != -1)

      {

            mn = min(v[x][y], mn);

            x++;

            y--;

      }

      cout << sum - mn << endl;

}



/*

****************************************************************************************************

*/



int main()

{

#ifndef ONLINE_JUDGE

      freopen("error.txt", "w", stderr);

#endif

      fast;

      cout << setprecision(30);

      // cin >> tc;

      tt

      {

            // cout << "#Case: " << TT << endl;

            solve();

      }

      timetaken;

      return 0;

}