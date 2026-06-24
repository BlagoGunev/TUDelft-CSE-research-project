#include <bits/stdc++.h>
    #include <iostream>
    #include<math.h>
    #include <set>
    #define ll long long
    #define INF LONG_LONG_MAX
    
    using namespace std;

    int main()
    {
     ll n,m;
     cin >> n >> m;
     ll a[n][m];
     for(ll i=0;i<n;i++)
     {
      for (ll j=0;j<m;j++)
      {
       char temp;
       cin >> temp;
       if(temp=='.')a[i][j]=0;
       else a[i][j]=1;
      }
     }


   for(ll i=0;i<n;i++)
     {
      for (ll j=0;j<m;j++)
      {
       if(a[i][j]==1)
       {
        ll north=-1,south=-1,west=-1,east=-1;
        for(ll k=i-1;k>=0;k--)
        {
         if(a[k][j]==1)
         {
          north=k;
          break;
         }
        }
        for(ll k=i+1;k<n;k++)
        {
         if(a[k][j]==1)
         {
          south=k;
          break;
         }
        }
        for(ll k=j-1;k>=0;k--)
        {
         if(a[i][k]==1)
         {
          west=k;
          break;
         }
        }
        for(ll k=j+1;k<m;k++)
        {
         if(a[i][k]==1)
         {
          east=k;
          break;
         }
        }
        if(north>=0 && east>=0)
        {
         if(a[north][east]==0)
         {
          cout<<"No";
          return 0;
         }
        }
        if(north>=0 && west>=0)
        {
         if(a[north][west]==0)
         {
          cout<<"No";
          return 0;
         }
        }
        if(south>=0 && west>=0)
        {
         if(a[south][west]==0)
         {
          cout<<"No";
          return 0;
         }
        }
        if(south>=0 && east>=0)
        {
         if(a[south][east]==0)
         {
          cout<<"No";
          return 0;
         }
        }
       }
      }
     }
     cout<<"Yes";
     return 0;
    }