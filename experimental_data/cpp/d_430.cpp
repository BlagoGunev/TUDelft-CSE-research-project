#include <iostream>

#include <stdio.h>

#include <string.h>

#define MAXN 1010



using namespace std;



int n , m , a[ MAXN ][ MAXN ] , f1[ MAXN ][ MAXN ] , f2[ MAXN ][ MAXN ] , f3[ MAXN ][ MAXN ] , f4[ MAXN ][ MAXN ] , ans;



inline int read()

{

	register int x = 0 , ch = getchar();

	while( !isdigit( ch ) ) ch = getchar();

	while( isdigit( ch ) ) x = x * 10 + ch - '0' , ch = getchar();

	return x;

}



int main()

{

	n = read() , m = read();

	for( register int i = 1 ; i <= n ; i++ )

		for( register int j = 1 ; j <= m ; j++ )

			a[i][j] = read();

	memset( f1 , -62 , sizeof( f1 ) );

	memset( f2 , -62 , sizeof( f2 ) );

	memset( f3 , -62 , sizeof( f3 ) );

	memset( f4 , -62 , sizeof( f4 ) );

	f1[0][1] = 0;

	for( register int i = 1 ; i <= n ; i++ )

		for( register int j = 1 ; j <= m ; j++ )

			f1[i][j] = max( f1[i - 1][j] , f1[i][j - 1] ) + a[i][j];

	f2[n + 1][1] = 0;

	for( register int i = n ; i ; i-- )

		for( register int j = 1 ; j <= m ; j++ )

			f2[i][j] = max( f2[i + 1][j] , f2[i][j - 1] ) + a[i][j];

	f3[0][m] = 0;

	for( register int i = 1 ; i <= n ; i++ )

		for( register int j = m ; j ; j-- )

			f3[i][j] = max( f3[i - 1][j] , f3[i][j + 1] ) + a[i][j];

	f4[n + 1][m] = 0;

	for( register int i = n ; i ; i-- )

		for( register int j = m ; j ; j-- )

			f4[i][j] = max( f4[i + 1][j] , f4[i][j + 1] ) + a[i][j];

	for( register int i = 2 ; i < n ; i++ )

		for( register int j = 2 ; j < m ; j++ )

			ans = max( ans , max( f1[i - 1][j] + f2[i][j - 1] + f3[i][j + 1] + f4[i + 1][j] , f1[i][j - 1] + f2[i + 1][j] + f3[i - 1][j] + f4[i][j + 1] ) );

	cout << ans << endl;

	return 0;

}