#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;



string s; 

int sl;



int toInt( int st , int en )

{

    if ( en-st>1 && s[st] == '0' ) return -1e8;

    

    int x = 0;

    while ( st < en )

    {

        x = x*10 + ( s[st] - '0' );

        st++;

    }

    return x;

}



int main()

{

    cin>>s; sl = s.length();

    

    int ans = -1;

    for ( int i=1 ; i<=7 ; i++ )

        for ( int j=i+1 ; j<=i+7 ; j++ )

        {

            int x = sl - j;

            if ( x < 1 || x > 7 ) continue;

            

            int a = toInt( 0 , i );

            int b = toInt( i , j );

            int c = toInt( j , sl );

            

            if ( a > 1e6 || b > 1e6 || c > 1e6 ) continue;

            

            ans = max( ans , a+b+c );

        }

    

    cout<<ans<<"\n";

    

    return 0;

}