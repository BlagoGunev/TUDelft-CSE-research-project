#include <bits/stdc++.h>

using namespace std;

int n,m;

pair<int,int> g[1010];

bool has_out[1010];

bool has_in[1010];

pair<int,int> dfs(int u,int mn){

    if(!has_out[u])

        return make_pair(u,mn);

    return dfs(g[u].first,min(mn,g[u].second));

}

int main()

{

    scanf("%d%d",&n,&m);

    for(int i=0,a,b,d;i<m;++i){

        scanf("%d%d%d",&a,&b,&d);

        g[a]=make_pair(b,d);

        has_out[a]=true;

        has_in[b]=true;

    }

    vector<pair<int,pair<int,int> > >out;

    for(int i=1;i<=n;++i){

        if(!has_in[i]&&has_out[i]){

            out.push_back(make_pair(i,dfs(i,INT_MAX)));

        }

    }

    printf("%d\n",(int)out.size());

    for(int i=0;i<(int)out.size();++i){

        printf("%d %d %d\n",out[i].first,out[i].second.first,out[i].second.second);

    }

    return 0;

}