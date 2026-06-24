#pragma GCC optimize(2)
#include <bits/stdc++.h>

using namespace std;

int n, m, q;

inline int rd()
{
	register int x = 0; register char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
	return x;
}

namespace DCC
{
    const int maxn = 1e+5 + 5;
    const int maxm = 5e+5 + 5;
    struct edge
    {
        int to, nxt;
    }e[maxm << 1];
    struct cedge
    {
    	int to, nxt;     
    }ce[maxn << 2];
    int dfn[maxn], low[maxn], cnt, ID;
    int lnk[maxn], clnk[maxn << 1], cptr, ptr;
    stack<int> st;

    void add(int bgn, int end)
    {
        e[++ptr].to = end;
        e[ptr].nxt = lnk[bgn];
        lnk[bgn] = ptr;
    }
    void cadd(int bgn, int end)
    {
        ce[++cptr].to = end;
        ce[cptr].nxt = clnk[bgn];
        clnk[bgn] = cptr;
    }

    void tarjan(int x, int inv)
    {
        dfn[x] = low[x] = ++cnt;
        st.push(x);
        for(int p = lnk[x]; p; p = e[p].nxt)
        {
            int y = e[p].to;
            if(!dfn[y])
            {
                tarjan(y, x);
                low[x] = min(low[x], low[y]);
                if(low[y] >= dfn[x]){
                    ID++; int now;
                    cadd(x, ID);
                    do {
                        now = st.top(); st.pop();
                        cadd(ID, now);
                    } while(now != y);
                }
            }
            else if(y != inv) low[x] = min(low[x], dfn[y]);
        }
    }

    void main()
    {
        ID = n;
        tarjan(1, 0);
        //cerr << "tarjan" << endl;
        return;
    }
};
namespace LHD
{
	using namespace DCC;
	const int maxp = 2e+5 + 5;
	int DFN[maxp], siz[maxp], mxson[maxp], dep[maxp];
	int f[maxp], top[maxp];
	//int dis[maxp];

	void dfs1(int x, int fa, int d)
	{
		//cerr << "dfs1" << endl;
		f[x] = fa;
		siz[x] = 1;
		dep[x] = d;
		for(register int p = clnk[x]; p; p = ce[p].nxt)
		{
			int y = ce[p].to;
			if(y == fa) continue;
			dfs1(y, x, d + 1);
			siz[x] += siz[y];
			if(siz[y] > siz[mxson[x]]) mxson[x] = y;
		}
	}
	void dfs2(int x, int init)
	{
		//cerr << "dfs2" << endl;
		top[x] = init;
		if(!mxson[x]) return;
		dfs2(mxson[x], init);
		for(register int p = clnk[x]; p; p = ce[p].nxt)
		{
			int y = ce[p].to;
			if(y == f[x] || y == mxson[x]) continue;
			dfs2(y, y);
		}
	}
	int lca(int x, int y)
	{
		while(top[x] != top[y])
		{
			if(dep[top[x]] < dep[top[y]]) swap(x, y);
			x = f[top[x]];
		}
		return (dep[x] < dep[y]) ? x : y;
	}
	void main()
	{
		dfs1(1, 0, 1);
		dfs2(1, 1);
		//cerr << "dfs" << endl;
		int x, y;
		while(q--)
		{
			//cin >> x >> y;
			x = rd(); y = rd();
			int LCA = lca(x, y);
			int dis = dep[x] + dep[y] - 2 * dep[LCA];
			//cout << (dis / 2) << endl;
			printf("%d\n", dis/2);
		}
	}
};

int main()
{
	
	//cin >> n >> m >> q;
	n = rd(); m = rd(); q = rd();
	int u, v;
	for(register int i = 1; i <= m; ++i)
	{
		//cin >> u >> v;
		u = rd(); v = rd();
		DCC::add(u, v); DCC::add(v, u);
	}
	DCC::main();
	LHD::main();
	return 0;
}