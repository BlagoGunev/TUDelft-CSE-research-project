#include<bits/stdc++.h>

using namespace std;

void solve(){
	long long n, m;
	cin >> n >> m;
	string s[n];
	for (int i = 0; i < n; i++) cin >> s[i];
	long long x = 0, cur = 0;
	while (x < n && cur + s[x].size() <= m) {
		cur += s[x].size();
		x += 1;
	}
	cout << x;
}

int main(){
	int t = 1;
	cin >> t;
	while (t--){
		solve();
		cout << "\n";
	}
}