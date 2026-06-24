#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(...)
#endif
 
void __print(int32_t x) {cerr << x;}
void __print(int64_t x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(string x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T>void __print(complex<T> x) {cerr << '{'; __print(x.real()); cerr << ','; __print(x.imag()); cerr << '}';}
 
template<typename T>
void __print(const T &x);
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto it = x.begin() ; it != x.end() ; it++) cerr << (f++ ? "," : ""), __print(*it); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

namespace mint_ns {
template<auto P>
struct Modular {
    using value_type = decltype(P);
    value_type value;
 
    Modular(long long k = 0) : value(norm(k)) {}
 
    friend Modular<P>& operator += (      Modular<P>& n, const Modular<P>& m) { n.value += m.value; if (n.value >= P) n.value -= P; return n; }
    friend Modular<P>  operator +  (const Modular<P>& n, const Modular<P>& m) { Modular<P> r = n; return r += m; }
 
    friend Modular<P>& operator -= (      Modular<P>& n, const Modular<P>& m) { n.value -= m.value; if (n.value < 0)  n.value += P; return n; }
    friend Modular<P>  operator -  (const Modular<P>& n, const Modular<P>& m) { Modular<P> r = n; return r -= m; }
    friend Modular<P>  operator -  (const Modular<P>& n)                      { return Modular<P>(-n.value); }
 
    friend Modular<P>& operator *= (      Modular<P>& n, const Modular<P>& m) { n.value = n.value * 1ll * m.value % P; return n; }
    friend Modular<P>  operator *  (const Modular<P>& n, const Modular<P>& m) { Modular<P> r = n; return r *= m; }
 
    friend Modular<P>& operator /= (      Modular<P>& n, const Modular<P>& m) { return n *= m.inv(); }
    friend Modular<P>  operator /  (const Modular<P>& n, const Modular<P>& m) { Modular<P> r = n; return r /= m; }
 
    Modular<P>& operator ++ (   ) { return *this += 1; }
    Modular<P>& operator -- (   ) { return *this -= 1; }
    Modular<P>  operator ++ (int) { Modular<P> r = *this; *this += 1; return r; }
    Modular<P>  operator -- (int) { Modular<P> r = *this; *this -= 1; return r; }
 
    friend bool operator == (const Modular<P>& n, const Modular<P>& m) { return n.value == m.value; }
    friend bool operator != (const Modular<P>& n, const Modular<P>& m) { return n.value != m.value; }
 
    explicit    operator       int() const { return value; }
    explicit    operator      bool() const { return value; }
    explicit    operator long long() const { return value; }
 
    constexpr static value_type mod()      { return     P; }
 
    value_type norm(long long k) {
        if (!(-P <= k && k < P)) k %= P;
        if (k < 0) k += P;
        return k;
    }
 
    Modular<P> inv() const {
        value_type a = value, b = P, x = 0, y = 1;
        while (a != 0) { value_type k = b / a; b -= k * a; x -= k * y; swap(a, b); swap(x, y); }
        return Modular<P>(x);
    }
 
    friend void __print(Modular<P> v) {
        cerr << v.value;
    }
};
template<auto P> Modular<P> pow(Modular<P> m, long long p) {
    Modular<P> r(1);
    while (p) {
        if (p & 1) r *= m;
        m *= m;
        p >>= 1;
    }
    return r;
}
 
template<auto P> ostream& operator << (ostream& o, const Modular<P>& m) { return o << m.value; }
template<auto P> istream& operator >> (istream& i,       Modular<P>& m) { long long k; i >> k; m.value = m.norm(k); return i; }
template<auto P> string   to_string(const Modular<P>& m) { return to_string(m.value); }
 
}
constexpr int mod = 998244353;
using mod_int = mint_ns::Modular<mod>;

struct Comb {
    int n;
    vector<mod_int> _fac, _invfac, _inv;
    Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
    Comb(int n) : Comb() { init(n); }
    void init(int m) {
        m = min(m, mod - 1);
        if (m <= n) return;
        _fac.resize(m + 1); _invfac.resize(m + 1); _inv.resize(m + 1);
        for (int i = n + 1; i <= m; i++) _fac[i] = _fac[i - 1] * i;
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) _invfac[i - 1] = _invfac[i] * i, _inv[i] = _invfac[i] * _fac[i - 1];
        n = m;
    }
    mod_int fac(int m) { if (m > n) init(2 * m); return _fac[m]; }
    mod_int invfac(int m) { if (m > n) init(2 * m); return _invfac[m]; }
    mod_int inv(int m) { if (m > n) init(2 * m); return _inv[m]; }
    mod_int ncr(int n, int r) { if (n < r || r < 0) return 0; return fac(n) * invfac(r) * invfac(n - r); }
	mod_int place(int n, int r) { return ncr(n + r - 1, r - 1); } // stars and bars : x1 + x2 - - - xr = n
} comb;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	auto __solve_testcase = [&](int test) {
		int N;	cin >> N;
		vector<int> cnt(2 * N + 1);
		for(int i = 0 ; i < N ; ++i) {
			int f;	cin >> f;
			cnt[f + N]++;
		}

		auto C = cnt;

		auto solve = [&](int f, int b, vector<int> cnt) -> mod_int {
			dbg(f, b);
			if(!cnt[f] || !cnt[b])	return 0;
			int first = 0, last = 2 * N;
			while(cnt[first] == 0)	++first;
			while(cnt[last] == 0)	--last;


			mod_int ans = 1;
			for(int j = last ; j > f ; --j) {
				if(j <= b)	--cnt[j];
				if(cnt[j] < 0)	return 0;
				ans *= comb.ncr(cnt[j - 1] - 1, cnt[j]);
				cnt[j - 1] -= cnt[j];
			}
			for(int j = first ; j < f ; ++j) {
				if(j >= b)	--cnt[j];
				if(cnt[j] < 0)	return 0;
				ans *= comb.ncr(cnt[j + 1] - 1, cnt[j]);
				cnt[j + 1] -= cnt[j];
			}
			if(cnt[f] > 2)	return 0;
			return ans;
		};

		mod_int ans = 0;
		for(int i = 2 * N ; i >= 0 ; --i) if(((i + 3 * N) ^ N ^ 1) & 1) if(cnt[i]) {
			ans += solve(N - 1, i, cnt) + solve(N + 1, i, cnt);
		}
		cout << ans << '\n';
	};
	
	int NumTest = 1;
	cin >> NumTest;
	for(int testno = 1; testno <= NumTest ; ++testno) {
		__solve_testcase(testno);
	}
	
	return 0;
}