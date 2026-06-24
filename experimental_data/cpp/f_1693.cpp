#ifndef LOCAL
#define NDEBUG
#endif

#include <bits/stdc++.h>
using namespace std;

#define  FILENAME "test"
#define     INPUT FILENAME".in"
#define    OUTPUT FILENAME".out"
#define XTREME_IO

const int PRECISION = 12;
const int BUFFER_SIZE = 1 << 20;
const double eps = 1e-9;

// utilities {{{1
#define fi first
#define se second
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define ppb pop_back
#define BE(x) (x).begin(), (x).end()
#define y1 ___y1
#define max mymax
#define min mymin
#define FOR(i, l, r) for (int i = (l), i##end = (r); i <= i##end; i++)
#define ROF(i, r, l) for (int i = (r), i##end = (l); i >= i##end; i--)
#define SON(i, u) for (int i = head[u]; i; i = e[i].nxt)

using si = int;
using ui = unsigned;
using ll = long long;
using ul = unsigned long long;
using l3 = __int128_t;
using u3 = __uint128_t;
using db = double;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;

#define mmap multimap
#define umap unordered_map
#define ummap unordered_multimap
#define mset multiset
#define uset unordered_set
#define umset unordered_multiset

const db finf = 1e121;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }
auto mymax = [](const auto &x, const auto &y) { return x < y ? y : x; };
auto mymin = [](const auto &x, const auto &y) { return x < y ? x : y; };
auto chkmn = [](auto &x, const auto &y) { return y < x ? (x = y, 1) : 0; };
auto chkmx = [](auto &x, const auto &y) { return x < y ? (x = y, 1) : 0; };

// }}}
// xtreme io {{{
// xtreme ios {{{
#ifndef XTREME_IO

int getc() { return getchar(); }
void flush() { fflush(stdout); }
void pc(int c) { putchar(c); }

#else

#define cin
#define cout
#define scanf 1
#define printf 1

namespace XTREME_IOS {
	const int SZ = BUFFER_SIZE;
	char ib[SZ], *li, *ri;
	char ob[SZ], *lo = ob, *ro = ob + SZ;
}
void flush() {
	using namespace XTREME_IOS;
	fwrite(ob, 1, lo - ob, stdout);
	lo = ob;
	fflush(stdout);
}
int getc() {
	using namespace XTREME_IOS;
	if (li == ri) {
		ri = ib + fread(ib, 1, SZ, stdin);
		li = ib;
	}
	return *li++;
}
void pc(int c) {
	using namespace XTREME_IOS;
	if (lo == ro) flush();
	*lo++ = c;
}
#endif
//}}}

#define gc getc()
#define fl flush()
#define br pc('\n')
#define sp pc(' ')

// xtreme input {{{
template <typename T>
typename enable_if<is_integral<T>::value>::type read(T &x) {
	int c = gc, tag = 0; x = 0;
	for (; !isdigit(c); c = gc)
		tag |= (c == '-');
	for (; isdigit(c); c = gc)
		x = (x * 10) + (c ^ 48);
	x = tag ? -x : x;
}
void read(char &x) {
	for (x = gc; isspace(x); x = gc);
}
void read(char *s) {
	char c = gc;
	for (; isspace(c); c = gc);
	for (; !isspace(c); c = gc) *s++ = c;
	*s++ = '\0';
}
void read(string &s) {
	char c = gc; s = "";
	for (; isspace(c); c = gc);
	for (; !isspace(c); c = gc) s += c;
}
template <typename T>
typename enable_if<!is_integral<T>::value>::type read(T &x) {
	stringstream ss;
	char c = gc;
	for (; isspace(c); c = gc);
	for (; !isspace(c); c = gc) ss << c;
	ss >> x;
}
template <typename A, typename B>
void read(pair<A, B> &pr) {
	read(pr.fi), read(pr.se);
}
template <typename It, typename = decltype(*It())>
void rarr(It l, It r) {
	for (; l != r; read(*l++));
}
template <typename T = long long>
T read() {
	T x;
	read(x);
	return x;
}
template <typename A, typename... B>
void read(A &x, B&... y) {
	read(x);
	read(y...);
}
//}}}
// xtreme output {{{
template <typename T>
typename enable_if<is_integral<T>::value>::type write(T x) {
	if (x < 0) pc('-'), x = -x;
	if (x >= 10) write(x / 10);
	pc((x % 10) ^ 48);
}
void write(char c) {
	pc(c);
}
void write(const char *s) {
	for (; *s; pc(*s++));
}
void write(const string &s) {
	for (auto c: s)
		pc(c);
}
template <int P = PRECISION, typename T>
typename enable_if<is_floating_point<T>::value>::type write(T x) {
	write((stringstream() << fixed << setprecision(P) << x).str());
}
template <typename A, typename B>
void write(const pair<A, B> &x) {
	write(x.fi), sp, write(x.se);
}
template <typename T, typename = decltype(ostream() << T())>
void write(T x) {
	write((stringstream() << x).str());
}
template <typename It, typename = decltype(*It())>
void warr(It l, It r) {
	for (; l != r; write(*l++), sp);
}
template <typename T, typename = decltype(T().begin())>
void write(const T &x) {
	warr(BE(x));
}
void wt() { }
template <typename A>
void wt(const A &x) { write(x); }
template <typename A, typename... B>
void wt(const A &x, const B&... y) { write(x), sp, wt(y...); }
//}}}

#define wts(args...) wt(args), sp
#define wtb(args...) wt(args), br
#define wte(args...) wt(args), exit(0)
#ifdef LOCAL
#define debug(args...) wtb('@', __func__, __LINE__), wtb(args), br, fl
#else
#define debug(args...) void()
#endif

int __init__ = []() {
#ifdef LOCAL
	freopen("test.in", "r", stdin), freopen("test.out", "w", stdout);
	atexit([](){ system("grep VmPeak /proc/$PPID/status > /dev/tty"); });
#endif
	atexit([](){ fl; });
	return 0;
}();
// xtreme io }}}

// mod int {{{
/*template <int Mod>
struct fixed_mod {
	static const int M = Mod;
	int mod(ul x) { return x % M; }
	int chkup(int x) { return x < 0 ? x + M : x; }
	int chkdn(int x) { return x >= M ? x - M : x; }
};
template <const int &Mod>
struct fast_mod {
	int M;
	u3 inv;
	void setmod() { M = Mod, inv = ((u3)1 << 64) / Mod; }
	int mod(ul x) { return chkdn(x - ((x * inv) >> 64) * M); }
	int chkup(int x) { return x < 0 ? x + M : x; }
	int chkdn(int x) { return x >= M ? x - M : x; }
};
template <, int RT = 3> struct mint {
	int x;
	mint(): x() {}
	mint(ll y) { x = y >= 0 ? mod.mod(y) : -mod.mod(-y); }
	explicit operator int() const { return x; }
	mint &operator += (const mint &a) { x = mod.chkdn(x + a.x); return *this; }
	mint &operator -= (const mint &a) { x = mod.chkup(x - a.x); return *this; }
	mint &operator *= (const mint &a) { x = mod.mod((ul)x * a.x); return *this; }
	bool operator == (const mint &a) const { return x == a.x; }
	bool operator != (const mint &a) const { return x != a.x; }
	mint operator - () const { mint res = *this; res.x = mod.chkdn(mod.M - res.x); return res; }
	mint operator ++ () const { return *this += 1; }
	mint operator -- () const { return *this -= 1; }
	mint operator ++ (int) const { return *this += 1; }
	mint operator -- (int) const { return *this -= 1; }
	friend mint pow(mint x, ul y) {
		mint ans = 1;
		for (; y; y >>= 1, x *= x) if (y & 1) ans *= x;
		return ans;
	}
	mint inv() const { return power(*this, mod.M - 2); }
	friend mint operator + (mint a, const mint &b) { return a += b; }
	friend mint operator - (mint a, const mint &b) { return a -= b; }
	friend mint operator * (mint a, const mint &b) { return a *= b; }
	friend void write(mint a) { write(a.x); }
	friend void read(mint &a) { a = mint(read()); }
};*/
// }}}

const int N = 200100;
char s[N];
int n, a[N], mx[N];
void solve() {
	read(n), read(s + 1);
	FOR (i, 1, n) a[i] = a[i - 1] + ((s[i] ^ 48) ? 1 : -1);
	if (a[n] < 0) {
		reverse(s + 1, s + n + 1);
		FOR (i, 1, n) s[i] ^= 1;
		FOR (i, 1, n) a[i] = a[i - 1] + ((s[i] ^ 48) ? 1 : -1);
	}
	FOR (i, 1, n) mx[i] = max(mx[i - 1], a[i]);
	int ans = 0;
	while (1) {
		while (n >= 1 && a[n] > a[n - 1]) n--;
		if (a[n] == -n) break;
		if (a[n] <= 0) { ans++; break; }
		int p = n;
		for (int i = n; i >= 0 && mx[i] >= a[n]; i--)
			if (a[i] == a[n])
				p = i;
		int m = (n + p) >> 1;
		for (int i = p + 1; i <= m; i++)
			mx[i] = mx[p], a[i] = a[i - 1] - 1;
		for (int i = m + 1; i <= n; i++)
			mx[i] = mx[p], a[i] = a[i - 1] + 1;
		ans++;
	}
	wtb(ans);
}

int main() { FOR (t, 1, read()) solve(); }