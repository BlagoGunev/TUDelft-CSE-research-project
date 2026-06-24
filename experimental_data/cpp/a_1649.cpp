//============================================================================
// Name        : SICK.cpp
// Author      : SICK-MAN
// Version     : 2021
// Description : BARA CHIKH
//============================================================================
#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define ll long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define endl "\n"
using namespace std;
const int MOD = 998244353   ;
const ll bl = 500;
const int N = 1e6+5;

void solv(){
      int n;
        cin>>n ;
         vector<int>v(n);
          for(int i = 0 ;i < n ; i++) cin>>v[i];
           ll ans = 0 ;
           int j = 0 ;
           for(int i = 1 ; i < n; i++) {
               if( v[i] == 0 ) {
                  j  = i ;
                  break;
               }
           }
           int k = 0 ;
           for(int i = n-2 ; i > 0 ; i-- ) {
              if( v[i] == 0) {
                 k = i ;
                 break;
              }
           }
         if( k == 0 && j == 0 ) cout<<0<<endl;
         else {
             cout<<k-j+2<<endl;
         }

}

int main(){
   // freopen("txt.txt","w",stdout);
    FAST ;
     int t  = 1 ;
      cin>>t;
         while(t--){
            solv();
         }
}