#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define MOD 1000000007



// cuoi Thao



void solve(){

	int n,cnt=0,c; cin >> n >> c;

	ll a[n];

	for(int i=0;i<n;i++){

		cin >> a[i];

		a[i]=a[i]+i+1;

	}

	sort(a,a+n);

	for(int i=0;i<n && c>=a[i];i++){

		++cnt;

		c-=a[i];

	}

	cout << cnt << endl;

}



int main(){

	ios::sync_with_stdio(false);

	cin.tie(nullptr);

	int t; cin >> t;

	while(t--){

		solve();

	}

	return 0;

}