#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD =1e9+7;
map<string,int> mp;
vector<int>node[200123];
ll dp[200123][3][11];
ll tmp[3][11];
int m,k,sz;
void dfs(int u,int fa)
{
    dp[u][0][0]=k-1;
    dp[u][1][1]=1;
    dp[u][2][0]=m-k;
    for(auto v:node[u])
    {
    	if(v!=fa)
    	{
        	dfs(v,u);
        	memset(tmp,0,sizeof tmp);
        	for(int i=0;i<3;i++)
        	{
        		for(int j=0;j<=sz;j++)
        		{
        			if(dp[u][i][j])
        			{
        				for(int k=0;k<3;k++)
        				{
        					for(int w=0;w+j<=sz;w++)
        					{
        						if(dp[v][k][w] && (!(k==1&&i>=1)) && (!(i==1&&k>=1)))
        						{
        							tmp[i][w+j]=(tmp[i][w+j]+dp[u][i][j]*dp[v][k][w])%MOD;
								}
							}
						}
					} 
				}
			}
            for(int x=0;x<3;x++)
			{
			 	for(int y=0;y<=sz;y++)
			 	{
			 		 dp[u][x][y]=tmp[x][y];
				 }
			}                                             
    	}
	}
        
}
int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin>>n>>m;
    for(int i=1;i<n;i++)
    {
        int u,v;
       	cin>>u>>v; 
        node[u].push_back(v);
        node[v].push_back(u);
    }
    cin>>k>>sz;
    dfs(1,0);
    ll ans=0;
    for(int i=0;i<3;i++)
    {
    	for(int j=0;j<=sz;j++)
		{
			ans=(ans+dp[1][i][j])%MOD;
		 } 
	}
    cout<<ans<<endl;
    return 0;
}