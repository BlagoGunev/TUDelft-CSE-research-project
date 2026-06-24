// Problem : cf 300 E
// Author : Leo Yu

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
typedef long long LL;

#define link Link
#define next Next
#define elif else if

inline int read()
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}

int size[1000006], f[1000006], g[1000006];
vector<int> edge[1000006];

void	DFS(int x, int h)
{
	size[x] = 0;
	if (!h)
	{
		f[x] = 1 << 30;
		g[x] = 0;
	}
	else
	{
		f[x] = 0;
		g[x] = 1 << 30;
	}
	for (int i = 0; i < edge[x].size(); ++ i)
	{
		int y = edge[x][i];
		DFS(y, h ^ 1);
		size[x] += size[y];
		if (!h)
		{
			f[x] = min(f[x], size[y] - f[y]);
			g[x] += g[y];
		}
		else
		{
			f[x] += size[y] - f[y] + 1;
			g[x] = min(g[x], g[y]);
		}
	}
	if (!h)
	{
		f[x] = size[x] - f[x];
	}
	else
	{
		f[x] = size[x] - f[x] + 1;
	}
	if (size[x] == 0)
	{
		size[x] = f[x] = g[x] = 1;
	}
}


int main()
{
#ifndef ONLINE_JUDGE
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
#endif

	int N = read();

	for (int i = 1; i < N; ++ i)
	{
		int x = read(), y = read();
		edge[x].push_back(y);
	}
	DFS(1, 0);
	cout << f[1] << " " << g[1] << endl;

	return 0;
}