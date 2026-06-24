#include<bits/stdc++.h>

using namespace std;

int main()

{

    int64_t n,m;

    cin>>n>>m;

   int64_t ans=(n+m)/3;

   if(ans>n || n==0 || m==0)

   {

       cout<<min(n,m)<<endl;

   }

   else if(ans>m)

   {

       cout<<m<<endl;

   }

   else

    cout<<ans<<endl;

}