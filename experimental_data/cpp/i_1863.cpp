#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using vi=vector<int>;
const int nax=3007;
const int vax=nax*nax/2;

int n;

vi graf[nax];

int k;
int num[nax][nax];

int ojf[vax];
int roz[vax];

int wstro[nax][nax];

int korz;

vi drz[vax];

int fin(int v)
{
	if (ojf[v]!=v)
		ojf[v]=fin(ojf[v]);
	return ojf[v];
}

void uni(int a, int b)
{
	ojf[fin(a)]=fin(b);
}

void dfs1(int v, int c)
{
	for (int i : graf[v])
	{
		if (i==wstro[c][v])
			continue;
		wstro[c][i]=v;
		dfs1(i, c);
	}
}

int dfs2(int v)
{
	int ret=0;
	for (int i : drz[v])
		ret+=dfs2(i);
	return max(ret, roz[v]);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=i+1; j<=n; j++)
		{
			k++;
			num[i][j]=k;
			num[j][i]=k;
			ojf[k]=k;
		}
	}
	for (int i=1; i<=n; i++)
		dfs1(i, i);
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++)
			if (wstro[i][j]!=i)
				uni(num[i][wstro[i][j]], num[j][wstro[j][i]]);
	for (int i=1; i<=k; i++)
		roz[fin(i)]++;
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++)
			if (wstro[i][j]==i)
				korz=fin(num[i][j]);
	vector<pii> kra;
	for (int i=1; i<=n; i++)
	{
		for (int j=i+1; j<=n; j++)
		{
			if (wstro[i][j]==i)
				continue;
			int x=fin(num[i][j]);
			int y=fin(num[i][wstro[i][j]]);
			kra.push_back({y, x});
		}
	}
	sort(kra.begin(), kra.end());
	kra.resize(unique(kra.begin(), kra.end())-kra.begin());
	for (pii i : kra)
		drz[i.first].push_back(i.second);
	printf("%d\n", dfs2(korz));
	return 0;
}