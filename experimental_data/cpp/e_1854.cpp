#ifdef MY_LOCAL
#include "C://competitive_programming/debug/debug.h"
#define debug(x) cerr << "[" << #x<< "]:"<<x<<"\n"
#else
#define debug(x) 
#endif
#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define sz(X) ((int)X.size())
#define READ(arr) for(auto &a: arr){cin>>a;}
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
const int MOD = 998244353;
const int MAXN = 1000007;  
int MAX = 35;
vvi dp(MAX, vi(MAX));

void solve(int m) {
	int bst = INF;
	REP(onect, MAX) {
		REP(twoct, MAX) {
			if (onect + twoct *2 >= 60) continue; 
			if (onect + twoct > MAX) continue;
			vi ways(30, 0);

			int needed = onect + twoct;
			vi ans;
			REP(_, onect) {
				ans.push_back(1);
			}
			REP(_, twoct) {
				ans.push_back(2);
			}
			REP(no1, onect+1) {
				REP(no2, twoct+1) {
					int tot = no1 + no2*2;
					if (tot >= 30) continue;
					ways[tot] += dp[onect][no1]*dp[twoct][no2];
				}
			}
			//debug("here!");
			vii inorder;
			REP(i, 30) {
				if (ways[i] == 0LL) continue;
				inorder.push_back({ways[i],i});
			}
			SORT(inorder);
			reverse(inorder.begin(), inorder.end());
			int curm = m;
			for (auto [wy, val]: inorder) {
				//debug(curm);
				needed += curm/wy;
				//debug(wy);
				curm %= wy;
			}
			curm = m;
			if (needed <= 60) {
				for (auto [wy, val]: inorder) {
				//debug(curm);
					int v = curm/wy;
					REP(_, v) {
						ans.push_back(60 - val);
					}
				//debug(wy);
					curm %= wy;
				}
				cout<<sz(ans)<<"\n";
				for (auto x: ans) {
					cout<<x<<" ";
				}cout<<"\n";return;
			}
			bst = min(bst, needed);

			//debug(needed);
		}
	}
	//assert(false);
	debug(bst);debug(m);
	if (bst > 60) {
		assert(false);
	}
	// cout<<sz(ans)<<"\n";
				// for (auto x: ans) {
				// 	cout<<x<<" ";
				// }cout<<"\n";retur
	//assert(false);
}


signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	dp[0][0] = 1;
	REP(i, MAX) {
		dp[i][0] = 1;
	}
	REPL(n, 1, MAX) {
		REPL(r,1, n+1) {
			dp[n][r] = dp[n-1][r-1] + dp[n-1][r];
		}
	} 
	// REP(i, 1000) {
	// 	int x = rand()%100000LL + (rand()%100000LL)*100000LL;
	// 	//debug(x);
	// 	solve(x);
	// }
	int m;cin>>m;
	solve(m);
}