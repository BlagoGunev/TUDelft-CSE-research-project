/*#pragma comment(linker, "/stack:200000000")

#pragma GCC optimize("O3")

#pragma GCC target ("avx2")

#pragma GCC optimize("Ofast")

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#pragma GCC optimize("unroll-loops")*/



#include<bits/stdc++.h>

 

#define sz(v) (int)v.size()

#define ll long long

#define pb push_back

#define x first

#define y second

#define all(v) v.begin(), v.end()

#define rall(v) v.rbegin(), v.rend()

#define nl "\n"



using namespace std;

using pii = pair<int, int>;



const int N = (int)3e5 + 7; // make sure this is right

const int M = (int)15e6 + 7;

const int inf = (int)1e9 + 7;

const ll INF = (ll)3e18 + 7;

const ll MOD = (ll)998244353; // make sure this is right



pii dir[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};



int a, b, x, y;



void solve() {

	cin >> a >> b >> x >> y;

	cout << max(max(x, a - x - 1) * b, max(y, b - y - 1) * a) << nl;

}                                                                                       	



signed main() {	

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	

	int test = 1;

	cin >> test;

	for(int i = 1; i <= test; ++i) {

	 	//cout << "Case #" << i << ": ";

		solve();

	}

	return 0;

}