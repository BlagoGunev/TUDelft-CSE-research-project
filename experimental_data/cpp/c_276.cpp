#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <numeric>

using namespace std;

typedef unsigned int UI;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef istringstream ISS;
typedef ostringstream OSS;

#define REP( i, m, n ) for ( int i = (int)( m ); i < (int)( n ); ++i )
#define FOR( v, c ) for ( auto &v : c )

#define ITER( c ) __typeof( (c).begin() )
#define EACH( it, c ) for ( ITER(c) it = c.begin(); it != c.end(); ++it )
#define ALL( c ) (c).begin(), (c).end()

#define PB( n ) push_back( n )
#define MP( a, b ) make_pair( ( a ), ( b ) )
#define EXIST( c, e ) ( (c).find( e ) != (c).end() )

#define fst first
#define snd second

#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define DEBUG( x ) cerr << __FILE__ << ":" << __LINE__ << ": " << #x << " = " << ( x ) << endl

int main()
{
	cin.tie( 0 );
	ios::sync_with_stdio( false );

	int n, q;
	cin >> n >> q;

	VI as( n );
	FOR( a, as )
	{
		cin >> a;
	}

	VI qs( 200001 );
	REP( i, 0, q )
	{
		int l, r;
		cin >> l >> r;
		l--;

		qs[l]++;
		qs[r]--;
	}

	vector<LL> counts( 1, 0 );
	partial_sum( ALL( qs ), back_inserter( counts ) );

	sort( ALL( counts ), greater<int>() );
	sort( ALL( as ), greater<int>() );

	ULL res = 0;
	REP( i, 0, n )
	{
		res += as[i] * counts[i];
	}

	cout << res << endl;

	return 0;
}