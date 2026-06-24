#include <bits/stdc++.h>

#pragma optimize ("g",on)

#pragma GCC optimize ("inline")

#pragma GCC optimize ("Ofast")

#pragma GCC optimize ("unroll-loops")

#pragma GCC optimize ("03")

#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx2,mmx,fma,avx,tune=native")

#pragma comment(linker, "/stack:200000000")



#define pb push_back

#define pob pop_back

#define pii pair <int, int>

#define pll pair <long long, long long>

#define pld pair <long double, long double>

#define ll long long

#define ld long double

#define int long long // HERE CAN BE WA/RE/MLE/TLE

#define x first

#define y second

#define all(v) v.begin(),v.end()

#define sz(s) s.size()

#define skip continue

#define div kruk



using namespace std;



const int N = 4e6 + 7;

const int MAXA = 2750131;

const int WN = 1e5 + 7;

const int inf = 1e9 + 7;

const int INF = 1e18;

const int MOD = 998244353;

const double eps = 1e-6;

const ld pi = 3.1415926535;







int n, mod;

int add(int x, int y) {

    x += y;

    if (x >= mod)x -= mod;

    return x;

}

int sub(int x, int y) {

    x -= y;

    if (x < 0)x += mod;

    return x;

}

int dp[N], suf[N];

void solve() {

    cin >> n >> mod;

    dp[n] = 1, suf[n] = 1;

    for (int i = n - 1;i >= 1;i--) {

        dp[i] = add(dp[i], suf[i + 1]);

        for (int mul = 2;;mul++) {

            int l = mul * i, r = (i + 1) * mul;

            if (l > n)break;

            dp[i] = add(dp[i], sub(suf[l], suf[min(r, n + 1)]));

        }

        suf[i] = add(suf[i + 1], dp[i]);

    }

    cout << dp[1];

}

signed main() {

    //srand(time(NULL));

    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    //freopen("headmasters.in", "r", stdin);

    //freopen("headmasters.out", "w", stdout);

    int t;

    t = 1;

    //cin >> t;

    while (t--)solve();

  return 0;

}