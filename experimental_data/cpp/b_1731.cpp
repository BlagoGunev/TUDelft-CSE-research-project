#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

#define all(v) (v).begin(), (v).end()

#define popcountll(x) __builtin_popcountll(x)

#define pb push_back

#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

#ifdef Liucj_2022

#include "../Liucj_2022/debug.h"

#else

#define LOG(...)

#endif // Liucj_2022



// 1*1 1*2 2*2 2*3 3*3

// 1*3 2*5 3*3 = 22



// 1*1 1*2 2*2 2*3 3*3 3*4 4*4

const int mod = 1e9 + 7;

template<const int T>

struct ModInt {

    const static int mod = T;

    int x;

    ModInt(int x = 0) : x(x % mod) {}

    int val() { return x; }

    ModInt operator + (const ModInt &a) const { int x0 = x + a.x; return ModInt(x0 < mod ? x0 : x0 - mod); }

    ModInt operator - (const ModInt &a) const { int x0 = x - a.x; return ModInt(x0 < 0 ? x0 + mod : x0); }

    ModInt operator * (const ModInt &a) const { return ModInt(1LL * x * a.x % mod); }

    ModInt operator / (const ModInt &a) const { return *this * a.inv(); }

    void operator += (const ModInt &a) { x += a.x; if (x >= mod) x -= mod; }

    void operator -= (const ModInt &a) { x -= a.x; if (x < 0) x += mod; }

    void operator *= (const ModInt &a) { x = 1LL * x * a.x % mod; }

    void operator /= (const ModInt &a) { *this = *this / a; }

    friend ostream &operator << (ostream &os, const ModInt &a) { return os << a.x;}

    friend istream &operator >> (istream &os, const ModInt &a) { int v; os >> v; a = ModInt(v); return os;}

    

    ModInt pow(int n) const {

        ModInt res(1), mul(x);

        while(n) {

            if (n & 1) res *= mul;

            mul *= mul;

            n >>= 1;

        }

        return res;

    }

    

    ModInt inv() const {

        int a = x, b = mod, u = 1, v = 0;

        while (b) {

            int t = a / b;

            a -= t * b; swap(a, b);

            u -= t * v; swap(u, v);

        }

        if (u < 0) u += mod;

        return u;

    }

};

using mint = ModInt<mod>;



void solve() {

    int n;  cin >> n;

    cout << (mint)n * (n + 1) * (4 * n - 1) / 6 * 2022 << endl;

}



signed main() {

    ios::sync_with_stdio(false), cin.tie(0);

    #ifdef Liucj_2022

freopen("sample.in", "r", stdin);	   freopen("sample.out", "w", stdout);

    #endif

    vector<int> v(1, 1);

    for (int i = 2, cs = 1; i <= 10; ++ i) {

        cs += i * i + (i - 1) * i;

        v.pb(cs);

    } LOG(v)

    int tt = 1;

    cin >> tt;

    while (tt -- ) solve();

    return 0;

}