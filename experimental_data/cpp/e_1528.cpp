#include <bits/stdc++.h>

using namespace std;



using i64 = long long;



template <int MOD>

struct Modint {

    static constexpr int P = MOD;



private:

    int v;



    static int minv(int a, int m) {

        a %= m;

        assert(a);

        return a == 1 ? 1 : m - 1LL * minv(m, a) * m / a;

    }



public:

    Modint() : v(0) {}

    Modint(i64 v_) : v(v_ % P) {

        if (v < 0) v += P;

    }

    explicit operator int() const { return v; }

    friend ostream& operator<<(ostream& out, const Modint& n) {

        return out << int(n);

    }

    friend istream& operator>>(istream& in, Modint& n) {

        i64 v;

        in >> v;

        n = Modint(v);

        return in;

    }

    friend string to_string(Modint a) {

        return to_string(int(a));

    }



    friend bool operator==(const Modint& a, const Modint& b) {

        return a.v == b.v;

    }

    friend bool operator!=(const Modint& a, const Modint& b) {

        return a.v != b.v;

    }



    Modint inv() const {

        Modint res;

        res.v = minv(v, P);

        return res;

    }



    Modint operator-() const {

        Modint res;

        res.v = v ? P - v : 0;

        return res;

    }



    Modint& operator++() {

        v++;

        if (v == P) v = 0;

        return *this;

    }

    Modint& operator--() {

        if (v == 0) v = P;

        v--;

        return *this;

    }

    Modint& operator+=(const Modint& o) {

        v -= P - o.v;

        v = (v < 0) ? v + P : v;

        return *this;

    }

    Modint& operator-=(const Modint& o) {

        v -= o.v;

        v = (v < 0) ? v + P : v;

        return *this;

    }

    Modint& operator*=(const Modint& o) {

        v = 1LL * v * o.v % P;

        return *this;

    }

    Modint& operator/=(const Modint& o) { return *this *= o.inv(); }



    friend Modint operator++(Modint& a, int) {

        Modint r = a;

        ++a;

        return r;

    }

    friend Modint operator--(Modint& a, int) {

        Modint r = a;

        --a;

        return r;

    }



    friend Modint operator+(const Modint& a, const Modint& b) {

        return Modint(a) += b;

    }

    friend Modint operator-(const Modint& a, const Modint& b) {

        return Modint(a) -= b;

    }

    friend Modint operator*(const Modint& a, const Modint& b) {

        return Modint(a) *= b;

    }

    friend Modint operator/(const Modint& a, const Modint& b) {

        return Modint(a) /= b;

    }

    

    Modint qpow(i64 p) {

        Modint res = 1, x = v;

        while (p > 0) {

            if (p & 1) res *= x;

            x *= x;

            p >>= 1;

        }

        return res;

    }

};



constexpr int P = 998244353;

using Mint = Modint<P>;



int main() {

    cin.tie(nullptr)->sync_with_stdio(false);



#ifdef LOCAL

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif



    auto solve = [&]() {

        int n;

        cin >> n;



        vector<Mint> f(n + 1), pf(n + 1);

        f[0] = pf[0] = 1;

        const Mint i2 = (P + 1) / 2, i6 = (P + 1) / 6;



        auto f2 = [&](Mint x) {

            return x * (x + 1) * i2;

        };

        auto f3 = [&](Mint x) {

            return x * (x + 1) * (x + 2) * i6;

        };



        for (int i = 1; i <= n; i++) {

            f[i] = f[i - 1] + f[i - 1] * (i == 1 ? 0 : pf[i - 2]) + f2(f[i - 1]);

            pf[i] = pf[i - 1] + f[i];

        }



        Mint ans = 2 * (f[n] + f[n - 1] * f2(n == 1 ? 0 : pf[n - 2]) + f2(f[n - 1]) * (n == 1 ? 0 : pf[n - 2]) + f3(f[n - 1])) - 1;



        for (int i = 1; i < n; i++) {

            ans += (f[i] - f[i - 1]) * (f[n - 1 - i] - 1);

        }



        cout << ans << '\n';

    };

    

    solve();

    

    return 0;

}