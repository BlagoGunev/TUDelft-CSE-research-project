#include<bits/stdc++.h>

using namespace std;

const int  N = 155;

int n,m,i,j ,dp[N][2],now,cur,fut,ans;

char s[N][N];

int main()

{

    ios::sync_with_stdio(false);cin.tie(0);

    cin >> n >> m;

    for( i = 0 ; i < n ; i++ ) cin >> s[i];    

    for( i = 0 ; i < n ; i++ )

        {

           dp[i][0] = m + 1 , dp[i][1] = -1;

             for( j = 0 ; j < m ; j++ )

                 if( s[i][j] == 'W' )

                     dp[i][0] = min( dp[i][0] , j ) , dp[i][1] = max( dp[i][1] , j);   

        }

      while( n > 1 && dp[n-1][0] == m + 1  ) --n;

        dp[n][0] = m +1 , dp[n][1] = -1;

    for( i = 0 ; i < n ; i++ )

         if( i%2 == 0) 

         {

             fut =  max(cur , max( dp[i][1] , dp[i+1][1] ) );

             ans += fut - cur + 1;

             cur = fut; 

         }

         else

         {

             fut =  min(cur , min( dp[i][0] , dp[i+1][0] ) );

             ans += cur - fut + 1;

             cur = fut; 

         }

    cout << ans - 1;

    return 0;

}