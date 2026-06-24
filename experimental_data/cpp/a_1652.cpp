#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define F first
#define S second
#define PB push_back
#define debug(x) cerr << #x << " : " << x << "\n"

using namespace std;
ll t_, n, a, b, c;
const ll MOD = 1e9 + 7;

ll gcd(ll a_, ll b_) {
    if (b_ == 0) {
        return a_;
    }
    if (b_ == 1) {
        return 1;
    }
    return gcd(b_, a_ % b_);
}

ll binpow(ll a_, ll b_) {
    if (b_ == 0) {
        return 1;
    }
    if (b_ == 1) {
        return a_;
    }
    if (b_ % 2 == 0) {
        return binpow(((a_ * a_) % MOD + MOD) % MOD, b_ / 2);
    }
    return ((binpow(((a_ * a_) % MOD + MOD) % MOD, b_ / 2) * a_) % MOD + MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t_;
    while (t_--) {
        cin >> n;
        a = 0;
        b = 0;
        for (int i = 0; i < n; i++) {
           cin >> c;
           if (c > a) {
               b = a;
               a = c;
           }
           else if (c > b) {
               b = c;
           }
        }
        cout << a + b << "\n";
    }
}