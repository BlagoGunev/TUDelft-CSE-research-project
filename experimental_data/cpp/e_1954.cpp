#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define N 300005
#define M 998244353
#define pii pair<ll,ll>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#ifndef ONLINE_JUDGE
#include "./dbg.h"
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...)
#endif
vector<pair<int,int>> where_ceil_changes(int m)
{
    vector<pair<int,int>>v;
    int l=1;
    while(l<=m)
    {
        if(l==m)
        {
            v.push_back({m,m});
            break;
        }
        int cl=(m+l-1)/l;
        int r=(m+cl-2)/(cl-1)-1;
        r=min(r,m);
        r=max(r,l);
        v.push_back({l,r});
        if(r==m) break;
        l=r+1;
    }
    return v;
}
int n;
int a[N];
int b[N];

main()
{
    fast;
    cin>>n;
    int mx=0;
    vector<int>ev[100005];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
        auto v=where_ceil_changes(a[i]);
        for(auto u:v)
        {
            int l=u.first;
            ev[l].push_back(i);
        }
        mx=max(mx,a[i]);
        a[i]=0;
    }


    ll ans=0;

    for(int k=1;k<=mx;k++)
    {
//        debug(k,ev[k]);
        for(int u:ev[k])
        {
            int age=max(0,a[u]-a[u-1])+max(0,a[u+1]-a[u]);
            a[u]=(b[u]+k-1)/k;

            int now=max(0,a[u]-a[u-1])+max(0,a[u+1]-a[u]);
//            debug(u,a[u],age,now);
            ans-=age;
            ans+=now;
        }
        cout<<ans<<' ';
    }

}