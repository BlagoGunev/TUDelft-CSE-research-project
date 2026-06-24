#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define ar array
#define pb push_back
#define ln '\n'
#define size(x) (int)(x).size()
#define int long long

typedef pair <int,int> pii;

using i64 = long long;

template <class F, class _S>
bool chmin(F &u, const _S &v){
	bool flag = false;
	if ( u > v ){
		u = v; flag |= true;
	}
	return flag;
}

template <class F, class _S>
bool chmax(F &u, const _S &v){
	bool flag = false;
	if ( u < v ){
		u = v; flag |= true;
	}
	return flag;
}

void solve(){
	int n; cin >> n;
	
	map <int,int> mp;
	
	int x = -1;
	
	for ( int i = 1; i <= n; i++ ){
		int y; cin >> y;
		
		if ( ++mp[y] > 1 ) chmax(x, y);
	}
	
	if ( x == -1 ) return cout << "-1\n", void();
	
	mp[x] -= 2;
	
	vector <int> p;
	
	for ( auto &[it, v]: mp ){
		for ( int j = 1; j <= v; j++ ) p.pb(it);
	}
	
	for ( int i = 0; i + 1 < size(p); i++ ){
		if ( p[i] + x * 2 > p[i + 1] ){
			return cout << p[i] << ' ' << p[i + 1] << ' ' << x << ' ' << x << '\n', void();
		}
	}
	
	cout << "-1\n";
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int t; cin >> t;
    
    while ( t-- ) solve();
	
	cout << '\n';
}