#include <bits/stdc++.h>
#define int long long 
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define debug(x) cout << #x << " is " << x << endl;
void solve(){
	int N;
	cin >> N;
	int A[N][N];
	for(int i=0;i<N;i++) for(int j=0;j<N;j++) cin >> A[i][N-1-j];
	int arr[2 * N];
	memset(arr, 0, sizeof(arr));
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			arr[i + j] = min(arr[i + j], A[i][j]);
		}
	}
	int ans = 0;
	for(int i=0;i<2 * N;i++) ans += arr[i];
	cout << -ans << '\n';
}
main(){
	int T;
	cin >> T;
	while(T--) solve();
}