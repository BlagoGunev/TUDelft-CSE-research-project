#pragma GCC optimize("O3")

#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>



#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using namespace __gnu_pbds;



template <class T>

using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// order_of_key (val): returns the no. of values less than val

// find_by_order (k): returns the kth largest element.(0-based)

#define ll long long

#define int ll

#define pb push_back

#define lb lower_bound

#define ub upper_bound

#define fs first

#define ss second

#define loop(i, k, n) for (ll i = k; i < n; i++)

#define vvpi vector<vector<pair<ll, ll>>>

typedef vector<ll> vi;

typedef pair<ll, ll> pi;

typedef vector<vi> vii;

typedef vector<vii> viii;

#define vpi vector<pi>

#define MOD 1000000007

#define MAX 10000001

#define dim 200005  // CHANGE THIS WHILE SUBMITTING

#define Z 11

#define PRIME 998244353

#define ld long double

#define PI (ld)3.141592653589793

#define all(v) v.begin(), v.end()

#define INF 1000000000000000000



#define lc(n) 2 * n

#define rc(n) 2 * n + 1



ll pwr(ll a, ll b) {

    a %= MOD;

    ll res = 1;

    while (b > 0) {

        if (b & 1) res = res * a % MOD;

        a = a * a % MOD;

        b >>= 1;

    }

    return res;

}

ll MOD_mul(ll a, ll b) {

    a = a % MOD;

    b = b % MOD;

    return (((a * b) % MOD) + MOD) % MOD;

}



template <typename Type>

istream &operator>>(istream &in, vector<Type> &vec) {

    ll n = vec.size();

    for (int i = 0; i < n; i++)

        in >> vec[i];

    return in;

}

template <typename Type>

ostream &operator<<(ostream &out, vector<Type> &vec) {

    for (auto val : vec)

        out << val << " ";

    out << endl;

    return out;

}

int inf = 1e16;



const int mxn = 2e5 + 2;

vi fac, invfac;



void prec() {

    fac = vi(mxn);

    invfac = vi(mxn);

    fac[0] = 1;

    for (int i = 1; i < mxn; i++) {

        fac[i] = MOD_mul(fac[i - 1], i);

    }

    for (int i = 0; i < mxn; i++) {

        invfac[i] = pwr(fac[i], MOD - 2);

    }

}



int ncr(int i, int j) {

    if (i < j) return 0;

    return MOD_mul(fac[i], MOD_mul(invfac[j], invfac[i - j]));

}



int n;

vi a;



int rec(vi &a, int which) {

    if (a.size() <= 1 or which < 0) return 0LL;

    vi b[2];

    for (auto &x : a) b[(x >> which) & 1LL].pb(x);

    return min(rec(b[0], which - 1) + max((int)b[1].size() - 1, 0LL), rec(b[1], which - 1) + max((int)b[0].size() - 1, 0LL));

}



void solve() {

    cin >> n;

    a = vi(n);

    cin >> a;

    cout << rec(a, 30) << "\n";

}



signed main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    //  freopen("input.txt", "r", stdin);

    //  freopen("output.txt", "w", stdout);

    int totalTests = 1;

    // cin >> totalTests;

    // prec();

    for (int testNo = 1; testNo <= totalTests; testNo++) {

        // cout << "Case #" << testNo << ": ";

        solve();

    }

    return 0;

}