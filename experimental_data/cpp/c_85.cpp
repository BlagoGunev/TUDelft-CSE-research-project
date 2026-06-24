#include <assert.h> 
#include <ctype.h> 
#include <float.h> 
#include <math.h> 
#include <stdio.h> 
#include <string> 
#include <stdlib.h> 
#include <time.h> 
#include <algorithm> 
#include <numeric> 
#include <functional> 
#include <utility> 
#include <vector> 
#include <list> 
#include <set> 
#include <map> 
#include <queue> 
#include <stack> 
#include <sstream> 
#include <iostream> 
#include <memory.h>

using namespace std; 

#define rep(i,n) for(int i=0;i<(n);++i)
#define clr(a,b) memset(a,b,sizeof(a)); 
#define all(c) (c).begin(), (c).end() 
#define inf 1000000000 

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<string> vs;
typedef vector<int> vi;

int c[100001];
int parent[100001];
int val[100001];
int l[100001];
int r[100001];

int leftMost[100001];
int rightMost[100001];

void dfs2(int v)
{
	if (l[v] == -1)
	{
		leftMost[v] = rightMost[v] = v;
	}
	else
	{
		dfs2(l[v]);
		dfs2(r[v]);

		leftMost[v] = leftMost[l[v]];
		rightMost[v] = rightMost[r[v]];
	}
}

vector<pair<int, int> > q;
double ans[100000];

void dfs(int v, int from, int to, double cur, int cnt)
{
	if (l[v] == -1)
	{
		cur /= cnt;

		int pos = lower_bound(all(q), make_pair(from, 0)) - q.begin();

		while (pos < q.size() && q[pos].first >= from && q[pos].first <= to)
		{
			ans[q[pos].second] = cur;
			pos++;
		}

		return;
	}
	else
	{
		int x = val[v];

		dfs(l[v], from, x - 1, cur + val[leftMost[r[v]]] , cnt + 1);
		
		dfs(r[v], x + 1, to, cur + val[rightMost[l[v]]], cnt + 1);
	}

}


int main(int argc, char* argv[])
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif
	
	int N;
	scanf("%d", &N);

	memset(l, -1, sizeof(l));
	memset(r, -1, sizeof(r));

	for (int i = 1; i <= N; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);

		parent[i] = u;
		val[i] = v;
	}

	int root = -1;
	for (int i = 1; i <= N; i++)
	{
		if (parent[i] != -1)
		{
			if (val[i] < val[parent[i]])
				l[parent[i]] = i;
			else
				r[parent[i]] = i;
		}
		else
		{
			root = i;
		}
	}


	dfs2(root);


	int K;
	scanf("%d", &K);

	q.resize(K);

	for (int i = 0; i < K; i++)
	{
		int x;
		scanf("%d", &x);

		q[i] = make_pair(x, i);
	}
	sort(q.begin(), q.end());

	dfs(root, 1, (int)1e9, 0, 0);
	
	for (int i = 0; i < K; i++)
	{
		printf("%.9lf\n", ans[i]);
	}
		


	return 0;
}