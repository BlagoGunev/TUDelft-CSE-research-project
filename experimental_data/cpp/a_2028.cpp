#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define ar array
#define pb push_back
#define ln '\n'
#define int long long

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
	int n, a, b; cin >> n >> a >> b;
	
	string s; cin >> s;
	
	string t;
	
	for ( int i = 1; i <= 1000; i++ ) t += s;
	
	int x = 0, y = 0;
	
	for ( auto &j: t ){
		if ( j == 'N' ) y++;
		else if ( j == 'E' ) x++;
		else if ( j == 'S' ) y--;
		else x--;
		
		if ( x == a && y == b ){
			return cout << "Yes\n", void();
		}
	}
	
	cout << "No\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	
	int t; cin >> t;
	
	while ( t-- ) solve();
 
    cout << '\n';
}