#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <algorithm>

#include <cmath>

using namespace std;



const int MaxN = 1e5;

int all, pre[2 * MaxN + 5], last[MaxN + 5], other[2 * MaxN + 5];

int n, m, k, tot = 0;

bool vis[MaxN + 5], flag = 0;

struct Point{

	int w, p;

}loc[MaxN + 5];



void Build(int x, int y)

{

	all++;

	pre[all] = last[x];

	last[x] = all;

	other[all] = y;

}



bool cmp(Point x, Point y)

{

	return x.w < y.w;	

}



void Dfs(int x, int y)

{

//	printf("**\n");

	int ed, dr;

	loc[x].w = ++tot; loc[x].p = x;

	vis[x] = 1;

	ed = last[x];

	while(ed != -1)

	{

		dr = other[ed];

		if(dr != y && !vis[dr]) Dfs(dr, x);

		if(flag) return;

		ed = pre[ed];

	}

	ed = last[x];

	flag = 1;

	while(ed != -1)

	{

		dr = other[ed];

		if(loc[x].w - loc[dr].w >= k) break;

		ed = pre[ed];

	}

	sort(loc + 1, loc + n + 1, cmp);

	int j = 1;

	while(loc[j].p != dr) {j++;}

	printf("%d\n", n - j + 1);

	for(int i = j; i <= n; i++) printf("%d ", loc[i].p);

	printf("\n");

	return;

}



int main()

{

	all = -1;

	memset(last, -1, sizeof(last));

	scanf("%d%d%d", &n, &m, &k);

	for(int i = 1; i <= m; i++)

	{

		int a, b;

		scanf("%d%d", &a, &b);

		Build(a, b); Build(b, a);

	}

	memset(vis, 0, sizeof(vis));

	tot = 0;

	Dfs(1, 0);

}