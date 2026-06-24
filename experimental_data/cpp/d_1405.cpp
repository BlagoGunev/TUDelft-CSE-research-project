#include<bits/stdc++.h>

#include<unordered_map>

#include<unordered_set>

using namespace std;

using LL = long long;

using LD = long double;

using ULL = unsigned long long;

using PII = pair<LL, LL>;

using TP = tuple<int, int, int>;

#define all(x) x.begin(),x.end()

#define mst(x,v) memset(x,v,sizeof(x))

#define mul(x,y) (1ll*(x)*(y)%mod)

#define mk make_pair

//#define int LL

//#define double LD

#define lc tr[x].ch[0]

#define rc tr[x].ch[1]

#define endl '\n'

#define inf 0x3f3f3f3f

#define INF 0x3f3f3f3f3f3f3f3f

#pragma warning(disable : 4996)

#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

const double eps = 1e-10;

const double pi = acos(-1);

const LL MOD = 1000000007;

const LL mod = 998244353;

const int maxn = 100010;



int T, N, A, B, DA, DB;

vector<int>G[maxn];

bool used[maxn];

int D[maxn], diameter = -inf, dep[maxn];

void add_edge(int from, int to)

{

	G[from].push_back(to);

	G[to].push_back(from);

}



void dp(int v)

{

	used[v] = true;

	for (int i = 0; i < G[v].size(); i++)

	{

		int to = G[v][i];

		if (!used[to])

		{

			dp(to);

			diameter = max(diameter, D[v] + D[to] + 1);

			D[v] = max(D[v], D[to] + 1);

		}

	}

}



void dfs(int v, int p,int d)

{

	dep[v] = d;

	for (auto& to : G[v])

	{

		if (to == p)

			continue;

		dfs(to, v, d + 1);

	}

}



void solve()

{

	diameter = -inf;

	if (DB <= 2 * DA)

	{

		cout << "Alice" << endl;

		return;

	}

	dfs(A, 0, 0);

	if (dep[B] <= DA)

	{

		cout << "Alice" << endl;

		return;

	}

	dp(A);

	//cout << diameter << endl;

	if (diameter <= 2 * DA)

		cout << "Alice" << endl;

	else

		cout << "Bob" << endl;

}



int main()

{

	IOS;

	cin >> T;

	while (T--)

	{

		cin >> N >> A >> B >> DA >> DB;

		int u, v;

		for (int i = 1; i <= N; i++)

			G[i].clear(), used[i] = false, D[i] = 0;

		for (int i = 1; i < N; i++)

			cin >> u >> v, add_edge(u, v);

		solve();

	}



	return 0;

}