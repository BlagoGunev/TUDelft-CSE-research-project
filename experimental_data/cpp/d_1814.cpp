#include<bits/stdc++.h>
#define int long long 
#define pii pair <int ,int > 
#define mkp make_pair
using namespace std;
const int N=3e3;
int T;
int n,k,f[N+5],d[N+5],p[N+5],bef[N+5][N+5],aft[N+5][N+5];
int getupb(int x,int k) { return (x+k-1)/k*k; }
int getlwb(int x,int k) { return x/k*k; }
int calc(int id){
    vector <int > cnt(n+5),tag(n+5); int res=0,num=0,ans=0;
    vector <pii > v;
    for(int i=1;i<=n;i++) {
        bool flag=0;
        if(abs(p[i]-p[id])<=k) v.emplace_back(mkp(p[i],i)),flag=1;
        if(abs(aft[i][id]-p[id])<=k) v.emplace_back(mkp(aft[i][id],-i)),flag=1;
        if(bef[i][id]&&abs(bef[i][id]-p[id])<=k) v.emplace_back(mkp(bef[i][id],-i)),flag=1;
        if(!flag) return 0;
    } sort(v.begin(),v.end());
    int l=0,r=0;
    for(int l=0;l<v.size();l++){
        while(r<v.size()&&v[r].first-k<=v[l].first) {
            pii now=v[r++];
            if(now.second<0) num+=(++cnt[-now.second]==1); 
            else num+=(++cnt[now.second]==1),res++;
        }
        if(num==n) ans=max(ans,res);
        pii now=v[l];
        if(now.second<0) num-=(--cnt[-now.second]==0);
        else num-=(--cnt[now.second]==0),res--;
    }
    return ans;
}
void solve(){
    cin>>n>>k; int ans=n;
    for(int i=1;i<=n;i++) cin>>f[i];
    for(int i=1;i<=n;i++) cin>>d[i],p[i]=f[i]*d[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            bef[i][j]=getlwb(p[j],f[i]),aft[i][j]=getupb(p[j],f[i]);
    for(int i=1;i<=n;i++) ans=min(ans,n-calc(i));
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>T;
    while(T--) solve();
    return 0;
}