#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast<t>(x)
#define AR(t) vector < t >
#define PII pair < int, int >
#define PLL pair < LL, LL >
#define PIL pair < int, LL >
#define PLI pair < LL, int >
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define PRF first
#define PRS second
#define INIT(ar,val) memset ( ar, val, sizeof ( ar ) )
#define lp(loop,start,end) for ( int loop = start; loop < end; ++loop )
#define lpd(loop,start,end) for ( int loop = start; loop > end; --loop )
#define lpi(loop,start,end) for ( int loop = start; loop <= end; ++loop )
#define lpdi(loop,start,end) for ( int loop = start; loop >= end; --loop )
#define qmax(a,b) (((a)>(b))?(a):(b))
#define qmin(a,b) (((a)<(b))?(a):(b))
#define qabs(a) (((a)>=0)?(a):(-(a)))

const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 200007;

struct eT
{
	void setd ( int _u, int _v, int _f, int _l )
	{
		u = _u, v = _v, f = _f, last = _l;
	}

	int u, v, f, last;
}edge[MAXN * 2];

int n, m, K;
int cans;
int ke, la[MAXN];
int eu[MAXN], ev[MAXN];
int deg[MAXN];
int ans[MAXN];
int q[MAXN], ql, qr;

void init ();
void input ();
void work ();

void pushdown ()
{
	int now, v;
	while ( ql < qr ) {
		now = q[ql++];
		--cans;
		for ( int i = la[now]; ~i; i = edge[i].last ) {
			if ( edge[i].f ) {
				v = edge[i].v;
				--deg[v];
				if ( deg[v] == K - 1 ) {
					q[qr++] = v;
				}
			}
		}
	}
}



int main ()
{
	init ();
	input ();
	work ();
}



void init ()
{
	// Init Everything Here

	ios::sync_with_stdio ( false );
}

void input ()
{
	// input method

	scanf ( "%d%d%d", &n, &m, &K );
	int u, v;
	INIT ( la, -1 );
	lpi ( i, 1, m ) {
		scanf ( "%d%d", &u, &v );
		eu[i] = u, ev[i] = v;
		edge[ke].setd ( u, v, 1, la[u] );
		la[u] = ke++;
		edge[ke].setd ( v, u, 1, la[v] );
		la[v] = ke++;
		++deg[u], ++deg[v];
	}
}

void work ()
{
	// main work

	cans = n;

	ql = qr = 0;
	lpi ( i, 1, n ) if ( deg[i] < K ) q[qr++] = i;
	pushdown ();

	lpd ( i, m, 0 ) {
		ans[i] = cans;
		edge[( i - 1 ) << 1].f = edge[( i - 1 ) << 1 | 1].f = 0;
		ql = qr = 0;
		if ( deg[eu[i]] >= K && deg[ev[i]] >= K ) {
			if ( deg[eu[i]] == K ) q[qr++] = eu[i];
			if ( deg[ev[i]] == K ) q[qr++] = ev[i];
			--deg[eu[i]], --deg[ev[i]];
		}
		pushdown ();
	}

	lpi ( i, 1, m ) printf ( "%d\n", ans[i] );
}