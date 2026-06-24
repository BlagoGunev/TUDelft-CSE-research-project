#pragma GCC optimize(2)

#pragma GCC optimize(3)

#include <bits/stdc++.h>

#define int long long

using namespace std;

void read(int &x)

{

	x = 0;

	bool f = false;

	char c = getchar();

	while (c < '0' || c > '9') f |= c == '-', c = getchar();

	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();

	if (f) x = -x;

}

void write(int x)

{

	if (x < 0)

	{

		putchar('-');

		x = -x;

	}

	if (x < 10) putchar(x + '0');

	else

	{

		write(x / 10);

		putchar(x % 10 + '0');

	}

}

struct Combination

{

	int fac[1000010], invfac[1000010];

	int power(int a, int b, int p)

	{

		int t = 1;

		while (b > 0)

		{

			if (b & 1) t = t * a % p;

			a = a * a % p, b >>= 1;

		}

		return t;

	}

	void init(int n, int p)

	{

		fac[0] = 1;

		for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % p;

		invfac[n] = power(fac[n], p - 2, p);

		for (int i = n - 1; i >= 0; i--) invfac[i] = invfac[i + 1] * (i + 1) % p;

	}

	int A(int n, int m, int p)

	{

		return fac[n] * invfac[n - m] % p;

	}

	int C(int n, int m, int p)

	{

		return fac[n] * invfac[n - m] % p * invfac[m] % p;

	}

};

struct Segment_Tree

{

	int a[500010];

	struct Node

	{

		int sum, max, min, lazy;

	} Tree[2000010];

	void maketag(int u, int len, int x)

	{

		Tree[u].sum += len * x, Tree[u].max += x, Tree[u].min += x, Tree[u].lazy += x;

	}

	void pushup(int u)

	{

		Tree[u].sum = Tree[u << 1].sum + Tree[u << 1 | 1].sum, Tree[u].max = max(Tree[u << 1].max, Tree[u << 1 | 1].max), Tree[u].min = min(Tree[u << 1].min, Tree[u << 1 | 1].min);

	}

	void pushdown(int u, int L, int R)

	{

		int M = L + R >> 1;

		maketag(u << 1, M - L + 1, Tree[u].lazy), maketag(u << 1 | 1, R - M, Tree[u].lazy);

		Tree[u].lazy = 0;

	}

	void build(int u, int L, int R)

	{

		if (L == R)

		{

			Tree[u].sum = Tree[u].max = Tree[u].min = a[L];

			return;

		}

		int M = L + R >> 1;

		build(u << 1, L, M), build(u << 1 | 1, M + 1, R);

		pushup(u);

	}

	void update(int u, int L, int R, int l, int r, int x)

	{

		if (l <= L && R <= r) maketag(u, R - L + 1, x);

		else if (L <= r && R >= l)

		{

			int M = L + R >> 1;

			pushdown(u, L, R);

			update(u << 1, L, M, l, r, x), update(u << 1 | 1, M + 1, R, l, r, x);

			pushup(u);

		}

	}

	int query_sum(int u, int L, int R, int l, int r)

	{

		if (l <= L && R <= r) return Tree[u].sum;

		else if (L <= r && l <= R)

		{

			int M = L + R >> 1;

			pushdown(u, L, R);

			return query_sum(u << 1, L, M, l, r) + query_sum(u << 1 | 1, M + 1, R, l, r);

		}

		else return 0;

	}

	int query_max(int u, int L, int R, int l, int r)

	{

		if (l <= L && R <= r) return Tree[u].max;

		else if (L <= r && l <= R)

		{

			int M = L + R >> 1;

			pushdown(u, L, R);

			return max(query_max(u << 1, L, M, l, r), query_max(u << 1 | 1, M + 1, R, l, r));

		}

		else return -1e18;

	}

	int query_min(int u, int L, int R, int l, int r)

	{

		if (l <= L && R <= r) return Tree[u].min;

		else if (L <= r && l <= R)

		{

			int M = L + R >> 1;

			pushdown(u, L, R);

			return min(query_min(u << 1, L, M, l, r), query_min(u << 1 | 1, M + 1, R, l, r));

		}

		else return 1e18;

	}

};

struct Dijkstra

{

	int dis[500010];

	bool vis[500010];

	vector<int> v[500010], w[500010];

	struct Node

	{

		int x, dis;

		bool operator < (const Node &a) const

		{

			return dis > a.dis;

		}

	};

	void dijkstra(int s)

	{

		priority_queue<Node> q;

		q.push((Node){s, 0});

		memset(dis, 0x3f, sizeof(dis)), memset(vis, false, sizeof(vis));

		dis[s] = 0;

		while (!q.empty())

		{

			int x = q.top().x;

			q.pop();

			if (vis[x]) continue;

			vis[x] = true;

			for (int i = 0; i < v[x].size(); i++)

			{

				if (dis[v[x][i]] <= dis[x] + w[x][i]) continue;

				dis[v[x][i]] = dis[x] + w[x][i];

				q.push((Node){v[x][i], dis[v[x][i]]});

			}

		}

	}

};

struct SPFA

{

	int dis[500010];

	bool vis[500010];

	vector<int> v[500010], w[500010];

	void spfa(int s)

	{

		queue<int> q;

		q.push(s);

		memset(dis, 0x3f, sizeof(dis)), memset(vis, false, sizeof(vis));

		dis[s] = 0, vis[s] = true;

		while (!q.empty())

		{

			int x = q.front();

			q.pop();

			vis[x] = false;

			for (int i = 0; i < v[x].size(); i++)

			{

				if (dis[v[x][i]] <= dis[x] + w[x][i]) continue;

				dis[v[x][i]] = dis[x] + w[x][i];

				if (vis[v[x][i]]) continue;

				q.push(v[x][i]);

				vis[v[x][i]] = true;

			}

		}

	}

};

struct Tarjan

{

	int t, colsz, dfn[500010], low[500010], col[500010];

	vector<int> v[500010];

	stack<int> s;

	void tarjan(int x)

	{

		dfn[x] = low[x] = ++t;

		s.push(x);

		for (auto i : v[x])

		{

			if (dfn[i] == 0)

			{

				tarjan(i);

				low[x] = min(low[x], low[i]);

			}

			else if (col[i] == 0) low[x] = min(low[x], dfn[i]);

		}

		if (dfn[x] == low[x])

		{

			colsz++;

			while (s.top() != x)

			{

				col[s.top()] = colsz;

				s.pop();

			}

			col[s.top()] = colsz;

			s.pop();

		}

	}

};

int dp[2][4][4][4];

signed main()

{

	ios::sync_with_stdio(0);

	cin.tie(0), cout.tie(0);

	int n;

	cin >> n;

	int ans = 0, now = 0;

	for (int i = 1; i <= n; i++)

	{

		int x;

		cin >> x;

		dp[now][0][0][0]++;

		if (x == 0) ans += i * (n - i + 1);

		else

		{

			now ^= 1;

			for (int j = 0; j <= 3; j++) for (int k = 0; k <= 3; k++) for (int l = 0; l <= 3; l++) dp[now][j][k][l] = 0;

			for (int j = 0; j <= 3; j++) for (int k = 0; k <= 3; k++) for (int l = 0; l <= 3; l++)

			{

				if (j == 0 || (j & x)) dp[now][x][k][l] += dp[now ^ 1][j][k][l];

				else if (k == 0 || (k & x)) dp[now][j][x][l] += dp[now ^ 1][j][k][l];

				else dp[now][j][k][x] += dp[now ^ 1][j][k][l];

			}

		}

		for (int j = 0; j <= 3; j++) for (int k = 0; k <= 3; k++) for (int l = 0; l <= 3; l++) ans += dp[now][j][k][l] * ((j > 0) + (k > 0) + (l > 0));

	}

	cout << ans << endl;

	return 0;

}