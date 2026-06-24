/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll sum1=0,sum2=0;
        for(ll i=0;i<n;i++){
            ll a;
            cin>>a;
            sum1+=a;
        }
        for(ll i=0;i<m;i++){
            ll a;
            cin>>a;
            sum2+=a;
        }
        if(sum1>sum2)
            cout<<"Tsondu"<<endl;
        else if(sum1==sum2)
            cout<<"Draw"<<endl;
        else
            cout<<"Tenzing"<<endl;
    }
    return 0;
}