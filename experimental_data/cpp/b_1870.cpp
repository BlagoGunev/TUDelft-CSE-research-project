#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int N=2e5+5;
typedef long long ll;
ll a[N];
ll b[N];
void solve()
{
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=m;i++){
		cin>>b[i];
	}
	ll maxn;
	ll minn;
		maxn=a[1];
		for(ll i=2;i<=n;i++){
			maxn=maxn^a[i];
		}
		ll k=0;
		for(ll i=1;i<=m;i++){
			k|=b[i];
		}
		for(ll i=1;i<=n;i++){
			a[i]|=k;
		}
		minn=a[1];
		for(ll i=2;i<=n;i++){
			minn=minn^=a[i];
		}
		if(n%2==0){
			cout<<minn<<" "<<maxn<<"\n";
		}
		else{
			cout<<maxn<<" "<<minn<<"\n";
		}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}