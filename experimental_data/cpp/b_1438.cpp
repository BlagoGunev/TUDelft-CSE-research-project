#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <chrono>
#include <random>
#include <bitset>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define fi first
#define se second
#define il inline
#define Ld double
#define rg register
#define ll long long
#define lll __int128
#define pb push_back
#define mp make_pair
#define It ::iterator
#define W(p) while(p--)
#define pll pair<ll, ll>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pii pair<int, int>
#define ull unsigned long long
#define all(x) x.begin(), x.end()
#define rep(i, b, s) for(int i = b; i <= s; ++i)
#define per(i, b, s) for(int i = b; i >= s; --i) 
#define FOR(i, b, s) for(rg int i = b; i <= s; ++i)
#define FOR_(i, b, s) for(rg int i = b; i >= s; --i)

namespace IO {
    const int SIZE = (1 << 20) + 1;
    char ibuf[SIZE], *iS, *iT, obuf[SIZE],*oS = obuf, *oT = obuf + SIZE - 1;
    char _st[55];
    int _qr = 0;
    inline char gc() {
        return (iS == iT ? iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS++) : *iS++);
    }
    inline void qread() {}
    template<class T1, class ...T2>
    inline void qread(T1 &IEE, T2&... ls) {
        register T1 __ = 0, ___ = 1;
        register char ch;
        while(!isdigit(ch = gc())) ___ = (ch == '-') ? -___ : ___;
        do {
            __ = (__ << 1) + (__ << 3) + (ch ^ 48);
        }while(isdigit(ch = gc()));
        __ *= ___;
        IEE = __;
        qread(ls...);
        return ;
    }
    template<class T>
	inline void QreadArr(T Begin, T End) {
		while(Begin != End) {
			qread(*Begin);
			++Begin;
		}
	}
    inline void flush() {
        fwrite(obuf, 1, oS - obuf, stdout);
        oS = obuf;
        return ;
    }
    inline void putc_(char _x) {
        *oS++ = _x;
        if(oS == oT) flush();
    }
    inline void qwrite() {}
    template<class T1, class ...T2>
    inline void qwrite(T1 IEE, T2... ls) {
        if(!IEE) putc_('0');
        if(IEE < 0) putc_('-'), IEE = -IEE;
        while(IEE) _st[++_qr] = IEE % 10 + '0', IEE /= 10;
        while(_qr) putc_(_st[_qr--]);
        qwrite(ls...);
        return ;
    }
    template<class T>
    inline void WriteArr(T Begin, T End) {
    	const char Kg = ' ', Edl = '\n';
    	while(Begin != End) {
    		qwrite(*Begin);
    		++Begin;
    		putc_(Kg);
		}
		putc_(Edl);
	}
    struct Flusher_{ ~Flusher_() { flush(); } } io_flusher;
}

using namespace IO;
using namespace std;

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll My_Rand(ll Mod) { return (ull)(rnd()) % Mod; }

template<class T1, class T2>
void To_max(T1 &x, T2 y) { x < y ? x = y : x = x; }
template<class T1, class T2>
void To_min(T1 &x, T2 y) { x > y ? x = y : x = x; }

il ll qpow(ll n, ll base) {
	ll ret = 1;
	while(n) {
		if(n & 1) ret = ret * base;
		base = base * base;
		n >>= 1;
	}
	return ret;
}

il ll gcd(ll x, ll y) { return !y ? x : gcd(y, x % y); }
il ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
//header

int n;
int b[200005];

int main() {
 	int Q;
 	qread(Q);
 	W(Q) {
 		qread(n);
 		int f = 0;
 		rep(i, 1, n) qread(b[i]);
 		sort(b + 1, b + n + 1);
 		rep(i, 1, n - 1) if(b[i] == b[i + 1]) { f = 1; break; }
		f ? puts("YES") : puts("NO");
		//QAQAQAQAQAQ
	}
	return 0;
}