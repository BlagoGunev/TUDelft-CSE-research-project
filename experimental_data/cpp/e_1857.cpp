//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cassert>
#include <queue>
#include <stack>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <fstream>
#include <bitset>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define int ll
#define ordered_set tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update>
#define vc vector
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define pip pair <int, int>
#define pill pair <ll,ll>
#define fi first
#define si second
#define pq priority_queue
#define all(s) s.begin(), s.end()
const int op = 1e9 + 7;
const ll inf = 1e18;
void solve() {
    int a, b, c = 111, n = 5e5, k = 0, m = 256, v, x;
    cin >> n;
    vc <int> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    vc <pip> q(n);
    for (int i = 0; i < n; i++) q[i] = mp(s[i], i);
    sort(all(q));
    a = 0, b = 0;
    for (int i = 0; i < n; i++) b += s[i];
    vc <int> dp(n);
    for (int i = 0; i < n; i++){
        x = q[i].first;
        dp[q[i].second] = b - (n-i)*x + i*x - a + n;
        a += x;
        b -= x;
    }
    for (int i = 0; i < n; i++) cout << dp[i] << ' ';
    cout << "\n";
}
signed main(){
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}