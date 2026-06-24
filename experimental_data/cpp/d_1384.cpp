#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<ll,ll> pi;

int A[100005];

void solve(){

	int n; cin>>n;

	for(int i=1; i<=n; i++) cin>>A[i];

	for(int i=30; i>=0; i--){

		int a = 0;

		for(int j=1; j<=n; j++) if(A[j]&(1<<i)) a++;

		int b = n-a;

		if(a%2==0) continue;

		if(a%4==3 && b%2==0) cout<<"LOSE"<<'\n';

		else cout<<"WIN"<<'\n';

		return;

	}

	cout<<"DRAW"<<'\n';

}

int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;

	cin >> t;

	while(t--) solve();

}