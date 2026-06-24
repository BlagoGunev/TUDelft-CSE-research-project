#include<bits/stdc++.h>

using namespace std;

//bool flag=false;



void dfs(unordered_map<int,vector<int>>&mp,int u,vector<vector<int>>&vis,vector<vector<int>>&adj,int num)

{

    if(vis[u][num]) return;

    vis[u][num]=1;

    mp[u].push_back(num);

    for(auto x:adj[u])

    {

        dfs(mp,x,vis,adj,num);

    }

}

int main()

{

    int t;

    cin>>t;

    while(t--)

    {

        int n;

        cin>>n;

        vector<vector<int>>adj(n+1,vector<int>());

        for(int i=0;i<n;i++)

        {

            string s;

            cin>>s;

            for(int j=0;j<n;j++)

            {

                if(s[j]=='1') adj[i+1].push_back(j+1);

            }

        }

        vector<vector<int>>vis(n+1,vector<int>(n+1,0));

        unordered_map<int,vector<int>>mp;

        for(int i=1;i<=n;i++)

        dfs(mp,i,vis,adj,i);

        for(int i=1;i<=n;i++)

        {

            cout<<mp[i].size()<<" ";

            for(int j=0;j<mp[i].size();j++) cout<<mp[i][j]<<" ";

            cout<<endl;

        }

    }

}