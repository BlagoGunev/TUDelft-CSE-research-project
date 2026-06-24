#include<bits/stdc++.h>
    using namespace std;
    #define ll long long int
    #define vi vector<int>
    #define vii vector<long long int>
    #define all(x) x.begin(),x.end()
    #define allr(x) x.rbegin(),x.rend()
    #define mod 1000000007
    #define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    void INP(){fast freopen("input.txt" , "r" , stdin); freopen("output.txt" , "w" , stdout);}

    bool customCompare(pair<ll, ll> a, pair<ll, ll> b) {
        if (a.first != b.first) {
            return a.first < b.first;
        }
        return a.second > b.second;
    }
    
    void sol(){
        int n; cin>>n;
        vector<pair<ll , ll>> v;
        for(int i=0 ; i<n ; i++){
            ll a,b; cin>>a>>b;
            v.push_back({a ,b});
        }
        sort(all(v) , customCompare);
        vector<int> mp(n+10 , 0);
        ll ans=0;
        for(auto &it:v){
            if(mp[it.first]>=it.first){
                continue;
            }
            ans+=it.second;
            mp[it.first]++;
            
        }
        cout<<ans<<endl;

    }
    
    int main(){
        #ifndef ONLINE_JUDGE 
        INP(); 
        #endif
    
        int TC=1;
        cin>>TC;
        while(TC--) sol();
    
    }