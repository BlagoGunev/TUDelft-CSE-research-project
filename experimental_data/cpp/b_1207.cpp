#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll nm[55][55];
bool vis[55][55];
vector<pair<ll,ll> >vec;
int main()
{
   ll a,b,c,d,e,i,j,k,l,n,m,x,y,t,p;
   scanf("%lld%lld",&n,&m);
   memset(vis,false,sizeof(vis));
   memset(nm,0,sizeof(nm));
   for(i=1;i<=n;i++)
   {
       for(j=1;j<=m;j++)
       {
           scanf("%lld",&nm[i][j]);
       }
   }
   for(i=1;i<=n;i++)
   {
       for(j=1;j<=m;j++)
       {
           if(nm[i][j]==1)
           {
               if(nm[i+1][j]==1 && nm[i][j+1]==1 && nm[i+1][j+1]==1)
               {
                   vec.push_back({i,j});
                   vis[i][j]=vis[i+1][j+1]=vis[i][j+1]=vis[i+1][j]=true;
               }
               else if(vis[i][j]==false)
               {
                   printf("-1\n");
                   return 0;
               }
           }
       }
   }
   l=vec.size();
   printf("%lld\n",l);
   for(i=0;i<l;i++)
   {
       printf("%lld %lld\n",vec[i].first,vec[i].second);
   }

}