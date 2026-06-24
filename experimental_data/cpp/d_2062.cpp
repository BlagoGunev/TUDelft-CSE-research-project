#include <bits/stdc++.h>
using namespace std;
#define LCBorz ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define all(x) x.begin(), x.end()
#define endl '\n'
const int N=200005;
const int INF=1e18;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define gen(a,b) uniform_int_distribution<int>(a,b)(rnd) 
vector<int> a(N),b(N);
vector<int> adj[N],dp(N);
int ans=0;
void dfs(int k,int pa){
    if(k!=pa&&adj[k].size()==1){
        dp[k]=a[k];
        return;
    }
    vector<int> t;
    int mx=0;
    for(int j:adj[k]){
        if(j==pa)continue;
        dfs(j,k);
        t.push_back(dp[j]);
        if(dp[j]>b[k]){
            ans+=dp[j]-b[k];
        }
        mx=max(mx,dp[j]);
    }
    if(mx>b[k]){
        mx=b[k];
    }
    mx=max(mx,a[k]);
    dp[k]=mx;
    return;
}
void solve(){
    ans=0;
    int n;cin>>n;
    vector<int> idx(n);
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        idx[i-1]=i;
        adj[i].clear();
    }
    for(int i=1;i<n;i++){
        int c,d;cin>>c>>d;
        adj[c].push_back(d);
        adj[d].push_back(c);
    }
    sort(all(idx),[&](int c,int d){return a[c]>a[d];});
    dfs(idx[0],idx[0]);
    cout<<dp[idx[0]]+ans<<endl;
}
int32_t main() {
    LCBorz;
    int t;cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}