#include <bits/stdc++.h>



#ifdef LOCAL

#include "debug.h"

#else

#define debug(x...) 228

#endif



using namespace std;



typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;



#define fi first

#define se second



const int inf = int(1e9) + 1;

const ll infll = ll(1e18) + 1;

const int mod = 998244353;//int(1e9) + 7;

mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());



template<typename T1, typename T2>

bool chmin(T1 &a, T2 b) {

    if (a > b) return a = b, true;

    return false;

}

template<typename T1, typename T2>

bool chmax(T1 &a, T2 b) {

    if (a < b) return a = b, true;

    return false;

}

struct mint{

    int v;

    mint(){

        v = 0;

    }

    template<typename  T>

    mint(T _v){

        if (_v < mod && _v >= 0){

            v = _v;

        }

        else{

            v = (_v % mod + mod) % mod;

        }

    }

    friend bool operator == (const mint &a, const mint &b){

        return a.v == b.v;

    }

    friend bool operator != (const mint &a, const mint &b){

        return !(a == b);

    }

    friend bool operator < (const mint &a, const mint &b){

        return a.v < b.v;

    }

    friend bool operator >(const mint &a, const mint &b){

        return a.v > b.v;

    }

    template<typename  T>

    friend mint pow(mint a, T b){

        mint ans = 1;

        while (b){

            if (b & 1){

                ans *= a;

            }

            a *= a;

            b >>= 1;

        }

        return ans;

    }

    friend mint inv(const mint &a){

        return pow(a, mod - 2);

    }

    mint& operator += (const mint &b){

        if ((v += b.v) >= mod){

            v -= mod;

        }

        return *this;

    }

    mint& operator -=(const mint &b){

        if ((v -= b.v) < 0){

            v += mod;

        }

        return *this;

    }

    mint& operator *= (const mint &b){

        v = (1ll * v * b.v) % mod;

        return *this;

    }

    mint& operator /= (const mint &b){

        return (*this) *= inv(b);

    }

    mint operator -() const{

        return mint(-v);

    }

    mint& operator++(){

        if ((v++) >= mod){

            v -= mod;

        }

        return *this;

    }

    mint& operator--(){

        if ((v--) < 0){

            v += mod;

        }

        return *this;

    }

    friend mint operator +(mint a, const mint& b){

        return a += b;

    }

    friend mint operator -(mint a, const mint& b){

        return a -= b;

    }

    friend mint operator *(mint a, const mint &b){

        return a *= b;

    }

    friend mint operator /(mint a, const mint &b){

        return a /= b;

    }

    friend ostream& operator << (ostream& out, const mint &a){

        out << a.v;

        return out;

    }

    friend istream& operator >> (istream& inp, mint &a){

        inp >> a.v;

        return inp;

    }

};

vector<mint> fact, inv_fact;

void pre_fact(int n){

    fact.reserve(n + 1), inv_fact.reserve(n + 1);

    fact.resize(n + 1), inv_fact.resize(n + 1);

    fact[0] = 1, inv_fact[0] = 1;

    for (int i = 1; i <= n; i++){

        fact[i] = fact[i - 1] * i;

    }

    inv_fact[n] = inv(fact[n]);

    for (int i = n - 1; i >= 1; i--){

        inv_fact[i] = inv_fact[i + 1] * (i + 1);

    }

}

mint choose(int n, int k){

    if (k < 0 || n < k){

        return 0;

    }

    return fact[n] * inv_fact[k] * inv_fact[n - k];

}



void solve_case() {

    int n, m;

    cin >> n >> m;

    if (m > n) {

        cout << 0 << "\n";

        return;

    }

    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> ord(n);

    iota(ord.begin(), ord.end(), 0);

    sort(ord.begin(), ord.end(), [&](int left, int right){

        return a[left] < a[right];

    });

    set<int> all(a.begin(), a.end());

    for (int i : b) {

        if (!all.count(i)) {

            cout << 0 << "\n";

            return;

        }

    }

    b.push_back(inf);

    vector<int> l(m), r(m);

    int i = 0, j = 0;

    while (i < n) {

        if (a[ord[i]] != b[j]) {

            cout << 0 << '\n';

            return;

        }

        int ni = i;

        while (ni + 1 < n && a[ord[ni + 1]] < b[j + 1]) ni++;

        for (int x = i; x <= ni; x++) {

            if (a[ord[x]] == b[j]) chmax(l[j], ord[x]);

            chmax(r[j], ord[x]);

        }

        i = ni + 1;

        j++;

    }

    mint ans = 1;

    for (i = 1; i < m; i++) {

        if (l[i] < r[i - 1]) {

            cout << 0 << '\n';

            return;

        }

        ans *= l[i] - r[i - 1];

    }

    cout << ans << '\n';

}



int main() {

    ios::sync_with_stdio(false);

    cin.tie(0), cout.tie(0);

#ifdef LOCAL

    freopen("inputik.txt", "r", stdin);

    clock_t tStart = clock();

#endif

    int T = 1;

    while (T--) {

        solve_case();

    }

#ifdef LOCAL

    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);

#endif

}