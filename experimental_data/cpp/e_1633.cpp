#pragma GCC Optimize("O3")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
const int N = 1e3+7;
const int INF = 1e9+7;
const ll INFM = 1e18;
struct edge{
    int u,v,w;
};
bool mc(edge &a,edge &b){
    return a.w<b.w;
}
vector<pair<int,pair<ll,int> > > rng;
int P[N];
int F(int x){
    return x==P[x]?x:P[x] = F(P[x]);
}
int unite(int a,int b){
    a = F(a);
    b = F(b);
    if (a==b)
        return 0;
    P[a] = b;
    return 1;
}
int n,m;
void solve(vector<edge> &lb,vector<edge> &rb,int lptr,int rptr,int l,int r,ll val,int delta){

    while(lptr<lb.size() && F(lb[lptr].u)==F(lb[lptr].v))
        ++lptr;
    while(rptr<rb.size() && F(rb[rptr].u)==F(rb[rptr].v))
        ++rptr;
    if (lptr==lb.size() && rptr==rb.size()){
        rng.push_back({r,{val,delta}});
        return;
    }
    if (lptr==lb.size() || (rptr!=rb.size() && lb[lptr].w+rb[rptr].w<(l<<1))){
        val+=rb[rptr].w;
        delta--;
        unite(rb[rptr].u,rb[rptr].v);
        solve(lb,rb,lptr,rptr+1,l,r,val,delta);
        return;
    }
    if (rptr==rb.size() || (lptr!=lb.size() && lb[lptr].w+rb[rptr].w>=(r<<1))){
        val-=lb[lptr].w;
        delta++;
        unite(lb[lptr].u,lb[lptr].v);
        solve(lb,rb,lptr+1,rptr,l,r,val,delta);
        return;
    }
    vector<int> cp(n+1);
    for(int i = 1;i<=n;++i)
        cp[i] = P[i];
    int sum = lb[lptr].w+rb[rptr].w;

    unite(lb[lptr].u,lb[lptr].v);
    solve(lb,rb,lptr+1,rptr,l,(sum/2),val-lb[lptr].w,delta+1);
    for(int i = 1;i<=n;++i)
        P[i] = cp[i];
    unite(rb[rptr].u,rb[rptr].v);
    solve(lb,rb,lptr,rptr+1,(sum/2)+1,r,val+rb[rptr].w,delta-1);
}
ll ans(ll w){
    auto elem = upper_bound(all(rng),pair<int,pair<ll,int>>{w,{-INFM,-INF}});

    return elem->second.first+w*elem->second.second;
}
void solve(){

    cin>>n>>m;
    vector<edge> edges(m);
    for(int i = 0;i<m;++i)
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
    edges.push_back({1,2,INF});
    sort(all(edges),mc);
    ++m;
    for(int i = 0;i<m;++i){
        vector<edge> lb,rb;
        for(int j = 0;j<i;++j)
            lb.push_back(edges[j]);
        for(int j = i;j<m;++j)
            rb.push_back(edges[j]);
        int l = i>0?edges[i-1].w+1:0,r = edges[i].w;
        reverse(all(lb));
        if (l<=r) {
            for (int i = 1; i <= n; ++i)
                P[i] = i;
            solve(lb, rb, 0, 0, l, r, 0, 0);
        }
    }
    sort(all(rng));
    int p,k,a,b,c;
    cin>>p>>k>>a>>b>>c;
    ll prev = 0;
    ll res = 0;
    for(int i = 1;i<=p;++i){
        int q;
        cin>>q;
        res^=ans(q);
       // cout<<ans(q)<<' ';
        prev = q;
    }
    for(int i = p+1;i<=k;++i){
        int q = (prev*a+b)%c;
        res^=ans(q);
       // cout<<ans(q)<<' ';
        prev = q;
    }
   // cout<<endl;
    cout<<res<<endl;
}
int main() {

    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;

}