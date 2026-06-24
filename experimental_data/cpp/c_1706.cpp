#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define T int t;cin>>t;while(t--)

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){

    fast

    T{

        int n;cin>>n;

        vector<ll>v(n);

        for(int i=0;i<n;i++){

            cin>>v[i];

        }

        vector<ll>cost(n,0);

        for(int i=1;i<n-1;i++){

            cost[i]=max(0LL,max(v[i-1],v[i+1])-v[i]+1);

        }

        ll ans=0;

        if(n&1){

           for(int i=1;i<n-1;i+=2){

               ans+=cost[i];

           }

        }

        else{

            for(int i=2;i<n-1;i+=2){

                ans+=cost[i];

            }

            ll x=ans;

            for(int i=1;i<n-1;i+=2){

                x-=cost[i+1];

                x+=cost[i];

                ans=min(ans,x);

            }

        }

        cout<<ans<<'\n';

    }

}