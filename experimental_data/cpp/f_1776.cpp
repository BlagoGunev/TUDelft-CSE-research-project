#include <bits/stdc++.h>



using namespace std;



int edges[ 5005 ][ 5005 ];

int ans[ 5005 * 5005 ];



std::vector<int> e[ 5005 ];

int vis[ 5005 ];

int d[ 5005 ];

 

void solve()

{



    int n,m;cin >> n >> m;



    for( int k = 1 ; k <= n ; k++ )

    {

        vis[ k ] = 0;

        d[ k ] = 0;

        e[ k ].clear();

        for( int i = 1 ; i <= n ; i++ )

            edges[ k ][ i ] = 0;

    }



    int x,y;

    for( int k = 1 ; k <= m ; k++ )

    {

        cin >> x >> y;

        edges[ x ][ y ] = edges[ y ][ x ] = k;

        ans[ k ] = 0;

        d[ x ]++;

        d[ y ]++;

        e[ x ].push_back( y );

        e[ y ].push_back( x );

    }



    cout << 2 + ( m == n * ( n - 1 ) / 2 ) << "\n";



    if( m == n * ( n - 1 ) / 2  )

    {



        for( int k = 2 ; k < n ; k++ )

            ans[ edges[ 1 ][ k ] ] = 1;

        ans[ edges[ 1 ][ n ] ] = 2;

        for( int k = 1 ; k <= m ; k++ )

            cout << ( ans[ k ] == 0 ? 3 : ans[ k ] ) << " \n" [ k == m ];   



    }else{



        for( int k = 1 ; k <= n ; k++ )

            if( d[ k ] < n - 1 )

            {

                for( int i : e[ k ] )

                    ans[ edges[ i ][ k ] ] = 1;

                break;

            }



        for( int k = 1 ; k <= m ; k++ ) cout << ( ans[ k ] == 1 ? 1 : 2 ) << " \n"[ k == m ];



    }



} 



signed main()

{



    cin.tie(0);

    cout.tie(0);

    ios_base::sync_with_stdio(false);



    int t = 1;cin >> t;



    while( t-- ) solve();



    return 0;



}