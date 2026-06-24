// Problem: F. Tree Queries

// Contest: Codeforces - Educational Codeforces Round 116 (Rated for Div. 2)

// URL: https://codeforces.com/contest/1606/problem/F

// Memory Limit: 512 MB

// Time Limit: 6000 ms

// 

// Powered by CP Editor (https://cpeditor.org)



#pragma GCC optimize(2)

#pragma GCC optimize(3)

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/hash_policy.hpp>

#define all(x) (x).begin(), (x).end()

#define gb std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

#define pi acos(-1.0)

#define fi first

#define se second

#define rep(i,a,b) for(int i=a;i<=b;++i)

#define fep(i,a,b) for(int i=b;i>=a;--i)

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)

#define DEC(i, a, b) for (int i = (a); i >= (b); --i)

//#define int long long 

#define random(x) (rand()%x)

#define endl '\n' 

#define cf int _; cin>> _; while(_--)

#define sz(x) int(x.size())

 

using namespace std;

using namespace __gnu_pbds;

typedef long long ll;

typedef pair<int, int> PII;

const double eps = 1e-9;

typedef pair<int, PII> PIII;

typedef unsigned long long ULL;

typedef deque<int>::iterator iterator_t;

typedef pair<double, double> PDD;

typedef const int& cint;

const int N = 2e5+10,INF=0x3f3f3f3f;

const int mod=1e9+7;

typedef vector<int> VI;

//const int INF = (1ULL<<63)-1;

const double PI=acos(-1);

vector<int> dp[N],ans[N];//ans维护大于号的dp

vector<int> g[N];

int son[N];



void dfs(int u,int fa){

	son[u] = sz(g[u]) - (u != 1);

	int sz = son[u];

	for(auto it:g[u]){

		if(it==fa)continue;

		dfs(it,u);

		sz = max(sz, sz(dp[it]));

	}

	dp[u].resize(sz);

	VI add(sz + 1);

	for(int v : g[u]){

        if(v == fa) continue;

        for(int i = 0; i < sz(dp[v]); i++)

            dp[u][i] += dp[v][i] - i;

        add[sz(dp[v])]++;

    }

	for(int i=0;i<sz;i++){

		if(i) add[i] += add[i - 1];

        dp[u][i] += add[i];

	}

	ans[u] = dp[u];

    while(sz(dp[u]) && dp[u].back() <= sz(dp[u]))

        dp[u].pop_back(); 

}



signed main(){

    gb;

    int n;

    cin>>n;

    rep(i,1,n-1){

    	int a,b;

    	cin>>a>>b;

    	g[a].push_back(b);

    	g[b].push_back(a);

    }

    dfs(1,0);

    int q;

    cin>>q;

    while(q--){

    	int u,k;

    	cin>>u>>k;

    	if(k >= sz(ans[u]))

            cout << son[u] << endl;

        else

            cout << ans[u][k] << endl;

    }

    return 0;

}