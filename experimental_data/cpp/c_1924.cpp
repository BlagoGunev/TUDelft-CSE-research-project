#include <iostream>

#define ll long long

using namespace std;

const ll MOD = 999999893;


ll Pow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll Ni(ll a) {
    return Pow(a, MOD - 2);
}

//a+b*sqrt(2)
struct Sq2 {
    ll a = 0;
    ll b = 0;
    ll Mod() const {
        return ((a * a - b * b * 2) % MOD + MOD) % MOD;
    }
    Sq2 Gonge() const {
        return { a, (-b + MOD) % MOD };
    }
    Sq2 operator+(const Sq2& other) const {
        return { (a + other.a) % MOD, (b + other.b) % MOD };
    }
    Sq2 operator-(const Sq2& other) const {
        return { (a - other.a + MOD) % MOD, (b - other.b + MOD) % MOD };
    }
    Sq2 operator*(const Sq2& other) const {
        return { (a * other.a + b * other.b * 2) % MOD, (a * other.b + b * other.a) % MOD };
    }
    Sq2 operator/(const Sq2& other) const {
        ll divide = Ni(other.Mod());
        // cout << "divide=" << divide << endl;
        Sq2 dividend = *this * other.Gonge();
        return { dividend.a * divide % MOD, dividend.b * divide % MOD };
    }
};


int T;

int n;

Sq2 M;
Sq2 V;
Sq2 res;

void Solve() {
    cin >> n;
    ll adda = (Pow(2, n / 2 + 1) - 2 + MOD) % MOD;
    ll addb = (Pow(2, (n - 1) / 2 + 1) - 2 + MOD) % MOD;
    M.a = adda;
    M.b = addb;
    V.a = adda;
    V.b = addb + 2;
    // cout << M.a << ',' << M.b << ',' << V.a << ',' << V.b << endl;
    res = M / V;
    // cout << res.a << ',' << res.b << endl;
    cout << res.b << endl;
}

int main() {
    ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}