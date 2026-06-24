#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n; ll m, k;
        cin>>n>>m>>k;
        vector<ll> h(n); for(auto &x:h) cin>>x;
        vector<ll> x(n); for(auto &x_i:x) cin>>x_i;
        ll l=1, r=1e9, ans=-1;
        while(l<=r){
            ll mid=(l+r)/2;
            vector<pair<ll, int>> events;
            for(int i=0;i<n;i++){
                ll ceil_val=(h[i]+mid-1)/mid;
                ll d = m - ceil_val;
                if(d>=0){
                    ll L = x[i]-d;
                    ll R = x[i]+d;
                    events.emplace_back(L, 1);
                    events.emplace_back(R+1, -1);
                }
            }
            if(events.empty()){
                l=mid+1;
                continue;
            }
            sort(events.begin(), events.end());
            ll cnt=0, max_cnt=0;
            for(auto &[pos, type]:events){
                cnt += type;
                if(cnt > max_cnt) max_cnt = cnt;
            }
            if(max_cnt >=k){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        cout<<ans<<"\n";
    }
}

/*

2
2
-1
6969697
15
1000000000

*/