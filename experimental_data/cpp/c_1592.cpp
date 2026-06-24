#include<bits/stdc++.h>

using namespace std;

#define  int long long



const int N=2e5+10,M=N<<1;

int a[N];

bool v[N],st[N];

vector<int>mp[N];

int tlug=0;



int dfs(int u,int x)

{ 

    if(tlug)return 0;

    if(v[u])return 0;

    st[u]=1;

    int ans=a[u];

    for(auto i:mp[u])

    {

        if(st[i])continue;

        ans^=dfs(i,x);

    }

    if(tlug)return 0;

    if(ans==x)v[u]=1,ans=0,tlug=1;

    return ans;

}



int dfs1(int u)

{

    if(v[u])return 0;

    st[u]=1;

    int ans=a[u];

    for(auto i:mp[u])

    {

        if(st[i])continue;

        ans^=dfs1(i);

    }

    

    return ans;

}



void solve()

{

    int n,k;

    cin>>n>>k;



    int x=0;

    for(int i=1;i<=n;i++)

    {

        cin>>a[i];

        x^=a[i];

    }

    for(int i=1;i<n;i++)

    {

        int a,b;

        cin>>a>>b;

        mp[a].push_back(b);

        mp[b].push_back(a);

    }

    if(x==0)

    {

        cout<<"YES"<<"\n";

        for(int i=1;i<=n;i++)

        {

        st[i]=v[i]=0;

        mp[i].clear();

        }

        return ;

    }

    if(k==2)

    {

        cout<<"NO"<<"\n";

        for(int i=1;i<=n;i++)

        {

        st[i]=v[i]=0;

        mp[i].clear();

        }

        return ;

    }



    int flag=0;

    tlug=0;

    dfs(1,x);

    if(!tlug)flag=1;

    for(int i=1;i<=n;i++)st[i]=0;



    tlug=0;

    dfs(1,x);

    if(!tlug)flag=1;

    for(int i=1;i<=n;i++)st[i]=0;



    if(dfs1(1)!=x)flag=1;

    for(int i=1;i<=n;i++)st[i]=0;



    if(flag)cout<<"NO"<<"\n";

    else cout<<"YES"<<"\n";



    for(int i=1;i<=n;i++)

    {

        st[i]=v[i]=0;

        mp[i].clear();

    }

}



signed main()

{

    cin.tie(0);

    ios_base::sync_with_stdio(false);

    int t;

    cin>>t;

    while(t--)

    {

        solve();

    }



}