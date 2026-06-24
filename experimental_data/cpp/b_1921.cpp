#include <bits/stdc++.h>
using namespace std;
#define name "aaaaaa"
using pii = pair<long long, long long>;

void file(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
}

void solve (){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string a, b;
		cin >> a >> b;
		a = " " + a; b = " " + b;
		int up = 0, down = 0;
		for(int i = 1; i <= n; i++){
			if(a[i] == '0' && b[i] == '1'){
				down++;
			}else if(a[i] == '1' && b[i] == '0'){
				up++;
			}
		}
		if(up > down) swap(up, down);
		cout << abs(up - down) + up << endl;
	}
}

int main(){
	file();
	solve();
}