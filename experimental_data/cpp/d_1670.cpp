#include<bits/stdc++.h>



using namespace std;



#define ll long long 



const int N = 200005;



ll a[N];



void solve(){

	int n;

	cin>>n;

	

	int l= 2;

	int r = 38730;

	int ans;

	while(l<=r){

		int mid = (l+r)/2;

		if(a[mid] >= n){

			ans = mid;

			r = mid-1;

		}else{

			l = mid+1;

		}

	}

	cout<<ans<<'\n';

}



int main()

{

	cin.sync_with_stdio(false);

	cin.tie(0);cout.tie(0);

	a[1] = 0;

	a[2] = 2;

	a[3] = 6;

	a[4] = 10;

	int cnt = 4;

	for(int i=5;i<=100000;++i){

		if(i%3 == 0) cnt+=2;

		else if(i%3 == 2) cnt+=2;

		a[i] = a[i-1] + cnt;

		if(a[i] > 1e9) break;

	}

	

	int t = 1;

	cin>>t;

	while(t--){

		solve();

	}

	

	return 0;

}