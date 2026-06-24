#include<bits/stdc++.h>
using namespace std;

#define int long long

int T,n;
vector<int> v;
int a[20]={0,1,2,3,5,6,7,8,9};

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		v.clear();
		cin>>n;
		while(n){
			v.push_back(n%9);
			n/=9;
		}
		reverse(v.begin(),v.end());
		for(auto i:v){
			cout<<a[i];
		}
		cout<<"\n";
	}
	return 0;
}