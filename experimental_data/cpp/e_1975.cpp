#ifdef MY_LOCAL
#include "D://competitive_programming/debug/debug.h"
#define debug(x) cerr << "[" << #x<< "]:"<<x<<"\n"
#else
#define debug(x) 
#endif
#define REP(i, n) for(int i = 0; i < (n); i ++)
#define REPL(i,m, n) for(int i = (m); i < (n); i ++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define sz(X) ((int)X.size())
#define READ(arr) for(auto &a: arr){cin>>a;}
#define SUM(arr) accumulate((arr).begin(), (arr).end(), 0LL)
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef tree<int,null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;
const ll INF = 1e18;
void roottree(int u, int pr, vi &deptharr, vi &parr, vvi &adj, int depth) {
	parr[u] = pr;
	deptharr[u] = depth;
	for (auto v: adj[u]) {
		if (v == pr) continue;
		roottree(v, u, deptharr, parr, adj, depth+1);
	}
}
void solve() {
	int n,q;cin>>n>>q;
	vi carr(n);READ(carr);
	vvi adj(n);
	REP(i, n-1) {
		int x,y;cin>>x>>y;x--;y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vi colarr(n);
	vi parr(n);
	vi darr(n);
	roottree(0, -1, darr, parr, adj, 0);
	int heads = 0;
	set<ii> coloured;
	vi colouredchildren(n, 0);
	int above1 = 0;
	auto colour = [&](int who) {
		heads++;
		heads -= colouredchildren[who];
		colarr[who] = 1;
		coloured.insert({darr[who], who});
		if (parr[who] != -1) {
			colouredchildren[parr[who]]++;
			if (colouredchildren[parr[who]] == 2) {
				above1++;
			}
			if (colarr[parr[who]] == 1) {
				heads--;
			}
		}
	};
	auto decolour = [&](int who) {
		heads--;
		heads += colouredchildren[who];
		colarr[who] = 0;
		coloured.erase({darr[who], who});
		if (parr[who] != -1) {
			colouredchildren[parr[who]]--;
			if (colouredchildren[parr[who]] == 1) {
				above1--;
			}
			if (colarr[parr[who]] == 1) {
				heads++;
			}
		}
	};
	REP(i, n) {
		if (carr[i] == 1) {
			colour(i);
		}
	}
	REP(i, q) {
		int x;cin>>x;x--;
		if (colarr[x] == 0) {
			colour(x);
		} else {
			decolour(x);
		}
		if (sz(coloured) == 0) {
			cout<<"No\n";continue;
		}
		if (heads > 1) {
			cout<<"No\n";continue;
		}
		auto [dd, suphead] = *coloured.begin();
		if (above1 > 1) {
			cout<<"No\n";continue;
		}
		if (above1 == 1) {
			if (colouredchildren[suphead] == 2) {
				cout<<"Yes\n"; continue;
			} else {
				cout<<"No\n";continue;
			}
		} else {
			cout<<"Yes\n";continue;
		}

	}

}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}