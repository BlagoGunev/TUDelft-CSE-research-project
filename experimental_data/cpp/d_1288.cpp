#include<bits/stdc++.h>

//#pragma GCC optimize(2)

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); uniform_int_distribution<int>(l,r)(rng)

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

#define endl '\n'

#define INF 0x7FFFFFFF

#define ch(a) (int(a-'a')+1)

const int maxn=3*1e5+11;

const int Maxx=1e6+11;

const int mod=998244353;

int t;

int n,m;

int a[maxn][10];

int vis[(1ll<<8)+2];

pair<int,int>Ans;

bool check(int x)

{

    for(int i=0;i<(1ll<<m);++i) vis[i]=0;

    vector<pair<int,int>>v;

    for(int i=1;i<=n;++i)

    {

        int res=0;

        for(int j=1;j<=m;++j)

        {

            if(a[i][j]>=x) res|=(1<<(j-1));

        }

        if(vis[res]) continue;

        vis[res]=1;

        v.emplace_back(res,i);

    }

    int f=0;

    for(int i=0;i<v.size();++i)

    {

        for(int j=i;j<v.size();++j)

        {

            if((v[i].first|v[j].first)==(1<<m)-1)

            {

                Ans.first=v[i].second;

                Ans.second=v[j].second;

                f=1;break;

            }

        }

    }

    if(f) return true;

    return false;

}

void solve()

{

    cin>>n>>m;

    int l=1e9+2,r=0;

    for(int i=1;i<=n;++i)

    {

        for(int j=1;j<=m;++j)

        {

            cin>>a[i][j];

            l=min(l,a[i][j]);

            r=max(r,a[i][j]);

        }

    }

    Ans.first=1;Ans.second=1;

    while(l<r)

    {

        int mid=(l+r+1)>>1;

        if(check(mid)) l=mid;

        else r=mid-1;

    }

    cout<<Ans.first<<" "<<Ans.second<<endl;

}

int main()

{

    //scanf("%d",&t);

    ios::sync_with_stdio(false);cin.tie(0);

    //ios::sync_with_stdio(false);cin.tie(0);cin>>t;while(t--)

    solve();

    return 0;

}