#include <bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#define N 100010
#define LL long long
#define INF 1000000000000000010
using namespace std;

int n,i,k;
LL l,r,L,Ans;
LL a[N],d[N],sum[N];

inline int Abs(int x){return (x<0)?x:-x;}
inline int Min(int a,int b){return (a<b)?a:b;}
inline int Max(int a,int b){return (a>b)?a:b;}

inline LL read(){
	LL p=0;	char	c=getchar();
	while (c<48||c>57)	c=getchar();
	while (c>=48&&c<=57)	p=(p<<1)+(p<<3)+c-48,c=getchar();
	return p;
}

inline void Ready(){
	int i=0;
	for (i=2;i<=n;i++)	d[i-1]=a[i]-a[i-1];
	d[n]=INF;
	sort(d+1,d+1+n);
	for (sum[1]=d[1],i=2;i<=n;i++)	sum[i]+=sum[i-1]+d[i];
}

inline void Work(){
	int i=0,low=1,high=n,mid=0;
	while (low<high){
		mid=(low+high)>>1;
		if (d[mid]>L)	high=mid-1;
		else low=mid+1;
	}
	while (d[low+1]<=L&&low<n)	low++;
	while (d[low]>L)	low--;
//	cout<<low<<" "<<d[low]<<" "<<L<<endl;
	Ans+=sum[low];
	Ans+=(LL)(n-low)*(LL)(L+1);
}

int main(){
//	freopen("zht.in","r",stdin);
//	freopen("zht.out","w",stdout);
	n=read();
	for (i=1;i<=n;i++)	a[i]=read();
	sort(a+1,a+1+n);
	Ready(); 	k=read();
	while (k--){
		l=read();	r=read();	Ans=0;
		L=r-l;	Work();
		printf("%lld\n",Ans);
	}
	return 0;
}