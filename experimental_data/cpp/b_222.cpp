#if 1	// folding: default stuff
// COMMON STUFF
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <utility>
#include <bitset>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
using namespace std;
using namespace rel_ops;

#define FOR(x, b, e)    for (int x = (b); x <= (e); ++x)
#define FORD(x, b, e)   for (int x = (b); x >= (e); --x)
#define REP(x, n)       for (int x = 0; x < (n); ++x)
#define VAR(v, n)       typeof(n) v = (n)
#define ALL(c)          (c).begin(), (c).end()
#define SIZE(x)         ((int) (x).size())
#define EACH(i, c)      for (VAR(i, (c).begin()); i != (c).end(); ++i)
#define REACH(i, c)     for (VAR(i,(c).rbegin()); i != (c).rend(); ++i)
#define UNIQUE(v)	{ sort(ALL(v)); (v).resize(unique(ALL(v)) - (v).begin()); }
#define PB      push_back
#define ST      first
#define ND      second
#define MP      make_pair
#define skip    continue
#define say		Cout,

const int INF = 1000000001;

typedef long long LL;
typedef unsigned long long ULL;
// COMMON STUFF END

// IO STUFF
template <class T, class U>
ostream &operator, (ostream &out, const pair<T,U> &p) {
	return out, p.first, ' ', p.second;
}
template <class T>
ostream &operator, (ostream &out, const vector<T> &v) {
	EACH (i, v) {
		out, *i, ' ';
	}
	return out;
}
template <class T, class U>
istream &operator, (istream &in, pair<T,U> &p) {
	return in, p.first, p.second;
}
template <class T>
istream &operator, (istream &in, vector<T> &v) {
	EACH (i, v) {
		in, (*i);
	}
	return in;
}
template <class T>
ostream &operator, (ostream &out, const T &t) {
	return out << t;
}
template <class T>
istream &operator, (istream &in, T &t) {
	return in >> t;
}
struct Ostream {
	ostream &out;
	Ostream(ostream &_out) : out(_out) {}
	
	static const void *lastLine;
	
	struct Line {
		ostream &out;
		bool first;
		Line(ostream &_out, bool _first = false) : out(_out), first(_first) {
			lastLine = this;
		}
		~Line() {
			if (this == lastLine) {
				out << '\n';
				lastLine = 0;
			}
		}
	};
};
const void *Ostream::lastLine = 0;
template <class T>
Ostream::Line operator, (const Ostream::Line &out, const T &t) {
	if (!out.first) {
		out.out << ' ';
	}
	out.out, t;
	return Ostream::Line(out.out);
}
template <class T>
Ostream::Line operator, (const Ostream &out, const T &t) {
	return Ostream::Line(out.out, true), t;
}
Ostream Cout(cout);
int io_init() {
	ios_base::sync_with_stdio(false);
#ifdef ONLINE_JUDGE
	cin.tie(0);
	cout.tie(0);
#endif
	cout << fixed << setprecision(9);
	
	return 1;
}
int _io_dummy = io_init();
const char *YN[] = {"NO", "YES"};
// IO STUFF END

// UTILS STUFF
template <class T, class U>
bool remin(T &a, const U &b) {
	return b < a ? a = b, true : false;
}

template <class T, class U>
bool remax(T &a, const U &b) {
	return b > a ? a = b, true : false;
}

template <class T>
T fromString(const string &s) {
	T t;
	istringstream(s) >> t;
	return t;
}

template <class T>
string toString(const T &t) {
	ostringstream oss;
	oss << t;
	return oss.str();
}
// UTILS STUFF END
#endif	// folding: default stuff

const int N = 1001;
int A[N][N];

int main() {
	int R, C, q;
	cin, R, C, q;
	REP (r, R) REP (c, C) cin, A[r][c];
	
	vector<int> ic(C + 1), ir(R + 1);
	
	FOR (c, 1, C) ic[c] = c-1;
	FOR (r, 1, R) ir[r] = r-1;
	
	string str;
	int x, y;
	REP (qq, q) {
		cin, str, x, y;
		char s = str[0];
		
		if (s == 'c') {
			swap(ic[x], ic[y]);
		} else if (s == 'r') {
			swap(ir[x], ir[y]);
		} else {
			say A[ir[x]][ic[y]];
		}
	}
}