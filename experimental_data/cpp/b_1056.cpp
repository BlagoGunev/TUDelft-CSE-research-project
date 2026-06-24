//IN THE NAME OF GOD

#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")

#include<bits/stdc++.h>
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>*/

#define sz(s) (int)(s.size())
#define all(s) s.begin(), s.end()
#define rep(a, b, c) for(int a = b; a <= c; ++a)
#define per(a, b, c) for(int a = b; a >= c; --a)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long

using namespace std;
//using namespace __gnu_pbds;

typedef unsigned long long ull;
typedef long long ll;
/*typedef tree<pair<int, int>, 
null_type, less<pair<int, int>>, 
rb_tree_tag, tree_order_statistics_node_update>
ordered_set;*/
//find_by_order() order_of_key()

const double eps = 1e-7;
const int mod = 1e9+7, MXN = 2e3+17;
const int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

template<typename T>inline bool updmin(T &a, const T &b) {return a > b ? a = b,1 : 0;}
template<typename T>inline bool updmax(T &a, const T &b) {return a < b ? a = b,1 : 0;}


int32_t main() { _
#ifdef DanQQQQQ
	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
#endif
	int n, m; cin >> n >> m;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	rep(i,1,m) rep(j,1,m) cnt1 += (!((i*i+j*j)%m));
	rep(i,1,m) rep(j,1,n%m) cnt2 += (!((i*i+j*j)%m));
	rep(i,1,n%m) rep(j,1,n%m) cnt3 += (!((i*i+j*j)%m));
	cout << (n/m)*(n/m)*cnt1+2ll*(n/m)*cnt2+cnt3 << endl;
	return 0;
}