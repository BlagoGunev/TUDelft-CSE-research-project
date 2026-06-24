// Exported by Exporter.exe

// Included from E.cpp
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define MTP make_tuple
#define R Read
#define RD Read_Digit
#define RP Read_P
#define RL Read_Loop
#define RLD Read_Loop_Digit
#define RLP Read_Loop_P
#ifdef ONLINE_JUDGE
	#define Debug(x) ;
	#define Debugln(x) ;
	#define Debug_Array(n,x) ;
	#define Debugln_Array(n,x) ;
	#define NL ;
#else
	#define Debug(x) printf("%s :", (#x)), _Debug(x)
	#define Debugln(x) printf("%s :", (#x)), _Debugln(x)
	#define Debug_Array(n,x) printf("%s :", (#x)), _Debug_Array((n), (x))
	#define Debugln_Array(n,x) printf("%s :", (#x)), _Debugln_Array((n), (x))
	#define NL printf("\n")
#endif
typedef long long int ll;
typedef unsigned long long int ull;

constexpr int kN = int(2E1 + 10);
constexpr int kM = int(5E4 + 10);
constexpr int kMod = 998244353;
// constexpr int kMod = int(1E9 + 7);
// constexpr int kInf = 0x3f3f3f3f;
// constexpr ll kInf = 0x3f3f3f3f3f3f3f3f;
// constexpr double kPi = acos(-1);
// constexpr double kEps = 1E-9;


// Included from C:\Users\ianli\Desktop\CP\template\Various\Fast_IO\Fast_IO.cpp
// --- Get ---
static inline char Get_Raw_Char() {
	static char buf[1 << 16], *p = buf, *end = buf;
	if (p == end) {
		if ((end = buf + fread(buf, 1, 1 << 16, stdin)) == buf) return '\0';
		p = buf;
	}
	return *p++;
}

// --- Read ---
template <typename T> static inline void Read_P(T &n) {
	static_assert(is_integral<T>::value, "Read_P requires an integral type");
	char c;
	while (!isdigit(c = Get_Raw_Char())) ;
	n = int(c - '0');
	while (isdigit(c = Get_Raw_Char())) n = n * 10 + int(c - '0');
	return ;
}

template <typename T> static inline void Read(T &n) {
	static_assert(is_integral<T>::value, "Read requires an integral type");
	char c;
	bool neg = false;
	while (!isdigit(c = Get_Raw_Char())) if (c == '-') neg = true;
	n = int(c - '0');
	while (isdigit(c = Get_Raw_Char())) n = n * 10 + int(c - '0');
	if (neg) n = -n;
	return ;
}

template <typename T> static inline void Read_Digit(T &n) {
	static_assert(is_integral<T>::value, "Read_Digit requires an integral type");
	char c;
	while (!isdigit(c = Get_Raw_Char())) ;
	n = int(c - '0');
	return ;
}

// --- Read multiple ---
template <typename T, typename... Targs> static inline void Read(T &n, Targs&... Fargs) {Read(n); return Read(Fargs...);}
template <typename T, typename... Targs> static inline void Read_Digit(T &n, Targs&... Fargs) {Read_Digit(n); return Read_Digit(Fargs...);}
template <typename T, typename... Targs> static inline void Read_P(T &n, Targs&... Fargs) {Read_P(n); return Read_P(Fargs...);}

// --- Read Loop ---
template <typename T> static inline void Read_Loop_i(int i, T *a) {return Read(a[i]);}
template <typename T, typename... Targs> static inline void Read_Loop_i(int i, T *a, Targs*... Fargs) {Read(a[i]); return Read_Loop_i(i, Fargs...);}
template <typename... Targs> static inline void Read_Loop(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) Read_Loop_i(i, Fargs...);}

template <typename T> static inline void Read_Loop_Digit_i(int i, T *a) {return Read_Digit(a[i]);}
template <typename T, typename... Targs> static inline void Read_Loop_Digit_i(int i, T *a, Targs*... Fargs) {Read_Digit(a[i]); return Read_Loop_Digit_i(i, Fargs...);}
template <typename... Targs> static inline void Read_Loop_Digit(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) Read_Loop_Digit_i(i, Fargs...);}

template <typename T> static inline void Read_Loop_P_i(int i, T *a) {return Read_P(a[i]);}
template <typename T, typename... Targs> static inline void Read_Loop_P_i(int i, T *a, Targs*... Fargs) {Read_P(a[i]); return Read_Loop_P_i(i, Fargs...);}
template <typename... Targs> static inline void Read_Loop_P(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) Read_Loop_P_i(i, Fargs...);}

// --- Float ---
template <int mul, typename T> static inline void Read(T &n) {
	char c;
	bool neg = false;
	while (!isdigit(c = Get_Raw_Char())) if (c == '-') neg = true;
	n = int(c - '0');
	while (isdigit(c = Get_Raw_Char())) n = n * 10 + int(c - '0');
	
	int cnt = 0;

	if (c == '.') {
		while (isdigit(c = Get_Raw_Char())) {
			n = n * 10 + int(c - '0');
			cnt++;
		}
	}

	while (cnt++ < mul) n = n * 10;

	if (neg) n = -n;
	return ;
}

template <int mul, typename T> static inline void Read_P(T &n) {
	char c;
	while (!isdigit(c = Get_Raw_Char())) ;
	
	n = int(c - '0');
	while (isdigit(c = Get_Raw_Char())) n = n * 10 + int(c - '0');
	
	int cnt = 0;

	if (c == '.') {
		while (isdigit(c = Get_Raw_Char())) {
			n = n * 10 + int(c - '0');
			cnt++;
		}
	}

	while (cnt++ < mul) n = n * 10;
	return ;
}

template <int mul, typename T, typename... Targs> static inline void Read(T &n, Targs&... Fargs) {Read<mul>(n); return Read<mul>(Fargs...);}
template <int mul, typename T, typename... Targs> static inline void Read_P(T &n, Targs&... Fargs) {Read_P<mul>(n); return Read_P<mul>(Fargs...);}

// --- init ---
inline void IOS() {ios::sync_with_stdio(false); cin.tie(0); return ;}
inline void Freopen(const char *in, const char *out) {freopen(in, "r", stdin); freopen(out, "w", stdout); return ;}

// --- Output ---
template <typename T> void Print(T x) {
	if (x < 0) {
		printf("-");
		x = -x;
	}
	if (x == 0) printf("0");
	else {
		static int val[100];
		int idx = -1;
		while (x) {
			val[++idx] = x % 10;
			x /= 10;
		}
		while (idx >= 0) printf("%d", val[idx--]);
	}
} 
// End of C:\Users\ianli\Desktop\CP\template\Various\Fast_IO\Fast_IO.cpp

// Included from C:\Users\ianli\Desktop\CP\template\Various\Useful_Functions\Useful_Functions.cpp
template <typename T> inline void sort(vector<T> &v) {return sort(v.begin(), v.end());}
template <typename T> inline void sort_r(vector<T> &v) {return sort(v.begin(), v.end(), greater<T>());}

template <typename T> inline void reverse(vector<T> &v) {return reverse(v.begin(), v.end());}

template <typename T> inline void Merge(vector<T> &a, vector<T> &b, vector<T> &c) {
	if (c.size() < a.size() + b.size()) c.resize(a.size() + b.size());
	merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
	return ;
}
template <typename T> inline void Concatanate(vector<T> &a, vector<T> &b, vector<T> &c) {
	int a_size = int(a.size()), b_size = int(b.size());
	c.resize(a_size + b_size);
	for (int i = 0; i < a_size; i++) c[i] = a[i];
	for (int i = 0; i < b_size; i++) c[i + a_size] = b[i];
	return ;
}

template <typename T> inline void Discrete(vector<T> &v) {sort(v); v.resize(unique(v.begin(), v.end()) - v.begin()); return ;}

template <typename T> using PQ = priority_queue<T>;
template <typename T> using PQ_R = priority_queue<T, vector<T>, greater<T>>;

template <typename T> inline T ABS(T n) {return n >= 0 ? n : -n;}
template <typename T> __attribute__((target("bmi"))) inline T gcd(T a, T b) {
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	if (a == 0 || b == 0) return a + b;
	int n = __builtin_ctzll(a);
	int m = __builtin_ctzll(b);
	a >>= n;
	b >>= m;
	while (a != b) {
		int m = __builtin_ctzll(a - b);
		bool f = a > b;
		T c = f ? a : b;
		b = f ? b : a;
		a = (c - b) >> m;
	}
	return a << min(n, m);
}
template <typename T> inline T lcm(T a, T b) {return a * b / gcd(a, b);}
template <typename T, typename... Targs> inline T gcd(T a, T b, T c, Targs... args) {return gcd(a, gcd(b, c, args...));}
template <typename T, typename... Targs> inline T lcm(T a, T b, T c, Targs... args) {return lcm(a, lcm(b, c, args...));}
template <typename T, typename... Targs> inline T min(T a, T b, T c, Targs... args) {return min(a, min(b, c, args...));}
template <typename T, typename... Targs> inline T max(T a, T b, T c, Targs... args) {return max(a, max(b, c, args...));}
template <typename T, typename... Targs> inline void chmin(T &a, T b, Targs... args) {a = min(a, b, args...); return ;}
template <typename T, typename... Targs> inline void chmax(T &a, T b, Targs... args) {a = max(a, b, args...); return ;}

vector<int> Primes(int n) {
	// 2 ~ n
	vector<int> primes;
	vector<bool> isPrime(n + 1, true);

	primes.reserve(n / __lg(n));

	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) primes.push_back(i);
		for (int j : primes) {
			if (i * j > n) break;
			isPrime[i * j] = false;
			if (i % j == 0) break;
		}
	}
	return primes;
}

int mex(vector<int> vec) {
	int n = int(vec.size());
	vector<bool> have(n, false);
	for (int i : vec) if (i < n) have[i] = true;
	for (int i = 0; i < n; i++) if (!have[i]) return i;
	return n;
}

template <typename T> T Mdist(pair<T, T> lhs, pair<T, T> rhs) {return ABS(lhs.first - rhs.first) + ABS(lhs.second - rhs.second);}
// End of C:\Users\ianli\Desktop\CP\template\Various\Useful_Functions\Useful_Functions.cpp

// Included from C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.cpp
void _print(int x) {printf("%d", x);}
void _print(long long int x) {printf("%lld", x);}
void _print(double x) {printf("%lf", x);}
template <typename T> void _print(T x) {return x.out();}
template <typename T1, typename T2> void _print(pair<T1, T2> x) {printf("("); _print(x.first); printf(", "); _print(x.second); printf(")");}

template <typename T> void _Debug(T x) {_print(x); printf("\n");}
template <typename T> void _Debug(vector<T> v) {
	if (v.empty()) printf(" empty");
	else for (T i : v) printf(" "), _print(i); 
	printf("\n");
}

template <typename T1, typename T2, typename T3> void _Debug(priority_queue<T1, T2, T3> pq) {
	if (pq.empty()) printf(" empty");
	else {
		while (!pq.empty()) {
			printf(" ");
			_print(pq.top());
			pq.pop();
		}
	}
	printf("\n");
}

template <typename T> void _Debug(queue<T> q) {
	if (q.empty()) printf(" empty");
	else {
		while (!q.empty()) {
			printf(" ");
			_print(q.front());
			q.pop();
		}
	}
	printf("\n");
}

template <typename T> void _Debug(stack<T> st) {
	if (st.empty()) printf(" empty");
	else {
		while (!st.empty()) {
			printf(" ");
			_print(st.top());
			st.pop();
		}
	}
	printf("\n");
}

template <typename T> void _Debug(deque<T> dq) {
	if (dq.empty()) printf(" empty");
	else {
		while (!dq.empty()) {
			printf(" ");
			_print(dq.front());
			dq.pop_front();
		}
	}
	printf("\n");
}

template <typename T> void _Debugln(vector<T> v) {
	if (v.empty()) printf(" empty\n");
	else {
		for (T i : v) printf("\n"), _print(i); 
		printf("\n");
	}
}

template <typename T1, typename T2, typename T3> void _Debugln(priority_queue<T1, T2, T3> pq) {
	if (pq.empty()) printf(" empty");
	else {
		while (!pq.empty()) {
			printf("\n");
			_print(pq.top());
			pq.pop();
		}
	}
	printf("\n");
}

template <typename T> void _Debugln(queue<T> q) {
	if (q.empty()) printf(" empty");
	else {
		while (!q.empty()) {
			printf("\n");
			_print(q.front());
			q.pop();
		}
	}
	printf("\n");
}

template <typename T> void _Debugln(stack<T> st) {
	if (st.empty()) printf(" empty");
	else {
		while (!st.empty()) {
			printf("\n");
			_print(st.top());
			st.pop();
		}
	}
	printf("\n");
}

template <typename T> void _Debugln(deque<T> dq) {
	if (dq.empty()) printf(" empty");
	else {
		while (!dq.empty()) {
			printf("\n");
			_print(dq.front());
			dq.pop_front();
		}
	}
	printf("\n");
}

template <typename T> void _Debug_Array(int n, const T *x) {for (int i = 1; i <= n; i++) printf(" "), _print(x[i]); printf("\n");}
template <typename T> void _Debugln_Array(int n, const T *x) {printf("\n"); for (int i = 1; i <= n; i++) _print(x[i]), printf("\n");}
// End of C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.cpp

// Included from C:\Users\ianli\Desktop\CP\template\Math\Mod_Int\Mod_Int.cpp
template <typename T1, typename T2> T1 Pow(T1 a, T2 b) {
	T1 ans({1});
	while (b) {
		if (b & 1) ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}

template <int kMod> struct Mod_Int {
	static constexpr int Mod() {return kMod;}

	int val;
	Mod_Int() : val(0) {}
	template <typename T> constexpr Mod_Int(const T &x) {val = x;}

	Mod_Int inv() const {return Pow(*this, kMod - 2);} 

	Mod_Int operator -() const {
		if (val) return Mod_Int(kMod - val);
		else return Mod_Int(0);
	}

	Mod_Int operator + (const Mod_Int &x) const {
		Mod_Int ans(val + x.val);
		if (ans.val >= kMod) ans.val -= kMod;
		return ans;
	}
	Mod_Int operator - (const Mod_Int &x) const {
		Mod_Int ans(val - x.val);
		if (ans.val < 0) ans.val += kMod;
		return ans;
	}
	Mod_Int operator * (const Mod_Int &x) const {return Mod_Int(1LL * val * x.val % kMod);}
	Mod_Int operator / (const Mod_Int &x) const {return *this * x.inv();}
	Mod_Int operator ^ (const Mod_Int &x) const {return Pow(*this, x.val);}
	Mod_Int operator << (const int &x) const {return ((1LL * val) << x) % kMod;}

	Mod_Int operator += (const Mod_Int &x) {return *this = *this + x;}
	Mod_Int operator -= (const Mod_Int &x) {return *this = *this - x;}
	Mod_Int operator *= (const Mod_Int &x) {return *this = *this * x;}
	Mod_Int operator /= (const Mod_Int &x) {return *this = *this / x;}
	Mod_Int operator ^= (const Mod_Int &x) {return *this = Pow(*this, x.val);}
	Mod_Int operator <<= (const int &x) {return *this = *this << x;}

	Mod_Int operator ++(int) {
		val++;
		if (val >= kMod) val -= kMod;
		return *this;
	}
	Mod_Int operator --(int) {
		val--;
		if (val < 0) val += kMod;
		return *this;
	}

	bool operator < (const Mod_Int &x) const {return val < x.val;}
	bool operator > (const Mod_Int &x) const {return val > x.val;}
	bool operator <= (const Mod_Int &x) const {return val <= x.val;}
	bool operator >= (const Mod_Int &x) const {return val >= x.val;}
	bool operator == (const Mod_Int &x) const {return val == x.val;}
	bool operator != (const Mod_Int &x) const {return val != x.val;}

	void out() const {printf("%d", val);}
};

using Mint = Mod_Int<kMod>;

namespace Factorial {
	Mint *f, *inf;
	bool preprocessed_factorial;
	void Pre_Factorial(const int &sz) {
		if (preprocessed_factorial) return ;
		preprocessed_factorial = true;
		f = new Mint[sz + 1];
		inf = new Mint[sz + 1];
		f[0] = f[1] = inf[0] = inf[1] = 1;
		for (int i = 2; i <= sz; i++) f[i] = f[i - 1] * i;
		inf[sz] = f[sz].inv();
		for (int i = sz; i > 2; i--) inf[i - 1] = inf[i] * i;
		return ;
	}
	inline Mint P(const int &n, const int &m) {return f[n] * inf[m];}
	inline Mint C(const int &n, const int &m) {return f[n] * inf[m] * inf[n - m];}
	inline Mint H(const int &n, const int &m) {return f[n + m - 1] * inf[m] * inf[n - 1];}
	inline Mint Catalan(const int &n) {return f[n << 1] * inf[n] * inf[n + 1];}
}

namespace Factorial_No_Inf {
	Mint *f;
	void Pre_Factorial(const int &sz) {
		f = new Mint[sz + 1];
		f[0] = f[1] = 1;
		for (int i = 2; i <= sz; i++) f[i] = f[i - 1] * i;
		return ;
	}
	inline Mint P(const int &n, const int &m) {return f[n] / f[m];}
	inline Mint C(const int &n, const int &m) {return f[n] / (f[m] * f[n - m]);}
	inline Mint H(const int &n, const int &m) {return f[n + m - 1] / (f[m] * f[n - 1]);}
	inline Mint Catalan(const int &n) {return f[n << 1] / (f[n] * f[n + 1]);}
}

namespace Inverse {
	using namespace Factorial;
	Mint *inv;
	void Pre_Inverse(const int &sz) {
		inv = new Mint[sz + 1];
		inv[1] = 1;
		Pre_Factorial(sz);
		for (int i = 1; i <= sz; i++) inv[i] = f[i - 1] * inf[i];
		return ;
	}
};
// End of C:\Users\ianli\Desktop\CP\template\Math\Mod_Int\Mod_Int.cpp
using namespace Factorial;

int d[kN][kM];
int cnt[kN];

int main() {
	Pre_Factorial(kN);
	int n, m; RP(n, m);
	for (int i = 1; i <= n; i++) RLP(m, d[i]);

	Mint ans = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= n; j++) cnt[j] = 0;
		for (int j = 1; j <= n; j++) cnt[n + 1 - d[j][i]]++;

		ans++;
		if (!cnt[n]) {

			Mint tmp = inf[n];
			for (int j = n - 1, cur = 1; j >= 0; j--, cur++) {
				if (cnt[j] > cur) tmp = 0;
				else {
					tmp *= C(cur, cnt[j]) * f[cnt[j]];
					cur -= cnt[j];
				}
			}

			ans -= tmp;
		}
	}
	printf("%d\n", ans);
}
// End of E.cpp