#include<bits/stdc++.h>
using namespace std;
#define N 2005
#define ll long long
#define mod 998244353
ll ksm(ll x,ll y){ll ret=1;for(;y;y>>=1,x=x*x%mod)if(y&1)(ret*=x)%=mod;return ret;}

int T,n,m,i,j,k,x,c[N],tot,a[N],b[N],f[N][N]; 
int main(){
//	ios::sync_with_stdio(0); 
	cin>>T;
//	T=1;
	while(T--){
		cin>>n>>m;
		if(m>=n+n)cout<<"NO\n";
		else{
			cout<<"YES\n";
			for(i=1;i<=n+n;++i){
				for(j=1;j<=m;++j){
					cout<<(((i-1+j-1)/2))%n+1<<" ";
				}
				cout<<"\n";
			}
		} 
	}
}