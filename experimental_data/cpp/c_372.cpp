//Krzysztof Pieprzak
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <list>
#include <deque>
#include <stack>
#include <map>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define Size(x) (int)x.size()
#define VAR(v,n) typeof(n)v = (n)
#define FOR(i,a,b) for(VAR(i,a); i < (b); ++i)
#define FORE(i,a,b) for(VAR(i,a); i <= (b); ++i)
#define FORREV(i,a,b) for(VAR(i,b); i >= (a); --i)
#define FORSTEP(i,a,b,step) for(VAR(i,a); i < (b); i += (step))
#define FOREACH(i,c) for(VAR(i,(c).begin()); i != (c).end(); ++i)
#define ALL(x) x.begin(),x.end()
#define CLEAR(t) memset(t, 0, sizeof(t))
#define F first
#define S second
#define MP make_pair
#define PUB push_back
#define POB pop_back
#define pieprzu ios_base::sync_with_stdio(0);
#define debug if(0)
#define send 0

const int    INF = 1000000007;
const double EPS = 10e-9;

const int MAXN = 150005;

int t[2][MAXN];
pii tab[MAXN];

void init(int n, int a)
{
	FORE (i, 1, n) t[1][i] = abs(i-a);
}

inline void go(int n, int a, int step)
{
	//printf("step = %d\n", step);
	if (!step)
	{
		FORE (i, 1, n) t[1][i] += abs(i-a);
		return;
	}

	int _end = 0;
	int _beg = 0;

	tab[0] = MP(t[1][1],1);
	t[0][1] = t[1][1] + abs(1-a);
	FORE (i, 1, n)
	{
		if (tab[_beg].S + step < i) ++_beg;

		for (; _end >= _beg; --_end) if (tab[_end].F < t[1][i]) break;
		tab[++_end] = MP(t[1][i],i);
		t[0][i] = tab[_beg].F + abs(i-a);
	}

	tab[0] = MP(t[1][n],n);
	_beg = _end = 0;
	t[1][n] = t[1][n] + abs(n-a);
	FORREV (i, 1, n)
	{
		if (tab[_beg].S - step > i) ++_beg;

		for (; _end >= _beg; --_end) if (tab[_end].F < t[1][i]) break;
		tab[++_end] = MP(t[1][i],i);
		t[1][i] = tab[_beg].F + abs(i-a);
		t[1][i] = min(t[0][i], t[1][i]);
	}
}

void rob()
{
	int n, m, d;
	scanf("%d %d %d", &n, &m, &d);

	int a, b, tmPrev, tmCur;
	scanf("%d %d %d", &a, &b, &tmPrev);
	init(n, a);

	//printf("%d %d %d\n", t[1][29], t[1][26], t[1][20]);

	ll sum = b;
	ll step;
	FOR (i, 1, m)
	{
		scanf("%d %d %d", &a, &b, &tmCur);
		step = (ll)(tmCur-tmPrev)*d;

		go(n, a, min(step,(ll)n+5));
		sum += b;

		//printf("%d %d %d\n", t[1][29], t[1][26], t[1][20]);

		tmPrev = tmCur;
	}

	int mn = INF;
	FORE (i, 1, n) mn = min(mn, t[1][i]);
	//printf("%I64d %d\n", sum, mn);
	printf("%I64d\n", sum - mn);
}

int main()
{
    int test = 1;
    //scanf("%d", &test);

    while (test--) rob();

    return 0;
}