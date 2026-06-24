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


const int MAXN = 6000;
const int MOD = 998244353;
vi fact2(MAXN, 1);
                                     
int modpow(int b, int p) {
	if (p == 0) return 1;
	if (p%2== 1) {
		return (b*modpow(b,p-1))%MOD;
	}
	int v = modpow(b, p/2);
	return (v*v)%MOD;
}

void intialize_fact2() {
	for (int i = 1; i < MAXN; i++) {
		fact2[i] = fact2[i-1]*i%MOD;
	}
}

vi powk(5000,1);
int solve(int n, int k) {
	REPL(i, 1, n) {
		powk[i] = powk[i-1]*k%MOD; 
	}

	vvi dp(n+1, vi(k));
	REPL(i,1, k) {
		dp[1][i] = 1;
	}
	REPL(i, 2, n+1) {
		REPL(prevval, 1, k) {
			// say you want to extend...
			if (prevval + 1 != k) {
				int leftovers = k - prevval;
				dp[i][prevval + 1] += (dp[i-1][prevval]*leftovers)%MOD;
				dp[i][prevval + 1] %= MOD;
			}
		}
		// maybe reduce..
		int cursm = 0;
		for (int nxt = k-1; nxt >= 1; nxt--) {
			cursm += dp[i-1][nxt];
			cursm %= MOD;
			dp[i][nxt] += cursm;
			dp[i][nxt] %= MOD;
		}
	}
	vi cumsum(n+1);
	REP(i, n+1) {
		REP(j, k) {
			cumsum[i] += dp[i][j];
			cumsum[i] %= MOD;
		}
	}
	vi anslen(n+1);
	REPL(len, k, n+1) {
		REP(idx, len) {
			int renlem = len - idx - k;
			if (renlem < 0 ) continue;
			int f1 = (idx == 0 ? 1 : cumsum[idx]);
			int f2 = fact2[k];
			int f3 = powk[renlem];
			//debug(f2);
			int afterwards = anslen[renlem];

			anslen[len] += (f1*f3%MOD + afterwards*f1%MOD)%MOD*f2%MOD;
			anslen[len] %= MOD;
		}
	}
	return anslen[n];
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	intialize_fact2();
	int n,k;cin>>n>>k;
	cout<<solve(n, k);
}