// M            

#include<iostream>

#include<bits/stdc++.h>

#include<vector>

#include<algorithm>

#include<queue>

#include<set>

#define ll long long

#define iosp ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const int N = 1e5 + 10, M = 998244353;

const ll inff = 1e18;

int n,u,v,lst[N],pt,ecnt[N];

bool cov[N],cov2[N], j[N], nleaf[N];

vector<int>e[N];

void spr(int x)

{

	cov2[x] = 1; int st;

	for (auto k : e[x])

	{

		if(cov2[k])continue;

		nleaf[x] = 1;

		j[k] = j[x] ^ 1;

		lst[k] = x;

		spr(k);

	}

}

void solve()

{

	cin >> n; 

	for (int i = 1; i < n; i++)

	{

		cin >> u >> v;

		e[u].push_back(v);

		e[v].push_back(u);

	}

	if (n % 2 == 0) { cout << n << '\n'; return; }

	spr(n); lst[n] = n; cov[n] = 1; 

	if (e[n].size() == 1)nleaf[n] = 0;

	for (int i = n; i; i--)

	{

		if(!nleaf[i]||j[i]) { cout << i << '\n'; return; }

		if(!cov[i])

		{

			pt = i;

			while (!cov[pt])

			{

				cov[pt] = 1; ecnt[pt]++;

				pt = lst[pt]; ecnt[pt]++;

			}

			if(ecnt[pt]>2&&!j[pt]) { cout << i << '\n'; return; }

		}

	}

}

int main()

{

	iosp

	int t = 1;//cin >> t;

	while (t--)solve();

}