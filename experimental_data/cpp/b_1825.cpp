#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
	int n,m;
	cin>>n>>m;
	vector<int>a(n*m);
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	ll ans=0;
	ll mx=0;
	if(m>n) swap(m,n);
		int a11=a[n*m-1];
		int a21=a[0];
		int a12=a[1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(i==1&&j==1) continue;
				if(i==1&&j>=2){
					ans+=(a11-a12);
				}
				else{
					ans+=(a11-a21);
				}
				//cout<<ans<<" ";
			}
		}
		mx=max(mx,ans);
		ans=0;
		a11=a[0];
		a21=a[n*m-1];
		a12=a[n*m-2];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(i==1&&j==1) continue;
				if(i==1&&j>=2){
					ans+=abs(a11-a12);
				}
				else{
					ans+=abs(a11-a21);
				}
				//cout<<ans<<" ";
			}
		}
		mx=max(mx,ans);

	cout<<mx<<'\n';
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}