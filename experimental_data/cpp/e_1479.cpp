//#pragma GCC optimize("O3")

#pragma GCC optimize("unroll-loops")

//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")



#include "bits/stdc++.h"



using namespace std;

using ll = long long;

using ld = long double;



#define rep(i, a, b) for (auto i{a}; i < (b); ++i)

#define per(i, a, b) for (auto i{b}; i-- > (a);)

#define all(x) begin(x), end(x)

#define rall(x) (x).rbegin(), (x).rend()

#define sz(x) static_cast<int>((x).size())



template <class T>

bool uin(T& a, const T& b) {

    return a > b ? a = b, true : false;

}

template <class T>

bool uax(T& a, const T& b) {

    return a < b ? a = b, true : false;

}



mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



constexpr int mod = 998244353;



int mul(ll x, int y) { return x * y % mod; }

void inc(int& x, int y) {

    x += y;

    if (x >= mod) x -= mod;

}

int add(int x, int y) { return x += y, x < mod ? x : x - mod; }



int inv(ll a) {

    ll res = 1;

    for (int b = mod - 2; b > 0; b >>= 1) {

        if (b & 1) res = res * a % mod;

        a = a * a % mod;

    }

    return res;

}



signed main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);



    int m;

    cin >> m;



    vector<int> a(m);

    for (auto& x : a) cin >> x;



    sort(all(a));



    const int n = accumulate(all(a), 0);



    struct frac {

        int num, den;

        frac operator+(frac a) { return {add(mul(a.num, den), mul(a.den, num)), mul(a.den, den)}; }

        operator int() { return mul(num, inv(den)); }

    };



    int ans = 0;



    frac f{0, 1}, g{mod - 2, 1};

    for (int x = 1, i = 0; x <= n; ++x) {

        f = f + g;



        g.num = mul(g.num, n + n - x);

        g.den = mul(g.den, n - x);



        while (i < m && a[i] == x) {

            inc(ans, f);

            ++i;

        }

    }

    ans -= f;

    if (ans < 0) ans += mod;



    cout << ans << '\n';

}