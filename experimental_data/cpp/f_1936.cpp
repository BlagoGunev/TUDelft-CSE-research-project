#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 111111;
const DB P = (sqrt(5)-1)/2;
DB M=1e7;
int tt=70;
int n;
struct node{
	int x,y,z;
}a[N];
DB cal(DB x,DB y,int prt=0){
	int i;
	DB s=M;
	for(i=1;i<=n;i++)
		s=min(s,a[i].z-sqrt((x-a[i].x)*(x-a[i].x)+(y-a[i].y)*(y-a[i].y)));
	if(prt)
		printf("%.12lf %.12lf %.12lf\n",x,y,s);
	return s;
}
DB solve(DB x,int prt=0){
	DB l,r,l1,r1,fl,fr;
	int j;
	l=-M,r=M;
	l1=l*P+r*(1-P),fl=cal(x,l1);
	r1=r*P+l*(1-P),fr=cal(x,r1);
	for(j=1;j<=tt;j++){
		if(fl>fr){
			r=r1;
			r1=l1,fr=fl;
			l1=l*P+r*(1-P),fl=cal(x,l1);
		}
		else{
			l=l1;
			l1=r1,fl=fr;
			r1=r*P+l*(1-P),fr=cal(x,r1);
		}
	}
	return cal(x,(l+r)/2,prt);
}
int main(){
	int i,j;
	DB l,r,l1,r1,fl,fr;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	l=-M,r=M;
	l1=l*P+r*(1-P),fl=solve(l1);
	r1=r*P+l*(1-P),fr=solve(r1);
	for(j=1;j<=tt;j++){
		if(fl>fr){
			r=r1;
			r1=l1,fr=fl;
			l1=l*P+r*(1-P),fl=solve(l1);
		}
		else{
			l=l1;
			l1=r1,fl=fr;
			r1=r*P+l*(1-P),fr=solve(r1);
		}
	}
	solve((l+r)/2,1);
	return 0;
}