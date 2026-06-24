#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fs first
#define sc second
#define pb push_back

void solve() {
    ll n,k;
    cin>>n>>k;
    ll a[n],b[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    auto calc=[&](ll x){
        pll p;
        for(int i=0;i<n;i++){
            if(a[i]<x)continue;
            ll c=(a[i]-x)/b[i]+1;
            p.fs+=c;
            p.sc+=c*(a[i]+a[i]-b[i]*(c-1))/2;
        }
        return p;
    }; 
    ll l=0,r=1e9;
    while(l<r){
        ll m=(l+r+1)/2;
        if(calc(m).fs>=k)l=m;
        else r=m-1;
    }
    pll p=calc(l);
    cout<<p.sc-(p.fs-k)*l<<'\n';
}

int main() {   
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;cin>>t;while(t--)solve();
}