#include<cstdio>

#include<algorithm>

#include<iostream>

#include<cstring>

#include<vector>

#define LL long long

#define N 200010

#define POW 20

using namespace std;

vector<int> edge[N];

int size[N], n, m, d[N];

LL sum[N], dsum[N];

int p[N][POW];

void dfs1(int u, int fa){

	size[u] = 1;

	sum[u] = 0;

	d[u] = d[fa] + 1;

	p[u][0] = fa;

	for(int i = 1; i < POW; i ++) p[u][i] = p[p[u][i - 1]][i - 1];

	for(int i = 0; i < edge[u].size(); i ++){

		int v = edge[u][i];

		if(v == fa) continue;

		dfs1(v, u);

		size[u] += size[v];

		sum[u] += sum[v] + size[v];

	}

}

void dfs2(int u, int fa){

	for(int i = 0; i < edge[u].size(); i ++){

		int v = edge[u][i];

		if(v == fa) continue;

		dsum[v] = dsum[u] + (size[1] - size[u]) + sum[u] + (size[u] - size[v]) - (sum[v] + size[v]);

		dfs2(v, u);

	}

}

double calc(int a, int b){

	int slca = 0;

	if(d[a] > d[b]) swap(a, b);

	int mema = a, memb = b;

	if(d[a] < d[b]){

		int del = d[b] - d[a] - 1;

		for(int i = 0; i < POW; i ++){

			if(del & (1 << i)) b = p[b][i];

		}

		slca = b;

		b = p[b][0];

	}

	if(a != b){

		for(int i = POW - 1; i >= 0; i --){

			if(p[a][i] != p[b][i]){

				a = p[a][i];

				b = p[b][i];

			}

		}

		a = p[a][0];

		b = p[b][0];

	}

	int lca = a;

	a = mema; b = memb;

	//cout << a << ' ' << b << endl;

	if(lca == a){

		int sz1 = size[1] - size[slca];

		int sz2 = size[b];

		LL sum1 = dsum[slca] - sz1;

		LL sum2 = sum[b];

		//cout << sz1 << ' ' << sum1 << ' ' << sz2 << ' ' << sum2 << endl;

		return (double)(sum1 * sz2 + sum2 * sz1 + 1LL * sz1 * sz2 * (d[b] - d[a] + 1)) / (1LL *sz1 * sz2);

	}

	else{

		int sz1 = size[a];

		int sz2 = size[b];

		LL sum1 = sum[a];

		LL sum2 = sum[b];

		//cout << sz1 << ' ' << sum1 << ' ' << sz2 << ' ' << sum2 << endl;

		return (double)(sum1 * sz2 + sum2 * sz1 + 1LL * sz1 * sz2 * (d[a] + d[b] - 2 * d[lca] + 1)) / (1LL * sz1 * sz2);

	}

}



int main(){

	scanf("%d%d", &n, &m);

	for(int i = 1; i < n; i ++){

		int x, y;

		scanf("%d%d", &x, &y);

		edge[x].push_back(y);

		edge[y].push_back(x);

	}

	dfs1(1, 0);

	dfs2(1, 0);

	/*

	for(int i = 1; i <= n; i ++){

		cout << size[i] << ' ' << sum[i] << ' ' << dsum[i] << endl;

	}

	*/

	for(int i = 1; i <= m; i ++){

		int x, y;

		scanf("%d%d", &x, &y);

		printf("%.10f\n", calc(x, y));

	}

	return 0;

}