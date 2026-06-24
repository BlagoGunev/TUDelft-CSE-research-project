#include <bits/stdc++.h>



using namespace std;

typedef long long ll;

typedef pair<int, int> PII;

constexpr int P = 1e9 + 7;

int norm(int x) {

    if (x < 0) x += P;

    if (x >= P) x -= P;

    return x;

}



template <typename T>

T power(T a, int b) {

    T res = 1;

    while (b) {

        if (b & 1) res = res * a;

        b >>= 1;

        a = a * a;

    }

    return res;

}



struct Z {

    int x;

    Z(int x = 0) : x(norm(x)) {}

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

        x = ll(x) * rhs.x % P;

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

    friend std::ostream &operator<<(std::ostream &os, const Z &a) {

        return os << a.val();

    }

};



int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    

    int n;

    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {

        cin >> a[i];

    }

    ll sum = accumulate(a.begin(), a.end(), 0ll);

    if (sum % n != 0) {

        cout << 0 << '\n';

    } else {

        int avg = sum / n;

        int equ = 0, source = 0, sink = 0;

        map<int, int> cnt;

        for (int i = 0; i < n; i++) {

            if (a[i] < avg) sink++;

            else if (a[i] > avg) source++;

            else equ++;

            if (a[i] != avg) {

                cnt[a[i]]++;

            }

        }

        vector<Z> fac(n + 1), invfac(n + 1);

        fac[0] = 1;

        for (int i = 1; i <= n; i++) {

            fac[i] = fac[i - 1] * i;

        }

        invfac[n] = fac[n].inv();

        for (int i = n; i >= 1; i--) {

            invfac[i - 1] = invfac[i] * i;

        }

        Z ans = 1;

        if (sink == 1) {

            ans *= fac[source + 1];

        } else if (source == 1) {

            ans *= fac[sink + 1];

        } else if (source >= 2 and sink >= 2) {

            ans *= fac[source] * fac[sink] * 2;

        }

        ans *= fac[n] * invfac[n - equ] * invfac[equ];

        for (auto [x, y] : cnt) {

            ans *= invfac[y];

        }

        cout << ans << '\n';

    }

    return 0;

}