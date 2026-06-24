#define XTREME_IO

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define BE(x) (x).begin(), (x).end()
#define y1 ___y1
#define max mymax
#define min mymin
#define pq priority_queue
#define FOR(i, l, r) for (int i = (l), i##end = (r); i <= i##end; i++)
#define ROF(i, r, l) for (int i = (r), i##end = (l); i >= i##end; i--)
#define SON(i, u) for (int i = head[u]; i; i = e[i].nxt)

using ui = unsigned;
using ll = long long;
using ul = unsigned long long;
using db = double;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using l3 = __int128_t;
using u3 = __uint128_t;

const ld finf = 1e121, eps = 1e-10, PI = acos((ld)-1);
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }

template <typename A, typename B>
inline auto mymax(const A &x, const B &y) { return x > y ? x : y; }
template <typename A, typename B>
inline auto mymin(const A &x, const B &y) -> decltype(x < y ? x : y) { return x < y ? x : y; }
template <typename A, typename B>
inline int chkmn(A &x, const B &y) { return x > y ? (x = y, 1) : 0; }
template <typename A, typename B>
inline int chkmx(A &x, const B &y) { return x < y ? (x = y, 1) : 0; }

#ifndef XTREME_IO
inline int gc() { return getchar(); }
inline void pc(int c) { return putchar(c); }
inline void fl() { flush(stdout); }
#define gc getchar
#define pc putchar
#define fl fflush(stdout)
void flush() { fflush(stdout); }
#else
#define cin
#define cout
#define scanf 1
#define printf 1
namespace XTREME_IOS {
	const int SZ = 1 << 20;
	char ib[SZ], ob[SZ], *li, *ri, *lo = ob, *ro = ob + SZ;
	inline int gc() {
		if (li == ri) ri = (li = ib) + fread(ib, 1, SZ, stdin);
		return *li++;
	}
	inline void fl() {
		fwrite(ob, 1, lo - ob, stdout), lo = ob, fflush(stdout);
	}
	inline void pc(int ch) {
		if (lo == ro) fl();
		*lo++ = ch;
	}
}
#define gc XTREME_IOS::gc
#define pc XTREME_IOS::pc
void flush() { XTREME_IOS::fl(); }
#endif
#define br pc('\n')
#define sp pc(' ')
#define fl flush()
template <typename T = long long> inline T read();
template <typename T>
inline typename enable_if<is_integral<T>::value>::type read(T &x) {
	int c = gc(), tag = 0; x = 0;
	for (; !isdigit(c); c = gc()) tag |= (c == '-');
	for (; isdigit(c); c = gc()) x = (x * 10) + (c ^ 48);
	if (tag) x = -x;
}
inline void read(char &x) {
	for (x = gc(); isspace(x); x = gc());
}
inline void read(char *s) {
	char c; read(c);
	for (; !isspace(c); c = gc()) *s++ = c;
	*s++ = '\0';
}
inline void read(string &s) {
	char c; read(c); s = "";
	for (; !isspace(c); c = gc()) s += c;
}
template <typename T, typename = decltype(stringstream() << T())>
inline typename enable_if<!is_integral<T>::value>::type read(T &x) {
	stringstream(read<string>()) >> x;
}
template <typename A, typename B>
inline void read(pair<A, B> &pr) { read(pr.fi); read(pr.se); }
template <typename It, typename = decltype(*It())>
void rarr(It l, It r) { for (; l != r; ++l) read(*l); }
template <typename A, typename... B>
inline void read(A &x, B&... y) { read(x); read(y...); }
template <typename T>
inline T read() { T x; read(x); return x; }
template <typename T>
inline void writeu(T x) {
	if (x >= 10) writeu(x / 10);
	pc((x % 10) ^ 48);
}
template <typename T>
inline typename enable_if<is_integral<T>::value>::type write(T x) {
	if (x < 0) pc('-'), x = -x;
	writeu(x);
}
template <typename A, typename B>
inline void write(const pair<A, B> &x) { write(x.fi), sp, write(x.se); }
inline void write(char c) { pc(c); }
inline void write(const char *s) { for (; *s; pc(*s++)); }
inline void write(const string &s) { for (auto c: s) pc(c); }
template <typename T>
inline typename enable_if<is_floating_point<T>::value>::type write(T x) {
	write((stringstream() << fixed << setprecision(12) << x).str());
}
template <typename T, typename = decltype(stringstream() << T())>
inline typename enable_if<!is_arithmetic<T>::value>::type write(T x) {
	write((stringstream() << x).str());
}
template <typename T, typename = decltype(T().begin())>
void write(const T &x) {
	if (x.empty()) return;
	write(*x.begin());
	for (auto it = x.begin(); (++it) != x.end(); )
		sp, write(*it);
}
inline void wt() { }
template <typename A>
inline void wt(const A &x) { write(x); }
template <typename A, typename... B>
inline void wt(const A &x, const B&... y) { write(x), sp, wt(y...); }
#define wts(args...) wt(args), sp
#define wtb(args...) wt(args), br
#define wtf(args...) wt(args), fl
#define wte(args...) wt(args), exit(0)

#ifdef LOCAL
#define debug(args...) wtb(__LINE__, args), fl
int __init__ = []() {
	freopen("test.in", "r", stdin), freopen("test.out", "w", stdout);
	return atexit([](){ system("grep VmPeak /proc/$PPID/status > /dev/tty"), fl; });
}();
#else
#define debug(...) void()
int __init__ = []() { return atexit([](){ fl; }); }();
#endif

const int N = 1000100;
int flag[N], pr[N], cnt;
u3 tag[N];

int vis[N];
void output(int n, vi v) {
	for (int x: v) vis[x] = 1;
	wtb(n - v.size());
	FOR (i, 1, n) if (!vis[i]) wts(i);
}

template<>
struct std::hash<u3> {
	ul operator()(u3 x) const {
		return (ul)x ^ (x >> 64);
	}
};

int main() {
	int n = read();
	FOR (i, 2, n) if (!flag[i]) {
		pr[++cnt] = i;
		FOR (j, 1, n / i) flag[i * j] = 1;
	}
	FOR (i, 1, cnt) {
		u3 wow = 0;
		FOR (j, 1, 4) wow = wow << 32 | rng();
		for (ll x = pr[i]; x <= n; x *= pr[i])
			for (int j = x; j <= n; j += x)
				tag[j] ^= wow;
	}
	FOR (i, 1, n) tag[i] ^= tag[i - 1];

	u3 qry = 0;
	FOR (i, 1, n) qry ^= tag[i];

	if (!qry) {
		output(n, {});
		return 0;
	}
	FOR (i, 1, n) if (tag[i] == qry) {
		output(n, {i});
		return 0;
	}
	unordered_map<u3, int> buc;
	FOR (i, 1, n) {
		buc[tag[i]] = i;
		if (buc.find(tag[i] ^ qry) != buc.end()) {
			output(n, {i, buc[tag[i] ^ qry]});
			return 0;
		}
	}
	output(n, {2, n / 2, n});
}