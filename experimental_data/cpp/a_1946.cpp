#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef long double ld;
const ld PI = acosl(-1);
const ll mod7 = 1e9 + 7;
const ll mod9 = 998244353;
const ll INF = 2 * 1024 * 1024 * 1023;
const char nl = '\n';
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define all(v) v.begin(),v.end()
#pragma GCC optimize("O2")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update>;

ll d, l, r, k, n, m, p, q, u, v, w, x, y, z;
string s, t;
 
vi d4x = {1, 0, -1, 0};
vi d4y = {0, 1, 0, -1};
vi d8x = {1, 0, -1, 0, 1, 1, -1, -1};
vi d8y = {0, 1, 0, -1, 1, -1, 1, -1};
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
////////////////////  LIBRARY CODE ////////////////////

///////////////////////////////////////////////////////

bool multiTest = 1;
void solve(int tt){


    cin >> n;
    vi a(n);
    for(auto& z : a) cin >> z;

    sort(all(a));

    int ptr = (n+1)/2;
    ptr--;
    int optr = ptr;
    int ans = 0;
    while(a[ptr] == a[optr]) {
        ptr++;
        ans++;
        if(ptr == n)break;
    }

    cout << ans << nl;

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifdef yangster
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cout << fixed << setprecision(14);

    int t = 1;
    if (multiTest) cin >> t;
    for (int ii = 0; ii < t; ii++) {
        solve(ii);
    }
}