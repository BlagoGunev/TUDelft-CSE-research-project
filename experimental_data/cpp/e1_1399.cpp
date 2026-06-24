/*
    JAI JAGANNATH!
*/
//@Author : zanj0
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long int lli;
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define pii             pair<lli,lli>
#define vi              vector<lli>
#define mii             map<lli,lli>
#define pqb             priority_queue<lli>
#define pqs             priority_queue<lli,vi,greater<lli> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            lli x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<lli, null_type, less<lli>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

void zanj0()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

struct Data {
	lli cost, x;
	Data(lli a, lli b) {
		cost = a;
		x = b;
	}
};
struct Cmp {
	bool operator()(Data& a, Data& b) {
		lli diffA = (a.cost * a.x) - ((a.cost / 2) * a.x);
		lli diffB = (b.cost * b.x) - ((b.cost / 2) * b.x);;
		return diffA != diffB ? !(diffA > diffB) : !(a.x > b.x);
	}
};
const lli N = 1e5 + 5;
lli sum;
lli n, s;
lli ret;
vector < pair <lli, lli> > graph[N];
lli dp[N];
priority_queue <Data, vector <Data>, Cmp> pq;
void dfs0(lli node, lli par) {
	if (graph[node].size() == 1 ) {
		//leaf
		dp[node] = 1;

	}
	for (auto &it : graph[node]) {
		if (it.first != par) {
			dfs0(it.first, node);
			dp[node] += dp[it.first];
		}
	}
}
void dfs1(lli node, lli par) {
	for (auto & it : graph[node]) {
		if (it.first == par) continue;
		while (it.second * dp[it.first] > s ) {
			it.second >>= 1;
			ret++;
		}
		sum += it.second * dp[it.first];
		if (it.second * dp[it.first] > 0 ) pq.push(Data(it.second, dp[it.first]));
		dfs1(it.first, node);
	}
}
void pre() {
	ret = 0;
	for (lli i = 1; i <= n; i++) {
		graph[i].clear();
		dp[i] = 0;
	}
	while (!pq.empty()) pq.pop();
	sum = 0;
}
void out(priority_queue <Data, vector <Data>, Cmp> pq) {
	while (!pq.empty()) {
		auto x = pq.top();
		cout << x.cost << " -- " << x.x << endl;
		pq.pop();
	}
	cout << endl;
}
void solve() {
	pre();

	cin >> n >> s;
	lli u, v, c;
	for (lli i = 0; i < n - 1; i++) {
		cin >> u >> v >> c;
		graph[u].pb({v, c});
		graph[v].pb({u, c});
	}
	dfs0(1, 0);
	// for (lli i = 1; i <= n; i++) {
	// 	cout << dp[i] << " ";
	// }
	dfs1(1, 0);
	// cout << sum << endl;
	// cout << ret << endl;
	// out(pq);
	while (sum > s) {
		ret++;
		Data node = pq.top();
		//cout << node.cost << " " << node.x << " " << sum << endl;
		pq.pop();
		lli val = node.cost * node.x;
		node.cost >>= 1;
		lli newVal = node.cost * node.x;
		// cout << newVal << " -> " << val << endl;

		lli diff = val - newVal;
		sum -= diff;

		// cout << node.cost << " " << node.x << " " << sum << endl;
		if (newVal) {
			pq.push(node);
		}
	}
	cout << ret << endl;
}
int main()
{
	zanj0();
	w(t) solve();
	return 0;
}