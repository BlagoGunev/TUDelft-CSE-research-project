#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve(){
	int n,m,q;cin>>n>>m>>q;
	int a[n],b[m];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	bool vis[n+1];
	for(int i=1;i<=n;i++){
		vis[i]=false;
	}
	vector<int>v;
	for(int j=0;j<m;j++){
		cin>>b[j];
		if(!vis[b[j]]){
			vis[b[j]]=true;
			v.push_back(b[j]);
		}
	}
	int len=v.size();
	for(int i=0;i<len;i++){
		if(v[i]!=a[i]){
			cout<<"TIDAK"<<endl;
			return;
		}
	}
	cout<<"YA"<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}