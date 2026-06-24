#include<bits/stdc++.h>
using namespace std;
#define long long int
void solve(){
    int n;
    cin>>n;
    unordered_map<int,int>mp;
    vector<int>v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(!mp[a]){
            v.push_back(a);
        }
        mp[a]++;
    }
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=0;i<v.size();i++){
        int lb=(lower_bound(v.begin(),v.end(),v[i]+n)-v.begin())-i;
        ans=max(ans,lb);
    }
    cout<<ans<<"\n";
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}