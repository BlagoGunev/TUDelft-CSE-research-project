#include <bits/stdc++.h>

#define int long long 

#define mod 1000000007

using namespace std;

int ch[1005][26],nxt[1005][26],fail[1005],nid,a[1005],N;

void ins(string s,int w)

{

	int nw=0;

	for(auto t:s)

	{

		t-='a';

		if(!ch[nw][t]) ch[nw][t]=++nid;

		nw=ch[nw][t];

	}

	a[nw]+=w;

}

vector<int> e[1005];

void getF()

{

	queue<int> q;

	q.push(0);

	while(!q.empty())

	{

		int x=q.front();

		q.pop();

		for(int i=0;i<26;i++)

		{

			if(ch[x][i])

			{

				fail[ch[x][i]]=nxt[fail[x]][i],nxt[x][i]=ch[x][i];

				q.push(ch[x][i]);

			}

			else if(x) nxt[x][i]=nxt[fail[x]][i];

		}

	}

	for(int i=1;i<=nid;i++)

	{

		e[fail[i]].push_back(i);

	//	cout << fail[i] << " " << i << "\n";

	}

}

void dfs(int u)

{

	for(auto v:e[u])

		a[v]+=a[u],dfs(v);

}

int Nx[16][1005],w[16][1005];

int dp[16400][1005];

const int inf=1e18;

signed main()

{

	ios::sync_with_stdio(false);

	cin.tie(0);

	cin >> N;

	for(int i=1;i<=N;i++)

	{

		string s;

		int w;

		cin >> s >> w;

		ins(s,w);

	}

	getF(),dfs(0);

	string s;

	cin >> s;

	int nw=0,c=0;

	for(int i=0;i<=nid;i++) Nx[0][i]=i,w[0][i]=a[i];

	for(int i=0;i<s.size();i++)

	{

		if(s[i]=='?')

		{

			++c;

			for(int i=0;i<=nid;i++) Nx[c][i]=i,w[c][i]=a[i];

			continue;

		}

		for(int j=0;j<=nid;j++)

		{

			Nx[c][j]=nxt[Nx[c][j]][s[i]-'a'];

			w[c][j]+=a[Nx[c][j]];

		}

	}

	for(int i=0;i<(1<<14);i++)

		for(int j=0;j<=nid;j++) dp[i][j]=-inf;

	dp[0][0]=w[0][0];

	int mx=-inf;

	for(int i=0;i<(1<<14);i++)

	{

		int p=__builtin_popcount(i);

		for(int j=0;j<14;j++)

		{

			if(!(i&(1<<j)))

			{

				for(int k=0;k<=nid;k++)

				{

					int nx=Nx[p][k];

					nx=nxt[nx][j];

					dp[i|(1<<j)][nx]=max(dp[i|(1<<j)][nx],dp[i][k]+w[p+1][nx]);

				}

			}

		}

		if(p==c) for(int j=0;j<=nid;j++) mx=max(mx,dp[i][j]);

	}

	cout << mx;

	return 0;

}