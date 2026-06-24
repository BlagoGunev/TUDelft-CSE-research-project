#include<bits/stdc++.h>

#define ll long long

#define endl "\n"

#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

using namespace std;

ll n,m,k,t,ans;

int main(){

fast

cin>>t;

while(t--){

    cin>>n>>k;

    if(n>k){ans=k;}

    

    else{ans=ceil(double(k)/(n-1))+k-1;}

    

    cout<<ans<<endl;

}



    return 0;

}