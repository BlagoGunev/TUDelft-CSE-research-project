#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+10;
int dp[N];
int color[N];
vector<vector<int>>adj(N);
int res;

void dfs(int vertex, int parent){
    res+=dp[color[vertex]];
    int temp=dp[color[vertex]];
    for(auto child: adj[vertex]){
        if(child==parent)continue;
        dp[color[vertex]]=1;
        dfs(child,vertex);
    }
    dp[color[vertex]]=temp+1;
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<=n;i++){
            adj[i].clear();
            dp[i]=0;
            color[i]=0;
        }
        res=0;
        for(int i=1;i<=n;i++) cin>>color[i];
        for(int i=1;i<n;i++){
            int x;
            cin>>x;
            int y;
            cin>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(1,0);
        cout<<res<<"\n";
    }
    return 0;
}