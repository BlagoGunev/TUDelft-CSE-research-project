#include <bits/stdc++.h>

/*
	Oce nas,
	koji si na nebesima,
	da se sveti ime Tvoje,
	da dodje carstvo Tvoje,
	da bude volja Tvoja,
	i na zemlji, kao i na nebu.

	Hleb nas nasusni daj nam danas,
	i oprosti nam dugove nase,
	kao sto i mi oprastamo duznicima svojim,
	i ne uvedi nas u iskusenje,
	no izbavi nas od zloga.

	Jer je Tvoje Carstvo,
	i sila, i slava,
	u vekove vekova.

	Amin.
*/

using namespace std;
typedef vector<int> vc;
typedef vector<vector<int>> vvc;
using ll = long long;
using ld = long double;
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define F first
#define S second
#define pb push_back
#define pf push_front
#define all(x) (x).begin(), (x).end()
#define int long long



void solve(){
    int n;
    cin >> n;
    int ans=1;
    while(ans<=n){
        ans*=2;
    }
    cout << ans/2 << '\n';
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)solve();
}