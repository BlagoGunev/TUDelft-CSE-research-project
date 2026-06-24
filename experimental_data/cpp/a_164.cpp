#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>

using namespace std;

int n, m;

int fst[100010];
int nxt[100010];
int val[100010];


int rfst[100010];
int rnxt[100010];
int rval[100010];

int f[100010];

void Load()
{
	scanf("%d%d", &n, &m);
	int i, j;
	for (i = 1; i <= n; i++) {
		scanf("%d", &f[i]);
	}
	memset(fst, -1, sizeof(fst));
	memset(rfst, -1, sizeof(rfst));
	for (j = 0; j < m; j++) {
		int a, b;
		scanf("%d%d", &a, &b);

		val[j] = b;
		nxt[j] = fst[a];
		fst[a] = j;

		rval[j] = a;
		rnxt[j] = rfst[b];
		rfst[b] = j;
	}
}


int was[100010];
int rwas[100010];

void Dfs(int u) 
{
//	cerr << "dfs " << u << "\n";
	was[u] = 1;
	for (int j = fst[u]; j != -1; j = nxt[j]) {
		int v = val[j];
		if (was[v] == 0)
			Dfs(v);
	}
}

void rDfs(int u) 
{
//	cerr << "rdfs " << u << "\n";
	rwas[u] = 1;
	if (f[u] == 1) return;
	for (int j = rfst[u]; j != -1; j = rnxt[j]) {
		int v = rval[j];
		if (rwas[v] == 0)
			rDfs(v);
	}
}



void Solve()
{
	int i;
	for (i = 1; i <= n; i++) {
		if (f[i] == 1 && was[i] == 0) Dfs(i);
		if (f[i] == 2 && rwas[i] == 0) rDfs(i);
	}
	for (i = 1; i <= n; i++) {
		if (was[i] && rwas[i]) printf("1\n");
		else printf("0\n");	
	}
}

int main()
{
	Load();
	Solve(); 
	return 0;
}