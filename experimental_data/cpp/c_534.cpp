#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

#define Nmax 200002

int v[Nmax];

int main(){

    /*freopen ( "date.in", "r", stdin );
    freopen ( "date.out", "w", stdout );
*/
    int N;
    long long A, S = 0, maxval;

    scanf ( "%d%I64d", &N, &A );

    long long st = 0, dr = 0;

    for ( int i = 1; i <= N; ++i ){
        scanf ( "%d", &v[i] );
        S += v[i];
    }

    for ( int i = 1; i <= N; ++i ){
        maxval = S - v[i];

        st = A - maxval;

        if ( st < 1 )
            st = 1;

        dr = A - N + 1;

        if ( v[i] < dr )
            dr = v[i];

        printf ( "%I64d ", st - 1 + v[i] - dr );
    }

    return 0;
}