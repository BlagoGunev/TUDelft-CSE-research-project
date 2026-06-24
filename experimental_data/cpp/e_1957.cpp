#include <bits/stdc++.h>
using namespace std;

using ll = long long; 

template <typename T>
T inverse(T a, T m) {
    T u = 0, v = 1;
    while (a != 0) {
        T t = m / a;
        m -= t * a; swap(a, m);
        u -= t * v; swap(u, v);
    }
    assert(m == 1);
    return u;
}

template<class T>
T power(T a, long long b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

template <typename T, typename U> 
T normalize(T & _v, U MOD) { _v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
        if (_v < 0) _v += MOD; return _v; }

template <int MOD> struct Modular {
    int v; explicit operator int() const { return v; } 
    Modular():v(0) {}
    Modular(long long _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
        if (v < 0) v += MOD; }
    bool operator==(const Modular& o) const {
        return v == o.v; }
    friend bool operator!=(const Modular& a, const Modular& b) { 
        return !(a == b); }
    friend bool operator<(const Modular& a, const Modular& b) { 
        return a.v < b.v; }
     
    Modular& operator+=(const Modular& o) { 
        if ((v += o.v) >= MOD) v -= MOD; 
        return *this; }
    Modular& operator-=(const Modular& o) { 
        if ((v -= o.v) < 0) v += MOD; 
        return *this; }
    Modular& operator*=(const Modular& o) { 
        v = int((long long)v*o.v%MOD); return *this; }
    Modular& operator/=(const Modular& o) { return (*this) *= Modular(inverse(o.v, MOD)); }
        
    Modular operator-() const { return Modular(-v); }
    Modular& operator++() { return *this += 1; }
    Modular& operator--() { return *this -= 1; }
    friend Modular operator+(Modular a, const Modular& b) { return a += b; }
    friend Modular operator-(Modular a, const Modular& b) { return a -= b; }
    friend Modular operator*(Modular a, const Modular& b) { return a *= b; }
    friend Modular operator/(Modular a, const Modular& b) { return a /= b; }
};
 
// U == std::ostream? but done this way because of fastoutput
template <typename U, int T>
U& operator<<(U& stream, const Modular<T>& number) {
        return stream << number.v;
}
 
// U == std::istream? but done this way because of fastinput
template <typename U, int T>
U& operator>>(U& stream, Modular<T>& number) {
    int x;
    stream >> x;
    number.v = normalize(x, T); 
    return stream;
}

constexpr int md = 1000000007;
using Mint = Modular<md>;

vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);

Mint C(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    while ((int) fact.size() < n + 1) {
        fact.push_back(fact.back() * (int) fact.size());
        inv_fact.push_back(1 / fact.back());
    }
    return fact[n] * inv_fact[k] * inv_fact[n - k];
}

void prime_sieve(int _n, vector<int> & _primes, vector<bool> & _is_prime) {
    _primes.clear(); _is_prime = vector<bool>(_n + 1, true); 
    _is_prime[0] = _is_prime[1] = false; 
    for (int i = 2; i <= _n; ++i) {
        if (_is_prime[i]) _primes.push_back(i); 
        for (auto p: _primes) {
            if (i * p > _n) break; 
            _is_prime[i * p] = false; 
            if (i % p == 0) break; 
        }
    }
}   

ll calc(ll n, ll k) {
    if (k == 1) return 0; 

    ll res = 1; 
    ll cnt = 0; 
    for (ll i = n - k + 1; i <= n; ++i) {
        ll v = i; 
        while (v % k == 0) {
            cnt++; 
            v /= k; 
        }
        res = (res * v) % k; 
    }
    assert(cnt > 0); 
    if (cnt > 1) res = 0; 
    return res; 
}

void solve(int n) {

	Mint ans = 0; 

	for (int k = 1; k <= n; ++k) {
        cout << "c " << k << ": "; 
		Mint cur = 0; 
		for (int v = k; v <= n; ++v) {
			cout << calc(v, k) << ' '; 
		}
		cout << '\n';
	}

}

int N = 1000010; 
vector<int> primes; 
vector<bool> isprime; 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); 

    C(N, 0); 
	prime_sieve(N, primes, isprime); 

    vector<Mint> ans(N, Mint(0)); 
    vector<int> ctrb(N, 0); 

    vector<vector<int>> todo(N); 
    for (int p: primes) {
        for (int i = 2 * p; i < N; i += p) {
            todo[i].push_back(p); 
        }
    }  

    ans[1] = 0; 
    Mint tc = 0; 

    for (int n = 2; n < N; ++n) {
        if (isprime[n]) {
            ctrb[n] = n - 1; 
            tc += ctrb[n]; 
        } 
        for (auto x: todo[n]) {
            tc -= ctrb[x]; 
            ctrb[x] = (ctrb[x] - 1 + x) % x; 
            tc += ctrb[x]; 
        }
        // if (n <= 10) cout << "! " << n <<  ' ' << tc << '\n';

        ans[n] = ans[n - 1] + tc; 
        if ((n % 8) >= 4) ans[n] += 2; 
    }

    // solve(8); 


    int t; 
    cin >> t; 
    while (t--) {
        int q; 
        cin >> q; 
        cout << ans[q] << "\n";
    }

	return 0; 
}