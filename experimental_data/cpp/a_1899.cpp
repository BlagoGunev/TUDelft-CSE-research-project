#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
//#pragma startup st_point /* start some function before main*/
//#pragma exit /* start some function after main */
//#pragma warn -rvl /* No return value, + do opposite*/
//#pragma warn -par /* Parameter not used, + do opposite */
//#pragma warn - rch /* Unreachable code, + do opposite */
/*
__attribute__((constructor)) acts like #pragma startup
__attribute__((destructor)) acts like #pragma exit
*/
#define pb push_back
#define mp make_pair	
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
#define F first
#define S second
#define left(v) (v) + (v)
#define right(v) (v) + (v) + 1
#define ll long long
#define int long long
using namespace std;
using namespace __gnu_pbds;
///using ll = long long;
//using ull = unsigned long long;
const int MAXN = 2e5 + 5;
const int inf = 1e9;
const long long INF = 1e15;
const int M = 998244353;
const int P = 191;
const int P2 = 191;
const double EPS = 1e-6;
void D_BASE(string name = "") {
	   if (sz(name)) {
	       freopen((name + ".in").c_str(), "r", stdin);
		   freopen((name + ".out").c_str(), "w", stdout);
	   }
	   ios_base::sync_with_stdio(0);
 	   cin.tie(0);
	   cout.tie(0);
}
int n;
void solve() {
	cin >> n;
	if((n - 1) % 3 == 0 || (n + 1) % 3 == 0) cout << "First\n";
	else cout << "Second\n";
}
signed main() {
    D_BASE("");
	int tt = 1, ct = 0;
    cin >> tt;
    while (tt--) {
        //cout << "Case " << ++ct << ": ";
		solve();
    }
	return 0;
}