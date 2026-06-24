#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef double dbl;

typedef pair<int, int> ii;

typedef vector<int> vi;

typedef vector<ii> vii;

// Input macros

#define si(n)                       scanf("%d",&n)

#define sii(a,b)                    scanf("%d%d",&a,&b)

#define sc(n)                       scanf(" %c",&n)

#define sl(n)                       scanf("%lld",&n)

#define sll(a,b)                    scanf("%lld%lld",&a,&b)

#define sf(n)                       scanf("%lf",&n)

#define ss(n)                       scanf("%s",n)

// Useful constants

#define INF                         (int)1e9

#define EPS                         1e-9

// Useful hardware instructions

#define bitcount                    __builtin_popcount

#define gcd                         __gcd

const ll MOD = 1e9 + 7;

#define all(a)                      a.begin(), a.end()

#define lp(i,n) 					for(int i=0;i<(int)n;i++)

#define lp1(i,n)					for(int i=1;i<=(int)n;i++)



//#ifdef ONLINE_JUDGE

//	freopen("input.txt", "r", stdin);

//	freopen("output.txt", "w", stdout);

//#endif



///////////////////////////////////////////////////////////

const int N = 2004;

int n, d;

int vis[N];

int a[N];

vi adj[N];

int root;

ll dfs(int u) {

//	cout << u << endl;

	vis[u] = 1;

	ll ret = 1;

	lp(i,adj[u].size())

	{

		int v = adj[u][i];

		if (vis[v])

			continue;

		if (a[v] < a[root] || a[v] > a[root] + d)

			continue;

		if (a[v] == a[root] && v < root)

			continue;

		ret *= (dfs(v) + 1);

		ret %= MOD;

	}

//	cout<<u<<" "<<ret<<endl;

	return ret;

}

int main() {

	sii(d, n);

	lp1(i,n)

	{

		si(a[i]);

	}

	lp(i,n-1)

	{

		int x, y;

		sii(x, y);

		adj[x].push_back(y);

		adj[y].push_back(x);

	}

	ll sum = 0;

	lp1(i,n)

	{

		memset(vis,0,sizeof vis);

		root = i;

		sum += dfs(i);

		sum %= MOD;

	}

	cout << sum << endl;

}