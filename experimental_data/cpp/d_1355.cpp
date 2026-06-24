#include <bits/stdc++.h>

 

#define ios ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define file(s) if (fopen(s".in", "r")) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

#define all(a) a.begin() , a.end()

#define F first

#define S second

 

using namespace std;

using ll = long long;

 

const int N = 2e5+5 , inf = 2e9 + 7;

const ll INF = 1e18 ,   mod = 1e9+7 , P = 6547;	



void solve(){

	ll n, s;

	cin >> n >> s;

	if(s-n >= n) {

		cout << "YES\n";

		for(int i = 1; i < n; i++) cout << 1 <<" ";

		cout << s-n+1 <<"\n";

		cout << s-n <<" ";

	} else{

		cout << "NO\n";

	}

}

/*



*/

signed main(){

	ios;

	solve();

	return 0;

}