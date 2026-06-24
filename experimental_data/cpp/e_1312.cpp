#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define flush fflush(stdout)
#define pb(x,y) push_back({x,y})
using namespace std;
const int inf=0x3f3f3f3f;
const ll mod=998244353LL;
const int N=400050;
int n;
int a[505],dp[1550];
vector < pii > vec[1550],v;

void solve()
{
    for(int i=1;i<=1505;++i)
    {
        sort(vec[i].begin(),vec[i].end());
        for(auto p:vec[i])
        {
            pii t={p.second+1,-1};
            auto it=lower_bound(vec[i].begin(),vec[i].end(),t);
            if(it!=vec[i].end())
            {
                auto tmp=*it;
                if((tmp.first)-1==p.second)
                    vec[i+1].pb(p.first,tmp.second);
            }
        }
    }
    for(int i=1;i<=1505;++i)
    {
        for(auto p:vec[i])
            v.push_back(p);
    }
    sort(v.begin(),v.end());
    for(auto i:v)
        dp[i.second]=min(dp[i.second],dp[i.first-1]+1);
}

int main()
{
    cin>>n;
    mem(dp,inf);
    dp[0]=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        vec[a[i]].pb(i,i);
    }
    solve();
    printf("%d\n",  dp[n]);
    return 0;
}