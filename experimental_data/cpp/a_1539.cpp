#include<bits/stdc++.h>

using namespace std;

typedef long long  int ll;



int main(){

    int k;

    cin>>k;

    while(k--){

        ll n,m,t;

        cin>>n>>m>>t;

        ll x=t/m;

        if(x<n){



        cout<<(n-x)*x+(x*(x-1))/2<<endl;

        }

        else{

            cout<<n*(n-1)/2<<endl;

        }

        

    }



    return 0;

}