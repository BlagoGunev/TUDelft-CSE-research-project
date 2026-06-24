#include<bits/stdc++.h>

using namespace std;

 

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

 

#define fix(n,f) std::fixed<<std::setprecision(f)<<n

#define ll long long 

#define all(v) v.begin(),v.end()

#define nl "\n"

#define M 1000000007 

#define sum(a,b) ((a%M)+(b%M))%M

#define pro(a,b) ((a%M)*(b%M))%M

#define diff(a,b) ((a%M)-(b%M))%M



/*=================================== Bow to Lord Shiva  =================================*/

void Print(vector<ll> v){

    for(auto &p:v){cout<<p<<" ";}cout<<nl;

}

void solve(){

    ll n,m;cin>>n>>m;

    if(m<n){

        cout<<"No"<<nl;

        return;

    }

    if(n&1){

        cout<<"Yes"<<nl;

        for(ll i=0;i<n-1;i++){

            cout<<1<<" ";

        }

        cout<<m-n+1<<nl;

    }

    else{

        if(m%2==0){

            cout<<"Yes"<<nl;

            for(ll i=0;i<n-2;i++){

                cout<<1<<" ";

            }

            cout<<(m-n+2)/2<<" "<<(m-n+2)/2<<nl;

        }

        else{

            cout<<"No"<<nl;

        }

    }

}



int main(){

    fastio();

   // freopen("input.txt", "r" ,stdin);

   // freopen("output.txt", "w" ,stdout);

    int t=1;

    cin>>t;

    while(t--){

        solve();    

    }

}