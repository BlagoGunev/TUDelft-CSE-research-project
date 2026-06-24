#pragma comment(linker, "/STACK:66777216")
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <memory.h>
#include <assert.h>
#include <list>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <cmath>
#include <ctime>
#include <queue>
#pragma hdrstop

using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define y0 __MY_Y0__
#define y1 __MY_Y1__
#define yn __MY_YN__
#define hash __MY_HASH__
#define prev __MY_PREV__
#define next __MY_NEXT__
#define less __MY_LESS__
#define sz(a) (int)a.size()
#define fill(a, x) memset (a, x, sizeof(a))

#ifdef _DEBUG
	#define Eo(x) {cout << "# " << #x << " = " << (x) << endl;}
	#define E(x) {cout << "# " << #x << " = " << (x) << " ";}
	#define Ou(x) {cout << "# " << (x) << endl;}
	#define OK {cout << "# OK    Line : " << __LINE__ << endl;}
#else
	#define Eo(x)
	#define E(x)
	#define Ou(x)
	#define OK
#endif

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

inline void sIO() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
}
inline void iIO() {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
inline void fIO(string fn) {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen ("output.txt", "w", stdout);
#else
	freopen((fn + ".in").c_str(), "r", stdin); freopen((fn + ".out").c_str(), "w", stdout);
#endif
}
inline void TM() {
#ifdef _DEBUG
	cout << endl << "# Time: " << clock() / 1000. << endl;
#endif
}
inline void swap(short& a, short& b) {b ^= a ^= b ^= a;}
inline void swap(int& a, int& b) {b ^= a ^= b ^= a;}
inline void swap(char& a, char& b) {b ^= a ^= b ^= a;}
inline void swap(ll& a, ll& b) {b ^= a ^= b ^= a;}
template<class T> inline T abs(T x) {return x < 0 ? -x : x;}
template<class T> inline T sqr(T x) {return x * x;}
template<class T> inline T min(T& a, T& b) {return a < b ? a : b;}
template<class T> inline T max(T& a, T& b) {return a > b ? a : b;}
template<class T> inline T gcd(T a, T b) {if (a < b) swap(a, b); while (b) {a %= b; swap(a, b);} return a;}
template<class T> inline T lcm(T a, T b) {return a / gcd(a, b) * b;}
template<class T> inline bool isPrime(T n) {if (n < 2) return false; T kk = (T)sqrt(n + 0.); for (T i = 2; i <= kk; ++i) if (!(n % i)) return false; return true;}
template<class T> inline string toa(T x) {stringstream ss; ss << x; string ret; ss >> ret; return ret;}
template<class T> inline T ppow(T a, ll b) {T ret = 1; while (b) {if (b & 1) ret *= a; a *= a; b >>= 1;} return ret;}
template<class T> inline T ppow(T a, ll b, ll md) {T ret = 1; a %= md; while (b) {if (b & 1) ret = ret * a % md; a = a * a % md; b >>= 1;} return ret % md;}
inline int toi(string s) {stringstream ss; ss << s; int ret; ss >> ret; return ret;}
inline ll tol(string s) {stringstream ss; ss << s; ll ret; ss >> ret; return ret;}
inline int Random() {return ((rand() << 16) | rand());}
inline char upperCase(char ch) {return (ch >= 'a' && ch <= 'z') ? ch^32 : ch;}
inline char lowerCase(char ch) {return (ch >= 'A' && ch <= 'Z') ? ch^32 : ch;}
inline string upperCase(string s) {int ls = s.length(); for (int i = 0; i < ls; ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] ^= 32; return s;}
inline string lowerCase(string s) {int ls = s.length(); for (int i = 0; i < ls; ++i) if (s[i] >= 'A' && s[i] <= 'Z') s[i] ^= 32; return s;}
inline int dig(char ch) {return ch - 48;}
inline bool isAlpha(char ch) {return (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z');}
inline bool isDigit(char ch) {return (ch >= '0' && ch <= '9');}
inline bool isLowerCase(char ch) {return (ch >= 'a' && ch <= 'z');}
inline bool isUpperCase(char ch) {return (ch >= 'A' && ch <= 'Z');}

int __;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-9;
//const int MD = 1000000007;

int n, kk, x, y, cnt[111111], to[111111][4], rr[111111];
bool w[111111];

bool go(int pp, int p, int k) {
	int xx, yy;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j) {
			xx = to[pp][i], yy = to[p][j];
			if (xx == yy && (!w[xx] || (k == n - 1 && xx == y))) {
				w[rr[k] = xx] = true;
				if (k == n - 1) return xx == y;
				return go(p, xx, k + 1);
			}
		}
	return false;
}

int main() {
	sIO();
	scanf("%d", &n);
	kk = n << 1;
	for (int i = 0; i < kk; ++i) {
		scanf("%d%d", &x, &y);
		to[x][cnt[x]++] = y;
		to[y][cnt[y]++] = x;
	}
	for (int i = 0; i < 4; ++i)
		for (int j = i + 1; j < 4; ++j) {
			fill(w, 0);
			w[1] = w[x = to[1][i]] = w[y = to[1][j]] = true;
			rr[0] = 1;
			rr[1] = x;
			if (go(1, x, 2)) {
				for (int k = 0; k < n; ++k)
					printf("%d ", rr[k]);
				return 0;
			}
		}
	printf("-1");
	return 0;
}