#include <bits/stdc++.h>

using namespace std;

#define go ios::sync_with_stdio (0); cin.tie(0); cout.tie(0);

typedef long long ll;

typedef vector<int> vi;

typedef vector<ll> vl;

typedef vector<vector <int>> vii;

typedef pair<int, int> pi;

#define F first

#define S second

#define PB push_back

#define reb(i,a,b) for (int i = a; i < b; i++)

#define endl  "\n"

#define NO cout <<"NO\n"

#define YES cout << "YES\n"

#define nax 100005

#define LFT p<<1, L, (L+R)>>1

#define RGT p<<1|1, ((L+R)>>1)+1, R

#define all(x) 		x.begin(), x.end()

#define rall(v)	v.rbegin(), v.rend()

#define dmid  ll mid = L + ((R - L ) >> 1);

#define T int t; cin >> t; while (t--)



ll M = 998244353;

ll mod(ll x) {

	return ((x % M + M) % M);

}

ll mul(ll a, ll b) {

	return mod(mod(a) * mod(b));

}

ll add(ll a, ll b) {

	return mod(mod(a) + mod(b));

}

ll dec(ll a, ll b) {

	return mod(mod(a) - mod(b));

}



int main() {

	//freopen("input.txt", "r", stdin);

	//freopen("output.txt", "w", stdout);

	//cout.flush();

	//memset(&a[0], 0, sizeof(a[0]) * a.size());

	//cout << fixed << setprecision(9);

	go;

	int t; cin >> t; 

	while (t --) {

		int n; cin >> n;

		string s; string t; 

		cin >> s; cin >> t;

		vi  a1, a2, c1, c2;

		string ss, tt;

		for (int i = 0; i < n; i++) {

			if (s[i] != 'b'){

				ss.PB(s[i]);

				if (s[i] == 'a') a1.PB(i);

				else c1.PB(i);

			}

			if (t[i] != 'b') {

				tt.PB(t[i]);

				if (t[i] == 'a') a2.PB(i);

				else c2.PB(i);

			}

		}

		if (tt != ss) { NO; continue; }

	    if (a1.size() != a2.size() || c1.size() != c2.size()) { NO; continue; }

		bool f = 1; 

		for (int i = 0; i < a1.size(); i++) {

			if (a1[i] > a2[i]){

				f = 0; break;

			}

		}

		for (int i = 0; i < c1.size(); i++) {

			if (c1[i] < c2[i]){

				f = 0; break;

			}

		}

		(f) ? YES : NO;

	}

	return 0;

}