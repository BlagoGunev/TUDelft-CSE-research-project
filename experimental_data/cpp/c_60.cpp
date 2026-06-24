#if 1
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <stack>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <functional>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <list>
#include <ctime>
using namespace std;

typedef long long LL;
typedef long double LD;
const LD eps = 1e-9;

typedef pair<int, int> pii;
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define iss istringstream
#define oss ostringstream
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbgv(x) { cerr << #x << ": {"; for(int i = 0; i < x.size(); ++i) { if(i) cerr << ", "; cerr << x[i]; } cerr << "}" << endl; }

const int maxn = 128;
vector< vector< pair<int, pii > > > g;
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
LL lcm(LL a, LL b) { return a / gcd(a, b) * b; }
int ans[maxn];
int cur[maxn];
bool used[maxn];
bool check(int u, int val)
{
	queue<int> q;
	q.push(u);
	memset(used, 0, sizeof used);
	memset(cur, 0, sizeof cur);
	cur[u] = val;
	used[u] = true;
	while(q.size())
	{
		int u = q.front(); q.pop();
		for(int i = 0; i < g[u].size(); ++i)
		{
			int v = g[u][i].X;
			int gc = g[u][i].Y.X;
			int lc = g[u][i].Y.Y;
			LL nval = gc * LL(lc);
			if(nval % cur[u] != 0)
				return false;
			nval /= cur[u];
			if(gcd(nval, cur[u]) != gc)
				return false;
			if(lcm(nval, cur[u]) != lc)
				return false;
			if(nval < 1 || nval > 1000000)
				return false;

			if(!used[v])
			{
				cur[v] = nval;
				used[v] = true;
				q.push(v);
			} else
			{
				if(cur[v] != nval)
					return false;
			}

		}
	}
	return true;
}
int main()
{
	// freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int n, m; cin >> n >> m;
	g.resize(n);
	for(int i = 0; i < m; ++i)
	{
		int gc, lc;
		int u, v;
		scanf("%d%d%d%d", &u, &v, &gc, &lc);
		u--;
		v--;
		g[u].pb(mp(v, mp(gc, lc)));
		g[v].pb(mp(u, mp(gc, lc)));

	}

	for(int i = 0; i < n; ++i)
		if(!ans[i])
		{
			if(g[i].size() == 0)
				ans[i] = 1;
			else
			{
				
				for(int j = 1; j * j <= g[i][0].Y.Y; ++j)
					if(g[i][0].Y.Y % j == 0)
					{
						if(check(i, j))
						{
							for(int k = 0; k < n; ++k)
								if(used[k])
									ans[k] = cur[k];
							break;
						} else if(check(i, g[i][0].Y.Y / j))
						{
							for(int k = 0; k < n; ++k)
								if(used[k])
									ans[k] = cur[k];
							break;
						}
					}
				if(!ans[i])
				{
					cout << "NO" << endl;
					return 0;
				} 
			}
			

		}


	cout << "YES" << endl;
	for(int i = 0; i < n; ++i)
	{
		if(i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
#endif