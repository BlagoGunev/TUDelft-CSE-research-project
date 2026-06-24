#include<bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int M=2e5+5;
const ll mod=1e9+7;

int chs[M],uchs[M],ans[M];
ll sumchs[M],sumuchs[M];
vector<int> adj[M];

void dfs1(int u,int p)
{
    chs[u]=1;
    sumchs[u]=adj[u].size();
    sumuchs[u]=1;
    for(auto&c:adj[u])
    {
        if(c!=p)
        {
            dfs1(c,u);

            if(chs[c]==uchs[c])
            {
                if(sumchs[c]<sumuchs[c])
                {
                    sumuchs[u]+=sumchs[c];
                }
                else sumuchs[u]+=sumuchs[c];
                uchs[u]+=chs[c];
            }
            else
            {
                if(chs[c]>uchs[c])
                {
                    uchs[u]+=chs[c];
                    sumuchs[u]+=sumchs[c];
                }
                else
                {
                    uchs[u]+=uchs[c];
                    sumuchs[u]+=sumuchs[c];
                }
            }
            chs[u]+=uchs[c];
            sumchs[u]+=sumuchs[c];
        }
    }
}

void trace(int u,int p,int is_choosed)
{
    if(is_choosed)
    {
        ans[u]=adj[u].size();
        for(auto&c:adj[u])
        {
            if(c!=p)
            trace(c,u,0);
        }
    }
    else
    {
        ans[u]=1;
        for(auto&c:adj[u])
        {
            if(c!=p)
            {
                if(uchs[c]>chs[c]||(uchs[c]==chs[c]&&sumuchs[c]<sumchs[c]))
                {
                    trace(c,u,0);
                }
                else trace(c,u,1);
            }
        }
    }
}

void process()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs1(1,1);
    if(chs[1]>uchs[1]||(chs[1]==uchs[1]&&sumchs[1]<sumuchs[1]))
    trace(1,1,1);
    else trace(1,1,0);
    int cnt=0;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        cnt+=(adj[i].size()==ans[i]);
        sum+=ans[i];
    }
//    cout<<chs[3]<<" "<<uchs[3]<<" "<<sumchs[3]<<" "<<sumuchs[3]<<"\n";
    cout<<cnt<<" "<<sum<<"\n";
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int test=1;
    while(test--)process();
}