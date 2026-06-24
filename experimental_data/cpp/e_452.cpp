#include <cstdio>

#include <cstring>

#include <vector>

#include <algorithm>

using namespace std;



const int N = 600010;

const int Mod = 1e9 + 7;



struct Event {

	int time;

	long long delta;

	Event( int time, long long delta ):time(time),delta(delta){}

};

bool operator<( const Event &r, const Event &s ) {

	return r.time < s.time;

}

vector<Event> events;



void upd( long long &a, long long b ) {

	a += b;

	if( a < 0 ) a += Mod;

	if( a >= Mod ) a -= Mod;

}

struct SuffixAutomation {

	int son[N][28], maxlen[N], link[N], ntot, last;

	int rcnt[N][3];

	int head[N], dest[N], next[N], etot;

	int lf[3], rg[3];



	void adde( int u, int v ) {

		etot++;

		next[etot] = head[u];

		dest[etot] = v;

		head[u] = etot;

	}

	void init( int len1, int len2, int len3 ) {

		link[0] = -1;

		lf[0] = 1, rg[0] = len1;

		lf[1] = len1+1+1, rg[1] = len1+1+len2;

		lf[2] = len1+len2+2+1, rg[2] = len1+len2+2+len3;

	}

	void append( int c ) {

		int p = last;

		int np = ++ntot;

		

		memset( son[np], 0, sizeof(son[np]) );

		maxlen[np] = maxlen[p] + 1;

		rcnt[np][0] = rcnt[np][1] = rcnt[np][2] = 0;

		for( int i = 0; i < 3; i++ )

			if( lf[i] <= maxlen[np] && maxlen[np] <= rg[i] ) {

				rcnt[np][i]++;

				break;

			}

		while( p != -1 && !son[p][c] )

			son[p][c] = np, p = link[p];

		if( p == -1 ) {

			link[np] = 0;

		} else {

			int q = son[p][c];

			if( maxlen[p] + 1 == maxlen[q] ) {

				link[np] = q;

			} else {

				int nq = ++ntot;

				memcpy( son[nq], son[q], sizeof(son[nq]) );

				maxlen[nq] = maxlen[p] + 1;

				link[nq] = link[q];

				link[q] = link[np] = nq;

				rcnt[nq][0] = rcnt[nq][1] = rcnt[nq][2] = 0;

				while( p != -1 && son[p][c] == q )

					son[p][c] = nq, p = link[p];

			}

		}

		last = np;

	}

	void dfs( int u ) {

		for( int t = head[u]; t; t = next[t] ) {

			int v = dest[t];

			dfs(v);

			for( int j = 0; j < 3; j++ ) 

				rcnt[u][j] += rcnt[v][j];

		}

	}

	void right() {

		for( int u = 1; u <= ntot; u++ )

			adde( link[u], u );

		dfs( 0 );

	}

	void add( int lf, int rg, long long delta ) {

		events.push_back( Event(lf,+delta) );

		events.push_back( Event(rg+1,-delta) );

	}

	void solve() {

		for( int u = 1; u <= ntot; u++ ) {

			if( !rcnt[u][0] || !rcnt[u][1] || !rcnt[u][2] ) continue;

			long long cnt = 1LL * rcnt[u][0] * rcnt[u][1] % Mod * rcnt[u][2] % Mod;

			add( maxlen[link[u]]+1, maxlen[u], cnt );

		}

	}

}sam;



int n[3], nmin;

char s[3][N];



int main() {

	for( int i = 0; i < 3; i++ ) {

		scanf( "%s", s[i] + 1 );

		n[i] = (int)strlen(s[i] + 1);

	}

	nmin = min( n[0], min( n[1], n[2] ) );

	sam.init(n[0], n[1], n[2]);

	for( int i = 0; i < 3; i++ ) {

		for( int j = 1; j <= n[i]; j++ )

			sam.append( s[i][j] - 'a' );

		if( i != 2 ) sam.append( 26 + i );

	}

	sam.right();

	sam.solve();

	sort( events.begin(), events.end() );

	long long sum = 0;

	int cur = -1;

	for( int i = 1; i <= nmin; i++ ) {

		while( cur+1<events.size() && events[cur+1].time <= i ) {

			upd( sum, events[cur+1].delta );

			cur++;

		}

		printf( "%d%s", (int)sum, i==nmin ? "\n" : " " );

	}

}