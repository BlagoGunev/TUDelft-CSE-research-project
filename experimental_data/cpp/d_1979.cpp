#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define sz(x) (int)((x).size())
#define all(x) begin(x), end(x) 
#define ff first
#define ss second
#define m_p make_pair

const int N = 100;   // !!!!!!!!!!!!!!!!!!!!!!!!
const int M = 250;
const ll MOD = 998244353;  // !!!!!!!!!!!!
const int INF = 1e9;

bool check(string s, int k) {
	for(int i = 1; i < k; i++) {
		if(s[i] != s[i - 1]) return false;
	}
	for(int i = 0; i < sz(s) - k; i++) {
		if(s[i] == s[i + k]) return false;
	}
	return true;
}

void solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	for(int i = 0; i < n; i++) {
		char c = s[i];
		int j = i;
		while(j < n && s[j] == c) j++;
		j--;
		int len = j - i + 1;
		if(len != k) {
			if(len <= 2 * k) {
				int ind;
				if(len < k) {
					ind = j;
				} else {
					ind = j - k;
				}
				string s1 = s.substr(0, ind + 1), t = s.substr(ind + 1);
				reverse(all(s1));
				t += s1;
				//cout << ind << '\n' << t << '\n';
				if(check(t, k)) cout << ind + 1 << '\n';
				else cout << "-1\n";
				return;
			} else {
				cout << "-1\n"; return;
			}
		} else {
			i = j;
		}
	}
	cout << n << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1; cin>>T;  // !!!!!!!!!!
    while(T--) solve();
    return 0;
}