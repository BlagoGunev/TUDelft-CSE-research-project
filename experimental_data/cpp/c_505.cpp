#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double rl;

#define pb push_back
#define popb pop_back
#define mk make_pair

#if 1
#define dbg(x) cerr << #x << ":" << (x) << endl;
#else
#define dbg(x)
#endif // 0

const int n = 30000;

int answ;
int m, d;
int gems[ n+3 ];

const int diff= 246;
const int midd= 250;
int dp[ 2*n+midd ][ midd*2 ];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen(".out", "w+", stdout);
    //ios_base::sync_with_stdio( false );cin.tie(0); cout.tie(0);

    scanf("%d %d", &m, &d );
    int g;
    for ( int i=0; i<m; i++ )
    {
        scanf("%d", &g );
        gems[ g ]++;
    }

    for ( int i=n; i>=d; i-- )
    {
        for ( int j=-diff; j<=diff; j++ )
        {
            if ( d + j > 0 )
            {
                dp[ i ][ midd+j ] = gems[ i ];
                dp[ i ][ midd+j ] += max( dp[ i+d+j ][ midd+j ],
                        max( (d+j-1 > 0 ) ? dp[ i+d+j-1 ][ midd+j-1 ] : 0,
                            dp[ i+d+j+1 ][ midd+j+1 ]) );
            }
        }
    }

    cout<<dp[ d ][ midd ]<<endl;

    return 0;
}