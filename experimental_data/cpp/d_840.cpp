#include<bits/stdc++.h>
using namespace std;
const int N=1e6,logn=1e7;
int lc[logn],rc[logn],s[logn];
int rt[N];
int a[N],x[N],tot;
inline void insert(int &i,int l,int r,int k) {
	s[++tot]=s[i]+1,lc[tot]=lc[i],rc[tot]=rc[i],i=tot;
	if (l!=r) {
		int mid=(l+r)>>1;
		k<=mid?insert(lc[i],l,mid,k):insert(rc[i],mid+1,r,k);
	}
}
int ans;
inline void query(int a,int b,int l,int r,int k) {
	if (s[b]-s[a]<k) return;
	if (ans) return;
	if (l==r) ans=l;
	else {
		int mid=(l+r)>>1;
		query(lc[a],lc[b],l,mid,k);
		query(rc[a],rc[b],mid+1,r,k);
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int n,q,len,l,r,k,i;
	scanf("%d%d",&n,&q);
	for (i=1;i<=n;i++) scanf("%d",&a[i]),x[i]=a[i];
	sort(x+1,x+1+n);
	len=unique(x+1,x+1+n)-x-1;
	for (i=1;i<=n;i++)
		insert(rt[i]=rt[i-1],1,len,lower_bound(x+1,x+1+len,a[i])-x);
	x[0]=-1;
	while (q--) {
		scanf("%d%d%d",&l,&r,&k);
		k=(r-l+1)/k+1;
		ans=0;
		query(rt[l-1],rt[r],1,len,k);
		printf("%d\n",x[ans]);
	}
	return 0;
}