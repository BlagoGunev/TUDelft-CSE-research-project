#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	
	int T;
	cin >> T;
	while(T--){
		int n, x;
		long long y;
		cin >> n >> x >> y;
		int cnt = 0;
		for(int i = 0; i < n; ++i){
			int t;
			cin >> t;
			cnt += t % 2;
		}
		y = abs(y - x);
		if( y % 2 == cnt % 2) cout << "Alice" << '\n';
		else cout << "Bob" << '\n';
	}
}