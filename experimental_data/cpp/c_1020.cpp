#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define my_min( a, b ) ( ( a ) < ( b )?( a ) : ( b ) )
#define my_max( a, b ) ( ( a ) > ( b )?( a ) : ( b ) )
#define ll long long
#define MAX_INF 0x3f
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

struct v {
	int p;
	ll c;
};
bool cmp( v a, v b ) {
	return a.c > b.c;
}

int num[ 3001 ];
v fuck[ 3001 ];

int main() {
	int n, m;
	int x, sum, index;
	ll y;
	ll ans = 100000000000000, all = 0, now;
	scanf( "%d%d", &n, &m );
	for( int i = 1; i <= n; ++i ) {
		scanf( "%d%lld", &x, &y );
		if( x == 1 )
			y = 0;
		fuck[ i ].p = x;
		fuck[ i ].c = y;
		all += y;
	}
	sort( fuck + 1, fuck + 1 + n, cmp );
	for( int i = 1; i <= n; ++i ) {
		now = all;
		memset( num, 0, sizeof( num ) );
		sum = 0;
		index = 1;
		while( sum < i && index <= n ) {
			if( num[ fuck[ index ].p ] + 1 < n - i ) {
				++num[ fuck[ index ].p ];
				--num[ 1 ];
				++sum;
				now -= fuck[ index ].c;
			}
			++index;
		}
		if( now < ans ) {
			ans = now;
		}
		if( sum < i )
			break;
	}
	printf( "%lld", ans );
	return 0;
}