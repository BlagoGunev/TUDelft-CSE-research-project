#include<bits/stdc++.h>

#define endl "\n"

typedef long long ll;

typedef long double lld;

typedef unsigned long long ull;

const lld pi = 3.14159265358979323846;

const ll mod = 1000000007;

 

using namespace std;



int32_t main(){

 ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 ll t; cin>>t; 

 while(t--){

   ll l,r,x,a,b; cin>>l>>r>>x>>a>>b;

   if(a==b){cout<<0<<endl;}

   else if(abs(l-a)<x && abs(r-a)<x){cout<<-1<<endl;}

   else if(abs(l-b)<x && abs(r-b)<x){cout<<-1<<endl;}

   else{

    if(abs(b-a)>=x){cout<<1<<endl;}

    else if(abs(b-l)>=x && abs(a-l)>=x){cout<<2<<endl;}

    else if(abs(r-a)>=x && abs(r-b)>=x){cout<<2<<endl;}

    else{cout<<3<<endl;}

   }

 }

    

    return 0;

}