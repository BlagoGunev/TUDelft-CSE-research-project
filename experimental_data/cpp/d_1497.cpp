#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define endl '\n'
#define MASK(i) (1LL << (i))
#define ull unsigned long long
#define ld long double
#define pb push_back
#define all(x) (x).begin() , (x).end()
#define BIT(x , i) ((x >> (i)) & 1)
#define TASK "task"
#define sz(s) (int) (s).size()
 
using namespace std;
const int mxN = 5027;
const int inf = 1e9 + 277;
const int mod = 1e9 + 7;
const ll infll = 1e18 + 7;
const int base = 307;
const int LOG = 20;
 
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) {
	if (a > b) {a = b; return true;} return false;
}
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) {
	if (a < b) {a = b; return true;} return false;
}
 
int n;
int tag[mxN];
int s[mxN];
ll dp[mxN];
ll maxval[mxN];

void solve()
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> tag[i];
	for(int i = 1; i <= n; i++) cin >> s[i];


	for(int i = 1; i <= n; i++) {
		maxval[i] = dp[i] = 0;
	}

	ll res = 0;
	for(int rig = 2; rig <= n; rig++) {
		for(int lef = rig; lef >= 1; lef--) {
			if(tag[rig] == tag[lef]) continue;
			maximize(dp[lef], maxval[rig] + abs(s[lef] - s[rig]));
			maximize(dp[rig], maxval[lef] + abs(s[lef] - s[rig]));
			maximize(maxval[rig], dp[rig]);
			maximize(maxval[lef], dp[lef]);
		}
	}

	for(int i = 1; i <= n; i++) maximize(res, dp[i]);
	cout << res << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

 
    int tc = 1;
    cin >> tc;
    while(tc--) {
    	solve();
    }
    return 0;
}