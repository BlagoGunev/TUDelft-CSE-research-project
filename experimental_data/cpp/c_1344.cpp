#include<bits/stdc++.h>
#define llong long long
#define mkpr make_pair
#define x first
#define y second
#define iter iterator
#define riter reversed_iterator
#define y1 Lorem_ipsum_dolor
using namespace std;

inline int read()
{
	int x = 0,f = 1; char ch = getchar();
	for(;!isdigit(ch);ch=getchar()) {if(ch=='-') f = -1;}
	for(; isdigit(ch);ch=getchar()) {x = x*10+ch-48;}
	return x*f;
}

const int mxN = 2e5;
vector<int> inv[mxN+3],ouv[mxN+3]; int ind[mxN+3];
int dfn[mxN+3];
int f[mxN+3],g[mxN+3];
queue<int> que;
char ans[mxN+3];
int n,m,dfnn;

int main()
{
	n = read(),m = read();
	for(int i=1; i<=m; i++) {int x = read(),y = read(); ouv[x].push_back(y),inv[y].push_back(x); ind[y]++;}
	for(int i=1; i<=n; i++) if(!ind[i]) {que.push(i); dfn[++dfnn] = i;}
	while(!que.empty())
	{
		int u = que.front(); que.pop();
		for(int i=0; i<ouv[u].size(); i++)
		{
			int v = ouv[u][i]; ind[v]--;
			if(ind[v]==0)
			{
				dfn[++dfnn] = v;
				que.push(v);
			}
		}
	}
	if(dfnn<n) {puts("-1"); return 0;}
	for(int i=n; i>=1; i--)
	{
		int u = dfn[i]; f[u] = u;
		for(int o=0; o<ouv[u].size(); o++)
		{
			int v = ouv[u][o];
			f[u] = min(f[u],f[v]);
		}
	}
	for(int i=1; i<=n; i++)
	{
		int u = dfn[i]; g[u] = u;
		for(int o=0; o<inv[u].size(); o++)
		{
			int v = inv[u][o];
			g[u] = min(g[u],g[v]);
		}
	}
	int ans_cnt = 0;
	for(int u=1; u<=n; u++)
	{
		ans[u] = min(g[u],f[u])<u?'E':'A';
		if(ans[u]=='A') ans_cnt++;
	}
	printf("%d\n",ans_cnt);
	for(int i=1; i<=n; i++) printf("%c",ans[i]); puts("");
	return 0;
}