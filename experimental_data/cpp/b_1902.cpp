#include<bits/stdc++.h>
using namespace std;

using ll=long long;using ull=unsigned long long;using pii=pair<int,int>;
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define YES puts("YES")
#define NO puts("NO")
#define Yes puts("Yes")
#define No puts("No")

#ifndef ONLINE_JUDGE
#include "template/debug.hpp"
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    ll n,l,t,P;
    cin>>n>>P>>l>>t;

    ll cntTask = (n-1)/7 + 1;
    
    ll k1 = t*2 + l;
    if(k1*(cntTask/2) > P){
        cout << n - (P+k1-1)/k1 << '\n';
        return; 
    }
    P -= k1*(cntTask/2);

    if(cntTask%2==1){
        if(P<=t+l){
            cout << n - cntTask/2 - 1 << '\n';
            return;        
        }
        else P -= t+l;
    }
    ll work = (cntTask+1)/2 + (P+l-1)/l;
    cout << n - work << '\n';
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int T; cin>>T;
    while(T--)solve();
    return 0;
}