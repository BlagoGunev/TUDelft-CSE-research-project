#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
int a[105];
int main(){
	int n,k,x;
	scanf("%d%d%d",&n,&k,&x);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int ans=0;
	if(n<=k) ans=x*n;
	else{
		for(i=0;i<n-k;i++){
			ans+=a[i];
		}
		ans+=k*x;
	}
	printf("%d\n",ans);
}