//	Mohib Manva
#include<bits/stdc++.h>
using namespace std;
#define LOCAL 0
#define pb push_back
#define ll long long

long long n,m,x,y;

long long solve(ll int r,ll int c,long long k){
	if(n==1){
		ll ans = k/m;
		k%=m;
		if(k>=c){
			ans++;
		}
		return ans;
	}
	ll total = n*m;
	if(k<=total){
		if(k>=((r-1)*m+c)){
			return 1;
		}
		return 0;
	}
	k -= total;
	ll ans = 1;
	ll times;
	times = k/((n-1)*m);
	ans += times;
	k %= ((n-1)*m);
	if(k>0){
		if(times%2&&r!=1){
			ll cnt = ((r-1)*m) + c;
			cnt -= m;
			if(k>=cnt)
				ans++;
		} else 
		if(times%2==0&&r!=n){
			ll cnt = (n-r)*m + c;
			cnt -= m;
			if(k>=cnt)
				ans++;
		}
	} 
	if(r==1||r==n){
		if(r==1){
			ans = ((ans)/2ll + 1ll);
		} else {
			ans = ((ans-1ll)/2ll + 1ll);
		}
	}
	return ans;
}

int main(){
	if(LOCAL){
    	freopen(":/Users/gold/Desktop/sublime IO/input.txt","r",stdin);
    	freopen("C:/Users/gold/Desktop/sublime IO/output.txt","w",stdout);
	}
	int T = 1;
	//scanf("%d",&T);
	while(T--){
		//int n,m,x,y;
		long long k;
		scanf("%lld %lld %lld %lld %lld",&n,&m,&k,&x,&y);
		ll ans1 = solve(x,y,k);
		ll ma = ans1,mi = ans1;
		//return 0;
		for(ll int i=1;i<=n;i++){
			for(ll int j=1;j<=m;j++){
				ma = max(ma,solve(i,j,k));
				mi = min(mi,solve(i,j,k));
			}
		}
		printf("%lld %lld %lld\n",ma,mi,ans1);
	}
	return 0;	
}