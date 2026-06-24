#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

#define ii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define vpll vector<pll>
#define msi multiset<int>
#define si set<int>
#define PB push_back
#define PF push_front
#define PPB pop_back
#define PPF pop_front
#define X first
#define Y second
#define MP make_pair
#define FOR(i, a, b) for (int i = int(a); i < int(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()

const int mod = 1e9 + 7;
const int MOD = 998244353;
const int inf = 1e8 + 7;
const ll INF = 1e18 + 7;
const int logo = 30;
const int MAXN = 1e6 + 2;
const int off = 1 << logo;
const int trsz = off << 1;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};

vll ac;

void solve(){
	int n, k;
	cin >> n >> k;
	ac.clear();
	for(int i=1; i<=n; i++){
		ll x;
		cin >> x;
		ac.PB(x);
	}
	sort(all(ac));
	ac.erase(unique(all(ac)), ac.end());
	if(k >= 3 or (int)ac.size() != n){
		cout << 0 << "\n";
		return;
	}
	
	ll ans = ac[0];
	if(k == 1){
		for(int i=1; i<n; i++){
			ll dl = ac[i] - ac[i - 1];
			ans = min(ans, dl);	
		}
	}else{
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				ll dl = ac[j] - ac[i];
				ans = min(ans, dl);
				
				int it = lower_bound(all(ac), dl) - ac.begin();
				if(it < n) ans = min(ans, ac[it] - dl);
				it--;
				if(it >= 0) ans = min(ans, dl - ac[it]);
			}
		}
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	cin >> t;
	while(t--) solve();
	return 0;
}