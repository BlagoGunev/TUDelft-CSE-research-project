#include<bits/stdc++.h>
using namespace std;
 
#define int long long 

// #ifndef ONLINE_JUDGE
// #include "debug.cpp"
// #else
// #define debug(...)
// #define debugArr(arr,n)
// #endif
 
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
 
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// find_by_order, order_of_key (SET)
 
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
// find_by_order, order_of_key (MULTISET)  
 
 
int mod=1e9+7;
 
 
void solve(){
    int n,k,q;cin>>n>>k>>q;
    vector<int> v(n);
    for(int& i : v) cin>>i;
    map<int,int> mp;
    set<vector<int>> ms;

    vector<int> ans(n);
    for(int i=0;i<k;i++) mp[v[i]-i]++;
    for(auto i : mp) ms.insert({i.second,i.first});
    
    ans[0]=(k-(*(--ms.end()))[0]);
        
    for(int i=k;i<n;i++){
        ms.erase({mp[v[i-k]-(i-k)],v[i-k]-(i-k)});
        mp[v[i-k]-(i-k)]--;
        ms.erase({mp[v[i]-i],v[i]-i});
        mp[v[i]-i]++;
        ms.insert({mp[v[i-k]-(i-k)],v[i-k]-(i-k)});
        ms.insert({mp[v[i]-i],v[i]-i});
        ans[i-k+1]=(k-(*(--ms.end()))[0]);
    }

    while(q--){
        int l,r;cin>>l>>r;
        cout<<ans[l-1]<<'\n';
    }

}   
 
 
signed main(){
 
    clock_t tStart = clock();
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("debug.txt", "w", stderr);
    // #endif
 
    int t=1;
    cin >> t;
 
    while(t--){
        solve();
    }
 
    // #ifndef ONLINE_JUDGE
    // cout<<'\n'<<"Time taken : "<<setprecision(10)<<((double)(clock()-tStart)/CLOCKS_PER_SEC)*1000<<" ms"<<'\n';    
    // #endif
 
    return 0;
}