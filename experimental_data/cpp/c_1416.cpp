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

#define int long long

#define nl "\n"



using namespace std;

using pii = pair<int, int>;



const int N = (int)3e5 + 7;

const int inf = (int)1e9 + 7;

const ll INF = (ll)1e18 + 7;

const ll MOD = (ll)1e9 + 7; // MAYBE WA



int n, a[N], cnt[20 * N], col[31];

int t[20 * N][2], sz;



void add(int x) {

	int v = 0;

	for(int i = 30; i >= 0; --i) {

		bool bit = (x >> i & 1);

		if(!t[v][bit]) t[v][bit] = ++sz;

		v = t[v][bit];

		cnt[v]++;

	}

}



int get(int x) {

	int v = 0, res = 0;

	for(int i = 30; i >= 0; --i) {

		bool bit = (x >> i & 1);

		if(bit) {

			res += cnt[t[v][0]];

			col[i] += cnt[t[v][0]];		

		} else {

			col[i] -= cnt[t[v][1]];

		}

		v = t[v][bit];

	}		

	return res;

}



void solve() {                        

	cin >> n;

	for(int i = 1; i <= n; ++i) cin >> a[i];

	int res = 0;

	for(int i = n; i >= 1; --i) {

		add(a[i]);

		res += get(a[i]);

	}

	int x = 0;

	for(int i = 0; i <= 30; ++i) {

		if(col[i] > 0) {

			res -= col[i];

			x |= (1 << i);

		}

	}               

	cout << res << ' ' << x << nl;

}   



signed main() {	

	ios_base::sync_with_stdio(NULL);

	cin.tie(0);

	cout.tie(0);

	int test = 1;

	//cin >> test;

	while(test--) {

		solve();

	}

	return 0;

}