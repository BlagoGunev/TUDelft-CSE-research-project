#include <bits/stdc++.h>

using namespace std;

const int N=5e4+5;

vector<int>G[N];

int res[N];

void dfs(int v,int f)

{

    for(auto i:G[v])

    {

        if(i==f)continue;

        res[i]=v;

        dfs(i,v);

    }

}

int main()

{

    int n,r1,r2,v;

    scanf("%d%d%d",&n,&r1,&r2);

    for(int i=1;i<=n;i++)

    {

        if(i==r1)continue;

        scanf("%d",&v);

        G[i].push_back(v);

        G[v].push_back(i);

    }

    dfs(r2,-1);

    for(int i=1;i<=n;i++)

    {

        if(i==r2)continue;

        printf("%d ",res[i]);

    }

    return 0;

}