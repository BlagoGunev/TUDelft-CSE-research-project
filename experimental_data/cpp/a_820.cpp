#include <cstdio>

using namespace std;

int main()
{
    int c, v0, v1, a, l, v, w, days = 1; scanf( "%i%i%i%i%i", &c, &v0, &v1, &a, &l );

    for( c -= v0, v = v0; c > 0; c -= w, days++ )
    {
        if ( a > 0 ) if ( ( v  += a ) > v1 ) v = v1;

        w = v; if ( l > 0 ) { w -= l; }
    }

    printf( "%i", days );
}