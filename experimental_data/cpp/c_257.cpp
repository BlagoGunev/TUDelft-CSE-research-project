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
#include <bitset>
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
#define EACH( v, c ) for ( auto &v : c )

#define ITER( c ) __typeof( (c).begin() )
#define IREP( c, it ) for ( ITER(c) it = c.begin(); it != c.end(); ++it )
#define ALL( c ) (c).begin(), (c).end()

#define PB( n ) push_back( n )
#define MP( a, b ) make_pair( ( a ), ( b ) )
#define EXIST( c, e ) ( (c).find( e ) != (c).end() )

#define fst first
#define snd second

#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define DEBUG( x ) cerr << __FILE__ << ":" << __LINE__ << ": " << #x << " = " << ( x ) << endl

const double PI = acos( -1 );

int main()
{
	cin.tie( 0 );
	ios::sync_with_stdio( false );

	int n;
	cin >> n;

	if ( n == 1 )
	{
		cout << 0 << endl;
		return 0;
	}

	vector< PII > ps( n );
	EACH( p, ps )
	{
		cin >> p.fst >> p.snd;
	}

	vector<double> degs;
	transform( ALL( ps ), back_inserter( degs ),
			[]( pair<double,double> a ) -> double { return atan2( a.snd, a.fst ); } );
	sort( ALL( degs ) );
	degs.PB( degs[0] + 2 * PI );

	double res = 0;

	REP( i, 0, n )
	{
		res = max( res, abs( degs[ i + 1 ] - degs[i] ) );
	}

	res = 360 - res * 180 / PI;

	cout.precision( 7 );
	cout << fixed;
	cout << res << endl;
		
	return 0;
}