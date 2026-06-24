#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <sstream>
using namespace std;
#pragma comment(linker, "/STACK:255000000")

typedef long long ll;

#define rep(i, a, b) for(i = (a); i < (b); ++i)
#define repb(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define repd(i, a, b, d) for(i = (a); i < (b); i += (d))
#define repbd(i, a, b, d) for(i = (a) - 1; i >= (b); i -= (d))
#define reps(i, s) for(i = 0; (s)[i]; ++i)
#define repl(i, l) for(i = l.begin(); i != l.end(); ++i)

#define in(f, a) scanf("%"#f, &(a))

bool firstout = 1;

#define out(f, a) printf("%"#f, (a))
#define outf(f, a) printf((firstout) ? "%"#f : " %"#f, (a)), firstout = 0
#define nl printf("\n"), firstout = 1

#define all(x) (x).begin(),(x).end()
#define sqr(x) ((x) * (x))
#define mp make_pair

template<class T>
T &minn(T &a, T b)
{
	if(b < a) a = b;
	return a;
}

template<class T>
T &maxx(T &a, T b)
{
	if(a < b) a = b;
	return a;
}

#define inf 1012345678
#define eps 1e-9


#ifdef XDEBUG
#define mod 23
#else
#define mod 1000000009
#endif

int &madd(int &a, int b)
{
	a += b;
	if(a >= mod) a -= mod;
	return a;
}

int &msub(int &a, int b)
{
	a -= b;
	if(a < 0) a += mod;
	return a;
}

int &mmult(int &a, int b)
{
	return a = (ll)a * b % mod;
}

int mdiv(ll a, ll b, ll m)
{
	a = (a % m + m) % m;
	b = (b % m + m) % m;
	if(a % b == 0) return a / b;
	return (a + m * mdiv(-a, m, b)) / b;
}

#define N 5012
#define M 1012

int n, m;
int A[N][N];
int AN[N];
int AI[N];

int calc(bool print)
{
	int res = 0;
	int p = 0;
	int i, j, k;
	if(print)
	{
	set<pair<int, int> > s;
	rep(i, 0, n) AI[i] = 0, s.insert(mp(A[i][0], i));
	for(; s.size();)
	{
		set<pair<int, int> >::iterator si = s.lower_bound(mp(p, -1));
		if(si == s.end()) si = s.begin(), ++res;
		i = si->second;
		p = si->first;
		if(print) outf(d, p), outf(d, i + 1), nl;
		s.erase(si);
		if(++AI[i] < AN[i]) s.insert(mp(A[i][AI[i]], i));
	}
	}
	else
	{
		rep(i, 0, n)
		{
			int r = 0;
			rep(j, 1, AN[i]) if(A[i][j] < A[i][j - 1]) ++r;
			maxx(res, r);
		}
	}
	return res;
}

int main()
{
#ifdef XDEBUG
	freopen("in.txt", "rt", stdin);
#else
#endif

	int i, j, k;
	char c;
	int a, d;
	
	int ts;	
#if 0
	int tss;
	in(d, tss);
	rep(ts, 1, tss + 1)
#else
	for(ts = 1; in(d, n) > 0; ++ts)
#endif
	{
		int nn = 0;
		rep(i, 0, n)
		{
			int l, a, x, y, m;
			in(d, l);
			nn += l;
			in(d, a);
			in(d, x);
			in(d, y);
			in(d, m);
			AN[i] = l;
			rep(j, 0, l)
			{
				A[i][j] = a;
				a = ((ll)a * x + y) % m;
			}
		}
		int res = calc(0);
		out(d, res); nl;
		if(nn <= 200000) calc(1);
	}

	return 0;
}