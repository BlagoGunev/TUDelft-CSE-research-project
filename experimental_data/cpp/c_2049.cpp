#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
ll gg(const unordered_set<ll>& h){
    ll cc=0;
    while(h.count(cc))++cc;
    return cc;}
    int main(){
    fast;
    int t;cin>>t;
    while(t--){
        ll n,x,y;cin>>n>>x>>y;vector<ll> a(n,-1);
        for(ll i=0;i<n;++i)a[i]=i%(n+1);
        for(ll i=0;i<n;++i){
            unordered_set<ll> kk;
            kk.insert(a[(i+n-1)%n]);
            kk.insert(a[(i+1)%n]);
            if(i==x-1)kk.insert(a[y-1]);
            if(i==y-1)kk.insert(a[x-1]);
            a[i]=gg(kk);}
        for(int ai:a)cout<<ai<<" ";
        cout<<endl;}
    return 0;}