#include<bits/stdc++.h>
#define ll long long
#define N 1000005
using namespace std;
ll T,n,k;
map<ll,ll> vis,cnt,sum;
inline void solve(ll x){
    if(vis[x]) return ;
    if(x<k) return ;
    if(x%2==1){
        ll opt = (x+1)/2;
        solve(x/2);
        vis[x]=1,sum[x]=sum[x/2]*2+opt+cnt[x/2]*opt,cnt[x]=cnt[x/2]*2+1;
    }
    else{
        solve(x/2);
        vis[x]=1,sum[x]=sum[x/2]*2+cnt[x/2]*(x/2),cnt[x]=cnt[x/2]*2;
    }
}
int main(){
	ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        vis.clear(),cnt.clear(),sum.clear();
        cin>>n>>k;
        solve(n);
        cout<<sum[n]<<endl;
    }
    return 0;
}