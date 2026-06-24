#include <bits/stdc++.h>

#define lli long long int
#define ld long double
#define pb push_back
#define mod (int)1e9 + 7

using namespace std;

int x , digits , eight , res;
char y;

int main(){

    ios::sync_with_stdio( 0 ); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen( "in.c"  , "r" , stdin  );
        //freopen( "OutPut.txt" , "w" , stdout );
    #endif

    cin >> x;
    for ( int i = 0; i < x; i++ )
    {
        cin >> y;
        if ( y == '8' ) eight++;
        else digits++;
    }

    int sum = digits + eight;
    sum /= 11;

    cout << min( sum , eight );

    return 0;
}