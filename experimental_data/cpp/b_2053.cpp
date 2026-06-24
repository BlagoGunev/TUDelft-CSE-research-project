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
	
	vector <int> l(n), r(n), cnt(n * 2 + 1), f(n * 2 + 1);
	set <int> st;
	
	for ( int i = 0; i < n; i++ ){
		cin >> l[i] >> r[i];
		
		if ( l[i] == r[i] ){
			f[l[i]] += 1;
			st.insert(l[i]);
		}
	}
	
	for ( auto &x: st ) cnt[x]++;
	
	for ( int i = 1; i <= n * 2; i++ ) cnt[i] += cnt[i - 1];
	
	for ( int i = 0; i < n; i++ ){
		if ( l[i] == r[i] ){
			cout << (f[l[i]] == 1);
			continue;
		}
		
		if ( cnt[r[i]] - cnt[l[i] - 1] == r[i] - l[i] + 1 ){
			cout << "0";
		} else cout << "1";
	} cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    
    while ( t-- ) solve();
    	
    cout << '\n';
}