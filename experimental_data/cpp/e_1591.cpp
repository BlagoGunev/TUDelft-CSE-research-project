#include<bits/stdc++.h>

using namespace std;

void solve()

{	

    int n,q;

    cin>>n>>q;

    vector<int>a(n+1);

    for(int i=1;i<=n;i++)

      cin>>a[i];

    vector<vector<int>>adj(n+1);

    for(int i=2;i<=n;i++)

    {

      int v;

      cin>>v;

      adj[v].push_back(i);

    }

    vector<vector<array<int,3>>>qur(n+1);

    for(int i=0;i<q;i++)

    {

      int v,l,k;

      cin>>v>>l>>k;

      qur[v].push_back({l,k,i});

    }

    vector<int>cnt(n+1),lb(n+1),ip(n+1),p(n+1);

    for(int i=1;i<=n;i++)

    {

      ip[i]=i;

      p[i]=i;

      lb[i]=n+1;

    }

    lb[0]=1;

    vector<int>ans(q);

    auto dfs=[&](auto self,auto u)->void

    {

        int v=a[u];

        cnt[v]++;

        int i=ip[v];

        int j=lb[cnt[v]]-1;

        swap(ip[p[i]],ip[p[j]]);

        swap(p[i],p[j]);

        lb[cnt[v]]--;

        for(auto [l,k,id]:qur[u])

        {

          ans[id]=(lb[l]+k-1>n?-1:p[lb[l]+k-1]);

        }

        for(auto v:adj[u])

          self(self,v);

        swap(ip[p[i]],ip[p[j]]);

        swap(p[i],p[j]);

        lb[cnt[v]]++;

        cnt[v]--;

    };

    dfs(dfs,1);

    for(auto x:ans)

      cout<<x<<" ";

    cout<<"\n";

}

int main()

{

  std::ios::sync_with_stdio(false);

  std::cin.tie(nullptr);

  int t;

  cin>>t;

  while(t--)

  solve();

  return 0;

}