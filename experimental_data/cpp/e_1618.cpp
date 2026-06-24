#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1000010,inf=0x3f3f3f3f,mod=1e9+7;

ll qmi(ll a,ll k) {
	ll res=1;
	while(k) {
		if(k&1) res=res*a%mod;
		a=a*a%mod;
		k>>=1;
	}
	return res;
}

ll a[N];

void Test() {
	ll n;
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	if(n==1){
		cout<<"YES\n";
		cout<<a[1]<<"\n";
		return ;
	}
	ll sum=0;
	for(int i=1; i<=n; i++) sum+=a[i];
	if(sum%((ll)n*(n+1)/2)!=0) {
		cout<<"NO\n";
		return ;
	}

	sum=sum/(n*(n+1)/2);
	vector<ll>V;

	for(int i=1; i<=n; i++) {
		ll b;
		if(i==1) b=a[1]-a[n];
		else b=a[i]-a[i-1];
		ll c=sum-b;
		if(c%(n)!=0) {
			cout<<"NO\n";
			return ;
		}
		if(c/n<1||c/n>1e9){
			cout<<"NO\n";
			return ;
		}
		V.push_back(c/(n));
	}
	cout<<"YES\n";
	for(int i=0;i<n;i++) cout<<V[i]<<" ";
	cout<<"\n";

}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
		Test();
}