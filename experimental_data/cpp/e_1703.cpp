#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

typedef long long int ll;

using namespace std;

#define sz 306

#define sz1 1001

#define mod1 1000000007

#define mod 998244353

#define pr1 67

#define pr2 61

#define f first

#define s second

#define pa pair<ll,ll>

#define vec array<ll,4>

const ll mx=10000000000000000ll;

const ll inf = 100000000000000000ll;

string c[sz];

int vis[sz][sz];

int main()

{ 

  ios_base::sync_with_stdio(0);cin.tie(0);

  int test_case=1;

   cin>>test_case;

   

   for(int cs=1;cs<=test_case;cs++)

   {

     ll n;

     cin>>n;

     ll ans=0;

     for(int i=0;i<n;i++)

     {

      cin>>c[i];

     }

     for(int j=0;j<n;j++)

     {

      for(int i=0;i<n;i++){

        int a1=0,b1=0;

        

        if(!vis[i][j])

        {

        if(c[i][j]=='1')

          a1++;

        else

          b1++;

        vis[i][j]=1;

        }



        if(!vis[j][n-1-i])

        {

           if(c[j][n-1-i]=='1')

          a1++;

        else

          b1++;

        vis[j][n-1-i]=1;

        }



        if(!vis[n-1-i][n-1-j])

        {

           if(c[n-1-i][n-1-j]=='1')

          a1++;

        else

          b1++;

        vis[n-1-i][n-1-j]=1;

        }



        if(!vis[n-1-j][i])

        {

           if(c[n-1-j][i]=='1')

          a1++;

        else

          b1++;

        vis[n-1-j][i]=1;

        }



        ans+=min(a1,b1);

    }

     }

     cout<<ans<<"\n";

     for(int i=0;i<n;i++)

     for(int j=0;j<n;j++)

     vis[i][j]=0; 

    }



  return 0;

}