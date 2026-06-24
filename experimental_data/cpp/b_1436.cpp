#include<bits/stdc++.h>

using namespace std;

#define int int long long 

#define endl '\n'

void solve(){

        int n;  cin>>n;

        vector<int>v;

        v.push_back(1);

        v.push_back(1);

        bool f=0;

        for(int i=0;i<n-2;i++)

        {

          v.push_back(0);

        }

        

        for (int i = 0; i < n; ++i)

         {

          int j=i;

          int c=0;

           while(c!=n)

           {

            cout<<v[j]<<" ";

            c++;

            if(j==n-1)

            {

              j=0;

            }

            else

            {

            j++;

          }

            

           }

           cout<<endl;

         }

         

         

    }

  

    

 



signed  main(){

    ios_base::sync_with_stdio(false), cin.tie(0);



    int t;

    cin >> t;

    

    while(t--){

        

        solve();

    }



    return 0;

}