//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(a);i>=(b);--i)
#define Yes printf("Yes\n")
#define No printf("No\n")
#define pb push_back
const ll N=1e6+10;
using namespace std;
//const ll p=1e9+7;
const ll p=998244353;
ll ksm(ll a,ll b){ll bns=1;while(b){if(b&1)bns=bns*a%p;a=a*a%p;b>>=1;}return bns;}

ll n,m,k;
ll a[N],b[N];



void mian(){
	
	ll ans=0;
	scanf("%lld",&n);
	scanf("%lld",&k);
	For(i,1,n){
		scanf("%lld",&a[i]);
	}
	
	sort(a+1,a+n+1);
	Rep(i,n,2){
		ll tmp=a[i]-a[i-1];
		ll ttt=min(tmp,k);
		k-=ttt,a[i-1]+=ttt;
		ans+=a[i]-a[i-1];
		--i;
	}
	if(n&1){
		ans+=a[1];
	}
	
	printf("%lld\n",ans);
	
}

int main(){
	int T=1;
	scanf("%d",&T);
	while(T--)mian();
	return 0;
}