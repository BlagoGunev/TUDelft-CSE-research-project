#include <bits/stdc++.h>
using namespace std;
struct Edge
{
	int to, nxt;
} e[400010];
int ecnt = 0, head[200010];
inline void addedge(int from, int to)
{
	e[ecnt].to = to;
	e[ecnt].nxt = head[from];
	head[from] = ecnt++;
}
int f[200010][2][2];
inline void dfs(int u, int fa)
{
	f[u][0][0] = f[u][0][1] = f[u][1][0] = f[u][1][1] = 0;
	int d = 0, m0 = INT_MAX, m1 = INT_MAX;
	for(int i = head[u]; i != -1; i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == fa)
			continue;
		dfs(v, u);
		d++;
		f[u][0][0] += max(f[v][0][0], f[v][1][0]);
		m0 = min(m0, max(f[v][0][0], f[v][1][0]) - max(f[v][0][1], f[v][1][1]));
		f[u][1][0] += f[v][0][0];
		m1 = min(m1, f[v][0][0] - f[v][0][1]);
	}
	if(!d)
		f[u][1][0] = 1;
	else
		f[u][0][1] = f[u][0][0] - m0, f[u][1][1] = f[u][1][0] - m1, f[u][1][0]++, f[u][1][1]++;
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		scanf("%d", &n);
		ecnt = 0;
		for(int i = 1; i <= n; i++)
			head[i] = -1;
		for(int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			addedge(u, v), addedge(v, u);
		}
		int p = 0;
		for(int i = 1; i <= n; i++)
			if(e[head[i]].nxt != -1)
			{
				p = i;
				break;
			}
		dfs(p, p);
		printf("%d\n", max(max(f[p][0][0], f[p][1][0]), max(f[p][0][1], f[p][1][1]) + 1));
	}
	return 0;
}