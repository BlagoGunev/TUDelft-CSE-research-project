#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define MOD 1000000007

 

// cuoi Thao

 

void solve(){

	int n,a=1; cin >> n;

	for(int i=2;i<=sqrt(n);i++){

		if(n%i==0){

			a=n/i;

			break;

		}

	}

	cout << a << " " << n-a << endl;

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