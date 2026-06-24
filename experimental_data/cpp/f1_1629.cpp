#include <bits/stdc++.h>



constexpr int P = 1000000007;

using i64 = long long;

// assume -P <= x < 2P

int norm(int x) {

    if (x < 0) {

        x += P;

    }

    if (x >= P) {

        x -= P;

    }

    return x;

}

template<class T>

T power(T a, i64 b) {

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

    Z(int x = 0) : x(norm(x)) {}

    Z(i64 x) : x(norm(x % P)) {}

    int val() const {

        return x;

    }

    Z operator-() const {

        return Z(norm(P - x));

    }

    Z inv() const {

        assert(x != 0);

        return power(*this, P - 2);

    }

    Z &operator*=(const Z &rhs) {

        x = i64(x) * rhs.x % P;

        return *this;

    }

    Z &operator+=(const Z &rhs) {

        x = norm(x + rhs.x);

        return *this;

    }

    Z &operator-=(const Z &rhs) {

        x = norm(x - rhs.x);

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

        i64 v;

        is >> v;

        a = Z(v);

        return is;

    }

};



std::vector<Z> fac(2001), inv(2001);



void solve() {

    int n, m, k;

    std::cin >> n >> m >> k;

    n -= m;



    Z ans;

    if (n == 0) {

        ans = Z(m) * k;

    } else if (m == 0) {

        ans = 0;

    } else {

        Z p = 1;

        for (int i = 1; i <= m; i++) {

            p *= 2;

            ans += i * p * fac[n + m - i - 1] * inv[n - 1] * inv[m - i];

        }

        ans /= power(Z(2), n + m);

        ans *= k;

    }



    std::cout << ans.val() << "\n";

}



int main() {

    std::ios::sync_with_stdio(false);

    std::cin.tie(nullptr);



    fac[0] = 1;

    for (int i = 1; i <= 2000; i++) {

        fac[i] = fac[i - 1] * i;

    }

    inv[2000] = fac[2000].inv();

    for (int i = 2000; i > 0; i--) {

        inv[i - 1] = inv[i] * i;

    }



    int t;

    std::cin >> t;



    while (t--) {

        solve();

    }



    return 0;

}