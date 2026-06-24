#include<bits/stdc++.h>

using namespace std;

void solve(){
	long long int n;
	cin >> n;
	string s;
	cin >> s;
	if (s[0] == s[n-1]) cout << "NO";
	else cout << "YES";
}

int main(){
	int t = 1;
	cin >> t;
	while (t--){
		solve();
		cout << "\n";
	}
}