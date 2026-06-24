#include <bits/stdc++.h>

#define db long double
#define int long long
#define pb push_back
#define pf push_front
#define PB pop_back
#define PF pop_front
#define mp make_pair
#define vec vector
#define endl "\n"
#define S second
#define F first

#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define max3( a, b, c ) max ( a, max ( b, c ) )
#define min3( a, b, c ) min ( a, min ( b, c ) )

#define MAX 100100
#define MOD 1000000009
#define INF 2100000000
const db pi = 2 * acos ( 0.0 );

using namespace std;

int32_t main ()
{
    int q;

    cin >> q;

    while ( q -- )
    {
        int m[4];

        cin >> m[0] >> m[1] >> m[2];

        sort ( m, m + 3 );

        int a = m[0], b = m[1], c = m[2];

        if ( a == b and a != c )
            if ( c - a == 1 ) -- c;
            else
                -- c, ++ b, ++ a;

        else if ( b == c and a != c )
            if ( c - a == 1 ) ++ a;
            else -- c, -- b, ++ a;

        else if ( a != b and b != c and a != c )
            ++ a, -- c;

        cout << 2 * ( c-a ) << endl;
    }

    return 0;
}