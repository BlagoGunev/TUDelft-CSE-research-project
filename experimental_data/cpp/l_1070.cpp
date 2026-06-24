#include<bits/stdc++.h>
#define maxn 2005
using namespace std;
int n,m;
int deg[maxn];
bitset<maxn>e[maxn];
bitset<maxn>ans;
int gauss()
{
    vector<int>where(n+1,-1);
    for(int row=1,col=1; row<=n&&col<=n; col++)
    {
        for(int i=row; i<=n; i++)
        {
            if(e[i][col]==1)
            {
                swap(e[i],e[row]);
                break;
            }
        }
        if(!e[row][col])
        {
            if(col==n&&e[row][n+1])return 0;
            row++;
            continue;
        }
        where[col]=row;
        for(int i=1; i<=n; i++)
        {
            if(i!=row&&e[i][col]==1)
            {
                e[i]^=e[row];
            }
        }
        row++;
    }
    ans.reset();
    for(int i=1; i<=n; i++)
    {
        if(where[i]!=-1)
        {
            ans[i]=e[where[i]][n+1];
        }
    }
    return 1;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        e[i].reset();
        deg[i]=0;
    }
    for(int i=1; i<=m; i++)
    {
        int u,v;
        cin>>u>>v;
        deg[u]++;
        deg[v]++;
        e[u][v]=e[v][u]=1;
    }
    for(int i=1; i<=n; i++)
    {
        if(deg[i]&1)
        {
            e[i][i]=1;
            e[i][n+1]=1;
        }
    }
    gauss();
    set<int>s;
    for(int i=1; i<=n; i++)
    {
        s.insert(ans[i]);
    }
    cout<<s.size()<<'\n';
    for(int i=1; i<=n; i++)
    {
        cout<<ans[i]+1<<' ';
    }
    cout<<'\n';
}
int main()
{
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
/*
2
5 3
1 2
2 5
1 5
6 5
1 2
2 3
3 4
4 2
4 1

*/