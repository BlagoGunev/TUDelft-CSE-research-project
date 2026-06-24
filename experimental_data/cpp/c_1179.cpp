#include<bits/stdc++.h>
using namespace std;
int a[300005],b[300005],sum[4000005],mi[4000005];
int read() {
	char c=getchar(); int x=0,f=1;
	while (c<'0' || c>'9') {
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
void add(int x,int l,int r,int t,int k) {
	if (l==r) {
		sum[t]+=k;
		mi[t]+=k;
		return;
	}
	int mid=(l+r)>>1,lson=t<<1,rson=lson|1;
	if (x<=mid) add(x,l,mid,lson,k);
	else add(x,mid+1,r,rson,k);
	sum[t]=sum[lson]+sum[rson];
	mi[t]=min(mi[rson],sum[rson]+mi[lson]);
}
int query(int l,int r,int t,int k) {
	if (l==r) return l;
//	cout<<l<<" "<<r<<" "<<k<<endl;
	int mid=(l+r)>>1,lson=t<<1,rson=lson|1;
//	cout<<sum[lson]<<" "<<sum[rson]<<endl;
	if (mi[rson]<k) return query(mid+1,r,rson,k);
	else return query(l,mid,lson,k-sum[rson]);
} 
int main() {
	int n=read(),m=read();
	for (int i=1; i<=n; i++) {
		a[i]=read();
		add(a[i],0,1000000,1,-1);
	}
	for (int i=1; i<=m; i++) {
		b[i]=read();
		add(b[i],0,1000000,1,1);
	}
	int q=read();
	for (int i=1; i<=q; i++) {
		int opt=read(),p=read(),x=read();
		if (opt==1) {
			add(a[p],0,1000000,1,1);
			a[p]=x;
			add(a[p],0,1000000,1,-1);
		}
		else {
			add(b[p],0,1000000,1,-1);
			b[p]=x;
			add(b[p],0,1000000,1,1);
		}
		int ans=query(0,1000000,1,0);
		if (ans>0) printf("%d\n", ans);
		else printf("-1\n");
	}
	return 0;
}