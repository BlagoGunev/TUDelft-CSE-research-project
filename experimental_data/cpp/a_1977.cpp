#include<bits/stdc++.h>
using namespace std;
#define int long long
int x,y;
void work(){
	cin>>x>>y;
	if(x<y){
		cout<<"No"<<endl;
		return ;
	}
	if(x%2==y%2){
		cout<<"Yes"<<endl;
		return ;
	}
	cout<<"No"<<endl;
	return ;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--) work();
	return 0;
}