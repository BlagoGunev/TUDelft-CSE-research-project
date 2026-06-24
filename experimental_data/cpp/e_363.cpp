/* In the name of ALLAH */



#include <bits/stdc++.h>

#define int long long

#define ld long double



using namespace std;



const int MAXN = 555 , MOD = 1e9 + 7;



int ps [ MAXN ] [ MAXN ] = {} , a [ MAXN ] [ MAXN ] = {} , w [ MAXN ] [ MAXN ] = {} , dp [ MAXN ] [ MAXN ] = {}  ;



int dp2 [ MAXN ] [ MAXN ] = {}  , dp3[ MAXN ]  [ MAXN ]  = {} , dp4 [ MAXN ] [ MAXN ] = {} , qqq [ MAXN ] = {};



int dis(int x1 , int y1 , int x2 , int y2 )

{

    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);

}



bool ok(int i , int j , int r )

{

    int x = i / 2 , y = j /2 ;

    for(int x1 = x - 3 ; x1 <= x+3 ; x1 ++ )

    {

        for(int y1 = y-3 ; y1<=y+3;y1++)

            if(dis(0,0,x1,y1)<=r*r&&dis(i,j,x1,y1)<=r*r)

                return 1 ;

    }

    return 0 ;

}



main()

{

   ios::sync_with_stdio(0);

   cin.tie(0);

   int n,m,r;

   cin >> n >> m >> r  ;

    for(int j = 0 ; j < m ; j ++ )

    {

        int x = 0 ;

        for(int i = 0 ; j < n ; i ++ )

        {

            if(ok(i,j,r))

                x=i;

            else

                break;

        }

        qqq[j] = x  ;

    }

    for(int i = 1 ; i <= n ; i ++ )

    {

        for(int j = 1 ; j <= m ; j ++ ){

            cin >> a[i][j] ;

            ps[j][i] =  ps[j][i-1] + a[i][j] ;

        }

    }



    for(int i = r+1 ; i <= n-r ; i ++ )

    {

        for(int j = r+1 ; j <= m-r ; j ++ )

        {

            for(int k = j-r ; k <= j+r ; k ++ )

            {

                int x = sqrt(r*r-(j-k)*(j-k));

                w[i][j] += ps[k][i+x] - ps[k][i-x-1] ;

            }

        }

    }

    for(int i = 1 ; i <= n; i ++ )

    {

        for(int j = 1 ; j <= m ; j ++ )

        {

            dp[j][i] = dp[j][i-1];

            dp3[j][i] = dp3[j][i-1];

            if(w[i][j]>dp[j][i])

                dp3[j][i] = 0 ;

            dp[j][i] = max(dp[j][i],w[i][j]);

            if(w[i][j]==dp[j][i])

                dp3[j][i] ++ ;





        }

    }

    for(int i = n ; i ; i --  )

    {

        for(int j = 1 ; j <= m ; j ++ )

        {

            dp2[j][i] = dp2[j][i+1];

            dp4[j][i] = dp4[j][i+1];

            if(w[i][j]>dp2[j][i])

                dp4[j][i] = 0 ;

            dp2[j][i] = max(dp2[j][i+1],w[i][j]);

            if(w[i][j]==dp2[j][i])

                dp4[j][i] ++ ;

        }

    }

    int ans =0 , x = 0 ;

    r*=2;



    for(int i = 1 ; i <= n ; i ++ )

    {



        for(int j = 1 ; j <= m ; j ++ )

        {

            if(!w[i][j])

                continue;

            int mx =  -10000000 , ww = 0 ,fk=0;

            for(int k = max(0ll,j-r) ; k <= j+r ; k ++ )

            {

                if(k>m)

                    break;

                int x = qqq[abs(j-k)];

                if(dp[k][max(0ll,i-x-1)]>mx)

                    ww=0,mx=dp[k][max(1ll,i-x-1)];

                if(dp[k][max(0ll,i-x-1)]==mx)

                    ww+=dp3[k][max(1ll,i-x-1)];



                if(dp2[k][min(n+1,i+x+1)]>mx)

                    ww=0,mx=dp2[k][min(n,i+x+1)];

                if(dp2[k][min(n+1,i+x+1)]==mx)

                    ww+=dp4[k][min(n,i+x+1)];

            }

            for(int k = 1 ; k < j - r ; k ++ )

            {

                if(dp[k][n]>mx)

                    ww=0,mx=dp[k][n];

                if(dp[k][n]==mx)

                    ww+=dp3[k][n];

            }

            for(int k = j+r+1 ; k <= m ; k ++ )

            {

                if(dp[k][n]>mx)

                    ww=0,mx=dp[k][n];

                if(dp[k][n]==mx)

                    ww+=dp3[k][n];

            }

            if(!mx)

                continue;

            if(w[i][j]+mx>ans)

                ans=w[i][j]+mx,x=0;

            if(w[i][j]+mx==ans)

                x+=ww;



        }



    }

    if(x%2==1)

        cout<<x<<endl;







    cout<<ans<<' '<<x/2<<endl;





}