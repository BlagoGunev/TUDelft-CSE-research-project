#include<bits/stdc++.h>

using namespace std;

 

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);



typedef long long  ll;

typedef long double ld;

typedef vector<int> vi;

typedef vector<long long> vl;

typedef pair<int,int> pi;

typedef pair<long long, long long> pl;



#define pb push_back

#define mp make_pair

#define ump unordered_map

#define sz(x) x.size()

#define all(x) x.begin(),x.end()

const ll m = 1e9 + 7;

#define PI 3.141592653589



void __print(int x) {cerr << x;}

void __print(long x) {cerr << x;}

void __print(ll x) {cerr << x;}

void __print(unsigned x) {cerr << x;}

void __print(unsigned long x) {cerr << x;}

void __print(unsigned long long x) {cerr << x;}

void __print(ld x) {cerr << x;}

void __print(char x) {cerr << '\'' << x << '\'';}

void __print(const char *x) {cerr << '\"' << x << '\"';}

void __print(const string &x) {cerr << '\"' << x << '\"';}



template<typename T, typename V>

void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}

template<typename T>

void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}

void _print() {cerr << "]\n";}

template <typename T, typename... V>

void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}



#ifndef ONLINE_JUDGE

#define debug(x...) cerr << "[" << #x << "] = ["; _print(x);

#else

#define debug(x...)

#endif





void solve() {

	int n;

	cin >> n;

	vector<vector<int>> a(n, vector<int>(n, - 1));

	for(int i = 0; i < n; i++) {

		cin >> a[i][i];

	}

	for(int i = 1; i < n; i++) {

		bool ok = 0;

		for(int j = i, k = 0; j < n; j++, k++)  {

			if(ok || a[j - 1][k] == i) {

				a[j][k] = a[j][k + 1];

				ok = 1;

			}

			else {

				a[j][k] = a[j - 1][k];

			}

		}

	}

	for(int i = 0; i < n; i++) {

		for(int j = 0; j <= i; j++) {

			cout << a[i][j] << " ";

		}

		cout << "\n";

	}

}



int main() {

 

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

	freopen("error.txt", "w", stderr);

	freopen("output.txt", "w", stdout);

#endif

 

	fastio();

    int tc = 1;

    // cin >> tc;

    for (int t = 1; t <= tc; t++) {

		// cout << "Case #" << t << ": ";

        solve();

    }

	return 0;

}