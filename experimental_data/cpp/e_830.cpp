#include <bits/stdc++.h>
using namespace std;

#define inf 1023456789
#define linf 1023456789123456789ll
#define pii pair<int,int>
#define pipii pair<int, pii >
#define pll pair<long long,long long>
#define vint vector<int>
#define vvint vector<vint >
#define ll long long
#define pdd pair<double, double>

//#define DEBUG
#ifdef DEBUG
#define db(x) cerr << #x << " = " << x << endl
#else
#define db(x)
#endif

vector<ll> value;
vector<bool> visited;
vvint sus;

vector<int> deg3, deg4;

int dfs(int node, int parent = -1)
{
	if(visited[node]) return node;
	visited[node] = 1;
	if(sus[node].size() == 3) deg3.push_back(node);
	if(sus[node].size() >= 4) deg4.push_back(node);
	for(int i=0; i<sus[node].size(); i++)
	{
		if(sus[node][i] == parent)continue;
		int ret = dfs(sus[node][i], node);
		if(ret != -1)
		{
			if(ret == -2) return -2;
			value[node] = 1;
			if(ret == node) return -2;
			return ret;
		}
	}
	return -1;
}

bool mark3dfs(int node, int parent = -1)
{
	if(parent != -1 && sus[node].size() >= 3)
	{
		value[node] = 2;
		for(int i=0; i<sus[node].size(); i++) value[sus[node][i]] = 1;
		return true;
	}
	for(int i=0; i<sus[node].size(); i++)
	{
		if(sus[node][i] == parent)continue;
		if(mark3dfs(sus[node][i], node))
		{
			value[node] = 2;
			return true;
		}
	}
	return false;
}

int find_depth(int node, int parent)
{
	for(int i=0; i<sus[node].size(); i++)
	{
		if(sus[node][i] == parent)continue;
		return find_depth(sus[node][i], node) + 1;
	}
	return 1;
}

void color(int node, int parent, ll val, ll step)
{
	val -= step;
	if(val <= 0) return;
	value[node] = val;
	for(int i=0; i<sus[node].size(); i++)
	{
		if(sus[node][i] == parent)continue;
		color(sus[node][i], node, val, step);
	}
}

bool solve_component(int node)
{
	deg3 = vint(0);
	deg4 = vint(0);
	if(dfs(node) == -2) return 1;
	if(deg4.size() > 0)
	{
		int hub = deg4[0];
		value[hub] = 2;
		for(int i=0; i<4; i++)
		{
			value[sus[hub][i]] = 1;
		}
		return true;
	}
	if(deg3.size() >= 2)
	{
		for(int i=0; i<sus[deg3[0]].size(); i++)
		{
			value[sus[deg3[0]][i]] = 1;
		}
		mark3dfs(deg3[0]);
		return true;
	}
	if(deg3.size() == 0)
	{
		return false;
	}
	
	int hub = deg3[0];
	ll depth[3];
	for(int i=0; i<3; i++)
	{
		depth[i] = min(6, 1+find_depth(sus[hub][i], hub));
	}
	if(depth[0] * depth[1] + depth[1] * depth[2] + depth[2] * depth[0] > depth[0]*depth[1]*depth[2])
	{
		return false;
	}
	value[hub] = 120000;
	for(int i=0; i<3; i++)
	{
		color(sus[hub][i], hub, value[hub], (value[hub]-1)/depth[i]+1);
	}
	return true;
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int test = 0; test < t; test++)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		sus = vector<vector<int> >(n);
		for(int i=0; i<m; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			a--;
			b--;
			sus[a].push_back(b);
			sus[b].push_back(a);
		}
		value = vector<ll>(n, 0);
		visited = vector<bool>(n, 0);
		bool solved = 0;
		for(int i=0; i<n; i++)
		{
			if(!visited[i])
			{
				if(solve_component(i))
				{
					printf("YES\n");
					for(int j=0; j<n; j++)
					{
						printf("%d%c", (int)(value[j]), " \n"[j+1 == n]);
					}
					solved = 1;
					break;
				}
			}
		}
		if(!solved)
		{
			printf("NO\n");
		}
	}
	return 0;
}