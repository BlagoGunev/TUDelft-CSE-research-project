#include "bits/stdc++.h"

using namespace std;
#define int long long

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...)
#endif
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        map<int,int> mp;
        for(int i = 0;i<n;i++){
            cin>>a[i];
            mp[a[i]]++;
        }
        int lol = 0 , ans = 0;
        for(int i = 0;i<n;i++){
            if(mp[i]==0)break;
            if(mp[i]>1)ans++;
            if(mp[i]==1){
                if(lol==0)ans++;
                else break;
                lol = 1;
            }
        }
        cout<<ans<<endl;
    }
}