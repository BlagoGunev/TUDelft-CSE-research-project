#include<bits/stdc++.h>
using namespace std;
void solve(){
	int x,k;
	cin>>x>>k;
	if((x<k)||(x%k)){
		cout<<1<<endl;
		cout<<x<<endl;
		return;
	}
	cout<<2<<endl;
	cout<<(k-1)<<" "<<(x-k+1)<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}