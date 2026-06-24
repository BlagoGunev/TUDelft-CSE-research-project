#include<bits/stdc++.h>
using namespace std;
using s64 = long long;
const s64 infl = 1e18;
const int inf = 2e9;
const int Mod = 998244353;
int mynorm(int x) {
    if (x < 0) {
        x += Mod;
    }
    if (x >= Mod) {
        x -= Mod;
    }
    return x;
}
template<class T>
T power(T a, s64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(mynorm(x)) {}
    Z(s64 x) : x(mynorm(x % Mod)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(mynorm(Mod - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, Mod - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = s64(x) * rhs.x % Mod;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = mynorm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = mynorm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Z &a) {
        s64 v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
};
constexpr int MN = 2e5 + 5;
int n, p[MN], a[MN], fa[MN];
vector<int> go[MN];
vector<s64> dp[MN];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        go[i].clear();
        dp[i].clear();
    }
    for(int i = 2; i <= n; i++) {
        cin >> p[i];
        go[p[i]].push_back(i);
    }
    s64 ans = 0;
    for(int i = n; i >= 1; i--) {
        if(!go[i].empty()) {
            int mh = n;
            s64 now = 0;
            for(int j : go[i]) {
                mh = min(mh, (int)dp[j].size());
                now += a[j];
            }
            dp[i].resize(mh + 1, 0);
            for(int j : go[i]) {
                for(int k = 0; k < mh; k++) {
                    dp[i][k + 1] += dp[j][k];
                }
            }
            now -= a[i];
            for(int j = 1; j <= mh && now < 0; j++) {
                s64 tmp = min(-now, dp[i][j]);
                dp[i][j] -= tmp;
                now += tmp;
                ans += (s64)tmp * j;
            }
            if(now < 0) {
                ans += (s64)-now * (mh + 1);
                now = 0;
            }
            dp[i][0] = now;
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    int TT = 1;
    cin >> TT;
    for( ;TT--; ) {
        solve();
    }
}