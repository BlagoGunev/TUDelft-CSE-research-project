/*--------------------------------------------

			Competitive programing

		   Name: Đào Xuân Hoàng Tuấn (Salmon)

	Nothing is impossible, as you as you believe you can do it

			 You can do it!!!

	----------------------------------------------*/



#include <bits/stdc++.h>

using namespace std;

#define ll 	long long

#define Hello_i_am_Salmon 		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define print_fix 			cout << fixed << setprecision(20);

#define show3 				cerr << "***" << endl;

#define show2 				cerr << "**" << endl;

#define show1 				cerr << "*" << endl;

#define all(v) 				v.begin(), b.end()

#define sz(t) 				(int) t.size()

#define pb 				push_back

#define se 				second

#define fi 				first

#define ed 				'\n'

#define _ 				<< " " <<



const long long N = 1e5+5;

const double PI = atan(1)*4;

const int MOD = 1e9+7;

const int INF = 2e9+5;



	/* --- Code ---- */



ll depth[N];

ll diam[N];

ll vis[N];

ll vis2[N];

ll n;

ll diam_tree;

pair<ll, ll> ma;

vector<ll> g[N];



void dfs_find_kc(ll a)

{

	vis[a]++;

	for(auto x : g[a])

	{

		if(!vis[x])

		{

			depth[x] = depth[a] + 1;

			if(depth[x] >= ma.fi)

			{

				ma.fi = depth[x];

				ma.se = x;

			}

			dfs_find_kc(x);

		}

	}

}



void dfs_find_tree_diameter(ll a)

{

	vis2[a]++;

	for(auto x : g[a])

	{

		if(!vis2[x])

		{

			diam[x] = diam[a]+1;

			diam_tree = max(diam_tree, diam[x]);

			dfs_find_tree_diameter(x);

		}

	}

}



int main()

{

	Hello_i_am_Salmon

	int t; cin >> t;

	while(t--)

	{

		ma.fi = 0;

		ma.se = 0;

		diam_tree = 0;



		ll a, b, da, db; cin >> n >> a >> b >> da >> db;



		for(int i=0; i<=n+10; i++) g[i].clear();

		for(int i=0; i<=n+10; i++)

		{

			vis[i] = 0, vis2[i] = 0;

		}



		for(int i=0; i<n-1; i++)

		{

			ll x, y; cin >> x >> y;

			g[x].push_back(y);

			g[y].push_back(x);

		}



		depth[a] = 0;

		dfs_find_kc(a);



		diam[ma.se] = 0;

		dfs_find_tree_diameter(ma.se);



		ll ans = 0;

		if(depth[b] <= da || 2*da >= min(diam_tree, db)) ans = 1;

		cout << (ans ? "Alice\n" : "Bob\n");

	}

}



/* Test case 

1

4 3 2 1 2

1 2

1 3

1 4





*/