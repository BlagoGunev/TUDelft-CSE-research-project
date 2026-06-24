#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mx=100005;

pair<ll,ll> m[105];
ll ara[105];

ll dif(ll a,ll b){
	ll d=abs(a-b);
	return d;
}

int main(){
	ll n,s;
	scanf("%lld %lld",&n,&s);
	for(ll i=1;i<=n;i++){
		scanf("%lld %lld",&m[i].first,&m[i].second);
		ara[i]=m[i].first*60+m[i].second;
	}
	ara[n+1]=1000000000;
	ll firstgap=s;
	if(dif(0,ara[1])>firstgap){
		printf("0 0\n");
		return 0;
	}
	
	ll gap=2*s+1;
	for(ll i=2;i<=n+1;i++){
		if(dif(ara[i],ara[i-1])>gap){
			ll ans=s+1+ara[i-1];
			printf("%lld %lld\n",ans/60,ans%60);
			break;
		}
	}

}