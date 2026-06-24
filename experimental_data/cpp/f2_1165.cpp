#include <bits/stdc++.h>
using namespace std;

const int maxn= 2e5+2;
long long n, m, v[maxn], v1[maxn];

vector<long long>G[maxn];

bool solve(long long x)
{
    vector<pair<long long, long long> >R;
    memcpy(v1, v, sizeof v);
    for(int i=1; i<=n; i++)
    {
        if(G[i].size()!=0&&G[i][0]<=x)
        {
            int st=0, res=0, dr=G[i].size()-1;
            while(st<=dr)
            {
                int mid=(st+dr)/2;
                if(G[i][mid]<=x)
                {
                    res=mid;
                    st=mid+1;
                }
                else
                {
                    dr=mid-1;
                }
            }
            //reduc[i]=G[i][res];
            R.push_back({G[i][res], i});
        }
    }
    sort(R.begin(),R.end());
    long long ruble=0, prev=0;
    for(auto it:R)
    {
        ruble=ruble+it.first-prev;
        prev=it.first;
        long long cate = min(v1[it.second], ruble);
        ruble=ruble-cate;
        v1[it.second]=v1[it.second]-cate;
    }
    ruble=ruble+x-prev;
    long long total=0;
    for(int i=1; i<=n; i++)
    {
        total=total+v1[i];
    }
    if(2*total<=ruble)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int x, y;
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>v[i];
    }
    for(int i=1; i<=m; i++)
    {
        cin>>x>>y;
        G[y].push_back(x);
    }
    for(int i=1; i<=n; i++)
    {
        sort(G[i].begin(),G[i].end());
    }
    long long st=1, dr=400002, res=400002;
    while(st<=dr)
    {
        long long mid=(st+dr)/2;
        if(solve(mid))
        {
            res=mid;
            dr=mid-1;
        }
        else
        {
            st=mid+1;
        }
    }
    cout<<res;
    return 0;
}