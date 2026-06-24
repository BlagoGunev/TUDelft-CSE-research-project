#include <iostream>

#include <cstdio>

#include <stack>

#include <queue>

#include <vector>

#include<algorithm>

#include<math.h>

#include<utility>

#include<map>

#include<set>

#include <string.h>

using namespace std;



#define ll long long int



ll dp[1000000];







main()

{

    ll i,j,k,l,n,r,t,q,b,x,y,c,p,ans,sum,z,s;

    dp[0]=1;

    ans=0;

    for(i=1;i<=17;i++)

        {dp[i]=dp[i-1]*4;

        //cout<<dp[i]<<endl;



        }



        cin>>n;



   for(i=1;i<=n;i++)

   {

       scanf("%I64d%I64d",&k,&x);

       if(x==1)

       {

               y=k+1;

               //cout<<y<<endl;

               if(y>ans)

                  ans=y;

              continue;



       }



       for(j=0;j<=17;j++)

       {

           //cout<<dp[j]<<" lol  ";

           if(dp[j]>=x)

           {

               y=k+j;

               //cout<<y<<endl;

               if(y>ans)

                  ans=y;

                break;

           }





       }

   }





   cout<<ans;



}