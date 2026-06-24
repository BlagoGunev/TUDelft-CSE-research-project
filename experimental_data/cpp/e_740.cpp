#include <bits/stdc++.h>
using namespace std; 

const int N=1e6;
const int Mod=1e9+7;

int n,m,a[N];
long long b[N];

struct Node {
	int sl,sr,ml,mr,m,len;
	long long v;
	Node(){} 
}tree[N<<2];

inline Node merge(Node &a,Node &b) {
	Node res;
	res.m=max(a.m,b.m);
	if(a.sr!=0&&b.sl!=0&&a.sr>=b.sl) res.m=max(res.m,a.mr+b.ml);
	res.sl=a.sl; 
	res.sr=b.sr;
	res.ml=a.ml;
	res.mr=b.mr;
	res.len=a.len+b.len;
	if(a.len==a.ml&&a.sr>=b.sl&&b.sl!=0&&a.sr!=0) res.ml+=b.ml;
	if(b.len==b.mr&&a.sr>=b.sl&&b.sl!=0&&a.sr!=0) res.mr+=a.mr;
	res.m=max(res.m,res.ml);
	res.m=max(res.m,res.mr);
	return res;
}

void build(int k,int l,int r) {
	tree[k].len=r-l+1; 
	if(l==r) {
		if(b[l]>0) tree[k].sl=tree[k].sr=1;
		if(b[l]==0) tree[k].sl=tree[k].sr=0;
		if(b[l]<0) tree[k].sl=tree[k].sr=-1;
		tree[k].ml=tree[k].mr=tree[k].m=1;
		if(b[l]==0) tree[k].ml=tree[k].mr=tree[k].m=0;
		tree[k].v=b[l];
		return;
	}	
	int mid=l+r>>1;
	build(k<<1,l,mid); build(k<<1|1,mid+1,r);
	tree[k]=merge(tree[k<<1],tree[k<<1|1]);
}

void Ins(int k,int l,int r,int p,int v) {
	if(l==r) {
		b[l]+=v;
		if(b[l]>0) tree[k].sl=tree[k].sr=1;
		if(b[l]==0) tree[k].sl=tree[k].sr=0;
		if(b[l]<0) tree[k].sl=tree[k].sr=-1;
		tree[k].ml=tree[k].mr=tree[k].m=1;
		if(b[l]==0) tree[k].ml=tree[k].mr=tree[k].m=0;
		tree[k].v=b[l];
		return;
	}
	int mid=l+r>>1;
	if(p<=mid) Ins(k<<1,l,mid,p,v);
	else Ins(k<<1|1,mid+1,r,p,v);
	tree[k]=merge(tree[k<<1],tree[k<<1|1]);
}

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	n--;
	for(int i=1;i<=n;i++) b[i]=a[i+1]-a[i];
	if(n) build(1,1,n);
	int l,r,d,tmp;
	scanf("%d",&m);
	if(n==0) {
		for(int i=1;i<=m;i++) {
			scanf("%d%d%d",&l,&r,&d);
			puts("1");
		}
		return 0;
	}
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d",&l,&r,&d);
		if(l>1)Ins(1,1,n,l-1,d);
		if(r<=n)Ins(1,1,n,r,-d);
		tmp=tree[1].m;
		tmp++;
		printf("%d\n",tmp);
	}
}