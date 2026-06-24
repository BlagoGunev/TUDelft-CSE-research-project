#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;
int n, m;

vector<int> edges[MAXN];
int t;
bool mark[MAXN];

void dfs(int v)
{
	t++;
	mark[v] = true;
	for(int i = 0; i < (int)edges[v].size(); i++)
	{
		if(!mark[edges[v][i]])
		{
			dfs(edges[v][i]);
		}
	}
}

int main()
{
	cin >> n >> m;
	if(n != m)
	{
		cout << "NO" << endl;
		return 0;
	}
	for(int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		edges[u - 1].push_back(v - 1);
		edges[v - 1].push_back(u - 1);
	}
	dfs(0);
	if(t == n)
	{
		cout << "FHTAGN!" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}