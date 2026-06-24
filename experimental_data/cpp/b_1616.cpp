#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
#include <set>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <random>
#include <complex>
#include <bitset>
#include<fstream>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline void boostIO() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
}

bool isPrime(int x) {
	if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
	for (int i = 5; i * i <= x; i += 6) if (x % i == 0 || x % (i + 2) == 0) return 0; return 1;
}

typedef long long int ll;
typedef long double ld;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;;
typedef pair<int, int> pii;

#define fori(n) for(int i = 0; i < (n); ++i)
#define forj(n) for(int j = 0; j < (n); ++j)
#define fork(n) for(int k = 0; k < (n); ++k)
#define forx(n) for(int x = 0; x < (n); ++x)

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ff first
#define ss second
#define debug(x) cerr << #x << " = " << x << endl;
#define debug_p(x) cerr << #x << " " << x.ff << " " << x.ss << endl;
#define debug_v(x) cerr << #x << " "; for (auto ii : x) cout << ii << " "; cout << endl;
#define debug_vp(x) cerr << #x << " "; for (auto ii : x) cout << '[' << ii.ff << " " << ii.ss << ']'; cout << endl;
#define mp make_pair
#define rand kjsdflsdfsdlsjdlkfsdjflsjdfl 

#define Return cerr<<endl<<"RUNTIME: "<<1.0*clock()/CLOCKS_PER_SEC << " s" <<endl; return 0;

#define PI 3.1415926535897932384626

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }


bool BREAKTIME(ld v) {
	return 1.0 * clock() >= v * CLOCKS_PER_SEC;
}

#define OR(a, b)  ((a) | (b))
#define AND(a, b) ((a) & (b))
#define XOR(a, b) ((a) ^ (b))
#define BIT(a) (1ll << (a))

unsigned int COUNT(unsigned int n) {
	unsigned int count = 0;
	while (n) {
		count += n & 1;
		n >>= 1;
	}
	return count;
}

/////////////////////
#define int long long
const int inf = 2e18;
int mod = 1e9 + 7;
#define endl '\n'
/////////////////////

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	string ans;
	
	bool flag = 1;

	int kek = 0;
	for (int i = 0; i < n; ++i) {
		ans.push_back(s[i]);
		if (i != n-1 && (kek == 0 && s[i] <= s[i + 1] || kek == 1 && s[i] < s[i+1]) ) {
			flag = 0;
			for (int j = i; j >= 0; --j) {
				ans.push_back(s[j]);
			}
			break;
		}
		kek = 1;
	}

	if (flag) {
		for (int j = n - 1; j >= 0; --j) {
			ans.push_back(s[j]);
		}
	}
	cout << ans << endl;
}

int32_t main() {
	boostIO();
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T = 1; cin >> T;
	while (T--) {
		solve();
	}

}