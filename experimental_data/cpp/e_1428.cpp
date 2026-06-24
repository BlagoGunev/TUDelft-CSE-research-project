#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/priority_queue.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
/* ordered_set notes:
    .order_of_key(k): Number of items strictly smaller than k
    .find_by_order(k): k-th element in a set
*/
#define X first
#define Y second
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
#ifdef cychien
#define debug(...) do {\
	fprintf(stderr, "%s - %d : (%s) = ", __PRETTY_FUNCTION__, __LINE__, #__VA_ARGS__);\
    _DO(__VA_ARGS__);\
}while(0) 
template<typename I> void _DO(I&&x) {cerr << x << '\n';}
template<typename I, typename ...T> void _DO(I&&x,T&&...tail) {cerr << x << ", "; _DO(tail...);}
#define IOS
#define DE(v) {cerr << #v << " = ["; for(auto it = (v).begin(); it != (v).end(); it++){cerr << *it; if (next(it) != (v).end()) cerr << ", "; } cerr << "]\n";}
#else
#define debug(...)
#define DE(v)  
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#endif
#define W(v) {for(auto it = (v).begin(); it != (v).end(); it++)cout << *it << " \n"[next(it) == (v).end()];}
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
#define pb emplace_back
#define mp make_pair
#define rsz resize
#define SZ(x) (ll)x.size()
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort(ALL(x))
template<class T> bool chmin(T &a, T b) { return b < a && (a = b, true); }
template<class T> bool chmax(T &a, T b) { return a < b && (a = b, true); }
typedef long long int ll;
// typedef __int128 lll; // C++20 only
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
const int NF = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
const ld PI = 3.14159265358979323846264338327950288;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int Rand(){
    return uniform_int_distribution<int>(INT_MIN, INT_MAX)(rng);
}
/*
#include <atcoder/all>
using namespace atcoder;
*/
#define MAXn 100000
ll a[MAXn + 5];
ll sq(ll x){
    return x * x;
}
ll f(ll x, ll k){
    return sq(x / (k + 1) + 1) * (x % (k + 1)) + sq(x / (k + 1)) * ((k + 1) - x % (k + 1));
}
priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, less<pair<ll, pll>>> pq;
int main() {
    IOS;
    int n, k; cin >> n >> k;
    ll s = 0;
    FOR (i, n) cin >> a[i], s += sq(a[i]), pq.push(mp(f(a[i], 0) - f(a[i], 1), mp(a[i], 0)));
    int times = k - n;
    while (times--){
        auto [delta, lk] = pq.top();
        pq.pop(); auto [_l, _k] = lk;
        s -= delta;
        pq.push(mp(f(_l, _k + 1) - f(_l, _k + 2), mp(_l, _k + 1)));
    }
    cout << s << '\n';
    return 0;
}