#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int binexp(int a,int b,int m=1e9+7)

{

   if(b==0) return 1;

   int x=binexp(a,b/2,m)%m;

   if(b%2) x=((a%m)*(x*1LL*x)%m)%m;

   else x=(x*1LL*x)%m;

   return x%m;

}

long long kr(long long &p,long long ma,long long tem)

{

   long long ans=tem/p;

   if(ans==0) return (tem-min(ma-1,tem));

   long long mod=tem%p;

   return (tem-(min(mod+1,ma)+ma-1+ma*(ans-1)));

}

void ram()

{  

   long long a,b,q;

   cin>>a>>b>>q;

   long long re=a*b/__gcd(a,b)-max(a,b);

   long long p=a*b/__gcd(a,b);

   while(q--)

   {

      long long l,r;

      long long ans=0;

      cin>>l>>r;

      if(__gcd(a,b)==min(a,b)){

         cout<<0<<" ";

         continue;

      }

      cout<<(kr(p,max(a,b),r)-kr(p,max(a,b),l-1))<<" ";

   }

   cout<<endl;

}

int main()

{ 

   IOS

   int t=1;

   cin>>t;

   while (t--) ram();

}