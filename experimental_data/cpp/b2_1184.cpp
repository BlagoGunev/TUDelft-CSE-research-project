#include <bits/stdc++.h>

using namespace std;


namespace TUMbledore
{
#define MAXN 2005

int n, mat[MAXN], lev[MAXN];
bool ibg;
bitset<MAXN> v;
vector<int> vl, e[MAXN];

bool findPath(int i) {
	for (int j : e[i]) {
		if (v[j])
			continue;
		v[j] = true;
		if (mat[j] == -1 || findPath(mat[j])) {
			mat[i] = j; mat[j] = i;
			return true;
		}
	}
	return false;
}

void dfs(int i, int l = 1) {
	lev[i] = l;
	if (l == 1)
		vl.push_back(i);
	for (int j : e[i])
		if (!lev[j])
			dfs(j, 3 - l);
	else
		ibg = ibg && lev[i] != lev[j];
}

pair<int, vector<pair<int, int>>> maxCardinalityBipartiteMatching() {
	int mbm = 0, prev = 0;
	ibg = true;
	vl.clear();
	for (int i = 0; i < n; i++)
		mat[i] = -1, lev[i] = 0;
	for (int i = 0; i < n; i++)
		if (!lev[i])
			dfs(i);
	if (!ibg)
		return {-1, vector<pair<int, int>>()};
	do {
		prev = mbm;
		v.reset();
		for (int i : vl)
			if (mat[i] == -1)
				mbm += findPath(i);
	} while (mbm > prev);
	vector<pair<int, int>> ma;
	for (int i : vl)
		if (mat[i] != -1)
			ma.push_back({i, mat[i]});
	return {mbm, ma};
}
#undef MAXN
};

const int MAX_N = 105;
const int INF = 123456789;
const int MAX_B = 1005;

int n,m;
int d[MAX_N][MAX_N];
int s,b,k,h;
int xs[MAX_B],a[MAX_B],f[MAX_B];
int xb[MAX_B],db[MAX_B];

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			if (i!=j)
				d[i][j]=INF;
	while (m--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		d[a][b]=d[b][a]=1;
	}
	for (int k=1; k<=n; k++)
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	scanf("%d %d %d %d",&s,&b,&k,&h);
	for (int i=0; i<s; i++)
		scanf("%d %d %d",xs+i,a+i,f+i);
	for (int i=0; i<b; i++)
		scanf("%d %d",xb+i,db+i);
	TUMbledore::n = s+b;
	//0..s-1 s...s+b-1
	for (int i=0; i<s; i++)
		for (int j=0; j<b; j++)
			if (d[xs[i]][xb[j]] <= f[i] && a[i] >= db[j])
			{
				TUMbledore::e[i].push_back(j+s);
				TUMbledore::e[j+s].push_back(i);
			}
	int m=TUMbledore::maxCardinalityBipartiteMatching().first;
	printf("%lld\n",min(s*1LL*h,k*1LL*m));
	return 0;
}