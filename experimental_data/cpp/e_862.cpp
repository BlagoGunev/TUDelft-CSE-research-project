#include <bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
long long sum[100005],sumb[100005];
int top=0;

int check(long long x){
	int l=0,r=top;
	while(l<r){
		int mid=(l+r)/2;
		if (sum[mid]<x) l=mid+1; else r=mid;
	}
	return l; 
}
long long _sum=0;
int main(){
	int n,m,q;
	long long x;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);
		long long t;
		if (i&1) t=1; else t=-1;
		_sum+=t*x;
	}
	//printf("%lld\n",suma[n]);
	for(int i=1;i<=m;i++){
		scanf("%lld",&x);
		long long t;
		if(i&1) t=1; else t=-1;
		sumb[i]=sumb[i-1]+t*x;
	}
	for(int j=0;j<=m-n;j++){
		long long t;
		if(j&1) t=1; else t=-1;
		long long ans=(sumb[j+n]-sumb[j])*t;
		sum[++top]=ans;
	//	printf("%lld\n",ans);
	}
	sort(sum+1,sum+top+1);
	sum[++top]=100000000000000000LL;
	sum[0]=-1000000000000000000LL;
	//long long _sum=suma[n];
	//printf("%lld %d\n",_sum,top);
	//printf("%d\n",check(_sum));
	int p=check(-_sum);
	printf("%lld\n",min(abs(sum[p]+_sum),abs(sum[p-1]+_sum)));
	for(int i=1;i<=q;i++){
		int a,b;
		scanf("%d%d%lld",&a,&b,&x);
		if((a+b)&1) {
			int p=check(-_sum);
			printf("%lld\n",min(abs(sum[p]+_sum),abs(sum[p-1]+_sum)));
		}
		else {
			if ((a&1)==1){
				_sum+=x;
				int p=check(-_sum);
				printf("%lld\n",min(abs(sum[p]+_sum),abs(sum[p-1]+_sum)));
			}
			else {
				_sum-=x;
				int p=check(-_sum);
				printf("%lld\n",min(abs(sum[p]+_sum),abs(sum[p-1]+_sum)));
			}
		}
	}
}