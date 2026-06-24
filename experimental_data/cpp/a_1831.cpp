#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> pll;
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vpll vector<pll>
#define ff first
#define ss second
//#define mp make_pair
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define PN cout<<"No\n"
#define PY cout<<"Yes\n" 
const int inf=INT_MAX;
long long mod = 1e9+7;  

void solve(){
    ll n;
    cin>>n;
    vll v(n);
    rep(i,n){
        cin>>v[i];
    }
    rep(i,n){
        cout<<n+1-v[i]<<" ";
    }
    cout<<"\n";
}


int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    //build();
    int x=0;
    while(t--){
        x++;
        //cout<<"Case #"<<x<<": ";
        solve();
    }
    return 0;
}