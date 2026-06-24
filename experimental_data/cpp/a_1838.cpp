#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int, int> pii;
typedef long double ld;
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define inf 1e18+8

void solve(){
	int n;
	cin >> n;
	map<int, int> freq;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		freq[a[i]]++;
	}
	sort(all(a));
	if(a[0] < 0){
		cout << a[0] << endl;
	}
	else{
		cout << a[n-1] << endl;
	}
}

signed main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}	
}