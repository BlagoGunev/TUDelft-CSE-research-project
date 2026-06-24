#include<bits/stdc++.h>

using namespace std;

#define int long long



signed main()

{

    int t;

   cin>>t;

    while(t--)

    {

       int n,m;

       cin>>n;

       if(n%2==1)

       {

           cout<<1<<" ";

            for(int i=2;i<=n;i++)

            {

           if(i%2==0)

           {

           cout<<i+1<<" ";

           }

           else

           cout<<i-1<<" ";

           

            }

            cout<<endl;

           

           continue;

       }

       

       for(int i=1;i<=n;i++)

       {

           if(i%2==1)

           {

           cout<<i+1<<" ";

           }

           else

           cout<<i-1<<" ";

           

       }

       cout<<endl;

    }

      

       

    

    

}