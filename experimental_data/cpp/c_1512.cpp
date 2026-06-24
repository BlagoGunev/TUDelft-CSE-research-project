#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;


#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define endl '\n'
#define forn(i, n) for(ll i = 0; i < n; i++)
#define fora(i, a, n) for(ll i = a; i < n; i++)
#define readi(e) int e; cin >> e
#define readl(e) ll e; cin >> e
#define reads(e) string e; cin >> e
#define T int tt; cin >> tt; while(tt--)


template<typename U>
void print(U arr) {
	for(auto element: arr) {
		cout << element << " ";
	}
	cout << endl;
}

// read and write into files, rather than standard i/o
void setup(string s) {
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}

const int M = 1e9+7;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T {
		int a, b;
		cin >> a >> b;
		int n = a+b;
		vector<char> s(n);
		for(auto& e: s) cin >> e;
		bool y=1;
		if(a%2 != 0 && b%2 != 0) {cout << -1 << endl;continue; }
		forn(i, n) {
			if(s[i] != '?') {
				if(s[n-1-i] != '?' && s[n-1-i] != s[i]) {
					y=0;
					break;
				} else {
					s[n-1-i] = s[i];
				}
			}
		}
		if(y == 0) {
			cout << -1 << endl;
			continue;
		}
		int rem_zero =  a - count(all(s), '0');
		int rem_one = b -  count(all(s), '1');
		if(rem_one%2 != 0) {
			forn(i, n) {
				if(s[i] == '?') {
					if(rem_zero > 0) {
						s[i] = '0';
						s[n-1-i] = '0';
						if(i == n-1-i) rem_zero -= 1;
						else rem_zero -= 2;
					} else {
						s[i] = '1';
						s[n-1-i] = '1';
						if(i == n-1-i) rem_one -= 1;
						else rem_one -= 2;
					}
				}
			}
		} else {
			forn(i, n) {
				if(s[i] == '?') {
					if(rem_one > 0) {
						s[i] = '1';
						s[n-1-i] = '1';
						if(i == n-1-i) rem_one -= 1;
						else rem_one -= 2;
					} else {
						s[i] = '0';
						s[n-1-i] = '0';
						if(i == n-1-i) rem_zero -= 1;
						else rem_zero -= 2;
					}
				}
			}
		}
		if(rem_zero == 0 && rem_one == 0) for(auto& e: s) cout << e;
		else cout << -1;
		cout << endl;
	}

	return 0;
}