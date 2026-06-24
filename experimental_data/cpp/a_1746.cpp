#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long loint;
typedef unsigned long long unlo;
void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(n);
    bool ok = false;
    for(int i = 0;i<n;i++){
        cin>>a[i];
        if(a[i]==1)ok = true;
    }
    if(ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    solve();
//    freopen("", "r", stdin);
//    freopen("", "w", stdout);
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}