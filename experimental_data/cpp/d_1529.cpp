#include<bits/stdc++.h>

using namespace std;



int n,sm,mod=998244353,a[1000001];



int main(){

    ios::sync_with_stdio(0);cin.tie(0);

    cin>>n;

    for(int i=1;i<=n;++i){

        for(int j=i;j<=n;j+=i){

            ++a[j];

        }

    }

    for(int i=1;i<=n;++i){

        a[i]=(a[i]+sm)%mod;

        sm=(sm+a[i])%mod;

    }

    cout<<a[n]<<'\n';

}