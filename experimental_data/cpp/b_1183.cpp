#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <cmath>
#include <queue>
#include <ctime>
#include <utility> // std::pair
#include <functional> // std::greater <int> ()
#define int long long
#define inf 1000000000000000001
#define BASE 29 // hashings mod, can be rand'd
#define mod 998244353 // can be 1000000007
#define pi 3.1415926535897
#define pii pair <int, int>
#define fii first
#define see second

typedef long long ll;
typedef long double ld;
using namespace std;

int n, k;
int a[105];

// functions
int bs(){
//	cerr << k << endl;
	int l=1, r=k+a[n]+1;
//	cerr << l << " " << r << endl;
	while(r>l){
//		cerr << l << " " << r << endl;
		bool chk=0;
		int mid=(r+l)/2;
//		if((r+l)%2!=0){
//			mid++;
//		}
		for(int i=1; i<=n; i++){
//			cerr << abs(mid-a[i]) << " ";
			if(abs(mid-a[i])>k){
//				cerr << i << endl;
				r=mid;
				chk=1;
				break;
			}
		}
		if(!chk){
			l=mid+1;
		}
	}
	return r-1;
}

void input(){
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	return;
}

void solve(){
	sort(a+1, a+n+1);
	if(a[n]-a[1]>2*k){
		cout << "-1";
		return;
	}
	else{
		cout << a[1]+k;
	}
	return;
}

void output(){
	cout << endl;
	return;
}

signed main(){
/*
//  REMEMBER TO TURN OFF IFDEF IN PROBLEMS WITH FILE I/O
*/
#ifdef sheeep
	freopen("forces.inp", "r", stdin);
	freopen("forces.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int i=1; i<=t; i++){
		input();
		solve();
		output();
	}
	return 0;
}
// Author: NamSPro