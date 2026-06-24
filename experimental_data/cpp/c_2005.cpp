// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
 
// #define _GLIBCXX_DEBUG
// #define _GLIBCXX_DEBUG_PEDANTIC
 
#include <iomanip>
#include <cassert>
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <map>
#include <set>
#include <functional>
#include <array>
#include <numeric>
#include <queue>
#include <deque>
#include <bitset>
#include <cmath>
#include <climits>
#include <cstdint>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
 
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;
using namespace std;
 
 
const int MOD = 998244353;
const long double PI = 3.141592653589793;
using ll = long long;
const ll INF = 1e18;
 
#define int ll

// --------> sashko123`s defines:

#define itn int     //Vasya sorry :(
#define p_b push_back
#define fi first
#define se second
#define pii std::pair<int, int>
#define oo LLONG_MAX
#define big INT_MAX
#define elif else if

int input()
{
    int x;
    cin>>x;
    return x;
}

// ----------> end of sashko123`s defines (thank you Vasya <3)

// template<typename K, typename V>
// using hash_table = cc_hash_table<K, V, hash<K>>;

// template<typename T>
// using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
template<typename T>
using graph = vector<vector<T>>;
 
template<typename T>
istream& operator>>(istream& in, vector<T>& a) {
    for (auto& i: a) {
        in >> i;
    }
    return in;
}
 
template<typename T>
ostream& operator<<(ostream& out, vector<T>& a) {
    for (auto& i: a) {
        out << i << " ";
    }
    return out;
}
 
ll fast_pow(ll a, ll b, ll mod) {
    if (b == 0)
        return 1;
    if (b % 2) {
        return (1ll * a * fast_pow(a, b - 1, mod)) % mod;
    }
    ll k = fast_pow(a, b / 2, mod);
    return (1ll * k * k) % mod;
}
 
ll fast_pow(ll a, ll b) {
    if (b == 0)
        return 1;
    if (b % 2) {
        return (1ll * a * fast_pow(a, b - 1));
    }
    ll k = fast_pow(a, b / 2);
    return (1ll * k * k);
}


void solve() {
    int n, m;
	cin >> n >> m;

	vector<vector<int>> dp(n + 1, vector<int>(5, -INF));
	dp[0][0] = 0;
	dp[0][1] = dp[0][2] = dp[0][3] = dp[0][4] = -INF;
	vector<int> mx(5);
	for (int j = 0; j < 5; j++) {
		mx[j] = dp[0][j];
	}

	string t = "narek";
	set<char> tt(t.begin(), t.end());
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		int C = 0, S = 0;
		
		for (int j = 0; j < m; j++) {
			if (tt.count(s[j]))
				S++;
		}

		for (int ss = 0; ss < 5; ss++) {
			int T = ss;
			C = 0;
			for (int j = 0; j < m; j++) {
				if (s[j] == t[T]) {
					T++;
					if (T == 5) {
						C++;
						T = 0;
					}
				}
			}

			dp[i][T] = max(dp[i][T], 2 * C * 5 - S + mx[ss]);
		}

		for (int j = 0; j < 5; j++) {
			mx[j] = max(dp[i][j], mx[j]);
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << '\n';
}	
 
int32_t main(int32_t argc, const char * argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    // insert code here...
    int tt= 1;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}