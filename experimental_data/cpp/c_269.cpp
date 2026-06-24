#include <map>

#include <set>

#include <cmath>

#include <queue>

#include <stack>

#include <vector>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <iomanip>

#include <iostream>

#include <algorithm>

#define ml m

#define mr m + 1

#define lson id << 1

#define rson id << 1 | 1

#define Error(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;

typedef pair<int, int> P;

const int inf  = 0x3f3f3f3f;

const int maxn = 2e5 + 15;

const int maxm = 1e6 + 15;



struct Edge {

	int to, next, cost, id;

}edge[maxm];



int head[maxn], in[maxn], out[maxn], ecnt;



void add(int u, int v, int id, int w) {

	edge[ecnt].to = v;

	edge[ecnt].id = id;

	edge[ecnt].cost = w;

	edge[ecnt].next = head[u];

	head[u] = ecnt++;

}



int a[maxn], b[maxn], dir[maxn];



int main() {

#ifdef NEKO

	freopen("C:\\Nya.txt", "r", stdin);

#endif

	int n, m; ecnt = 0;

	scanf("%d %d", &n, &m);

	memset(head, -1, sizeof head);

	for(int i = 1; i <= m; i++) {

		int u, v, w;

		scanf("%d %d %d", &u, &v, &w);

		add(u, v, i, w); out[u] += w;

		add(v, u, i, w); out[v] += w;

		a[i] = u, b[i] = v;

	}



	stack<int> que; que.push(1); out[1] = 0;

	while(que.size()) {

		int u = que.top(); que.pop();

		for(int i = head[u]; ~i; i = edge[i].next) {

			int v = edge[i].to, w = edge[i].cost;

			if(in[v] == out[v] and v != n) continue;

			in[v] += w; out[v] -= w;

			if(in[v] == out[v] and v != n) que.push(v);

			if(v == a[edge[i].id]) dir[edge[i].id] = 1;	

		}

	}



	for(int i = 1; i <= m; i++)

		printf("%d\n", dir[i]);

	return 0;

}