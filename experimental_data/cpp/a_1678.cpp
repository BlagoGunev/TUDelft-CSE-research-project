#include<bits/stdc++.h>

using namespace std;

typedef long long int LLI;

    LLI t,n,m,i,j,k,x,f[200005],ans;

int main(){

    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>t; 

    while(t--){

        cin>>n; fill(f,f+102,0); LLI ok=0;

        for(i=1;i<=n;i++) {

            cin>>x;f[x]++;

            if(x==0) ok++;

        }

        if(ok) ans=n-ok;

        else {

            for(i=1;i<=100;i++) if(f[i]>1) ok=1;

            if(ok) ans=n;else ans=n+1;

        }

        cout<<ans<<endl;

    }

    return 0;

}