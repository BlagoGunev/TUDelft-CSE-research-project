#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,ans,now;
int a[400005],t[400005];
int m1,m2,m;
int A[400005],B[400005];
int b[400005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1){
		int x; scanf("%1d%1d",&x,&t[i]);
		t[i]|=(x<<1); scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i+=1){
		if(t[i]==3){
			ans+=a[i]; now+=1;
		}
		if(t[i]==1) A[++m1]=a[i];
		if(t[i]==2) B[++m2]=a[i];
		if(!t[i]) b[++m]=a[i];
	}
	sort(A+1,A+m1+1,cmp); sort(B+1,B+m2+1,cmp);
	if(m1<m2) swap(m1,m2),swap(A,B);
	for(int i=1;i<=m2;i+=1) ans+=A[i]+B[i];
	for(int i=m2+1;i<=m1;i+=1) b[++m]=A[i];
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<=m&&i<=now;i+=1) ans+=b[i];
	printf("%d\n",ans);
	return 0;
}