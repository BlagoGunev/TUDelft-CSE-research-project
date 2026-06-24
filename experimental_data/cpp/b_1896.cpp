#include<bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define clr(x) vector<int>().swap(x);
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define lb lower_bound
#define ub upper_bound
#define endl '\n'
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vvi vector<vector<int>>
#define vii vector<pii>
#define random mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()); mt19937 rnd(time(0));
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define le v * 2
#define re v * 2 + 1
#define tm (tl + tr)/2
#define no {cout << "No" << endl; return;}
#define yes {cout << "Yes" << endl; return;}
const ll INF=9e18;
const ll MN=-2e9;
const ll MX=2e5+9;
const ll MXX=2e9;
const ll SQ=5e2;
const ll MOD=1e9+7;
//const ll MOD=998244353;
const ll PP=1e6+3;
const ll P2=1299827;
const ld PI=3.141592653589793;
const ld eps=1e-11;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
    ordered_set;

int n, a, b;
string s;

void solve() {
    cin >> n;
    cin >> s;
    a = 0;
    b = n - 1;
    while (a < n && s[a] != 'A') a++;
    while (b > -1 && s[b] != 'B') b--;
    cout << max(b - a, 0) << endl;
}

int main() {
    FAST;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}

/*



*/