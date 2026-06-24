#include <bits/stdc++.h>
#define LL long long
#define PII pair<int,int>
using namespace std;
const int MAXN = 2005;
const int INF = (LL)1e9 + 5;
const LL MOD = 998244353;

int first_not[128], N;
string s;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> s;
	
	LL ans = 0;
	if (s[0] == s.back()) {
		LL l = 0, r = s.size() - 1;
		while (s[l] == s[0]) l++;
		while (s[r] == s[0]) r--;
		ans = (l + 1) * (N - r) % MOD;
	}
	else {
		LL l = 0, r = s.size() - 1;
		while (s[l] == s[0]) l++;
		ans = (ans + (l + 1)) % MOD;
		
		while (s[r] == s.back()) r--;
		ans = (ans + (N - r)) % MOD;
		
		ans = (ans - 1 + MOD) % MOD;
	}
	
	cout << ans << '\n';
}