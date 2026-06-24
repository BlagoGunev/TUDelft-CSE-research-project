#include<bits/stdc++.h>

using namespace std;



int main()

{

int t=1;cin>>t;



while(t--)

{

   int n;cin>>n;

   vector<int>v1(n),v2(n);

   int c=0,d=0;

  

   for(int i=0;i<n;i++){

       cin>>v1[i];

       

   }

    for(int i=0;i<n;i++){

       cin>>v2[i];

       

   }

   for(int i=0;i<n;i++){

       c += abs(v1[i]-v2[i]);

       d +=v1[i]-v2[i];

   }

 //  cout<<c<<" "<<abs(d)+1;

   cout<<min(abs(d)+1,c)<<endl;





}

}