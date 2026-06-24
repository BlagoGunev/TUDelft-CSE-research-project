#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define F first 
#define S second 

const int mol=1e9+7;

void solve(){
    string a;
    cin>>a;
    auto p=a;
    sort(a.begin(), a.end());
    if(a[0]==a[a.size()-1]){
        cout<<"NO\n";
    }
    else{
        if(p==a) reverse(a.begin(), a.end());
        cout<<"YES\n";cout<<a<<"\n";
    }
}


signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}