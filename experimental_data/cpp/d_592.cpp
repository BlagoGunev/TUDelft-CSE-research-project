#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Node
{
	int n, d;
};

vector<int> f[123500];
bool flag[123500], vis[123500];
queue<Node> q;
int s, t, last[123500];

int Bfs(int x, int& y)
{
	int res = -1;
	memset(vis, 0, sizeof(vis));
	memset(last, 0, sizeof(last));
	Node A, B;
	A.n = x; A.d = 0;
	vis[x] = 1;
	q.push(A);
	while (!q.empty())
	{
		A = q.front(); q.pop();
		if (flag[A.n])
		{
			if (res < A.d || y > A.n) y = A.n;
			res = A.d;
		}
		for (int i = 0; i < f[A.n].size(); i++)
		{
			B.n = f[A.n][i];
			B.d = A.d + 1;
			if (!vis[B.n])
			{
				last[B.n] = A.n;
				q.push(B);
				vis[B.n] = 1;
			}
		}
	}
	return res;
}

int Dfs(int x)
{
	if (last[x] == 0) return 0;
	int res = Dfs(last[x]) + 1;
	last[x] = 0;
	return res;
}

int main()
{
	memset(flag, 0, sizeof(flag));
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0, a, b; i < n-1; i++)
	{
		scanf("%d%d", &a, &b);
		f[a].push_back(b);
		f[b].push_back(a);
	}
	for (int i = 0, a; i < m; i++)
	{
		scanf("%d", &a);
		flag[a] = 1;
		s = a;
	}
	Bfs(s, t);
	int k = Bfs(t, s);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (flag[i]) ans += Dfs(i);
	ans = ans * 2 - k;
	printf("%d\n%d\n", min(s, t), ans);
	return 0;
}