#include <bits/stdc++.h>
#define pb push_back
using namespace std;

void solve(){
    int n;cin>>n;
    int b[n];
    for(auto &it:b)  cin>>it;
    vector<int>ans;
    ans.pb(b[0]);
    for(int i=1;i<n;i++ ){
        if(b[i]>=b[i-1]){
            ans.pb(b[i]);
        }
        else{
            ans.pb(1);
            ans.pb(b[i]);
        }
    }
    cout<<ans.size()<<"\n";
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<"\n";
    
    
}

int main() {
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}