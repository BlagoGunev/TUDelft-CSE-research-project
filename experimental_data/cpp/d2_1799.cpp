#include<bits/stdc++.h>
#define mz 1000000007
using namespace std;

struct Node{
	int l,r,mid;
	long long minn;
}tre[1200006];


int c[300006],h[300006],a[300006];

void build(int x,int l,int r){
	tre[x].l=l;
	tre[x].r=r;
	tre[x].mid=(l+r)>>1;
	tre[x].minn=mz*1LL*66666;
	if(l!=r){
		build(x*2,l,tre[x].mid);
		build(x*2+1,tre[x].mid+1,r);
	}
}
void change(int x,int p,long long val){
	if(tre[x].l==tre[x].r)
		tre[x].minn=min(tre[x].minn,val);
	else{
		if(p<=tre[x].mid)
			change(x*2,p,val);
		else
			change(x*2+1,p,val);
		tre[x].minn=min(tre[x*2].minn,tre[x*2+1].minn); 
	}
}
long long ask(int x,int l,int r){
	if(l==tre[x].l && r==tre[x].r)
		return tre[x].minn;
	if(r<=tre[x].mid)
		return ask(x*2,l,r);
	if(l>tre[x].mid)
		return ask(x*2+1,l,r);
	return min(ask(x*2,l,tre[x].mid),ask(x*2+1,tre[x].mid+1,r));
}

int main(){
	int t,n,k;
	long long m1,m2,flg;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		build(1,0,k);
		change(1,0,0);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=k;i++)
			scanf("%d",&c[i]);
		for(int i=1;i<=k;i++)
			scanf("%d",&h[i]);
		flg=0;
		for(int i=1;i<=n;i++){
			m1=ask(1,0,a[i]-1)+flg;
			if(a[i]<k)
				m1=min(m1,ask(1,a[i]+1,k)+flg);
			m2=ask(1,a[i],a[i])+flg;
			if(a[i]==a[i-1])
				flg+=h[a[i]];
			else
				flg+=c[a[i]];
			change(1,a[i-1],min(m1+c[a[i]],m2+h[a[i]])-flg);
		}
		printf("%lld\n",ask(1,0,k)+flg);
	} 
	return 0; 
}
/*

dp[i][k] 

dp[i+1][k]:dp[i][k]+cold[a[i+1]]/hot[a[i+1]](ȡ����a[i+1]==a[i])
dp[i+1][a[i]]:dp[i][k]+cold[a[i+1]]/hot[a[i+1]](ȡ����a[i+1]==k)
*/