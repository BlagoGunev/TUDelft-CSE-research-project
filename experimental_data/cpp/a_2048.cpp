#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ll long long
#define mod 998244353
ll ksm(ll x,ll y){ll ret=1;for(;y;y>>=1,x=x*x%mod)if(y&1)(ret*=x)%=mod;return ret;}

int T,n,i,j,k,a[N];

int main(){
	cin>>T;
//	T=1;
	while(T--){
		cin>>n;
		if(n%33==0)cout<<"YES\n";
		else cout<<"NO\n";
	}
}