#include <bits/stdc++.h>

using namespace std;

// additional data structs

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();

struct chash {
	int operator()(int x) const { return x ^ RANDOM; }
};

typedef __gnu_pbds::gp_hash_table<int, int, chash> hash_map;

// shortening

using ll = long long;
using ull = unsigned long long;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// reused objects

struct comp {
	bool operator()(const pair<ll, ll> &x, const pair<ll, ll> &y) const {
		if (x.second != y.second) return x.second < y.second;
		return x.first < y.first;
	}
};

// consts

const ll MOD = 1e9+7;
const ll INF = (ll)1e18;
const int LOG = 17;

void solve() {
	ll n, x; cin >> n >> x;
	unordered_set<ll> k;
	ll first = n-x;
	for (ll i = 1; i <= (ll)sqrt(first); ++i) {
		if (first%i == 0) {
			if (i%2 == 0 && (i+2)/2 >= x) {
				k.insert((i+2)/2);
			}
			if ((first/i)%2 == 0 && (first/i+2)/2 >= x) {
				k.insert((first/i+2)/2);
			}
		}
	}
	ll second = n+x-2;
	for (ll i = 1; i <= (ll)sqrt(second); ++i) {
		if (second%i == 0) {
			if (i%2 == 0 && (i+2)/2 >= x) {
				k.insert((i+2)/2);
			}
			if ((second/i)%2 == 0 && (second/i+2)/2 >= x) {
				k.insert((second/i+2)/2);
			}
		}
	}
	cout << k.size() << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	// cout << std::fixed;
	// cout << std::setprecision(10);

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}