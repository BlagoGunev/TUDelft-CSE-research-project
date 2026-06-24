#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[2050][2050];
ll f(ll x){
	if(x==0)return 0;
	else return (x+1)*x/2;
}
void solve(){
	int n;
	cin>>n;
	int x,y;
	for(ll i=1;i<=2023;i++){
		if(f(i-1)<n&&f(i)>=n){
			x=i;
			y=n-f(i-1);
			break;
		}
	}
	ll res=0;
	for(ll i=x;i>=1;i--){
		int l=x-i+1;
		if(l>y)l=y;
		res+=a[i][y]-a[i][y-l];
	}
	cout<<res<<endl;
	return;
}
int main(){
	ll cnt=1;
	for(int i=1;i<=2023;i++){
		for(int j=1;j<=i;j++){
			a[i][j]=a[i][j-1]+cnt*cnt;
			cnt++;
		}
		for(int j=i+1;j<=2023;j++)a[i][j]=a[i][i];
	}
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}