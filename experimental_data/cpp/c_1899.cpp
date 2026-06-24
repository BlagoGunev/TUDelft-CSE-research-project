#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define PII pair<int,int>
#define ll long long
#define multicase 1
#define N 300005
#define mod 998244353
int a[N];
long long pre[N];
unordered_map<int, int>M;
void init() {
    
}
void solve() {
    int n; cin>>n;
    long long ans=-1e18, mn=0;
    for(int i=1;i<=n;++i)cin>>a[i], pre[i]=pre[i-1]+a[i];
    a[0]=a[1]^1;
    for(int i=1;i<=n;++i) {
        if((a[i]^a[i-1])&1^1) mn=pre[i-1];
        ans=max(ans, pre[i]-mn);
        mn=min(mn, pre[i]);
    }
    cout<<ans<<endl;
}
int main() {
    init();
    #if multicase
    int _; cin>>_; while(_--) solve(); 
    #else
    solve();
    #endif
}