#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define uint unsigned
#define N 300005
using namespace std;
template <typename T>
inline void read(T &r) {
	r=0;bool f=0;char c=getchar();
	while(!isdigit(c)) f|=(c=='-'),c=getchar();
	while(isdigit(c)) r=(r<<3)+(r<<1)+(c^'0'),c=getchar();
	r=f?-r:r;
	return;
}
template <typename T>
inline void write(T x) {
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+48);
	return;
}
int n,q;
ll a[N],sum[N],ssum[N],qsum[N],ksum[N];
inline ll js(ll x){
	ll ans=0;
	int now=0;
	for(int step=1<<22;step;step>>=1)if(now+step<=n&&1ll*(n+n-now-step+1)*(now+step)/2<=x)now+=step;
	x-=1ll*(n+n-now+1)*now/2;
	return qsum[now]+ksum[now+1+x-1]-sum[now]*x-ksum[now];
}
inline ll query(ll l,ll r){
	return js(r)-js(l-1);
}
int main(){
	read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;++i)ssum[1]+=sum[i];
	for(int i=2;i<=n;++i)ssum[i]=ssum[i-1]-a[i-1]*(n-i+2);
	for(int i=1;i<=n;++i)qsum[i]=qsum[i-1]+ssum[i];
	for(int i=1;i<=n;++i)ksum[i]=ksum[i-1]+sum[i];
	read(q);
	ll l,r;
	while(q--){
		read(l);read(r);
		write(query(l,r));putchar('\n');
	}
	return 0;
}