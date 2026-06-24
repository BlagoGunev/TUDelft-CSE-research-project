#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define N 200005
using namespace std;
int n,t[N];
ll T,fac[N],_inv[N],inv[N],h[N],g[N],s[N],ans;
ll C(int n,int m){
	if(m>n) return 1;
	return fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
int main(){
	scanf("%d%lld",&n,&T);
	fac[0]=1;
	for(int i=1;i<N;i++)
		fac[i]=fac[i-1]*i%MOD;
	_inv[0]=_inv[1]=1;  
    for(int i=2;i<N;i++)
        _inv[i]=((MOD-MOD/i)*_inv[MOD%i])%MOD;  
    inv[0]=inv[1]=1;
    for(int i=2;i<N;i++)
    	inv[i]=inv[i-1]*_inv[i]%MOD;
    h[0]=1;
	for(int i=1;i<N;i++)
		h[i]=h[i-1]*_inv[2]%MOD;
    for(int i=1;i<=n;i++){
    	scanf("%d",&t[i]);
    	s[i]=s[i-1]+t[i];
    	g[i]=g[i-1]+t[i]+1;
    }
    g[n+1]=T+1;
    for(int i=1;i<=n;i++){
    	if(g[i]>T&&T>=s[i-1]){
	    	for(int j=max(0ll,T-s[i]+1);j<=i&&s[i-1]+j-1<=T;j++){
	    		if(s[i-1]+j>T){
	    			ans=(ans+(ll)(i-1)*h[i]%MOD*C(i-1,j-1)%MOD)%MOD;
	    		}else{
	    		 	ans=(ans+(ll)(i-1)*h[i]%MOD*C(i,j)%MOD)%MOD;
	    		}
	    	}
    	}
    }
    for(int i=0;i<=T-s[n];i++)
    	ans=(ans+(ll)n*h[n]%MOD*C(n,i)%MOD)%MOD;
    printf("%lld\n",ans);
}