#include <bits/stdc++.h>

using namespace std;

int nid,son[5005][15],nxt[5005][15];

int w[5005],fail[5005];

int dp[4100][5005];

pair<int,int> fr[4100][5005];

int X[4100][5005];

const int inf=1e9;

void ins(string s,int x)

{

	//cout << s << "*" << x << "\n";

	int p=0;

	for(auto t:s)

	{

		if(!son[p][t-'a']) son[p][t-'a']=++nid;

		p=son[p][t-'a'];

	}

	w[p]+=x;

}

vector<int> e[5005];

void getF()

{

	queue<int> q;

	q.push(0);

	while(!q.empty())

	{

		int x=q.front();

		q.pop();

		for(int i=0;i<12;i++)

		{

			fail[son[x][i]]=nxt[fail[x]][i];

			if(son[x][i]) nxt[x][i]=son[x][i],q.push(son[x][i]);

			else nxt[x][i]=nxt[fail[x]][i];

		}

		w[x]+=w[fail[x]];

	}

}

int E[12][12]={};

string S;

void dfs(int u,int f)

{

	S+=u+'a';

	for(int i=0;i<12;i++)

		if(i!=f&&E[u][i]) dfs(i,u);

}

signed main()

{

	ios::sync_with_stdio(false);

	cin.tie(0);

	int n;

	cin >> n;

	for(int i=1;i<=n;i++)

	{

		int c;

		string s;

		cin >> c >> s;

		memset(E,0,sizeof E);

		for(int j=1;j<s.size();j++)

			E[s[j-1]-'a'][s[j]-'a']=E[s[j]-'a'][s[j-1]-'a']=1;

		int p=-1,flag=0;

		for(int j=0;j<12;j++)

		{

			int cnt=0;

			for(int k=0;k<12;k++)

				cnt+=E[j][k];

			if(cnt>2) flag=1;

			if(cnt==1) p=j;

		}

		if(flag||p==-1) continue;

		S.clear();

		dfs(p,-1);

		ins(S,c);

		reverse(S.begin(),S.end());

		ins(S,c);

	}

	getF();

	for(int i=0;i<4096;i++)

		for(int j=0;j<=nid;j++) dp[i][j]=-inf;

	dp[0][0]=0;

	for(int i=0;i<4096;i++)

	{

		for(int j=0;j<12;j++)

		{

			if(!(i&(1<<j)))

			{

				for(int k=0;k<=nid;k++)

				{

					if(dp[i][k]+w[nxt[k][j]]>dp[i|(1<<j)][nxt[k][j]])

						dp[i|(1<<j)][nxt[k][j]]=dp[i][k]+w[nxt[k][j]],fr[i|(1<<j)][nxt[k][j]]={i,k},X[i|(1<<j)][nxt[k][j]]=j;

				}

			}

		}

	}

	int x=4095,y;

	pair<int,int> mx={-1,-1};

	for(int i=0;i<=nid;i++)

		mx=max(mx,{dp[x][i],i});

//	cout << mx.first << "!!!!!\n";

	y=mx.second;

	for(int i=0;i<12;i++)

	{

		cout << (char)('a'+X[x][y]);

		pair<int,int> qwq=fr[x][y];

		x=qwq.first,y=qwq.second;

	}

	return 0;

}