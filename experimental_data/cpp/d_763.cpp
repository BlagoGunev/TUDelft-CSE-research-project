#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <queue>
#include <stack>
#include <bitset>
#define y1 y11
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define NAME ""

using namespace std;
	
typedef long long ll;
typedef long double ld;

const ld PI = acos(-1.0);

const int MAXN = 400001;

const ll H1 = 1000003;
const ll H2 = 279787;
ll d[MAXN];
ll u[MAXN];
ll rt[MAXN];
ll vls[MAXN];
int vc;

void mlb(ll &x)
{
	x = lower_bound(vls, vls + vc, x) - vls;
}

vector <int> e[MAXN];

int cn[MAXN];
int cur;
int ans = 0;
int ver;
	
void chng(int i1, int i2)
{
	if (cn[i1] == 1) cur--;
	cn[i1]--;
	if (cn[i2] == 0) cur++;
	cn[i2]++;
}

void dfs1(int v, int p)
{
	d[v] = 0;
	for (int i = 0; i < e[v].size(); i++)
	{
		int  uu = e[v][i];
		if (uu != p)
		{
			dfs1(uu, v);
			d[v] += d[uu] * H1;
		}
	}
	d[v] ^= H2;
}

void dfs2(int v, int p)
{
	rt[v] = d[v] ^ H2;
	if (p != v) rt[v] += u[v] * H1;
	rt[v] ^= H2;
	for (int i = 0; i < e[v].size(); i++)
	{
		int uu = e[v][i];
		if (uu != p)
		{
			u[uu] = ((rt[v] ^ H2) - d[uu] * H1) ^ H2;
			dfs2(uu, v);
		}
	}
}

int an[MAXN];
void dfs3(int v, int p)
{
	if (v != p)
	{
		chng(rt[p], u[v]);
		chng(d[v], rt[v]);
	}
	if (cur > ans) ans = cur, ver = v;
	an[v] = cur;
	for (int i = 0; i < e[v].size(); i++)
	{
		if (e[v][i] != p) dfs3(e[v][i], v);
	}
	if (v != p)
	{
		chng(u[v], rt[p]);
		chng(rt[v], d[v]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i= 1; i < n; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		e[v1].push_back(v2);
		e[v2].push_back(v1);
	}
	dfs1(1, 1);
	dfs2(1, 1);
	for (int i = 1; i <= n; i++)
	{
		vls[i * 3 - 3] = d[i];
		vls[i * 3 - 2] = rt[i];
		vls[i * 3 - 1] = u[i];
	}
	sort(vls, vls + 3 * n);
	memset(cn, 0, sizeof(cn));
	vc = unique(vls, vls + 3 * n) - vls;
	cur = 1;
	for (int i = 1; i <= n; i++)
	{
		mlb(d[i]);
		mlb(rt[i]);
		mlb(u[i]);
	}
	cn[rt[1]] = n;
	for (int i = 2; i <= n; i++)
	{
		chng(rt[1], d[i]);
	}
	dfs3(1, 1);
	cout << ver << endl;
	return 0;
}