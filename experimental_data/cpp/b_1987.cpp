#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int long long
void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }
using ll = long long;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 2e5 + 5;
const int MOD = 1e9+7; //998244353;
const int INF = 0x3f3f3f3f;
const ll INF64 = ll(4e18) + 5;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int mn = 0;
	int mx = 0;
	int base = 0;
	for(int i = 0; i < n; i++){
		mn = max(mn,a[i]);
		int op = mn-a[i];
		base += op;
		mx = max(mx,op);
	}
	int ans = base + mx;
	cout << ans << '\n';
}

signed main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}

/*
Makefile:
CXXFLAGS=-Wall -Wextra -Wshadow -g -pedantic -fsanitize=address,undefined -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUGPEDANTIC -std=gnu++17
*/