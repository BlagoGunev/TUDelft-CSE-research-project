#include <bits/stdc++.h>



using namespace std;

int t,n,k,p,i,y;

int v[200005];

int dp[2][200005];

int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(0);



    cin>>t;

    while(t)

    {

        t--;

        cin>>n>>k;

        for(i=1;i<=n;i++)

            cin>>v[i];

        for(i=1;i<=n;i++)

            cin>>y;



        sort(v+1, v+n+1);



        p=1;

        for(i=1;i<=n;i++)

        {

            while(v[p]<v[i]-k)

                p++;



            dp[0][i]=max(dp[0][i-1], i-p+1);

        }



        p=1;

        for(i=1;i<=n;i++)

        {

            while(v[p]<v[i]-k)

                p++;



            dp[1][i]=max(dp[1][i-1], dp[0][p-1]+i-p+1);

        }



        cout<<dp[1][n]<<'\n';

    }

    return 0;

}