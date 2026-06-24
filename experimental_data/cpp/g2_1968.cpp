#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define N 200005
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

vector<int> z_function(string s)
{
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++)
    {
        if(i < r)
        {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }
        if(i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int s[N*4];

void build(int node,int l,int r,vector<int>&z)
{
    if(l==r)
    {
        s[node]=z[l];
        return;
    }
    build(node*2,l,(l+r)/2,z);
    build(node*2+1,(l+r)/2+1,r,z);

    s[node]=max(s[node*2],s[node*2+1]);
}
int n;
int query(int node,int b,int e,int l,int r,int thres)
{
    if(e<l||r<b)
        return n;
    if(l<=b&&e<=r)
    {
        if(s[node]<thres)
            return n;
        else
        {
            if(b==e)
                return b;
            else
            {
                if(s[node*2]>=thres)
                    return query(node*2,b,(b+e)/2,l,r,thres);
                else
                    return query(node*2+1,(b+e)/2+1,e,l,r,thres);
            }
        }
    }
    return min(query(node*2,b,(b+e)/2,l,r,thres),query(node*2+1,(b+e)/2+1,e,l,r,thres));
}

void solve()
{
    int l,r;
    cin>>n>>l>>r;
    string s;
    cin>>s;
    auto z=z_function(s);
    z[0]=n;

    vector<int>all[n+1];
    for(int i=0; i<n; i++)
    {
        all[z[i]].push_back(i);
    }
    vector<int>cnt(n+1);
    int upto=0;
    vector<int>ans(n+1);
    build(1,0,n-1,z);
    for(int len=n; len>=1; len--)
    {
        int now=0;
        int c=0;
        while(now!=n)
        {
            auto itr=query(1,0,n-1,now,n-1,len);
            if(itr==n) break;
            else now=itr+len,c++;
        }

        cnt[len]=c;
        for(int j=upto+1; j<=cnt[len]; j++)
        {
            ans[j]=len;
        }
        upto=max(upto,cnt[len]);
    }

    for(int i=l; i<=r; i++)
        cout<<ans[i]<<' ';
    cout<<"\n";

}

main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}