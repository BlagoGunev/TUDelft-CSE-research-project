#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k,q;
int b[200005];
int pre[200005];
int nex[200005];
vector<int> v[200005];

void print(vector<pair<int,int>> &b)
{
    for (auto x:b)
    {
        cout<<x.first<<' '<<x.second<<endl;
    }
    cout<<"#"<<endl;
}

int main()
{
    scanf("%d%d%d%d",&n,&m,&k,&q);
    int ma=-1;
    for (int i=1;i<=k;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        ma=max(x,ma);
        v[x].push_back(y);
    }
    for (int i=1;i<=ma;i++)
    {
        sort(v[i].begin(),v[i].end());
    }
    for (int i=1;i<=q;i++)
    {
        int x;
        scanf("%d",&x);
        b[x]=1;
    }
    int x=-1;
    for (int i=1;i<=m;i++)
    {
        pre[i]=x;
        if (b[i]==1) x=i;
    }
    x=m+1;
    for (int i=m;i>=1;i--)
    {
        nex[i]=x;
        if (b[i]==1) x=i;
    }
    vector<pair<int,ll>> h;
    vector<pair<int,ll>> hh;
    if (v[1].size()==0)
    {
        h.push_back({1,0LL});
    }
    else
    {
        h.push_back({v[1].back(),(ll)v[1].back()-1});
    }
    for (int i=2;i<=ma;i++)
    {
        hh.clear();
        vector<pair<int,ll>> r;
        for (auto x:h)
        {
            if (b[x.first]==1) r.push_back(x);
            else
            {
                if (pre[x.first]!=-1) r.push_back({pre[x.first],x.second+x.first-pre[x.first]});
                if (nex[x.first]!=m+1) r.push_back({nex[x.first],x.second+nex[x.first]-x.first});
            }
        }
        h=r;
        if (v[i].size()==0)
        {
            for (auto x:h)
            {
                hh.push_back({x.first,x.second+1LL});
            }
        }
        else if (v[i].size()==1)
        {
            ll mi=0x3f3f3f3f3f3f3fLL;
            for (auto x:h)
            {
                mi=min(mi,1LL+x.second+abs(v[i][0]-x.first));
            }
            hh.push_back({v[i][0],mi});
        }
        else
        {
            ll mi1=0x3f3f3f3f3f3f3fLL,mi2=0x3f3f3f3f3f3f3fLL;
            for (auto x:h)
            {
                mi1=min(mi1,1LL+x.second+abs(v[i].back()-x.first)+(v[i].back()-v[i].front()));
                mi2=min(mi2,1LL+x.second+abs(v[i].front()-x.first)+(v[i].back()-v[i].front()));
            }
            hh.push_back({v[i].front(),mi1});
            hh.push_back({v[i].back(),mi2});
        }
        h=hh;
    }
    ll mi=0x3f3f3f3f3f3f3fLL;
    for (auto x:h)
    {
        mi=min(mi,x.second);
    }
    cout<<mi<<endl;
    return 0;
}