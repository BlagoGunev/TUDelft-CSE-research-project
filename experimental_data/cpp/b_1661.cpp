#include <bits/stdc++.h>

using namespace std;





#define int long long 

#define mod 1000000007





int32_t main() {

ios_base::sync_with_stdio(false);

cin.tie(NULL);

int t; t=1;

cin>>t;

while(t--){

   int n; cin>>n;



   int aarav=20;



   for(int add=0; add<=20; add++)

   {

      for(int mul=0; mul<=16; mul++)

      {

         if((add+n<<mul)%32768==0)

         aarav=min(aarav,add+mul);

      }

   }

   cout<<aarav<<" ";

}

return 0;

}