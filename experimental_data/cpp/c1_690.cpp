#include<cstdio>

#include<cstring>

#include<vector>

#include<queue>

using std::queue;

using std::vector;

const int maxn=1000+5;

bool vis[maxn];

vector<int> G[maxn];

queue<int> q;

int main(int argc,char **argv)

{

	int n,m,i,u,v,sum=0;

	scanf("%d%d",&n,&m);

	if(m!=n-1)

	{

		puts("no");

		return 0;

	}

	memset(vis,0,sizeof(vis));

	for(i=0;i<m;i++)

	{

		scanf("%d%d",&u,&v);

		if(u==v)

		{

			puts("no");

			return 0;

		}

		G[u].push_back(v);

		G[v].push_back(u);

	}

	vis[1]=1;

	q.push(1);

	while(!q.empty())

	{

		u=q.front();

		q.pop();

		sum++;

		for(i=0;i<G[u].size();i++)

		{

			v=G[u][i];

			if(!vis[v])

			{

				q.push(v);

				vis[v]=1;

			}

		}

	}

	if(sum==n)puts("yes");

	else puts("no");

	return 0;

}