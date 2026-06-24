#include <cstdio>
#include <vector>

using namespace std;

pair< int, int > tab[ 110 ];
vector< int > G[ 110 ];
bool odw[ 110 ];
int size = 1;

void dfs( int v ){

	odw[ v ] = true;
	for( int i = 0; i < G[ v ].size(); i++ ){
		if( odw[ G[ v ][ i ] ] == false )
			dfs( G[ v ][ i ] );
	}
}

int main(){

	int n;
	scanf( "%d", &n );

	for( int i = 0; i < n; i++ ){

		int t, a, b;
		scanf( "%d %d %d", &t, &a, &b );

		if( t == 1 ){

			tab[ size ] = make_pair( a, b );
			size++;

			for( int i = 1; i < size - 1; i++ ){

				if( ( tab[ i ].first < tab [ size - 1 ].first && tab[ i ].second > tab[ size - 1].first ) || ( tab[ i ].first < tab[ size - 1 ].second && tab[ i ].second > tab[ size - 1 ].second ) )
					G[ size - 1 ].push_back( i );

				if( ( tab[ size - 1 ].first < tab [ i ].first && tab[ size -  1 ].second > tab[ i ].first ) || ( tab[ size - 1 ].first < tab[ i ].second && tab[ size - 1  ].second > tab[ i ].second ) )
					G[ i ].push_back( size - 1 );

			}

		}

		if( t == 2 ){

			for( int i = 0; i < size; i++ )
				odw[ i ] = false;

			dfs( a );
			if( odw[ b ] == true )
				printf( "YES\n" );
			else
				printf( "NO\n" );

		}

	}

}