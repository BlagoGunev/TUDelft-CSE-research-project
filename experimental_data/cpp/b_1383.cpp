#include<bits/stdc++.h>

using namespace std;

const int N=1e6+10,R=1e6;

const int mod=1e9+7;





void solve() {

	int n;

	cin>>n;

	vector<int>a(n);

	for(int i=0;i<n;i++)cin>>a[i];

	for(int i=30;i>=0;i--){

		int ones=0;

		for(int v:a){

			if(v>>i&1)ones++;

		}

		if(ones%2==0)continue;

		else{

			int zeros=n-ones;

			if(ones%4==1){

				cout<<"WIN\n";

				return;

			}else {

				if(zeros%2==1)cout<<"WIN\n";

				else cout<<"LOSE\n";

				return;

			}

		}

	}

	cout<<"DRAW\n";

}

int main() {

	ios::sync_with_stdio(false);

	cin.tie(0);

	cout.tie(0);

	int T=1;

	cin>>T;

	while(T--) {

		solve();

	}

	return 0;

}

/*



*/