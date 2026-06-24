#include <bits/stdc++.h>

using namespace std;

vector< int > compose( vector< int > a, vector< int > b )
{
	int n = (int) a.size();
	vector< int > ret( n );
	for( int i = 0; i < n; ++ i )
		ret[i] = b[a[i]];
	return ret;
}

int main ()
{
	int n;
	scanf("%d", &n );

	vector< int > p( n + 1 ), in_degree( n + 1 );
	for( int i = 1; i <= n; ++ i )
	{
		scanf("%d", &p[i] );
		in_degree[ p[i] ]++;
	}

	int out = 0;
	for( int i = 1; i <= n; ++ i )
		if( in_degree[i] == 0 ) ++out;

	int mx = 0;
	vector< int > a( n + 1 );
	for( int i = 1; i <= n; ++ i )
	{
		scanf("%d", &a[i] );
		mx = max( mx, a[i] );
	}

	const int rounds = ( mx - n ) / out;

	vector< int > nxt( n + 1 );
	iota( nxt.begin(), nxt.end(), 0 );

	{
		int pot = rounds;

		auto base = p;
		while( pot )
		{
			if( pot & 1 )
				nxt = compose( nxt, base );
			
			base = compose( base, base );
			pot >>= 1;
		}
	}

	vector< int > pos( n + 1 );
	for( int i = 1; i <= n; ++ i )
		if( a[i] <= n )
			pos[a[i]] = i;

	vector< vector< int > > prv( n + 1 );
	for( int x = 1; x <= n; ++ x )
		prv[ nxt[x] ].push_back( x );

	set< int > no_has;
	for( int x = 1; x <= n; ++ x )
		if( pos[x] == 0 )
			no_has.insert( x );

	vector< int > b ( n + 1 ), at_least( n + 1 );
	for( int x = 1; x <= n; ++x )
	{
		if( pos[x] == 0 ) continue;

		int sz = (int) prv[pos[x]].size();

		b[ prv[pos[x]][0] ] = x;

		for( int i = 1; i < sz; ++ i )
		{
			int &curr = at_least[prv[pos[x]][i]];
			curr = max( curr, x );
		}
	}

	for( int i = 1; i <= n; ++ i )
	{
		if( at_least[i] )
		{
			int y = *no_has.upper_bound( at_least[i] );
			b[i] = y;
			no_has.erase( y );
		}
	}

	for( int i = 1; i <= n; ++ i )
		printf("%d ", b[i] );
	puts("");


	return 0;
}