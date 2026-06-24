#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

#define LL long long
#define mod 1000000007
#define eps 1e-8

bool g[305][305], a[305];

int main()
{
    int n, m, k, x;
    cin >> n >> m >> k;
    for( int i = 1; i <= k; ++i )
        cin >> x, a[x] = true;
    if( k == n ) {
        puts( "-1" );
        return 0;
    }
    k = 1;
    while( a[k] ) ++k;
    int l = 1; while( a[l] == 0 ) ++l;
    int r = l + 1; while( a[r] == 0 ) ++r;
    for( int i = 1; i <= n; ++i ) if( i != k ) g[i][k] = 1;
    m -= n - 1;
    for( int i = 1; i <= n && m; ++i ) if( i != l )
        for( int j = 1; j <= n && m; ++j ) if( j != l )
            if( i != j && g[i][j] == 0 && g[j][i] == 0 )
                g[i][j] = 1, --m;
    for( int i = 1; i <= n && m; ++i )
        if( g[l][i] == 0 && g[i][l] == 0 && a[i] == 0 )
            g[i][l] = 1, --m;
    if( m ) {
        puts("-1");
        return 0;
    }
    for( int i = 1; i <= n; ++i )
        for( int j = 1; j <= n; ++j )
            if( g[i][j] )
                printf( "%d %d\n", i, j );
    return 0;
}