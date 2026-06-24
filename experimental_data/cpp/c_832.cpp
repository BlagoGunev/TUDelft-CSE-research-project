#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define N 1234567
using namespace std;
struct node{double x,v;};
node L[N],R[N];
int n,lcnt,rcnt;double s,EN=1000000;
bool ok(double t)
{
	int i,j,k;bool f=0;
	double tmp;
	int LL=1e6,RR=0;
	for(i=1;i<=lcnt;i++)
	{
		if(L[i].x==0||(L[i].v!=0&&L[i].x/L[i].v<=t)){f=1;LL=0;RR=EN;break;}
		if(L[i].x/(L[i].v+s)>t)continue;
		tmp=(t*(s*s-L[i].v*L[i].v)+L[i].v*L[i].x)/s;
		RR=max(RR,int(floor(tmp)));
		LL=min(LL,int(ceil(L[i].x)));
		f=1;
	}
	if(!f)return 0;
	for(i=1;i<=rcnt;i++)
	{
		if(R[i].x<LL&&(R[i].v!=0&&(EN-R[i].x)/R[i].v>t))continue;
		if(R[i].x==EN||(R[i].v!=0&&(EN-R[i].x)/R[i].v<=t))return 1;
		if((EN-R[i].x)/(R[i].v+s)>t)continue;
		if(RR>R[i].x&&LL<R[i].x)return 1;
		tmp=(R[i].x-RR)/(s-R[i].v);
		tmp=(EN-R[i].x-tmp*R[i].v)/(s+R[i].v)+tmp;
		if(tmp<=t)return 1;
	}
	return 0;
}
void EF(double l,double r)
{
	while(r-l>=0.0000000001)
	{
		double mid=(l+r)/2;
		if(ok(mid))r=mid;
		else l=mid;
	}
	printf("%.10lf",l);
}
int main()
{
	double x,y;int i,j,k;
	scanf("%d%lf",&n,&s);
	for(i=1;i<=n;i++)
	{
		scanf("%lf%lf%d",&x,&y,&k);
		if(k==1){++lcnt;L[lcnt].x=x;L[lcnt].v=y;}
		else{++rcnt;R[rcnt].x=x;R[rcnt].v=y;}
	}
	EF(0,1000000);
}