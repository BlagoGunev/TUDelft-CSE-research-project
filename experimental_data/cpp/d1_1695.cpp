#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef long long ll;

const int N=2e5+10;

vector<int>e[N];

int a[N];

int dfs(int x,int fa){

    int sum=0,cnt=0;

      for(auto y:e[x]){

        if(y==fa)continue;

        int temp=dfs(y,x);

        cnt+=(temp==0);

        sum+=temp;

      }

      return sum+max(cnt-1,0ll);

}

void solve()

{

    int n,m,k;

    cin>>n;

    int mmax=0;

    int pos=0;

    for(int i=1;i<=n;i++)e[i].clear();

    for(int i=1;i<n;i++){

        int x,y;

        cin>>x>>y;

        e[x].push_back(y);

        e[y].push_back(x);

        mmax=max({(int )e[x].size(),mmax,(int )e[y].size()});

    }

    if(n==1){

        cout<<"0\n";

        return;

    }

    if(mmax<3){

        cout<<1<<'\n';

        return;

    }

    for(int i=1;i<=n;i++){

        if(e[i].size()>=3){

                cout<<dfs(i,0)<<'\n';

                return;

        }

    }

}

signed main()

{

    ios::sync_with_stdio(false),cin.tie(0);

    int t=1;

    cin>>t;

    while(t--)solve();

}