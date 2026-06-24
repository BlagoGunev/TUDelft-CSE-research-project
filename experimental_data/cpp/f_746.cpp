#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
#define N 200010
#define mid ((l+r)>>1)
#define ls t<<1,l,mid
#define rs t<<1|1,mid+1,r
inline int rd(){int t;scanf("%d",&t);return t;}
struct data{ll s,k;}a[40050];
data mer(data x,data y){
	return (data){x.s+y.s,x.k+y.k};
}
void add(ll t,ll l,ll r,ll x){
	if (l==r) a[t].s++,a[t].k+=l/2;
	else (x<=mid?add(ls,x):add(rs,x)),a[t]=mer(a[t<<1],a[t<<1|1]);
}
void del(ll t,ll l,ll r,ll x){
	if (l==r) a[t].s--,a[t].k-=l/2;
	else (x<=mid?del(ls,x):del(rs,x)),a[t]=mer(a[t<<1],a[t<<1|1]);
}
ll ask(ll t,ll l,ll r,ll x){
	if (x==0) return 0;
	if (x>=a[t].s) return a[t].k;
	if (l==r) return x*a[t].k/a[t].s;
	if (a[t<<1|1].s>=x) return ask(rs,x);
	return ask(ls,x-a[t<<1|1].s)+a[t<<1|1].k;
}
ll n,w,k,mx,i,l,r,v[N],t[N],ans[N],sum[N],anss,tmp;
int main(){
	n=rd(),w=rd(),k=rd(),mx=10000;
	for (i=1;i<=n;i++) v[i]=rd(),ans[i]=ans[i-1]+v[i];
	for (i=1;i<=n;i++) t[i]=rd(),sum[i]=sum[i-1]+t[i];
	for (l=1;r<n&&l<=n;l++){
		r=max(r,l-1);
		while (1){
			if (r==44270){
				r=r+1-1;
			}
			if (r==n) break;
			add(1,1,mx,t[r+1]);
			if (sum[r+1]-sum[l-1]-(tmp=ask(1,1,mx,w))>k) break;
			r++;
		}
		if (r!=n) del(1,1,mx,t[r+1]);
		anss=max(anss,ans[r]-ans[l-1]);
		if (r>=l) del(1,1,mx,t[l]);
	}
	cout<<anss<<"\n";
	return 0;
}