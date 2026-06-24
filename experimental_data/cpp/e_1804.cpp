#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <cassert>
#include <chrono>
using namespace std;

const int MAXN = 20;

int n;
int adj[MAXN];

int dp[MAXN][1<<MAXN];
int neighbours[1<<MAXN];

int testbit(int n, int m)
{
	return (n>>m)&1;
}

int anybit(int n)
{
	assert(n!=0);
	for(int i=0;;i++)
		if(testbit(n,i))
			return i;
	throw;
}

int main()
{
	int m;
	scanf("%d%d",&n, &m);

	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		adj[a]|=1<<b;
		adj[b]|=1<<a;
	}

	for(int i=0;i<n;i++)
		dp[i][1<<i]=1<<i;

	for(int k=0;k<n;k++)
		for(int i=1;i<(1<<n);i++)
			for(int j=0;j<n;j++)
				if(!testbit(i,j) && (adj[j]&dp[k][i]) )
					dp[k][i|(1<<j)] |= 1<<j;

	for(int i=1;i<(1<<n);i++)
	{
		for(int j=0;j<n;j++)
			if(testbit(i,j))
			{
				neighbours[i] = neighbours[i^(1<<j)] | adj[j];
				break;
			}
	}

	int cycleStart = -1;
	int cycleMask = -1;
	int ALL = (1<<n)-1;

	for(int k=0;k<n && cycleMask == -1;k++)
		for(int i=1;i<(1<<n);i++)
		{
			if( (dp[k][i]&adj[k]) && (neighbours[i]) == ALL)
			{
				cycleStart = k;
				cycleMask = i;
				break;
			}
		}

	if(cycleMask == -1)
		puts("NO");
	else
	{
		puts("YES");

		vector<int> cycle;

		int cur = anybit( dp[cycleStart][cycleMask]&adj[cycleStart] );
		int maskLeft = cycleMask^(1<<cur);
		cycle.push_back(cur);
		while(maskLeft)
		{
			cur = anybit( maskLeft & adj[cur] & dp[cycleStart][maskLeft] );
			maskLeft ^= 1<<cur;

			cycle.push_back(cur);
		}

		int p[MAXN];
		memset(p,-1,sizeof(p));
		for(int i=0;i<cycle.size();i++)
			p[cycle[(i+1)%cycle.size()]] = cycle[i];
		for(int i=0;i<n;i++)
			if(p[i] == -1)
				p[i] = anybit(cycleMask & adj[i]);
		for(int i=0;i<n;i++)
			printf("%d ", p[i]+1);
		puts("");
	}


	return 0;
}