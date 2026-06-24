#include <bits/stdc++.h>

using namespace std;



typedef long long ll;

typedef vector< int > vi;

typedef vector< vi > vvi;

typedef vector< vvi > vvvi;

typedef vector< vvvi > vvvvi;

typedef vector< ll > vl;

typedef vector< vl > vvl;

typedef vector< vvl > vvvl;

typedef vector< vvvl > vvvvl;

typedef pair< int, int > pii;

typedef vector< pii > vp;

typedef vector< vp > vvp;

typedef vector < string > vs;

typedef vector< vs > vvs;

typedef vector< double > vd;

typedef vector< vd > vvd;



const int INF = 0x3f3f3f3f;

const int MOD7 = ( int ) 1e9 + 7;



template< class T1, class T2 >

int upmin( T1 &x, T2 v ){

    if( x > v ){

        x = v;

        return 1;

    }

    return 0;

}



template< class T1, class T2 >

int upmax( T1 &x, T2 v ){

    if( x < v ){

        x = v;

        return 1;

    }

    return 0;

}



int N;

vi A;



void init(){

    cin >> N;

    A = vi( N + 1 );

    for( int i = 0; i < N; ++i )

        cin >> A[ i ];

}



void preprocess(){



}



int dfs( int lb, int rb, int h ){ // [ lb, rb )

    if( lb >= rb )

        return 0;

    int mid = lb;

    for( int i = lb; i < rb; ++i )

        if( A[ mid ] > A[ i ] )

            mid = i;

    return min( rb - lb, A[ mid ] - h + dfs( lb, mid, A[ mid ] ) + dfs( mid + 1, rb, A[ mid ] ) );

}



void solve(){

    cout << dfs( 0, N + 1, 0 ) << endl;

}



signed main(){

    ios::sync_with_stdio( 0 );

    init();

    preprocess();

    solve();

    return 0;

}