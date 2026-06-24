#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define mod 1000000007 





void solve (){

   ll n,r;

   ll res;

   cin>>n>>r;

   if (n>r){

    res=(r*(r+1))/2;

   }

   else  res=(n*(n-1))/2+1;

   cout<<res<<endl;

}



int main(){

    int t;

    cin>>t;

    while(t--){

      solve();

    }

    return 0;

}