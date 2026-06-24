#include"bits/stdc++.h"
using namespace std;
#pragma GCC optimize(2)
#define int long long
const int maxn = 200010;
bitset<maxn>f,Ms;
int n,a[maxn],s[maxn],ans;
signed main(){
	cin>>n,f[1]=1,ans=0;
	for(int i=1;i<=n;i++)cin>>a[i],s[i]=s[i-1]+a[i],Ms[i]=1;
	for(int i=1;i<=n;i++)f|=(f&Ms)<<a[i],Ms[i]=0;
	for(int i=1;i<maxn;i++)if(f[i])ans=max(ans,s[min(i,n)]-i+1);
	cout<<ans<<endl;
}