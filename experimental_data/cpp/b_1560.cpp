#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;

const int M=1e9+7,N=100009;

int main()

{

     ios_base::sync_with_stdio(0); cin.tie(0);

     ll T,t,i,n,m,k,a,b;

     cin>>T;

     while(T--){

       cin>>a>>b>>n;

       if(a>b)

         swap(a,b);

       int d=(b-a)*2;

       if(a>d||b>d||n>d){

          cout<<"-1\n";

       }else if(n>(d/2)){

            cout<<n-d/2<<"\n";

       }else{

           cout<<n+d/2<<"\n";

       }



     }

}