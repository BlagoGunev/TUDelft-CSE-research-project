#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll rd(){
	ll x=0;char o,f=1;
	while(o=getchar(),o<48)if(o==45)f=-f;
	do x=(x<<3)+(x<<1)+(o^48);
	while(o=getchar(),o>47);
	return x*f;
}
const int maxn=1e5+5;
const ll mod=998244353;
ll _,n,a[maxn],b[maxn];
ll tmp[maxn];
int main() {
    for(_=rd();_;_--){
        n=rd();
        for (int i=1;i<=n;i++)a[i]=rd(),b[i]=a[i],tmp[i]=0;
        sort(b+1,b+n+1);
    	int tot=unique(b+1,b+n+1)-b-1;
    	for (int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+tot+1,a[i])-b;
    	ll ans=0;
    	for (int i=1;i<=n;i++){
    		ans+=tmp[a[i]]*(n-i+1);
    		tmp[a[i]]+=i;
    	}
    	printf("%lld\n",ans);
    }
    return 0;
}