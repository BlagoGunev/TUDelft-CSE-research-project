#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
const int N=202202;
int n,m,d;
int a[N],c[N];
struct AC{
	int o,p,x,pos;	
}q[N];
struct AK{
	int l,r,mx;	
}tree[N*8];

void update(int p){
	tree[p].mx=max(tree[p*2].mx,tree[p*2+1].mx);
	if (tree[p*2+1].l&&tree[p*2].r)	tree[p].mx=max(tree[p].mx,c[tree[p*2+1].l]-c[tree[p*2].r]);
	if (tree[p*2].l)	tree[p].l=tree[p*2].l;
	else tree[p].l=tree[p*2+1].l;
	if (tree[p*2+1].r)	tree[p].r=tree[p*2+1].r;
	else tree[p].r=tree[p*2].r;
}
void print(int p,int l,int r){
	printf("%d %d %d %d %d %d\n",p,l,r,tree[p].l,tree[p].r,tree[p].mx);
	if (l==r)	return;
	int mid=(l+r)>>1;
	print(p*2,l,mid);
	print(p*2+1,mid+1,r);
}

void modify(int p,int l,int r,int a,int z){
	if (l==r){
		tree[p].l=tree[p].r=l*z;
		return;
	}
	int mid=(l+r)>>1;
	if (a<=mid)	modify(p*2,l,mid,a,z);
	else modify(p*2+1,mid+1,r,a,z);
	update(p);
}
int main(){
	scanf("%d%d",&n,&m);
	int tot=0;
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]),c[++tot]=a[i];
	for (int i=1; i<=m; i++){
		scanf("%d%d",&q[i].o,&q[i].x);
		c[++tot]=q[i].x;
	}
	sort(c+1,c+1+tot);
	int T=unique(c+1,c+1+tot)-c-1;
	for (int i=1; i<=m; i++)
		q[i].pos=lower_bound(c+1,c+1+T,q[i].x)-c;
	for (int i=1; i<=n; i++)
		modify(1,1,T,lower_bound(c+1,c+1+T,a[i])-c,1);
	printf("%d\n",c[tree[1].r]-c[tree[1].l]-tree[1].mx);
	for (int i=1; i<=m; i++){
		modify(1,1,T,q[i].pos,q[i].o);
		printf("%d\n",c[tree[1].r]-c[tree[1].l]-tree[1].mx);
	}
	return 0;
}