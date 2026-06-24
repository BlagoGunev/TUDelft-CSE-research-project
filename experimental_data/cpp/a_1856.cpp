#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n";
#define i64 long long
 
// Always check for overflows, out of bounds in any form
const int INF = 1e9 + 7;
const double EPS = 1e-8;
const i64 SIZE=1e6;
void solve(int test_case) {
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0 ; i < n ; i++) cin >> v[i];
	int da=0;
	for(int i = n-1; i>=0 ; i--){
		if(v[i]<v[i-1]){
			da=i;
			break;
		}
	}
	if(da==0){
		cout << 0 << endl;
		return;
	}
	int ma=0;
	for(int i = 0 ; i < da ; i++){
		ma=max(v[i],ma);
	}
	cout << ma << endl;
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
//ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int _T = 1;
    cin >> _T;
    int test_case=1;
    while (_T--) {
        solve(test_case++);
    }
}