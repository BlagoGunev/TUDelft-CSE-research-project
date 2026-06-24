#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N=200000,mod=998244353;
int p[N+1],sz[N+1];
struct edge
{
    int u,v,w;
    void read(){cin>>u>>v>>w;}
    bool operator<(edge x){return w<x.w;}
}a[N+1];
int leader(int v)
{
    if(p[v]==v)return v;
    else return p[v]=leader(p[v]);
}
void unite(int u,int v)
{
    u=leader(u);
    v=leader(v);
    p[u]=v;
    sz[v]+=sz[u];
}
i64 qpow(i64 x, i64 y){
	i64 ret = 1;
    while(y){
        if(y & 1) ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,S;cin>>n>>S;
        for(int i=1;i<=n;i++)p[i]=i,sz[i]=1;
        for(int i=0;i<n-1;i++)a[i].read();
        sort(a,a+n-1);
        long long ans=1;
        for(int i=0;i<n-1;i++)
        {
            int sub_u=sz[leader(a[i].u)];
            int sub_v=sz[leader(a[i].v)];
            ans=ans*qpow(S-a[i].w+1,1ll*sub_u*sub_v-1)%mod;
            unite(a[i].u,a[i].v);
        }
        cout<<ans<<"\n";
    }
}